//heijian-jindao ��������
//by fqyy
/*
    ��һ����ͷֱ���������ƺ���Ϊ���ͣ����ֻ����һ����������ױܹ���Ȼ��������
��������Ȧȴ����ס����ǰ�����ң������������ܶ���֮�������ֻ�þ����ظ��ȣ�һ��
��ֻ�����족��Ӳ���������С������õ���һ�����죬�����ཻ��ֻ���û��Ľ������˫
��ֻ��һ�����顣��������ڶ����������ϣ��з����һ��һģһ���������ѧ����ȹ㣬
�ٵ�ʱ���ǻ����쳣�������޷��ƽ����Ɀ׾���ص�һ�У�����ͬ��Ӳ��֮�⣬�����Ʋߡ�
���ȶ����ཻ�����˫���������������ֻҪ�ٸ�����㿳�ϼ��������ֱ��ϵĽ���ҲҪ��
���ˡ�˼��δ���������������ֿ��˹������ٽ�������������еİ�ظ����Ѹ��𵶿���
����ȱ�ڣ����ֻ�����Ҳ���Ѫ����
    �����������Σ��֮����������΢Ц������һ�����������ֺڽ���������С���ϴ�ȥ��
�����ʱ�Ѹ����������ǣ��ۼ�����̵���æ����ƽ��һ����������������ģ�������ɻ�
�Σ����˻�����ԭ��С��Ů���������Ǽ��ܣ��ڽ�������ȴҲ�������á�
*/

#include <ansi.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
void next1(object me, object target, int i);
void next2(object me, object target, int i);
int perform(object me,object target)
{
	int i;
	string msg;
	object *inv;
	object weapon2;
        object weapon = me->query_temp("weapon");  

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("�����������ʹ������������\n");

        if( me->query("jing") <= 500 )
                return notify_fail("��ľ�������ʹ������������\n");
        if( me->query_skill("heijian-jindao",1) < 60 )
                return notify_fail("��ڽ���δ��¯����֮����\n");

        if (!weapon)
                return notify_fail("�������޽�����ʹ��������������\n");
        if (!me->query_temp("heijian-jindao/luanren",1)||!me->query_temp("heijian-jindao/nizhuan",1))
                return notify_fail("�㲻ʹ�á����������з�����ô��������������ס�����ж���\n");

        if ( me->query_skill_mapped("sword") != "heijian-jindao"
          || me->query_skill_mapped("parry") != "heijian-jindao"
          || me->query_skill_mapped("blade") != "heijian-jindao"
          && userp(me))
             	return notify_fail("������Ƚ��ڽ����໥��ϡ�\n");
       inv = all_inventory(me);
       for(i=0; i<sizeof(inv); i++) {
           if( inv[i]->query("equipped") || weapon == inv[i] ) continue;
		if (weapon->query("skill_type") == "blade") {
        	   if( inv[i]->query("skill_type") == "sword" ) 
		   {
			   weapon2 = inv[i];
			   i = 3;
			   break;
		   }
		}
		if (weapon->query("skill_type") == "sword") {
   	        if( inv[i]->query("skill_type") == "blade" ) 
		   {
			   weapon2 = inv[i];
			   i = 2;
			   break;
		   }
		}
       }
	if (!objectp(weapon2)) return notify_fail("��ֻ��һ�ֱ�����������������\n");

	msg = HIM"$N��һ����ͷֱ���������ƺ���Ϊ���ͣ�$nֻ����һ����������ױܹ���\n"+
		"Ȼ��$N������Ȧȴ����ס����ǰ�����ң���$n�������ܶ���֮����\n"NOR;
	me->start_perform(5,"������������");
	if((random(me->query_skill("heijian-jindao",1)) + me->query_int()) >
	(target->query_skill("dodge",1)/3 + target->query_int())) {
		msg = msg + HIR "$nֻ��һ�С�ֻ�����족��Ӳ����$N���С�\n" NOR;
		target->add_busy(random(i*5) + 2);
	}
	else {
		msg = msg + HIW "����$n������$N����ͼ���ɿ�������ȥ��\n" NOR;
		me->start_busy(2);
	}
	message_vision(msg, me, target);
	next1(me, target, i);
	return 1;
}

void next1(object me, object target, int i)
{
	string msg;
	int damage;
	object weapon;

	if (!me) return ;
	weapon = me->query_temp("weapon");
	if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
		return ;
	}

	msg = HIG"\n$N�ڶ����������ϣ��з����һ��һģһ����\n"+
		"$n��ѧ����ȹ㣬�ٵ�ʱ���ǻ����쳣�������޷��ƽ����Ɀ׾���ص�һ�У�����ͬ��Ӳ��֮�⣬�����Ʋߡ�\n"NOR;

	if((random(me->query("max_neili")) + me->query_skill("force",1)) >
	    (target->query("max_neili") + target->query_skill("force",1))/3 ||(target->is_busy()&&random(2))){
		msg = msg + HIR"$N$n������ƴ��$n˫�����������ֻҪ�ٸ�$N��㿳�ϼ�����$n�ֱ��ϵĽ���ҲҪ�����ˡ�\n"NOR;
		damage = me->query_skill("heijian-jindao",1);
		damage += me->query_skill("blade",1);
		damage += random(damage);
		if (!target->is_busy()) target->start_busy(damage/500);
		target->add("neili",-(500+random(150)));
		damage=damage+500;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		msg += damage_msg(damage, "����");
		msg = replace_string(msg, "$w", weapon->name());
		msg = replace_string(msg, "$l", "�ֱ�");
		message_vision(msg, me, target);
		COMBAT_D->report_status(target, random(2));
		me->add("neili",-300);
me->start_busy(2);
		me->add("jing",-100);
	} else {
		msg  =  msg + CYN"$n�������Ӳ������������һ�С�\n"NOR;
		message_vision(msg, me, target);
		me->start_busy(1+random(2));
		target->start_busy(1+random(2));
	}

	next2(me, target, i);

}

void next2(object me, object target, int i)
{
	string msg;
	int damage;
	object weapon;

	if( !me ) return ;

	weapon = me->query_temp("weapon");
	if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
		return ;
	}

	msg = HIC "\n$n˼��δ����$N�������ֿ��˹���������һ�����������ֽ���ͻ����$nС���ϴ�ȥ��\n"NOR;

	if((random(me->query("combat_exp")) + me->query_str()) >
	    (target->query("combat_exp") + target->query_str())/3 ||(target->is_busy()&&random(2))){
		msg = msg + HIW "$n��ʱ�Ѹ�$N�������ǣ��ۼ�����̵���æ����ƽ��һ�����������$n���ģ�\n"NOR;
		damage = me->query_skill("heijian-jindao",1);
		damage += me->query_skill("sword",1);
		damage += random(damage);
		if (!target->is_busy()) target->start_busy(damage/500);
		target->add_temp("apply/attack", -100);
		target->add_temp("apply/dodge", -100);
		target->add_temp("apply/parry", -100);
		damage=damage+500;
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		msg += damage_msg(damage, "����");
		msg = replace_string(msg, "$w", weapon->name());
		msg = replace_string(msg, "$l", "����");
		message_vision(msg, me, target);
		COMBAT_D->report_status(target, random(2));
		me->add("neili",-300);
		me->add("jing",-50);
		call_out("back", 5 + random(me->query("jiali") / 20), target);
	} else {
		msg = msg + HIW "$n��ʱ�Ѹ����������ǣ��ۼ�����̵���æ����ƽ��һ����������������ģ�\n$n�������ʹ�ý�����ɻ��Σ����˻�����\n" NOR;
		message_vision(msg, me, target);
		me->start_busy(2);
		target->start_busy(1+random(2));
	}
}

void back(object target)
{
	if (!target) return;
	target->add_temp("apply/attack", 100);
	target->add_temp("apply/dodge", 100);
	target->add_temp("apply/parry", 100);
}

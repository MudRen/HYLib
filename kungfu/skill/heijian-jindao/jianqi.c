// heijian-jindao ������ն���
/*
    �������������ս�������е��������������ڽ����������ش�ȥ�����ǽ��Ⲣ��ֱ����
ȴ��������ǰ��תȦ�ӡ������֪��ڽ�Ҫ����η�����֮�£������Ծ��
    ����������ֿ켫�������Ծ�˱ܣ��ڽ����ɵ�ԲȦ����ָ������ǰ����ȦԽ��Խ��
��ʱ��ֻ������ǰ��תȦ������һ����������С��Ҳ���ڽ�Ȧ֮�У���ʹ���У���Ȧ������
������ͷ��������Ծ�����������Ҫ���Ѿ�������������֮�¡����ַ�������������������
����ƽ��δ������㻮Ȧ�ƵеĽ������޲���Ϊ���졣
*/
#include <ansi.h>
inherit F_DBASE;
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
	int i,damage;
	object *inv;
	object weapon2;
	string msg;
        object weapon = me->query_temp("weapon");  

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������նԷ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_dex() < 40 )
                return notify_fail("�������������������㣬����ʹ�ý�����նԷ���\n");
        
        if( me->query_skill("dodge") < 150 )
                return notify_fail("������նԷ���Ҫ�������Ṧ��ϣ�������Чʩչ��\n");

        if( me->query_skill("sword") < 150 )
                return notify_fail("�㽣��δ��¯����֮����������ʹ�ý�����նԷ���\n");
        if( me->query_skill("blade") < 150 )
                return notify_fail("�㵶��δ��¯����֮����������ʹ�ý�����նԷ���\n");
        if( me->query_skill("heijian-jindao",1) < 150 )
                return notify_fail("��ڽ���δ��¯����֮����\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("�����������ʹ�ý�����նԷ���\n");

        if( me->query("jing") <= 500 )
                return notify_fail("��ľ�������ʹ�ý�����նԷ���\n");

        if (!weapon)
                return notify_fail("�������޽�����ʹ�ý�����նԷ�����\n");
        if (target->is_busy())
                return notify_fail("�Է����Թ˲�Ͼ����Էŵ�������\n");
        if (me->query_temp("heijian-jindao/nizhuan",1))
                return notify_fail("������ʹ�����������з��޷����ý�����նԷ���\n");

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
	if (!objectp(weapon2)) return notify_fail("��ֻ��һ�ֱ������뽣����նԷ���\n");
	if (i>2) weapon=weapon2; 
message_vision(HIM"$N�е�������������"+weapon->name()+HIM"���������ش�ȥ�����ǽ��Ⲣ��ֱ����ȴ����$n��ǰ��תȦ�ӡ�\n"+
		HIW"$n��֪��"+weapon->name()+HIW"Ҫ����η�����֮�£������Ծ��\n"+
		HIM"$N���ֿ켫��$n��Ծ�˱ܣ�"+weapon->name()+HIM"���ɵ�ԲȦ����ָ��$n��ǰ����ȦԽ��Խ��\n"+
		"��ʱ��ֻ����$nǰ��תȦ������һ��������$nС��Ҳ���ڽ�Ȧ֮�У���ʹ���У���Ȧ��������$n��ͷ����\n"+
		HIR"$n�Ծ�����������Ҫ���Ѿ�������������֮�¡�\n"NOR,me,target);
	if((random(me->query("max_neili")) + me->query_skill("force",1)) >
	    (target->query("max_neili") + target->query_skill("force",1))/3 ||(target->is_busy()&&random(2))){
		damage = me->query_skill("heijian-jindao",1);
		damage += me->query_skill("sword",1);
		damage += random(damage);
		target->start_busy(damage/300);
    		target->add_temp("lost_attack", damage/100);
              target->start_busy(4);
		target->add("neili",-(500+random(150)));
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		msg = damage_msg(damage, "����");
		msg = replace_string(msg, "$w", weapon->name());
		msg = replace_string(msg, "$l", "С��");
		message_vision(msg, me, target);
		COMBAT_D->report_status(target, random(2));
		me->add("neili",-300);
		me->add("jing",-50);
	} else {
		damage=600;
	}
        me->start_busy(2);
        me->add("neili", -500);
        me->add("jing", -50);
	me->start_perform(damage/300,"������նԷ�");

        return 1;
}

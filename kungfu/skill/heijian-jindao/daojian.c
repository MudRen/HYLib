// heijian-jindao �������
/*
    ���������ϲ�����������ӽ��������������ֵ�ȴͬʱʹ�ˡ������롱������ʽ��
�𡱡���������ء�������Ʒ��̨�����С������ֽ���Ʈ����ת���Ľ���������֮�С����
��������������С��Ůȴ�����Ļţ���ӽ�ȥ�������棬��������ɷ�������������
��֪��������������ˣ�ʹһ��ȫ�潣���еġ������仨����ƽ�������������ָ������
*/
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;
void attack_ob(object me, object target,object weapon,object weapon2);
int perform(object me, object target)
{
	int i;
	object *inv;
	object weapon2;
        object weapon = me->query_temp("weapon");  

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_dex() < 40 )
                return notify_fail("�������������������㣬����ʹ�õ�����ӣ�\n");
        
        if( me->query_skill("dodge") < 180 )
                return notify_fail("���������Ҫ�������Ṧ��ϣ�������Чʩչ��\n");

        if( me->query_skill("sword") < 180 )
                return notify_fail("�㽣��δ��¯����֮����������ʹ�õ�����ӣ�\n");
        if( me->query_skill("blade") < 180 )
                return notify_fail("�㵶��δ��¯����֮����������ʹ�õ�����ӣ�\n");
        if( me->query_skill("heijian-jindao",1) < 180 )
                return notify_fail("��ڽ���δ��¯����֮����\n");

        if( me->query("neili") <= 1000 )
                return notify_fail("�����������ʹ�õ�����ӣ�\n");

        if( me->query("jing") <= 500 )
                return notify_fail("��ľ�����ʹ�õ�����ӣ�\n");

        if (!weapon)
                return notify_fail("�������޽�����ʹ�õ�����ӣ���\n");
        if (me->query_temp("heijian-jindao/luanren",1))
                return notify_fail("������ʹ�����������з��޷��ٵ�����ӣ�\n");

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
	if (!objectp(weapon2)) return notify_fail("��ֻ��һ�ֱ������뵶����ӣ�\n");
        me->add_temp("apply/attack", me->query_skill("heijian-jindao",1)/10);
        message_vision(HIC"$N���һ����ʱ�书��������޷�������������ת���ӽ�����������\n"NOR, me, target);
	if (!me->query_temp("heijian-jindao/nizhuan",1)) {
		me->set_temp("heijian-jindao/nizhuan",1);
		i=4;
	}
	if (weapon->query("skill_type")=="blade") {
		weapon->unequip();
		weapon2->wield();
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		weapon2->unequip();
		weapon->wield();
	} else if (weapon->query("skill_type")=="sword") {
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
	}
	if (i==4) {
		me->delete_temp("heijian-jindao/nizhuan");
	}
        me->add_temp("apply/attack", -me->query_skill("heijian-jindao",1)/10);
        me->add("neili", -500);
        me->add("jing", -100);
me->start_busy(3);
	call_out("attack_ob",1,me,target,weapon,weapon2);
	me->start_perform(4,"�������");

        return 1;
}
void attack_ob(object me, object target,object weapon,object weapon2)
{
	int i;
	if (!me) return ;
	if (!weapon || !target || !living(me) || !me->is_fighting(target)) {
		return ;
	}
	message_vision(HIR"\n������$N����ͣ�����ֵ�ͬʱʹ�ˡ������롱������ʽ�ֽ𡱡���������ء�������Ʒ��̨�����С�\n"+
"�����ֽ���Ʈ����ת���Ľ���������֮�С�\n"+"$n������������ӽ�ȥ�������棬��"+
weapon->name()+weapon2->name()+HIR"����ɷ����������\n"NOR,me,target);
	if (!me->query_temp("heijian-jindao/nizhuan",1)) {
		me->set_temp("heijian-jindao/nizhuan",1);
		i=4;
	}
        me->add_temp("apply/attack", me->query_skill("heijian-jindao",1)/6);
	if (weapon->query("skill_type")=="blade") {
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
		COMBAT_D->do_attack(me, target, weapon,1);
	} else if (weapon->query("skill_type")=="sword") {
		weapon->unequip();
		weapon2->wield();
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		COMBAT_D->do_attack(me, target, weapon2,1);
		weapon2->unequip();
		weapon->wield();
	}
        me->add_temp("apply/attack", -me->query_skill("heijian-jindao",1)/6);
	if (i==4) {
		me->delete_temp("heijian-jindao/nizhuan");
	}
}


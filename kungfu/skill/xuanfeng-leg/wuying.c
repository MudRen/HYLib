// suodi.c ����������.����ֹ��

#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;
int extra;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����Ӱ�š���ʼʱ�������ű�����\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("bibo-shengong",1) < 50 )
		return notify_fail("��ı̲��񹦲�����\n");

	if( (int)me->query_skill("luoying-zhang",1) < 100 ||
	    me->query_skill("xuanfeng-leg",1) < 100)
		return notify_fail("������ƹ��򻹲����ң��޷�ʹ����Ӱ�ţ�\n");   
        if (me->query_skill_mapped("unarmed") != "xuanfeng-leg")
                return notify_fail("��û�м�������ɨҶ�ȣ�����ʩչ��\n");
	if( (int)me->query("neili") < 200  ) 
		return notify_fail("�������������\n");

	extra = me->query_skill("xuanfeng-leg",1) / 10;
	extra += me->query_skill("luoying-zhang",1) /20;
         attack_time = (int)me->query_skill("xuanfeng-leg", 1) / 30;
        if (attack_time< 2)attack_time=2;
        if (attack_time> 12)attack_time=12;
        msg = HIC "$N�߸�Ծ��˫����������Ӱ���١�\n";
if (!target->is_busy() && random(6)==0 ) target->start_busy(2);
        message_combatd(msg, me, target);
  
        for(i = 0; i < attack_time; i++){
         msg =  HIC "��"+chinese_number(i+1)+"��!" NOR;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*2);
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra*2);
                                        }
	me->add("neili", - 20*i);
        me->start_busy(2);
        return 1;
}


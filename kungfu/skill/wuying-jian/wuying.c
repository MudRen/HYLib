//��ȥ������ wuying.c
// by godzilla 99.03.06

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

//inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
	int extra;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������Ӱ��ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
                return notify_fail("��������Ӱ�������ý�����ʩչ��\n");

        if( (int)me->query_skill("wuying-jian", 1) < 150 )
                return notify_fail("��ġ�������Ӱ����������죬����ʹ�á�������Ӱ����\n");

//        if (me->query_skill_mapped("force") != "yijinjing")
//                return notify_fail("����ڹ������׽��\n");

	if( (int)me->query_skill("yijinjing", 1) < 100 )
		return notify_fail("����׽������졣\n");

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("�������������\n");

        skill = me->query_skill("wuying-jian");
	extra = me->query_skill("wuying-jian",1) / 10;
	extra += me->query_skill("wuying-jian",1) /10;
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", (extra*5));

        msg = HIG "$N����ͻ�䣬˲������ֳ�������Ӱ��������$n��ȥ��\n"NOR;
        message_vision(msg, me, target);

        me->add("neili", -200);

        msg = HIR"VV���־���\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIY"VVVVȥ�־���\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIG"VVVVVV���־���\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIB"VVVVVVVV���־���\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIW"VVVVVVVVVV���־���\n"NOR;
       
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);


        me->start_busy(2);
	me->add_temp("apply/attack", -80);
	me->add_temp("apply/damage", -(extra*5));

        return 1;
}

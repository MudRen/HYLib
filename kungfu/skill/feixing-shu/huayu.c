// huayu.c

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int amount, i;
        string msg;
        object weapon, *ob;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���컨��ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
	     || (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");

        if( (int)me->query_skill("feixing-shu", 1) < 150 )
                return notify_fail("��ķ�����������죬����ʹ�����컨�ꡣ\n");
        if( (int)me->query_skill("huagong-dafa", 1) < 150 )
                return notify_fail("��Ļ����󷨲�����죬����ʹ�����컨�ꡣ\n");
	 if( (int)me->query_skill("throwing",1) <150 )
		  return notify_fail("��İ���Ͷ��������죬����ʹ�����컨�ꡣ\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("�����������ˡ�\n");
weapon = me->query_temp("weapon");

        msg=HIR"ֻ��һ�ɾ����$N���Ҳ෢����$N���е�"+weapon->name()+HIR"���������$n���ֹ�ȥ��\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        target->apply_condition("xx_poison",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);

        me->start_busy(3);
	weapon->unequip();
        destruct(weapon);
        me->reset_action();
	me->add("neili",-300);
        return 1;
}


// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        object weapon;
        extra = me->query_skill("qingshe-sword",1);
        if ( extra < 50) return notify_fail("��ģ����߽����ݻ��������죡\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�þ��С�\n");
        if( !target ) target = offensive_target(me);
        if( !target

        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ǧ�߳�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        me->add_temp("apply/attack",50);
        me->add_temp("apply/damage",500);
        weapon = me->query_temp("weapon");
        msg = HIR  "\n\n$N���е�$w�ó�ǧ�佣��ʹ�����߽����Ĳ�����ѧ ---ǧ-��-��-��--- ����\n\n\n������̽ͷ��\n$N����$wֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "����΢��о��\n$N����$wб��$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "���߷�����\n$N����$w���$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "�������˷���\n$N����$w�ʹ�$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "���������Σ�\n$N����$w����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-180);
        me->start_busy(3);
        me->add_temp("apply/attack",-50);
        me->add_temp("apply/damage",-500);
        return 1;

}
// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        object weapon,ob;
        extra = me->query_skill("qishen-dao",1);
        
        if( (int)me->query("neili") < 300 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("blade") < 150 ||
            me->query_skill_mapped("blade") != "qishen-dao")
                return notify_fail("��ġ����񵶷����������ң��޷�ʹ�á�ɱ�����ڡ���\n");

        if((int)me->query_skill("qishen-dao", 1) < 200)
                return notify_fail("��Ĵ����书�ȼ���������\n");


        dodskill = (string) me->query_skill_mapped("dodge");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ɱ�����ڡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");

//        me->clean_up_enemy();
        ob = me->select_opponent();
        if( !target->is_killing(me) ) me->kill_ob(target);
        msg = HIW  "$N������ͨ�������񵶷���ʽһ���ǳɣ�\n\n"HIY"��һʽ����Ŀȫ�ǣ�\n\n$N����$wбָ��һ�С���Ŀȫ�ǡ����������ŵ��棬��$n��$l��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ڶ�ʽ������������\n\n"HIY"$Nһ�С�������������$w�����ַ��գ�����Ӷ������˾�ɼ�׶��������$nֱ�������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "����ʽ��Ѫ�����\n\n"HIY"$Nչ���鲽������Ծ�䣬һ�С�Ѫ����𡹣�����һ������ն��$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "����ʽ��������룡\n\n"HIY"$Nһ�С�������롹��$w�󿪴��أ����϶��»���һ�����磬ֱ����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "����ʽ���з�֮ʹ��\n\n"HIY"$N����$wһ����һ�С��з�֮ʹ����˫�ֳ����������У�����$n���ؿڡ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "����ʽ�����زң�\n\n"HIY"$Nһ�С����زҡ�������������裬�˵�������ƣ���������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "����ʽ�������ţ�\n\n"HIY"$Nһ�С������š������Ծ����أ�$w˳����ǰ��Ю��������$n��$l��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�ڰ�ʽ����������\n\n"HIY"$N����פ�أ�һ�С��������񡹣��ӳ�һƬ�����ĵ�Ӱ����$n��ȫ��ӿȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -500);
        me->start_busy(4);
        return 1;
}


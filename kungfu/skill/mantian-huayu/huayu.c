// ren.c  ���ǽ��������컨�꡹

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage,extra;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "throwing")
               return notify_fail("��ʹ�õ��������ԡ�\n");
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("�����컨�꡹ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("mantian-huayu", 1) < 80 )
        return notify_fail("�����컨�겻����죬ʹ���������컨�꡹��\n");
    if ((int)me->query_skill("xuantian-wuji", 1) < 40 )
        return notify_fail("�������޼�����򲻹���ʹ���������컨�꡹��\n");

    if ((int)me->query("max_neili")<400)
        return notify_fail("��������Ϊ���㣬�޷�����������\n");
    if ((int)me->query("neili")<200)
    {
        return notify_fail("����������������û�ܽ������컨�꡹ʹ�꣡\n");
    }
	extra = me->query_skill("mantian-huayu",1) / 20;
	extra += me->query_skill("mantian-huayu",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 400);
if (random(2)==0) target->start_busy(3);
    msg = HIW "$N�����ָ�ץ��ö�������ƺ�����������$n��\n"NOR;
    msg += HIC"һ��ڹ�����$n��ͷ����"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg =  HIB"һ��ڹ���$n��в����ȥ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"һ��ڹ���·�ͻȻ˦����ֱ����$n��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"һ��ڹ�Ӹߴ����䣬ֱ��$n��ȥ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"����ö��һ��һ������$n�����ң�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -400);

      if(!target->is_fighting(me)) target->fight_ob(me);
	me->start_busy(3);
        me->add("neili", -200);
    return 1;
}

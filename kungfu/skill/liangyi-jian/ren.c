// ren.c  ���ǽ��������ͬ�ʡ�

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
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail("��ʲô��Ц��ûװ��������ʹ�����ͬ�ʡ���\n");
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("�����ͬ�ʡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("liangyi-jian", 1) < 50 )
        return notify_fail("�����ǽ���������죬ʹ���������ͬ�ʡ���\n");
    if ((int)me->query_skill("xuantian-wuji", 1) < 50 )
        return notify_fail("�������޼�����򲻹���ʹ���������ͬ�ʡ���\n");
    if ((int)me->query("max_neili")<400)
        return notify_fail("��������Ϊ���㣬�޷�����������\n");
    if ((int)me->query("neili")<210)
    {
        return notify_fail("����������������û�ܽ������ͬ�ʡ�ʹ�꣡\n");
    }
	extra = me->query_skill("liangyi-jian",1) / 20;
	extra += me->query_skill("liangyi-jian",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
if (random(2)==0) target->start_busy(2);
    msg = HIC "$N���г�����âԾ�������Ⱪ������������ƺ������Ҵ���$n��\n"NOR;
    msg += HIC"$n��������ƫ�󣬼�������ת����ֻ��һɲ������ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG"$n��������ƫ�ң���������ת����ֻ��һɲ������ɲʱϮ�����ף�"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR"$n��������ƫ�ϣ����������У���ֻ��һɲ������ɲʱϮ������"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

      if(!target->is_fighting(me)) target->fight_ob(me);
	me->start_busy(2);
        me->add("neili", -200);
    return 1;
}

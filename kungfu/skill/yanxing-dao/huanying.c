// huanying.c  ���е��������λ�Ӱ��

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
    int damage;
    string msg;
    object weapon;

    if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����λ�Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
        return notify_fail("��ʲô��Ц��ûװ������ôʹ�����λ�Ӱ����\n");
    if ((int)me->query_skill("yanxing-dao", 1) < 150 )
        return notify_fail("�����е���������죬ʹ���������λ�Ӱ����\n");
    if ((int)me->query_skill("linji-zhuang", 1) < 90 )
        return notify_fail("���ټ�ׯ��򲻹��������λ�Ӱ��������ʽ��\n");
    if ((int)me->query("max_neili")<300)
        return notify_fail("���������Ϊ���㣬�޷����㡸���λ�Ӱ����������\n");
    if ((int)me->query("neili")<200)
    {
        return notify_fail("����������������û�ܽ������λ�Ӱ��ʹ�꣡\n");
    }
	extra = me->query_skill("yanxing-dao",1) / 15;
	extra += me->query_skill("linji-zhuang",1) /15;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
    msg = HIC "$N���һ����ȫ���Ĵ��ζ���$nֻ����$N����������Ӱ�����쵶��ϯ�������"NOR;
	   COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$n����һ�ܣ���$N������·��$nֻ��סһ����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N�ĵ�������$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N���ε���Ӱ��$n�����������ɻ�Ӱ��$n׽�����壡" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N��Ʈ����������ʱ�Ŀ���$n���������Σ������Ӱ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
    me->add("neili", -200);
    me->start_busy(2);
    return 1;
}

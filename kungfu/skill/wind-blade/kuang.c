//kuang.c -������ʮһʽ��
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int extra;
	object weapon;
    string msg;
	extra=me->query_skill("wind-blade",1);
    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�����ʮһʽ����\n");
    if( (int)me->query_skill("wind-blade",1) < 70)
    return notify_fail("��Ŀǰ������ʹ����������ʮһʽ����\n");
    	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 100 )
    return notify_fail("�������������\n");
    me->add("neili", -60);
    msg = HIC"$N��ȻһЦ�����Ϳ�ݾ��׵ĵ�����Ȼ��ø���������������һ˲֮�䣬"+
    "$N��������ʮһ�����������ŷ磬���ﺬ�ŵ�Ӱ��$nֻ����������ֹͣ�ˣ�"NOR;
        message_vision(msg, me, target);                
	msg = HIY  "$N�����������ߵ���" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N����$n�����������ߵ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N��Ȼ�ִ����������ߵ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

if( (int)me->query_skill("wind-blade",1) > 300)
{	
        msg = HIC  "-----���ߵ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "-----���ߵ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "-----���ߵ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "-----���ߵ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}

	me->start_busy(2);


    return 1;
}


// jianzhang.c  ������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
 
	if( !target ) target = offensive_target(me);
	if( !me->is_fighting() )
		return notify_fail("�������̡�ֻ����ս����ʹ�á�\n");
        if ((int)me->query_skill("kuihua-xinfa", 1) < 80 )
        return notify_fail(RED"������ķ���򲻹���\n"NOR);
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("�������̡���ʼʱ��������һ�ѽ���\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	if((int) me->query_skill("pixie-jian",1) < 100)
		return notify_fail("��ı�а�����������ң��޷�ʹ�������̣�\n");

	msg = RED "$N��ȻһЦ������֮��������Ȼ�ӿ죡" NOR;
if (!me)
return notify_fail("�������̡�ֻ����ս����ʹ�á�\n");
if (!target)
return notify_fail("�������̡�ֻ����ս����ʹ�á�\n");
if (!me->query_temp("weapon"))
return notify_fail("�������̡�ֻ����ս����ʹ�á�\n");
if (random(2)==0) target->start_busy(2);
	message_vision(msg, me);
msg = 	RED"�ȴ�˫Ŀ��"NOR;
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = 	RED"���˫�㣡"NOR;
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = 	RED"�����ģ�"NOR;
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add("neili", -150);
	me->start_busy(2);

	return 1;
}
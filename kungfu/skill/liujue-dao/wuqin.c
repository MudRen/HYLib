// wuqin.c ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
string msg;
if( !target ) target = offensive_target(me);
	if( !me->is_fighting() )
		return notify_fail("���������塹ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 200 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("blade") < 50 ||
	    me->query_skill_mapped("blade") != "liujue-dao")
		return notify_fail("��ġ������������������ң��޷�ʹ�á��������塹��\n");

	if( (int)me->query_skill("liujue-dao", 1) < 150 )
		return notify_fail("��ġ������������������ң��޷�ʹ�á��������塹��\n");

	msg = HIY "$Nʹ�����������塹����ͻ�ر���쳣�鶯Ʈ����\n" NOR;
	message_vision(msg, me);

//	me->clean_up_enemy();
//	ob = me->select_opponent();

       COMBAT_D->do_attack(me, target, weapon, 1);
       COMBAT_D->do_attack(me, target, weapon, 1);
       COMBAT_D->do_attack(me, target, weapon, 1);
       COMBAT_D->do_attack(me, target, weapon, 1);
       COMBAT_D->do_attack(me, target, weapon, 1);

	me->add("neili", -200);
	me->start_busy(random(2)+2);

	return 1;
}

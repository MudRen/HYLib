// yifeng.c  �Ʒ罣 [�Ʒ������Ʒ���]

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
 
    if( !me->is_fighting() )
	    return notify_fail("���Ʒ������Ʒ��ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if((int)me->query_dex() < 30)
		return notify_fail("���������, Ŀǰ������ʹ���������! \n");

//	if((int)me->query_skill("dodge") < 235)
//		return notify_fail("����Ṧ��Ϊ����, ����ʹ���Ʒ������Ʒ��\n");
 
	if( (int)me->query_skill("yifeng-jian", 1) < 150 )
		return notify_fail("����Ʒ罣��������졣\n");

	if((int)me->query_skill("sword") < 235)
		return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ���Ʒ������Ʒ���! \n");

    if( (int)me->query("neili") < 1000 )
		return notify_fail("�������������\n");


    msg = HIM "$Nʹ���Ʒ罣���ľ������Ʒ������Ʒ������ʱ������裡\n" NOR;
    message_vision(msg, me);

//	me->clean_up_enemy();
	ob = me->select_opponent();

	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);

	me->add("neili", -550);
	me->start_busy(random(4));

    return 1;
}
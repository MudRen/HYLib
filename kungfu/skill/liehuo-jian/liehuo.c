// guangming.c ����

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count, i;
	int skill;
 
    if( !me->is_fighting() )
	    return notify_fail("���һ������ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��û��װ��������\n");
        if ((int)me->query_skill("jiuyang-shengong", 1) < 20)
                return notify_fail("��ľ����񹦻��̫ǳ��\n");

	if((int)me->query_skill("liehuo-jian",1) < 100)
		return notify_fail("��Ľ�����Ϊ����, ����ʹ�á��һ��������\n");
 
	if((int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	me->clean_up_enemy();
	ob = me->select_opponent();

	skill = me->query_skill("liehuo-jian", 1);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill/3);
	me->add_temp("apply/strength", skill/3);
	weapon = me->query_temp("weapon");
   message_vision(HIW "$N���һ������" + HIR "���Ҳ���������ʥ��" + HIW"����������������ʱ���ܿ�������$n���Ӳ���һ��\n" NOR, me, ob);
   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
   message_vision(HIC "$N���г���������"HIR"���Ҳ���������ʥ������λ�������ο�"HIC"����\n" NOR, me, ob);
   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
   message_vision(HIC "$N���г���������"HIR"Ϊ�Ƴ���Ψ�����ʡ�ϲ�ֱ���Թ鳾��"HIC"����\n" NOR, me, ob);
   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
   message_vision(HIC "$N���г���������"HIR"�������ˣ��ǻ�ʵ�࣡�������ˣ��ǻ�ʵ��"HIC"����\n" NOR, me, ob);
   COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
	me->add_temp("apply/attack", -skill/3);
	me->add_temp("apply/damage", -skill/3);
	me->add_temp("apply/strength", -skill/3);
	me->add("neili", -250);
	me->start_busy(2);
 	return 1;
}
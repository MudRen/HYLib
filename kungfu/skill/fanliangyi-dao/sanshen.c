// sanshen.c ���������

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
		return notify_fail("����������塹ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 100 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("zixia-shengong",1) < 80 )
		return notify_fail("�����ϼ�񹦹������㣡\n");

	if( (int)me->query_skill("blade") < 50 ||
	    me->query_skill_mapped("blade") != "fanliangyi-dao")
		return notify_fail("��ġ������ǵ������������ң��޷�ʹ�á���������塹��\n");

	msg = RED "$Nʹ����ɽ�ɾ�������������塹����ͻ�ر���쳣�鶯Ʈ����" NOR;
	message_vision(msg, me, target);          

	msg =  YEL  "��Ů�壡 " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =  YEL  "�����壡 " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	msg =  YEL  "�����壡 " NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add("neili", -50);
	me->start_busy(2);
	
	return 1;
}

// wuji.c ��Ԫ�޼�
 
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target;
	int skill,extra;

	me->clean_up_enemy();
	target = me->select_opponent();

	skill = me->query_skill("hunyuan-zhang",1);
	extra = me->query_skill("poyu-quan",1);
	if( !(me->is_fighting() ))
		return notify_fail("����Ԫ�޼���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (objectp(weapon = me->query_temp("weapon")))
		return notify_fail("��ʹ����������\n");

	if( skill < 60)
		return notify_fail("��ġ���Ԫ�ơ��ȼ�����, ����ʹ�á���Ԫ�޼�����\n");

	if( extra < 60)
		return notify_fail("��ġ�����ȭ���ȼ�����, ����ʹ�á���Ԫ�޼�����\n");
	
	if( me->query("neili") < 150 )
		return notify_fail("��������������޷����á���Ԫ�޼�����\n");
 	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",skill);

	msg = YEL "$NǱ�ˡ���Ԫ�ơ���˫��Ю�������ķ���֮����$n��ȥ��"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = CYN "$N��ʹ������ȭ����˫ȭЮ�����ĵĺ�Х֮����$n��ȥ��"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(1);
	me->add_temp("apply/attack",-extra);
	me->add_temp("apply/damage",-skill);
	return 1;
}

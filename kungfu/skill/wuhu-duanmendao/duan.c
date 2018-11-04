#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
	int i,j;
 if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("�廢���ŵ����ϡ��־�ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 250 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("blade") < 60 ||
	    me->query_skill_mapped("blade") != "wuhu-duanmendao")
		return notify_fail("��ġ��廢���ŵ����������ң��޷�ʹ�á��ϡ��־���\n");

	msg = HIY "$N��Ȼ���أ�ʹ�����õ����־�����ʱһƬ����ֱ��ǰ��ȥ��" NOR;
	message_vision(msg,me,target);
	j = random(7)+1;
	for(i=1;i<=j;i++)
	{
	msg =  BLU "��"+chinese_number(i)+"��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}

	me->add("neili", -200);
	me->start_busy(3);
	return 1;
}

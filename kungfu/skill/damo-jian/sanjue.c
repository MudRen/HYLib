// sanjue.c  ��Ħ�� [��Ħ������]
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
        int extra;
        extra = me->query_skill("tianyu-qijian",1);

	 if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����Ħ��������ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if((int)me->query_skill("hunyuan-yiqi",1) < 60)
		return notify_fail("��Ļ�Ԫһ��������Ϊ����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("sword") < 135)
		return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ�ô�Ħ������! \n");
	weapon = me->query_temp("weapon");
	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
	
	extra = me->query_skill("damo-jian",1) / 20;
	extra += me->query_skill("damo-jian",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIG "$Nʹ����Ħ���ľ�������Ħ��������������Ȼ�ӿ죡\n" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIC  "$N���μӿ죬��������һ���� \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "$N������ת������$n����һ���� \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

	me->add("neili", -150);
	me->start_busy(2);
	return 1;
}

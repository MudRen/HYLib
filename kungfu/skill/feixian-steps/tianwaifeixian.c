// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	if (!weapon) return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");
	if( (string)weapon->query("skill_type") != "sword" )
	return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");
	if ( (string) me->query_skill_mapped("sword") != "feixian-sword")
	return notify_fail("�������ֻ�ܺͷ��ɽ�����ͣ�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-200);

	extra = me->query_skill("feixian-sword",1) / 20;
	extra += me->query_skill("feixian-steps",1) /20;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = RED  "$N��̤�۷��ɲ����ݣ�ͬʱʹ���۷��ɽ����Уݵľ��裭��������ɣ����е�"+ weapon->name() +"����һ�����磬�����Ļ���$n��" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg =  HIW "����һ������ʧ��������\n" NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
	msg = RED "$N����ͻת�������طɣ�\n" NOR;

	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	}
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(2);
	return 1;
}


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
		return notify_fail("�۵����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	        extra = me->query_skill("ittouryu",1) ;
        if ( extra < 100) return notify_fail("��ģ�һ���������ݻ��������죡\n");
		if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 600 )
		return notify_fail("�������������\n");
	
	extra = (int)me->query_skill("ittouryu",1) / 10;
	if (extra >= 80) extra=80;
	me->add_temp("apply/attack", extra*2);	
	me->add_temp("apply/damage", extra*2);
	msg = HIR  "$Nʹ����Բ����ն���е����Ͼ�����������"+ weapon->name() +"��������Ļ��ߣ���ն$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	for(i=0;i<extra/5;i++)
	{
	msg = CYN "$N�������񣬵����ݺᣡ\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add("neili",-30);
	}
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -extra*2);
	me->start_busy(3);
	return 1;
}

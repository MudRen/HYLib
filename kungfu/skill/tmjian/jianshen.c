
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i,lv;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۽����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "sword" )
        return notify_fail("������û��װ������������\n");
        if( (int)me->query("neili")<500)
        return notify_fail("����������̫��������ʹ�ã�\n"NOR);
        
	weapon = me->query_temp("weapon");
	extra = me->query_skill("tmjian",1) / 4;
	
	if (extra> 200) extra=200;
	me->add_temp("apply/attack", extra*2);	
	me->add_temp("apply/damage", extra*2);
	msg = HIR  "$Nʹ����Բ����ն���е����Ͼ�����������"+ weapon->name() +"��������Ļ��ߣ���ն$n��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	lv=extra/8;
	if (lv > 8) lv=8;
	me->set_temp("action_flag", 1);
	for(i=0;i<lv;i++)
	{
	msg = CYN "��"+(i+1)+"����$N�������񣬽����ݺᣡ\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add("neili",-30);
	}
	me->delete_temp("action_flag");
	me->add_temp("apply/attack", -extra*2);
	me->add_temp("apply/damage", -extra*2);
	
	me->start_busy(3);
	return 1;
}

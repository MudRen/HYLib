// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����ħʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	extra = me->query_skill("demon-strike",1) ;
	if(extra < 80 ) return notify_fail("��ģ������ħ�������ƣݲ���������\n");
	msg = HIR "\n$N˫�۱�����һ�У���ħʽ�ݣ�˫��£��$n��" NOR;
	if(random((int)me->query("combat_exp")) >= (int)target->query("combat_exp"))
	{
	message_vision(msg+"\n",me,target);
	message_vision( HIC "$N����������ȫ��������Ӱ��ס�� һ��������$N������ӿ������\n" NOR,target);
	target->receive_wound("jing",extra);
	me->receive_heal("jing",extra);
	}	
	else{
        weapon = me->query_temp("weapon");
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
	me->start_busy(2);
	return 1;
}

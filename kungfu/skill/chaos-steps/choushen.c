
#include <ansi.h>
#include <combat.h>
#include <command.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	string msg;
	int lvl;
	if( !target ) target = me;
	if(!me->is_fighting() )
		return notify_fail("�۳�����ֻ����ս����ʹ�á�\n");
	if( target != me)
		return notify_fail("�۳�����ֻ�ܶ��Լ�ʹ�á�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-140);
	msg = YEL "$N���һ�У�����������������ͼ�ܿ����˵Ĺ��ƣ�\n" NOR;
	lvl = (int)me->query_skill("dodge",1);
	me->add_temp("apply/attack",lvl);
        message_vision(msg, me);
	msg = HIR  "��һ����" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "��һ����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "�����һ����" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add_temp("apply/attack",-lvl);
	me->start_busy(2);
	return 1;
}

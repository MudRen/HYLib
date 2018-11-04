// powerup.c

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
	int skill;

	if( target != me ) return notify_fail("你只能用云龙神功提升自己的战斗力。\n");

	if( (int)me->query("neili") < 100 ) return notify_fail("你的内力不够。\n");
        if( (int)me->query_temp("powerup")) return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	me->add("force", -100);
        me->receive_damage("qi", 0);

	message_combatd(
        HIR "$N长吸一口气，运起云龙神功已将全身潜力尽数提起！\n" NOR, me);

	me->add_temp("apply/attack", skill/3);
	me->add_temp("apply/damage", skill/3);
	me->add_temp("apply/defense", skill/3);
	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill);

	if( me->is_fighting() ) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
   int skill;
   skill = me->query_skill("force");
   if ( (int)me->query_temp("powerup") ) {
   me->add_temp("apply/attack", -skill/3);
   me->add_temp("apply/damage", -skill/3);
   me->add_temp("apply/defense", -skill/3);
	me->delete_temp("powerup");
    tell_object(me, "你的云龙神功运行完毕，将内力收回丹田。\n");}
}

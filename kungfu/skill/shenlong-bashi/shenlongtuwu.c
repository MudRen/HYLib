// tuwu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	int damage;
	string msg;
	object weapon;
	 if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("神龙吐珠只能在战斗中使用。\n");

        if( objectp(me->query_temp("weapon")) )
		return notify_fail("你必须空手才能使用神龙吐珠！\n");

	if( (int)me->query_skill("zhaosheshu", 1) < 150 )
		return notify_fail("你的招蛇术不够娴熟，不会使用神龙吐珠。\n");

	if( (int)me->query_skill("shenlong-bashi", 1) < 150 )
		return notify_fail("你的神龙八式不够娴熟，不会使用神龙吐珠。\n");

        if ((int)me->query_skill("shenlong-xinfa", 1) < 60 )
        return notify_fail(RED"你神龙心法火候不够。\n"NOR);

	if( (int)me->query("neili") < 300 )
		return notify_fail("你内力不够了。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");

	skill = me->query_skill("shenlong-bashi", 1);

	me->add("neili", -200);
	target->receive_damage("qi", (int)skill/ 3);
	message_combatd(HIW "只听一阵狂风扫叶般的声响中，$N吹一下口哨，附近全是蛇群
	发出的怪叫声。\n"NOR,me,target);
    if (random(me->query_skill("force")) > target->query_skill("force")/3&& 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
	message_combatd(
        HIW "迷雾中一条巨蟒像$n扑了上去，神龙吐珠”！
$n除了眼前一重重的雾气外，$n啥也看不见了！\n" NOR, me, target);
	target->set_temp("block_msg/all",1);
	damage = (int)me->query_skill("zhaosheshu", 1);
	damage = damage + random(damage);
	target->receive_damage("qi", damage/2);
	target->receive_damage("qi", damage/2);
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);
	call_out("tuwu_end", (int) skill/30, me, target);
	target->start_busy(me->query_skill("shenlong-bashi",1)/40 + 2 );
        me->start_busy(2);
        //	return 1;
    } else
    {
	message_combatd(
        HIW "迷雾中一条巨蟒像$n扑了上去，神龙吐珠”！
$n除了眼前一重重的雾气外，$n啥也看不见了！\n" NOR, me, target);
        msg = HIY"$p情急智生，用气功迫开了$P的雾气。\n"NOR;
        me->start_busy(2);
        message_combatd(msg, me, target);
    }
if (random(5)==0 && (int)me->query_skill("shenlong-bashi",1) > 300
&& (int)me->query_skill("zhaosheshu",1) > 200
&& (int)me->query_skill("yangsheshu",1) > 200)
{
	message_combatd(
        HIW "$N大喊 我弟子杀敌护教，洪教主亲加提拔，升任圣职。！
$n被一团蛇雾笼罩，$n心口一阵巨痛！\n" NOR, me, target);
target->apply_condition("shenlong_poison",50);
}
//    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}
void tuwu_end(object me, object target)
{
if (target)
{
	target->enable_player();
	message_combatd("$N抹了抹满脸的"HIR"鲜血"NOR"，终于睁开了眼。\n", target);
	target->set_temp("block_msg/all", 0);
}
	write(HIR"你终于抹掉了满脸的鲜血，看到了周围的情景。\n"NOR);
	return;
}

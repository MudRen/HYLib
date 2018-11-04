// tuwu.c

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
	int skill;
	string msg;
	object weapon;
	 if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("id") != "jinshe zhui")
           return notify_fail("��û�ý���׶������ʹ�þ��У�\n");

	if( (int)me->query_skill("jinshe-zhui", 1) < 100 )
		return notify_fail("��Ľ���׶��������죬����ʹ�ý�������\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������ˡ�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	skill = me->query_skill("jinshe-zhui", 1);

	me->add("neili", -200);
	target->receive_damage("qi", (int)skill/ 3+200);

    if (random(me->query_skill("force")) > target->query_skill("force")/3 && 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
	message_combatd(
        HIY "ֻ��һ����ɨҶ��������У�$N���е�"YEL"����׶"HIY"������Ŀ�Ĺ�â����ҫ��
$n��ð�𻨣�������������������ǰһ���ص������⣬$nɶҲ�������ˣ�\n" NOR, me, target);
	target->set_temp("block_msg/all",1);
	call_out("tuwu_end", (int) skill/30, me, target);
	target->start_busy(me->query_skill("jinshe-zhui",1)/40+2);
        me->start_busy(2);
    } else
    {
	message_combatd(
        HIY "ֻ��һ����ɨҶ��������У�$N���е�"YEL"����׶"HIY"������Ŀ�Ĺ�â����ҫ��
$n��ð�𻨣�������������������ǰһ���ص������⣬$nɶҲ�������ˣ�\n" NOR, me, target);
        msg= HIY"$p�鼱�������ý����ȿ���$P��������\n"NOR;
        me->start_busy(2);
        message_combatd(msg, me, target);
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
	message_combatd("$NĨ��Ĩ������"HIR"��Ѫ"NOR"�������������ۡ�\n", target);
	target->set_temp("block_msg/all", 0);
}
	write(HIR"������Ĩ������������Ѫ����������Χ���龰��\n"NOR);
	return;
}

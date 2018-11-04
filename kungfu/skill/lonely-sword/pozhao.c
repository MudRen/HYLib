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

//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");
     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("���¾Ž����������ϼ�񹦡�\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query_skill("lonely-sword", 1) < 200 )
		return notify_fail("��Ķ��¾Ž�������죬����ʹ���������С�\n");

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������ˡ�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	skill = me->query_skill("lonely-sword", 1);

	me->add("neili", -200);
	target->receive_damage("qi", (int)skill/ 3);
	message_combatd(HIC "$N���ּ�����$n����,һ��ֻ�¾�ȫ�Ǵ���$n�书������
$n����һ��.....���ɵķ����Ĺֽ�����\n"NOR,me,target);
    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
	message_combatd(
        HIR "$N���еĽ������������Ľ���,һ��һ���Ľ�����$n��ȥ��\n" NOR, me, target);
	target->start_busy(1);
    if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
	target->set_temp("block_msg/all",1);
	message_combatd(
        HIR "$n����һ�ڣ�$nɶҲ�������ˣ�\n" NOR, me, target);
    }
	damage = (int)me->query_skill("lonely-sword", 1);
	damage = damage + random(damage);
	target->receive_damage("qi", damage/2);
	call_out("tuwu_end", (int) skill/30, me, target);
	target->start_busy(me->query_skill("lonely-sword",1)/40 + 2);
        me->start_busy(1);
        //	return 1;
    } else
    {
	message_combatd(
        HIR "$N���еĽ������������Ľ���,һ��һ���Ľ�����$n��ȥ��\n" NOR, me, target);
        me->start_busy(3);
        msg = HIY"$p�鼱���������һ��...�ӳ��˽����ķ�Χ��\n"NOR;
        message_combatd(msg, me, target);
    }
    if(!target->is_fighting(me)) target->fight_ob(me);
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

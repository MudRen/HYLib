// cimu.c  ��а��������Ŀ��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("����Ŀ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
      if ((int)me->query_skill("kuihua-xinfa", 1) < 80 )
      return notify_fail(RED"������ķ���򲻹���\n"NOR);

     if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("���������һ�ѽ���\n");

    if ((int)me->query_skill("pixie-jian", 1) < 80 )
        return notify_fail(WHT"���а����������죬ʹ��������Ŀ����\n"NOR);
    if ((int)me->query("max_neili")<400)
        return notify_fail(RED"��������Ϊ���㣬�޷�����������\n"NOR);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

    if ((int)me->query("neili")<200)
    {
        return notify_fail(HIC"����������������û�ܽ�����Ŀ��ʹ�꣡\n"NOR);
    }
        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
       msg = HIC "$N������ָ��£���ֱ۱�����Ѹ���쳣�ִ�$n˫Ŀ��\n"NOR;
    else
       msg = HIC "$N���г���һ�񣬽���һ�㱩�����ִ�$n����˫Ŀ��\n"NOR;
    if (random(me->query_skill("force")) > target->query_skill("force")/3 && 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
        me->start_busy(1);
        target->start_busy(random(4));
        damage = (int)me->query_skill("pixie-jian", 1) + (int)me->query_skill("sword", 1)/2;
        damage = damage/2 + random(damage);
        target->receive_damage("qi", damage);
        target->receive_wound("qi", damage/2);
        msg += HIC"$nֻ��������һ�㣬˫Ŀһ���ʹ����ǰһ�ڣ���ʲôҲ������
�ˣ���ʱ����ʹ��������\n"NOR;
        message_combatd(msg, me, target);
        me->add("neili", -damage/5);
	me->set_temp("pixie/cimu", 1);
//	target->set_temp("block_msg/all",1);
	call_out("cimu_end", (int) 2+random(6), me, target);
    } else
    {
        me->start_busy(2);
        msg += HIY"$p�鼱������̧��Ҳ$P���۴�ȥ���ȵ�$P�ؽ�Ծ����\n"NOR;
        message_combatd(msg, me, target);
    }
    if(!target->is_fighting(me)) target->fight_ob(me);
//    if(userp(target)) target->fight_ob(me);
//    else if( !target->is_killing(me) ) target->kill_ob(me);
    return 1;
}

void cimu_end(object me, object target)
{
//	target->set_temp("block_msg/all",0);
//	target->enable_commands();
    if (!target ) target = offensive_target(me);
if (target )
{
	message_combatd("$NĨ��Ĩ����"HIR"��Ѫ"NOR"�������ܿ����ˡ�\n", target);
	target->set_temp("block_msg/all", 0);
}
	me->delete_temp("pixie/tuwu");
	return;
}

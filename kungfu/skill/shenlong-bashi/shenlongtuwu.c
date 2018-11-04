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
		return notify_fail("��������ֻ����ս����ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ���������飡\n");

	if( (int)me->query_skill("zhaosheshu", 1) < 150 )
		return notify_fail("���������������죬����ʹ���������顣\n");

	if( (int)me->query_skill("shenlong-bashi", 1) < 150 )
		return notify_fail("���������ʽ������죬����ʹ���������顣\n");

        if ((int)me->query_skill("shenlong-xinfa", 1) < 60 )
        return notify_fail(RED"�������ķ���򲻹���\n"NOR);

	if( (int)me->query("neili") < 300 )
		return notify_fail("�����������ˡ�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

	skill = me->query_skill("shenlong-bashi", 1);

	me->add("neili", -200);
	target->receive_damage("qi", (int)skill/ 3);
	message_combatd(HIW "ֻ��һ����ɨҶ��������У�$N��һ�¿��ڣ�����ȫ����Ⱥ
	�����Ĺֽ�����\n"NOR,me,target);
    if (random(me->query_skill("force")) > target->query_skill("force")/3&& 
       random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
    {
	message_combatd(
        HIW "������һ��������$n������ȥ���������顱��
$n������ǰһ���ص������⣬$nɶҲ�������ˣ�\n" NOR, me, target);
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
        HIW "������һ��������$n������ȥ���������顱��
$n������ǰһ���ص������⣬$nɶҲ�������ˣ�\n" NOR, me, target);
        msg = HIY"$p�鼱�������������ȿ���$P��������\n"NOR;
        me->start_busy(2);
        message_combatd(msg, me, target);
    }
if (random(5)==0 && (int)me->query_skill("shenlong-bashi",1) > 300
&& (int)me->query_skill("zhaosheshu",1) > 200
&& (int)me->query_skill("yangsheshu",1) > 200)
{
	message_combatd(
        HIW "$N�� �ҵ���ɱ�л��̣�������׼���Σ�����ʥְ����
$n��һ���������֣�$n�Ŀ�һ���ʹ��\n" NOR, me, target);
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
	message_combatd("$NĨ��Ĩ������"HIR"��Ѫ"NOR"�������������ۡ�\n", target);
	target->set_temp("block_msg/all", 0);
}
	write(HIR"������Ĩ������������Ѫ����������Χ���龰��\n"NOR);
	return;
}

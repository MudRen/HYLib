// meng.c ��Ҷ����衸�򶾡�

#include <ansi.h>

inherit F_SSERVER;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"tmzhuihun_poison",
"tmpili_poison",
"zm_poison",
"zmqidu_poison",
});

int perform(object me, object target)
{
	string msg;
int level;
object weapon;
weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
            return notify_fail("��"+HIR"��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

//	if( !userp(target) || wizardp(target) )
//		return notify_fail("ʩ��ֻ�ܶ����ʹ�á�\n");


	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "throwing")
		return notify_fail("�������ֲ���ʹ�á��򶾡���\n");		


	if( (int)me->query_skill("qiulinshiye", 1) < 60 )
                return notify_fail("�������ʰҶ�����ߡ�\n");

	if( (int)me->query_skill("biyun-xinfa", 1) < 60 )
                return notify_fail("��ı����ķ������ߡ�\n");

	if( (int)me->query("neili", 1) < 500 )
		return notify_fail("����������̫��������ʹ�á��򶾡���\n");

        level=(int)me->query_skill("biye-wu", 1);
if (!level) level=10;
	if( (int)me->query("neili") < 500 )
		return notify_fail("�����ڵ�����������\n");

	msg = HIW "$NͻȻ���ƣ�Ȼ��Ѹ�ٷ���! ���о�Ȼ�ж�ɰ�����Ʒ羡Ȼ��������ɫ�ģ���\n";

	me->start_busy(1);
	if( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  ) {
		msg += HIR"$nӲ��ͷƤ������Ӳ�ӣ���������о޶���\n" NOR;
            me->add("neili",-300);
		me->start_busy(2);
            target->receive_damage("qi",20);
            target->receive_wound("qi",15 + random(10));
            target->apply_condition(du[random(sizeof(du))], 25);
            target->apply_condition(du[random(sizeof(du))], 25);
            target->apply_condition(du[random(sizeof(du))], 25);
            target->apply_condition(du[random(sizeof(du))], 25);
            target->apply_condition(du[random(sizeof(du))], 25);
            target->start_busy(3);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "$p������������һ�𣬽�$N�����Ķ���ж��������!\n" NOR;
		me->start_busy(3);
            me->add("neili",-300);
		message_combatd(msg, me, target);
	}
	return 1;
}

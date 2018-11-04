
// sandu.c �嶾��ʩ����

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
"xscold_poison",
});

int perform(object me, object target)
{
	string msg;
int level;
	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
            return notify_fail("��"+HIR"ʩ��"NOR+"��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

//	if( !userp(target) || wizardp(target) )
//		return notify_fail("ʩ��ֻ�ܶ����ʹ�á�\n");


         if( (int)me->query_skill("wudu-shengong",1) < 100 )
                return notify_fail("����嶾����Ϊ��������\n");

         if( (int)me->query_skill("poison",1) < 100 )
                return notify_fail("��Ļ���������Ϊ��������\n");

	if( (int)me->query_skill("shedu-qiqiao", 1) < 100 )
		return notify_fail("����߶����ɻ��������, ���ܴ��� !\n");
        level=(int)me->query_skill("duji", 1);
if (!level) level=10;
	if( (int)me->query("neili") < 500 )
		return notify_fail("�����ڵ�����������\n");

	msg = HIM "ֻ��$N�ӻ��У��ó�һ�����֪����ʲô������ҩ�ۣ�һ������$n������!\n";

	me->start_busy(1);
	if( random( (int)me->query("combat_exp",1))+ level*100
          > target->query("combat_exp")/3  ) {
		msg += HIR"$nû�з�����ȫ�����±�����һ�����ţ�\n" NOR;
            me->add("neili",-300);
		me->start_busy(2);
            //if (!target->is_busy())
            target->start_busy(3);
            target->receive_damage("qi",20);
            target->receive_wound("qi",15 + random(10));
            target->apply_condition(du[random(sizeof(du))], 35);
            target->apply_condition(du[random(sizeof(du))], 35);
            target->apply_condition(du[random(sizeof(du))], 35);
if (me->query_skill("duji",1) > 150)
{
	       target->apply_condition("snake_poison",
		        (int)target->query_condition("snake_poison") + 30 );
	       target->apply_condition("wugong_poison",
		        (int)target->query_condition("wugong_poison") + 30 );
	       target->apply_condition("zhizhu_poison",
		        (int)target->query_condition("zhizhu_poison") + 30 );
	       target->apply_condition("xiezi_poison",
		        (int)target->query_condition("xiezi_poison") + 30 );
	       target->apply_condition("chanchu_poison",
		        (int)target->query_condition("chanchu_poison") + 30 );
}
if (me->query_skill("duji",1) > 200)
{
            target->apply_condition(du[random(sizeof(du))], 35);
            target->apply_condition(du[random(sizeof(du))], 35);
            target->apply_condition(du[random(sizeof(du))], 35);
}
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "$p������������һ�𣬽�$N�����Ķ���ж��������!\n" NOR;
		me->start_busy(1);
            me->add("neili",-300);
		message_combatd(msg, me, target);
	}
//	if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

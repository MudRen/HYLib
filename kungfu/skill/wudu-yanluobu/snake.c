// snake.c  ��������

#include <ansi.h>
#include <combat.h>
// inherit F_CLEAN_UP;
inherit F_SSERVER;
void remove_effect(object me, int amount);

int perform(object me, object target)
{
       object ob;
	int skill,tg_skill,time;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query_skill("wudu-yanluobu", 1) < 50 )
		return notify_fail("����嶾���ܲ���򲻹�������ʹ��������������\n");

	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á�����������\n");

        if( (int)me->query_skill("wudu-shengong",1) < 50 )
                return notify_fail("����嶾����Ϊ��������\n");

	if( target->is_busy() )
		return notify_fail(target->name() + "Ŀǰ����æ���ң��㻹��תʲô���Ͽ�����ɣ�\n");
			
	msg = HIC "$N���к���һ�䣬ʹ�������������ľ�������Խ��Խ�졣\n\n\nֻ��$N�ɿ���Ƴ����ߣ�հ֮��ǰ����֮�ں�һʱ�䵽������$N����Ӱ��\n"NOR;
	message_vision(msg, me, target);
       time = (int)me->query_skill("wudu-yanluobu",1)/50+2;
       skill = (int)me->query_skill("wudu-yanluobu",1)
             + (int)me->query_skill("dodge",1);
       tg_skill = (int)target->query_skill("dodge",1);
	me->add("neili", -100);
       if ((int)random(me->query("combat_exp"))+skill*600 > (int)random(target->query("combat_exp")))
       {
       target->start_busy(time);
	msg = HIR"$n���ɵ�һ�������޴룬��$N�������У�\n"NOR;
	message_vision(msg, me, target);
       return 1;
        }
       else
        {
       me->start_busy(2);
	msg = HIR"����$n�Ծ��ƶ��������Ż���˿������$N��Ӱ��,$N�Լ����۵���ͷ�󺹣�\n"NOR;
	message_vision(msg, me, target);
       }
	return 1;
}

// Code of JHSH
//  /kungfu/skill/kongming-quan/kongming.c ��̨����
// sdong 07/98
#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage,skill,wap,wdp;
	string *limb, type, result, str,msg;

	type = "����";

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��̨����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( me->query_temp("sanhua") )
		return notify_fail("������ʹ�������۶��ˣ�\n");

	if( me->query_temp("kongming") )
		return notify_fail("������ʹ����̨�����ˣ�\n");
        if(me->is_busy())
        return notify_fail("��������æ��\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("���ֲ���ʩչ��̨������\n");

	if( me->query_skill_mapped("unarmed") != "kongming-quan" )
		return notify_fail("�����õĲ��ǿ���ȭ������ʩչ��̨������\n");

//	if( me->query_skill_prepared("unarmed") != "kongming-quan" )
//                return notify_fail("�������Ĳ��ǿ���ȭ������ʩչ��̨������\n");

/*
	if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("�����õĲ������칦��ʩչ������̨������\n");
*/

        if( me->query_skill("force") < 100 )
		return notify_fail("������칦���δ�����޷�ʩչ��̨������\n");

        if( me->query_skill("unarmed") < 100 )
		return notify_fail("��̨������Ҫ��տ�Ŀ���ȭ������Чʩչ��\n");

	if( me->query("neili") <= 300 )
		return notify_fail("�����������ʹ����̨������\n");

	if( me->query("jing") <= 200 )
		return notify_fail("��ľ�����ʹ����̨������\n");


	msg = HIY"$N����һ������Ŀ����Ȼ�峺�ޱȣ�����˫ȭʮ�ֽ���������$n���˹�ȥ��\n\n"NOR;
	message_vision(msg, me, target);

	me->set_temp("kongming", 1);

	skill =   (int)me->query_skill("kongming-quan");
if (skill>=400) skill=400;
	me->add_temp("apply/attack", skill/2);
	me->add_temp("apply/damage",  skill/6);
	me->add_temp("apply/dodge",  skill/2);
	me->add_temp("apply/parry",  skill/2);
	me->add_temp("apply/defense",  skill/2);
if (random(2)==0) target->start_busy(3);
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

	me->add("neili", -skill/2);

	me->add("jing", -100);
	me->start_busy(random(2));

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/2 :), skill/10);

	return 1;
}

void remove_effect(object me, int amount)
{
	me->add_temp("apply/attack", -amount);
	me->add_temp("apply/damage", -amount/3);
	me->add_temp("apply/parry", -amount);
	me->add_temp("apply/dodge", -amount);
	me->add_temp("apply/defense", -amount);
	me->delete_temp("kongming");
	message_vision(HIY "\n$N����һ�������������ջص��\n\n" NOR, me);

	return;
}

// Code of JHSH
//  /kungfu/skill/kongming-quan/quan.c ��ȭ����
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
		return notify_fail("��ȭ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("���ֲ���ʩչ��ȭ���裡\n");

	if( me->query_skill_mapped("unarmed") != "kongming-quan" )
		return notify_fail("�����õĲ��ǿ���ȭ������ʩչ��ȭ���裡\n");
        if(me->is_busy())
        return notify_fail("��������æ��\n");
//	if( me->query_skill_prepared("unarmed") != "kongming-quan" )
//                return notify_fail("�������Ĳ��ǿ���ȭ������ʩչ��ȭ���裡\n");

/*
	if( me->query_skill_mapped("force") != "xiantian-gong" )
                return notify_fail("�����õĲ������칦��ʩչ������ȭ���裡\n");
*/

        if( me->query_skill("force") < 120 )
		return notify_fail("������칦���δ�����޷�ʩչ��ȭ���裡\n");

        if( me->query_skill("unarmed") < 120 )
		return notify_fail("��ȭ������Ҫ��տ�Ŀ���ȭ������Чʩչ��\n");

	if( me->query("max_neili") <= 1000 )
                return notify_fail("��������ȼ�����ʹ����ȭ���裡\n");

        if( me->query("neili") <= 1000 ) 
                return notify_fail("��������������޷�����ʩչ��ȭ���裡\n");

	msg = HIY"$N�ſ�һ�����ȣ�˫Ŀ�������䣬��������Ʈ��������˫ȭ�û�������ȭӰ������$n���ֹ�ȥ��\n\n"NOR;
	message_vision(msg, me, target);

skill =   (int)me->query_skill("kongming-quan");
if (skill>=400) skill=400;
	me->add_temp("apply/damage",  skill/3);
        me->add_temp("apply/attack", skill/3);
if (random(5)==0) target->start_busy(3);
	message("vission",HIR  "��һȭ��\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "��һȭ��\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "��һȭ��\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "��һȭ��\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "ǰһȭ��\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "��һȭ��\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	message("vission",HIR  "�����һȭ��\n" NOR,environment(me));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->start_busy(3);

        me->add_temp("apply/damage",-skill/3);
        me->add_temp("apply/attack", -skill/3);

	me->add("neili", -skill);

	return 1;
}

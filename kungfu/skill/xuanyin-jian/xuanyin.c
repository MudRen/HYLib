#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int lvl;
        lvl = me->query_skill("xuanyin-jian", 1);
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target) )
                return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ����������\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
        if( (int)me->query_skill("xuanyin-jian", 1) < 120 )
                return notify_fail("�����������������죬�޷�ʩչ����������\n");
        if ((int)me->query_skill("jiuyin-zhengong", 1) < 100)
                return notify_fail("��ľ����湦��򲻹����޷�ʩչ����������\n");
        if ((int)me->query_skill("jiuyin-shenfa", 1) < 120)
                return notify_fail("��ľ�������򲻹����޷�ʩչ����������\n");
        if ( (int)me->query("max_neili") < 2000)
                return notify_fail("��������������޷�ʩչ����������\n");
        if ( (int)me->query("neili") < 800)
                return notify_fail("��������������޷�ʩչ����������\n");
        message_vision(HIB"$Nʹ������������������Ѹ���ޱȵĹ���$n��\n"NOR,me, target);

        me->add("neili", -(300 +random(300)) );
        me->start_perform(2,"����������");

        message_vision(HIB"$N����������һ����һ��������\n"NOR,me);
	if (random(lvl) > target->query_skill("parry", 1) / 3) {
		message_vision(HIB"$N�������ˣ������������ѣ�����˵�����ˡ�\n"NOR,target);
	        target->start_busy(lvl / 50);
	        me->start_perform(7, "����������");
		me->add("neili", -300);
	}
        me->add_temp("apply/attack",lvl/2);
        me->add_temp("apply/dexerity",lvl/3);
        me->add_temp("apply/damage",lvl/2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 2);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
	if (userp(target))
        me->start_busy(3);
        else me->start_busy(random(3) + 2);
        me->add_temp("apply/attack", -lvl/2);
        me->add_temp("apply/dexerity",-lvl/3);
        me->add_temp("apply/damage", -lvl/2);
        return 1;
}

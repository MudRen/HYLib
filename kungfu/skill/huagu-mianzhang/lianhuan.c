//lianhuan.c ���� perform

#include <ansi.h>

inherit F_DBASE;
inherit F_SSERVER;

int perform(object me, object target)
{
        mapping fam;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//        if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
//                return notify_fail("��������̵��ӣ������˱��������ȷ���\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ����ͷת�򣬳˻������ɢ�\n");

	if( (int)me->query_skill("shenlong-xinfa", 1) < 150 )
		return notify_fail("��������ķ�������졣\n");

	if( (int)me->query_skill("huagu-mianzhang", 1) < 140 )
		return notify_fail("��Ļ������Ʋ�����졣\n");

        if( me->query("neili") <= 300 )
                return notify_fail("�����������ʹ����������\n");

        if( (int)me->query("jing") < 150 )
                return notify_fail("��ľ����޷����С�\n");

        message_vision(HIR"��һ�ƣ�\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision(HIM"��һ�ƣ�\n" NOR,me,target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        msg = HIY "\n ͻȻ��$N�����ڿն��������$n�������߼��ȣ�\n" NOR;


        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )
         {
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") )
{
        target->start_busy( (int)me->query_skill("huagu-mianzhang", 1) / 20 );
}
                damage = (int)me->query_skill("huagu-mianzhang", 1);
                damage = damage/2 + random(damage);

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
        target->apply_condition("cold_poison",10);
		msg += HIB "��Ȼһ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵�����$p����\n" NOR;
        target->apply_condition("snake_poison",10);
                me->add("neili", -damage/10);

                if( damage < 40 ) msg += HIY"���$n��$N���������ߵ���ͷת�򣡢�\n" NOR;
                else msg += HIR"���$n��$N������������Ҫ�������ۣ�����һ����Ѫ��ӿ������\n"NOR;
        }

         else {
                msg += "����$p������$P����ͼ������ö��˿�ȥ��\n" NOR;
                me->start_busy(1 + random(3));
        }
        message_vision(msg, me, target);

        return 1;
}


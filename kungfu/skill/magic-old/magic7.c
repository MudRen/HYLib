// mie.c  ������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��ʥ�ס�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query_skill("magic-old", 1) < 50)
                return notify_fail(WHT"��ĹŴ�ħ��������죬��ʹ������ʥ�ס���\n"NOR);
        if ((int)me->query("neili")<50)
        {
               return notify_fail(HIC"����������(����)������û�ܽ���ʥ�ס�ʹ�꣡\n"NOR);
        }
        msg = YEL "$N"YEL"����������������.����п�ʼ�ۼ��޴��ޱȵ�����.\n"NOR;
       msg += HIC"$N"HIM"� վ�ڼ�̳�ϣ�����ʥ����������  ���װ�...\n"NOR;
        msg += HIC"$N"HIC"���һ��  �����ס�!!  ,���ϳ���һ���޴���׵羶ֱ��$n��ȥ����������.��\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/3|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
//                target->start_busy(2);
                damage = (int)me->query_skill("magic-old", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", target->query("eff_qi")/3);
                target->receive_wound("qi", target->query("eff_qi")/3);
        msg += HIC"$n"HIC"����û����ܣ����������,�˶���\n"NOR;
        msg += HIC"������$n"HIC"�����ϣ�$n"HIC"����Χȫ��ը����!!\n"NOR;
                me->add("neili", -10);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
                me->start_busy(1);
        msg += HIY"����$p"HIY"����һЦ��һ�������Ծ.\n"NOR;
        msg += HIY"������$p"HIY"���ը�䣬�������ˡ�\n"NOR;
                me->add("neili", -50);
		message_combatd(msg, me, target);
        }
	if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}

// suo.c ������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;

        if (!objectp(weapon = me->query_temp("weapon"))
            || (string)weapon->query("id") != "jinshe jian")
           return notify_fail("��û�ý��߽�������ʹ�þ��У�\n");

        if( me->query("dex") < 20 || me->query("str") < 20 )
            return notify_fail("�����������������, ����ʹ�á�����������\n");

	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

       skill = me->query_skill("jinshe-jian",1);
        if( !target ) target = offensive_target(me);

        if( !(me->is_fighting() ))
            return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
            return notify_fail("�Է�û��ʹ�ñ��������ò��ˡ�����������\n");

        if( skill < 150)
            return notify_fail("��Ľ��߽����ȼ�����, ����ʹ�á�����������\n");

        if( me->query("neili") < 300 )
            return notify_fail("��������������޷����á�����������\n");

        msg = HIC "$N����"YEL"���߽�"HIC"����һ����⣬б��һ����������������
"YEL"���߽�"HIC"���⵹�����ù���$n��"+weapon2->name()+"�ϡ�\n";
        message_combatd(msg, me, target);

        damage = 500 + random(skill / 2);
        ap = me->query_skill("sword")/3 + skill;
        dp = target->query_skill("dodge")/2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > random(dp) )
        {
   target->receive_damage("qi", damage);
        }
     if (random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
        {
            if(userp(me))
                 me->add("neili",-50);
            msg = "$n��ʱ������ǰ���һ��������һ������";
            msg += weapon2->name();
            msg += "���ַɳ���\n" NOR;
            me->start_busy(2);
            target->receive_damage("qi", damage);
            weapon2->move(environment(me));
        }
        else
        {
            if(userp(me))
                 me->add("neili",-30);
            msg = "$n����������������" + weapon2->name()+
"бб˳��һ��һ����˻�����\n"NOR;
            me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

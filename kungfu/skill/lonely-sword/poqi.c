// poqi.c ����ʽ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, force;

//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");
     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("���¾Ž����������ϼ�񹦡�\n");

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("lonely-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("������ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( skill < 170)
            return notify_fail("��Ķ��¾Ž��ȼ�����, ����ʹ�á�����ʽ����\n");

        if( me->query("neili") < 250 )
            return notify_fail("��������������޷����á�����ʽ����\n");
	 force = target->query("max_neili");

        msg = HIC "$NǱ�˶��¾Ž�������ʽ���������ὣʹ���������ۣ����޻��ε�ֱ
��$n�ĵ��\n"NOR;
        message_combatd(msg, me, target);

        ap = me->query_skill("sword") + skill;
        dp = target->query_skill("dodge") / 2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150);
            msg = BLU"$n��ʱ������ǰһ��������Ѩ��΢΢һʹ��ȫ��������й������\n"NOR;
            target->set("neili",force/2 );
//            target->set("neili",);
            me->start_busy(2);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        }
        else
        {
            if(userp(me))
                 
            msg = "����$n������$N����ͼ�������ؽ��Ż��������������ڻ��е�
����\n"NOR;
            me->start_busy(2);
		message_combatd(msg, me, target);
        }

        return 1;
}

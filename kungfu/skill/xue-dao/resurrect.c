// resurrect.c ԡѪ����

#include <ansi.h>

#define R "��" HIR "ԡѪ����" NOR "��"

inherit F_CLEAN_UP;

int perform(object me, object target)
{
        int skill;
        string msg;
        mapping my;
        int rp;
        int neili_cost;


        if ((int)me->query_skill("xue-dao", 1) < 120)
                return notify_fail("���Ѫ���󷨲����������ʩչ" R "��\n");

        if ((int)me->query("max_neili") < 1000) 
                return notify_fail("���������Ϊ���㣬����ʩչ" R "��\n");

        if ((int)me->query("neili") < 200) 
                return notify_fail("�����ڵ���������������ʩչ" R "��\n");

        my = me->query_entire_dbase();
        if ((rp = (my["max_qi"] - my["eff_qi"])) < 1)
                return (SKILL_D("force") + "/recover")->exert(me, target);

        if (rp >= my["max_qi"] / 10)
                rp = my["max_qi"] / 10;

        skill = me->query_skill("xue-dao", 1);
        msg = HIR "$N" HIR "��������һ��������ɫ�ɺ�ת�ף������ɰ׷�"
              "�죬���ƻָ��˲��١�\n" NOR;
        message_combatd(msg, me);

        neili_cost = rp + 100;
        if (neili_cost > my["neili"])
        {
                neili_cost = my["neili"];
                rp = neili_cost - 100;
        }
        me->receive_curing("qi", rp);
        me->receive_healing("qi", rp * 3 / 2);
        me->add("neili", -neili_cost);

        if (random(10) < 3)
        {
                tell_object(me, HIC "��������ȵĴ߶���Ԫ�����������"
                                "��������ġ�\n" NOR);
                me->add("max_neili", -1);
        }
        me->start_busy(3);
        return 1;
}

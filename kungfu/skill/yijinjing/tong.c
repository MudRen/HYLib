// shield.c �׽ һ��ͨ����

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill, qi, maxqi;



        if (target != me)
                return notify_fail("��ֻ�����׽������һ��ͨ���� \n");

        if ((skill = (int)me->query_skill("yijinjing", 1)) < 100)
                return notify_fail("����׽�ȼ�������\n");

        if ((int)me->query("eff_qi")*120/(int)me->query("max_qi") > 80)
                return notify_fail("�����ƺ��ᣬ�޷������׽���߾�ѧ��\n");

        //if ((int)me->query("eff_qi")*100/(int)me->query("max_qi") < 10)
        //        return notify_fail("������̫�أ��޷������׽���߾�ѧ��\n");

        if ((int)me->query("neili") < skill*5 ||
            (int)me->query("max_neili") < 500)
                return notify_fail("�������������\n");

        me->add("neili", -skill*5);
        me->receive_damage("qi", 0);

        message_combatd(HIM "$N" HIM "Ĭ���׽�Ŀھ�: "
                            "Ԫ��,��������,�����⡣"
                            "�׽�,�л���Ϣ,����֧....\n"
                        HIW "һ����͵İ�ɫ�����ͷ��Ѹ��"
                        HIW "�α�" HIW "$N" HIW "���澭������\n"
                        HIR "�������ɲ�Ǽ��Ϊ��ת����\n" NOR, me);

        me->add("max_neili", -1);

        me->add("eff_qi",skill*8);
        if (me->query("eff_qi") > me->query("max_qi"))
                me->set("eff_qi",me->query("max_qi"));
        me->set("qi",me->query("eff_qi"));

        if (me->is_fighting()) me->start_busy(3+random(3));

        return 1;
}


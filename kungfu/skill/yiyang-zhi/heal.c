#include <ansi.h>

#define HEAL "��" HIR "��������" NOR "��"

int perform(object me, object target)
{
        string force;

        if ((int)me->query_skill("kurong-changong",1) < 100)
            return notify_fail("��Ŀ�������̫�͡�\n");

        if (! target)
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
       	if(me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("û�п���������Ϊ׼�����޷�ʹ����\n"); 

        if (target == me)
                return notify_fail(HEAL "ֻ�ܶԱ���ʩչ��\n");

        if (me->is_fighting() || target->is_fighting())
                return notify_fail("ս�����޷��˹����ˡ�\n");

        if ((int)me->query_skill("yiyang-zhi", 1) < 100)
                return notify_fail("���һ��ָ��������죬����ʩչ" HEAL "��\n");


        if (me->query_skill_mapped("finger") != "yiyang-zhi")
                return notify_fail("��û�м���һ��ָ������ʩչ" HEAL "��\n");


        if ((int)me->query("max_neili") < 1500)
                return notify_fail("���������Ϊ̫ǳ������ʩչ" HEAL "��\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("�����ڵ��������㣬����ʩչ" HEAL "��\n");

        if ((int)me->query("jing") < 100)
                return notify_fail("�����ڵ�״̬���ѣ�����ʩչ" HEAL "��\n");

        if (target->query("eff_qi") >= target->query("max_qi") &&
            target->query("eff_jing") >= target->query("max_jing"))
                return notify_fail("�Է�û�����ˣ�����Ҫ�������ơ�\n");
force="��������";
        message_vision(HIY "\nֻ��$N" HIY "ĬĬ��ת" + to_chinese(force) +
                     HIY "����������һ������ͷ������ð��������Ȼʩչ��\n"
                     "һ��ָ�����Դ���ָ��˲ʱ�����$n" HIY "ȫ����ʮ��\n"
                     "����Ѩ������һ�ᣬ�����$n" HIY "���ۡ���һ���³�\n"
                     "������Ѫ����ɫ��ʱ������������ˡ�\n" NOR, me, target);

        me->add("neili", -800);
        me->receive_damage("qi", 100);
        me->receive_damage("jing", 10);
target->clear_condition("shenzhao");
target->clear_condition("huanyin_poison");
target->clear_condition("cuixin_zhang");
        target->add("qi", 200 + (int)me->query_skill("force") +
                                     (int)me->query_skill("yiyang-zhi", 1) * 3);
        target->add("eff_qi", 200 + (int)me->query_skill("force") +
                                     (int)me->query_skill("yiyang-zhi", 1) * 3);

        if (target->query("qi") <= 0)
                target->set("qi", 1);

        target->add("jing", 200 + (int)me->query_skill("force") / 3 +
                                       (int)me->query_skill("yiyang-zhi", 1));
        target->add("eff_jing", 200 + (int)me->query_skill("force") +
                                     (int)me->query_skill("yiyang-zhi", 1) * 3);

        if (target->query("jing") <= 0)
                target->set("jing", 100);

        if ((int)target->query_condition("yyz_damage")
           || (int)target->query_condition("yyz_damage"))
        {
                target->clear_condition("yyz_damage");
                tell_object(target, HIC "\n��ֻ�����ڲд��һ��ָָ������"
                                    "���ˣ��о��ö��ˡ�\n" NOR);
        }

         if (target->query("qi") >= 10000)
                target->set("qi", 10000);

         if (target->query("eff_qi") >= 10000)
                target->set("eff_qi", 10000);

         if (target->query("jing") >= 10000)
                target->set("jing", 10000);

         if (target->query("eff_jing") >= 10000)
                target->set("eff_jing", 10000);


        if (! living(target))
                target->revive();

        if (! target->is_busy())
                target->stary_busy(3);

        message_vision("\n$N��Ŀڤ������ʼ�˹���Ϣ��\n", me);
        me->start_busy(5);
        return 1;
}

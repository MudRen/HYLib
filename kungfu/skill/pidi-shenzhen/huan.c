#include <ansi.h>
#include <combat.h>

#define HUAN "��" HIR "�öݺ���" NOR "��"

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int skill, i, p;
        int n;
        int my_exp, ob_exp;
        string pmsg;
        string msg;
        object weapon;

        if (! target) target = offensive_target(me);



        if (! target || ! me->is_fighting(target))
                return notify_fail(HUAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "throwing")
                return notify_fail("���������в�û�����Ű�����\n");

        if (weapon->query_amount() < 20)
                return notify_fail("����Ҫ�ж�ʮö��������ʩչ" HUAN "��\n");

        if ((skill = me->query_skill("pidi-shenzhen", 1)) < 140)
                return notify_fail("��ıٵ����벻����죬����ʩչ" HUAN "��\n");

        if ((int)me->query_skill("force") < 200)
                return notify_fail("����ڹ���򲻹�������ʩչ" HUAN "��\n");

        if ((int)me->query("neili") < 150)
                return notify_fail("�������������㣬����ʩչ" HUAN "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "ֻ��$N" HIR "һ����Ц�����弱����ת����ʱ���������е�"
              + weapon->name() + HIR "��������˷����˳�ȥ��\n" NOR;

        my_exp = me->query("combat_exp") + skill * skill / 10 * skill;
        ob_exp = target->query("combat_exp");

        if (random(my_exp) > ob_exp)
        {
                n = 4 + random(4);
                if (random(my_exp) > ob_exp) n += 4 + random(4);
                if (random(my_exp / 2) > ob_exp) n += 4 + random(4);
                if (random(my_exp / 4) > ob_exp) n += 4 + random(8);
                if (weapon->query_amount() < n) n = weapon->query_amount();

                msg += HIR "$n" HIR "��ʱֻ��������â��������Լ�Ϯ������"
                       "����������������$P" HIR + chinese_number(n) +
                       weapon->query("base_unit") + weapon->name() + HIR
                       "��\n" NOR;
                target->receive_damage("qi", skill + random(skill)+100);
                target->receive_wound("qi", skill  + random(skill)+100);
	        target->start_busy(2);
	        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                while (n--)
                {
                        //COMBAT_D->clear_ahinfo();
                        weapon->hit_ob(me, target,
                                       me->query("jiali") + 100 + n * 15);
                }

                if (stringp(pmsg = COMBAT_D->query_ahinfo()))
                        msg += pmsg;

                msg += "( $n" + eff_status_msg(p) + " )\n";
                message_combatd(msg, me, target);
        } else
        {
                msg += CYN "$p" CYN "����$P" CYN "�������أ����Ҵ��⣬��"
                       "������㿪������" + weapon->name() + CYN "��\n" NOR;
                message_combatd(msg, me, target);
        }

        weapon->add_amount(-n);
        me->add("neili", -100);
        me->start_busy(2);
        me->reset_action();
        return 1;
}

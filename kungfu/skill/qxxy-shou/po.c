#include <ansi.h>
#include <combat.h>

#define PO "��" HIC "���" HIW "��" HIC "��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        string wname;
        int ap, dp;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(PO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        //if (objectp(weapon = me->query_temp("weapon")))
        //        return notify_fail("ֻ�п��ֲ���ʩչ" PO "��\n");

        if ((int)me->query_skill("qxxy-shou", 1) < 150)
                return notify_fail("�������书������죬����ʩչ" PO "��\n");

        if (me->query_skill_mapped("hand") != "qxxy-shou")
                return notify_fail("��û�м��������书������ʩչ" PO "��\n");


        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ���Ϊ����������ʩչ" PO "��\n");

        if ((int)me->query("neili") < 300)
                return notify_fail("�����ڵ��������㣬����ʩչ" PO "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        damage = (int)me->query_skill("qxxy-shou", 1) / 2;
        damage += random(damage);

        ap = me->query_skill("hand");
        dp = target->query_skill("parry");
        msg = HIC "$N" HIC "˫ĿԲ�������ֶ�Ȼһ����׶�ʱ�ܳ�һ��" NOR + MAG
              "�Ϲ�" HIC "��ֱ��$n" HIC "ǰ�ء�\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "����$P" HIR "�����������Ѹ��֮��"
                                           "��$n" HIR "��αܵã���ʱ���Ͼ�����"
                                           "���ߣ�\n" NOR;        	
        } else
        {
                msg += CYN "$p" CYN "���Ʋ����æ����ݿ����ߣ��ܿ���$P"
                       CYN "���С�\n" NOR;
        }

        ap = me->query_skill("hand");
        dp = target->query_skill("dodge");
        msg += "\n" HIC "������$N" HIC "�������һ̧��ƾ���黮�˵�" HIY "��â" HIC
               "�����϶��·���$n" HIC "�󾱡�\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$p" HIR "ֻ����һ�飬�ѱ�$N" HIR
                                           "���л������У���ʱȫ��̱��Ż��һ����"
                                           "Ѫ��\n" NOR;        	

        } else
        {
                msg += CYN "����$p" CYN "˿����Ϊ$P"
                       CYN "�����������񵲣����Ƚ���һ�мܿ���\n" NOR;
        }

        ap = me->query_skill("hand");
        dp = target->query_skill("force");
        msg += "\n" HIC "���ڴ�ʱ��ȴ��$N" HIC "˫����Ȼ��Ȧ��ƽ�ƶ�������ʱ���"
               HIW "����" HIC "ֱϮ$n" HIC "��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg +=HIR "$p" HIR "��$N" HIR "���͹�֮�£���"
                                           "���������мܣ�������һ����÷���ˤ��"
                                           "��ȥ��\n" NOR;        	

        } else
        {
                msg += CYN "Ȼ��$p" CYN "�������������һ�񣬱㽫$P"
                       CYN "�����������Ρ�\n" NOR;
        }
        me->start_busy(2);
        me->add("neili", -200);
        message_combatd(msg, me, target);
if ((int)me->query_skill("qxxy-shou", 1)> 300)
{
        if (random(3)==0) target->start_busy(3);
        msg = HIR"$N˫��������ǰ�����λ�������㽫��"HIW"����"HIR"������$n��̴��Ѩ"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIG"������$N������ƣ�����һ�������¶�����Ϯ��$n��С��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIR"ֻ��$N���������������һԾ�����������������$n��ͷ��"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIY"$N�ڿ���һ����ת��Я��"HIR"����֮��"HIY"��, ˫�ư���$n�ĵ���"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 }
        return 1;
}

#include <ansi.h>
#include <combat.h>

#define LANG "��" HIM "���κ���" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int lvl, p;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(LANG "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(LANG "ֻ�ܿ���ʩչ��\n");

	if ((int)me->query_skill("shenlong-xinfa", 1) < 165)
		return notify_fail("��������ķ���򲻹�.\n");

        if (me->query_skill_mapped("force") != "shenlong-xinfa")
                return notify_fail("��û�м��������ķ�Ϊ�ڹ����޷�ʩչ" LANG "��\n");
                
        if ((int)me->query_skill("xuanming-zhang", 1) < 220)
                return notify_fail("�����ڤ���Ʋ����������޷�ʩչ" LANG "��\n");

        if ((int)me->query("max_neili") < 3000)
                return notify_fail("���������Ϊ���㣬�޷�ʩչ" LANG "��\n");

        if ((int)me->query("neili") < 800)
                return notify_fail("��������������޷�ʩչ" LANG "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "\n$N" HIW "Ĭ����ڤ�񹦣�չ�����С�" HIM "���κ���" HIW "������Ȼ������"
              "��ǰ��˫��������Ʒ������ޱȣ���δ������������˲Ϣ��˫��������$n" HIW "��\n"NOR;  

        lvl = me->query_skill("xuanming-zhang", 1);

        ap = me->query_skill("strike") + me->query_skill("force");
        dp = target->query_skill("dodge") + target->query_skill("force");

        me->start_busy(4);

        // ��һ��

        msg += HIM "\n$N" HIM "��������һת��������ǰ����Ȼ��ֱϮ$n" HIM "���š�\n" NOR;
        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -300);
        target->apply_condition("xuanming_poison",50);
        target->receive_wound("jing", target->query("jing")/5);
        target->receive_damage("jing", target->query("jing")/6);
                msg += HIR "$n" HIR "�������㣬ȴ��$N" HIR "ͻȻ�Ƶ�$p" HIR "���$n" HIR "����һ"
                   "�����������ƣ��پ�������һ�ɺ������𣬾�������������\n" NOR;
                                           
        } else
        {
                msg += HIY "$n" HIY "����$N" HIY "������ӿ����æ����Ծ����\n" NOR;
                me->add("neili", -180);
        }
        message_vision(msg, me, target);
         
        // �ڶ���
        msg = HIM "\n$N" HIM "����һ���������ƽ����������絽�Ƶ���������$n" HIM "�ؿڡ�\n" NOR;
        if (ap / 2 + random(ap) > dp)
        { 
                damage = ap + random(ap / 2);
                me->add("neili", -400);
        target->apply_condition("xuantian_han",50);
       target->receive_wound("qi", target->query("qi")/5);
        target->receive_damage("qi", target->query("qi")/6);
                msg += HIR "$n" HIR "����$N" HIR "�����ѹ���������������ͻȻ���ؿ�һ�𣬲�������"
               "�п࣬�ٸ��ؿڴ�һ�ɺ������𣬾�������������\n" NOR;
                                           
        } else
        {
                msg += HIY "$n" HIY "����$N" HIY "������ӿ����æ����Ծ����\n" NOR;
                me->add("neili", -180);
        }
        message_vision(msg, me, target);

        return 1;
}



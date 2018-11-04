#include <ansi.h>
#include <combat.h>

#define GUI "��" HIR "��ȥ����" NOR "��"

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
                return notify_fail(GUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (objectp(weapon = me->query_temp("weapon")))
                return notify_fail("ֻ�п��ֲ���ʩչ" GUI "��\n");

        if (me->query_skill("force") < 200)
                return notify_fail("����ڹ���Ϊ����������ʩչ" GUI "��\n");

        if ((int)me->query_skill("wudoumi-shengong", 1) < 140)
                return notify_fail("����嶷���񹦲�����죬����ʩչ" GUI "��\n");

        if ((int)me->query("neili") < 800)
                return notify_fail("��������������������ʩչ" GUI "��\n");

        if (me->query_skill_mapped("force") != "wudoumi-shengong")
                return notify_fail("��û�м����嶷����Ϊ�ڹ�������ʩչ" GUI "��\n");

        if (me->query_skill_mapped("unarmed") != "wudoumi-shengong")
                return notify_fail("��û�м����嶷����Ϊȭ�ţ�����ʩչ" GUI "��\n");



        if (! me->query_temp("powerup"))
                return notify_fail("��δ��ȫ����������������ʩչ" GUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        damage = (int)me->query_skill("wudoumi-shengong", 1) * 2;
        damage += random(damage);

        ap = me->query_skill("force") + me->query("con") * 10;
        dp = target->query_skill("dodge") + target->query("dex") * 10;

        msg = HIR "$N" HIR "һ���Ϻȣ�˫��ʩ���嶷���񹦡���ȥ���⡹��������ʱ��"
              "�����ȣ�ӿ��$n" HIR "��\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage);
                msg += HIR "$p" HIR "��æ�����񵲣���ֻһ˲��"
                                           "��$P" HIR "���ƾ���͸����룬�������"
                                           "�����߹ǣ�\n" NOR;
                                           NOR;        	
        } else
        {
                msg += CYN "$p" CYN "��$P" CYN "������ӿ������Ӳ��"
                       "��ֻ��С����Ų������������\n" NOR;
        }

        ap = me->query_skill("force") + me->query("con") * 10;
        dp = target->query_skill("dodge") + target->query("dex") * 10;

        msg += "\n" HIR "������ֻ��$N" HIR "˫�ֶ�Ȼ��Ȧ����ʹ��Ϯ�����ƾ�����"
               "����$n" HIR "����ٶ�ϯ����顣\n" NOR;
        if (ap / 2 + random(ap) > dp)
        {
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage);
                msg += HIR "$p" HIR "��֮�£���Ȼ��ֱ������$P"
                                           HIR "���ȵ��ƾ���ʱ��͸���ţ�����������"
                                           "����\n" NOR;        	

        	

        } else
        {
                msg += CYN "$p" CYN "��֮�¼�æ����Ծ�����ڶ㿪"
                       "�������Ī���һ����\n" NOR;
        }
        me->start_busy(2);
        me->add("neili", -600);
        message_combatd(msg, me, target);
        return 1;
}

 // duoming.c


#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp;
        int damage;
        int count;
        int i, attack_time;

        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail( "��������ֻ����ս����ʹ��\n");


        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");


        if (me->query_skill("force") < 150)
                return notify_fail("����ڹ�����Ϊ����������ʹ�á�������������\n");

        if (me->query_skill("canglang-bian", 1) < 150)  
                return notify_fail("��ġ����˱޷� ��δ�����磬�޷�ʩ����������������\n");  

        if (me->query_skill("bibo-shengong", 1) < 150)  
                return notify_fail("��ı���������Ϊ�������޷�ʩ�������˱޷�����\n");  

        if (me->query_skill_mapped("whip") != "canglang-bian")  
                return notify_fail("�����õĲ��ǡ����˱޷� ����ʩչ������������������\n");  

        if (me->query("neili") < 500)
                return notify_fail("��������������޷�ʹ�á�������������\n");

        if (me->query_skill_mapped("whip") != "canglang-bian")
                return notify_fail("��û�м��������ޣ�����ʹ�á�������������\n");
	msg = HIM "$N" HIM "һ����Х������" + weapon->name() + HIM "һ������ʱ"
              "�û��������â��$n" HIM "�������׹�ȥ��\n" NOR;

        if (random(me->query_skill("whip")) > target->query_skill("parry") / 2)
        {
        	msg += HIR "��ʱ$n" HIR "ֻ��" + weapon->name() + HIR
                       "ѹ���������ӣ������ƹ�֮������֮��ȥ��\n" NOR;
                target->start_busy(5);
	        me->add("neili", -80);
	        me->start_busy(1);
        } else
	{
                msg += CYN "����$n" CYN "С��Ӧ�ԣ�˿�������Ի�����"
                       "Ծ����$N" CYN "�����֡�\n" NOR;
	        me->add("neili", -30);
	        me->start_busy(2);
        }
        message_combatd(msg, me, target);
        msg = HIB "ͻȻ֮�䣬" HIB "$N" HIB "����һ��һ�Σ���������,"+ weapon->name() +
              HIB "���Ҽ缱˦��󣬶���"
              HIB "��ͷ����\n" HIB "$n" HIB "���š�" HIB "$N" HIB "������"
              HIB "$n" HIB "���ʮ������,��"+ weapon->name() +
              HIB "˵���㵽��������"
              HIB "��\n������ʸ�ö�������\n" NOR;

        ap = me->query_skill("whip");
        dp = target->query_skill("parry");
        attack_time = 5;
        if (ap / 2 + random(ap * 2) > dp || !living(target))
        {
                msg += HIR "���$p" HIR "��$P" HIR
                       "���˸����ֲ�����Ŀ�Ӳ�Ͼ��ƣ�ڱ�����\n" NOR;
                count = ap / 10;
                me->add_temp("apply/attack", 30);
                attack_time += random(ap / 45);
        } else
        {
                msg += HIC "$n" HIC "��$N" HIC "���ƺ�����������Ȼ������Ӧ����\n" NOR;
                count = 0;
        }

        message_combatd(msg, me, target);

        if (attack_time > 7)
                attack_time = 7;

        me->add("neili", -attack_time * 20);

        for (i = 0; i < attack_time; i++)
        {
                if (! me->is_fighting(target))
                        break;
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -30);
        me->start_busy(3);
        return 1;
}

#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

#define SUO "��" HIR "������" NOR "��"

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int ap, dp;
        int lvl, p;
        int count;
	int i, attack_time;


        if (! target) target = offensive_target(me);

        if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (! target || ! me->is_fighting(target))
                return notify_fail(SUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ((int)me->query_skill("chanhun-suo",1) < 120)
                return notify_fail("��Ĳ���������̫ǳ��ʹ���ˡ�\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("��Ļ����󷨻�򲻹�.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("����������צ��򲻹�.\n");

        if ((int)me->query_skill("force", 1) < 100)
                return notify_fail("����ڹ���򲻹���ʹ����" SUO "��\n");

        //if (target->is_busy())
        //        return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

        if (me->query_skill_mapped("whip") != "chanhun-suo")
                return notify_fail("��û�м�������������ʹ����" SUO "��\n");

        if (me->query("neili") < 350)
                return notify_fail("���������㣬�޷�ʩչ" SUO "��\n");

        if (! living(target))
               return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIR "$N" HIR "һ����Ц��ʹ���������������������������Ӱ����$n"
              HIR "ȫȫ���֣�\n\n" NOR;

        if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3)
        {
                msg += HIY "���$n" HIY "������ɽ������Ĺ������˸����ֲ�����������������ȫ�޷�����\n" NOR;
        message_combatd(msg, me, target);

attack_time=(int)me->query_skill("chanhun-suo", 1) /40;
        if (attack_time > 9)
                attack_time = 9;
        me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", 300);
        me->add("neili", -attack_time * 30);


	for (i = 0; i < attack_time; i++)
	{
                if (! target->is_busy() && random(5) == 1)
                       target->start_busy(2);
 
         msg = HIG "$N����������Ӱ�������"+(i+1)+"�ޣ�\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}
        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -300);
                me->start_busy(2);
        } else
        {
                msg += CYN "����$p" CYN "������$P" CYN "����ͼ������һ�ݣ��ӿ��˹��ơ���\n" NOR;
                me->start_busy(3);
        message_combatd(msg, me, target);
        }
        
        return 1;
}

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

#define DUO "��" HIC "�����" NOR "��"

int perform(object me, object target)
{
        object weapon;
        string msg;
        int ap, dp,attack_time,i;
        int damage;
 
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(DUO "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            weapon->query("skill_type") != "whip")
                return notify_fail("��ʹ�õ��������ԡ�\n");

        if (me->query_skill("force", 1) < 130)
                return notify_fail("����ڹ���򲻹���ʹ����" DUO "��\n");
	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("��Ļ����󷨻�򲻹�.\n");

	if ((int)me->query_skill("sanyin-wugongzhao", 1) < 120)
		return notify_fail("����������צ��򲻹�.\n");

        if (me->query_skill("chanhun-suo", 1) < 100)
                return notify_fail("��Ĳ���������̫ǳ��ʹ����" DUO "��\n");

        if (me->query("neili") < 220)
                return notify_fail("��������������޷�ʹ��" DUO "��\n");

        if (me->query_skill_mapped("whip") != "chanhun-suo")
                return notify_fail("��û�м�������������ʹ����" DUO "��\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIY "$N" HIY "�����һЦ������" + weapon->name() +
              HIY "���ñ�ֱ������$n" HIY "���󣬿��Ǵ�����;ȴ��ͣ�ͣ�ת��$n"
              HIY "�ؿڻ�ȥ��\n" NOR;

        ap = me->query_skill("whip") + me->query_skill("force");
        dp = target->query_skill("force") + target->query_skill("parry");

        if (random(me->query("combat_exp"))+100000 > (int)target->query("combat_exp") / 2)
        {
                damage = ap + random(ap / 3);
                me->add("neili", -180);
                me->start_busy(2);
        target->receive_wound("qi", target->query("qi")/8);
        target->receive_damage("qi", target->query("qi")/7);
target->apply_condition("xx_poison",20);
target->apply_condition("x2_sandu",20);
target->apply_condition("sanpoison",20);
                msg += HIR "���$n" HIR "һ���ҽУ�δ�ܿ���$N"
                                           HIR "����ͼ������һ��Ӳ�����ؿڣ���Ѫ��"
                                           "����Ƥ��������\n" NOR;


                message_combatd(msg, me, target);
                if (ap > 400) ap = 400;
                dp += target->query_skill("huagong-dafa", 1) * 2;
                if (! target->is_busy() &&
                    ap / 2 + random(ap) > dp)
                {
                        target->start_busy(2 + random(6));
                        message_vision(HIW "$N" HIW "һ�������е�" + weapon->name() +
                                       HIW "��ಡ��Ĵ��˳���������Ȼ����$n"
                                       HIW "��\n$n" HIW "���һ������æ�˺���ȥ��һ�С�\n" NOR,
                                       me, target);
                }
        } else
        {
                me->add("neili", -100);
                me->start_busy(2);
                msg += CYN "����$p" CYN "����һԾ���𣬶�ܿ���"
                       CYN "$P" CYN "�Ĺ�����\n" NOR;
                message_combatd(msg, me, target);
        }

attack_time=(int)me->query_skill("chanhun-suo", 1) /50;
        if (attack_time > 6)
                attack_time = 6;

        me->add("neili", -attack_time * 10);


	for (i = 0; i < attack_time; i++)
	{
                if (! target->is_busy() && random(5) == 1)
                       target->start_busy(2);
 
         msg = HIG "$N����������Ӱ�������"+(i+1)+"�ޣ�\n"NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	}


        return 1;
}

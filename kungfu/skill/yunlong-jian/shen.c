#include <ansi.h>
#include <combat.h>

#define SHEN "��" HIM "����Ԫ��" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg, wn;
        object weapon;
        int ap, dp;
                int count;
	int i, attack_time;
        me = this_player();


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(SHEN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon"))
           || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" SHEN "��\n");

	if( (int)me->query_skill("yunlong-shengong", 1) < 150 )
		return notify_fail("��������񹦲����ߡ�\n");
	if( (int)me->query_skill("yunlong-jian", 1) < 150 )
		return notify_fail("��������������������죡\n");
        if (me->query_skill_mapped("sword") != "yunlong-jian")
                return notify_fail("��û�м�����������������ʩչ��\n");

        if ((int)me->query_skill("force", 1) < 220)
                return notify_fail("����ڹ���򲻹�������ʩչ" SHEN "��\n");

        if ((int)me->query_skill("dodge", 1) < 200)
                return notify_fail("����Ṧ��򲻹�������ʩչ" SHEN "��\n");  

        if ((int)me->query("max_neili") < 5500)
                return notify_fail("���������Ϊ���㣬����ʩչ" SHEN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("�����ڵ���������������ʩչ" SHEN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        wn = weapon->name();

        msg = HIM "\n$N" HIM "һ��ŭ�ȣ��ھ����ǣ�����" + wn +
              HIM "�����ǧ�����Ǽ仯��������̰�������⣬��"
              "����\n$P����ر�죬���Ž���ͬʱ����" HIR
              "ף��" HIM "������" HIY "�ϸ�" HIM "������" NOR
              WHT "ʯ��" HIM "������" HIG "ܽ��" HIM "������"
              HIW "����" HIM "��\n���׽�������ʹ��������ʯ��"
              "��Ϯ��$n" HIM "ȫ��" NOR;

//        message_sort(msg, me, target);
        
        ap = me->query_skill("yunlong-jian", 1) +
             me->query_skill("parry", 1);

        dp = target->query_skill("dodge", 1) +
             target->query_skill("parry", 1);

        if (ap * 2 / 3 + random(ap) > random(dp))
        {
                damage = me->query_skill("yunlong-jian", 1) +
                         me->query_skill("force", 1) +
                         me->query_skill("parry", 1);

                damage += random(damage / 2);

                // ���֮һ�ļ��ʿɱ��м�
                if (random(10) <= 1 && ap / 2 < dp)
                {
                        damage = damage / 3;

                               target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIG "\n$n" HIG "��$N" HIG "������⽣��"
                                                  "���ˣ���æ������������мܡ�\n��֪$P��"
                                                  "�������Ƿ���$pһ���ƺߣ����˼�������"
                                                  "��һ����Ѫ��\n" NOR;
                        me->add("neili", -100);
                        me->start_busy(3);
                } else 
                {
                               target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "\n$n" HIR "��$N" HIR "��������ͷ�"
                                                  "���䣬�����ݺᣬ��Х�����Լ�Ϯ����\n��"
                                                  "�ײ��ɴ󾪣���ʱ���á����͡�һ������"
                                                  "��͸�������\n" NOR;

                        me->add("neili", -100);
                        me->start_busy(3);
                }
        } else
        {
                msg = CYN "\nȻ��$n" CYN "�Կ�Կ죬����һ��"
                      "��Ȼ���$N" CYN "��һ�С�\n" NOR;
                me->add("neili", -150);
                me->start_busy(3);
        }
        message_vision(msg, me, target);
count = ap / 3;
                attack_time += random(ap / 40);
        if (attack_time > 7)
                attack_time = 7;

        me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", count / 2);
        me->add("neili", -attack_time * 30);
	me->start_busy(3);

        me->set_temp("perform_wushenjian/qian", 1);
	for (i = 0; i < attack_time; i++)
	{
		if (! me->is_fighting(target))
		       break;

                if (! target->is_busy() && random(3) == 1)
                       target->start_busy(2);
 
	        COMBAT_D->do_attack(me, target, weapon, 0);
	}
        me->delete_temp("perform_wushenjian/qian");

        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -count / 2);

        return 1;
}

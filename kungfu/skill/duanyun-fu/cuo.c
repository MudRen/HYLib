#include <ansi.h>
#include <combat.h>

#define CUO "��" HIR "���־�" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int level,ap,dp;
	string msg;
        int i, attack_time;
 
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(CUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "axe")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" CUO "��\n");

        if (target->is_busy())
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ�\n");

    if( (int)me->query_skill("duanyun-fu",1) < 70)
    return notify_fail("��Ŀǰ������ʹ���������־�����\n");
    
        if ((int)me->query_skill("force") < 120)
                return notify_fail("����ڹ���򲻹�������ʩչ" CUO "��\n");

        if ((int)me->query("max_neili") < 800)
                return notify_fail("���������Ϊ����������ʩչ" CUO "��\n");

        if ((int)me->query("neili") < 100)
                return notify_fail("��������������������ʩչ" CUO "��\n");


        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIR "$N" HIR "�߾�����" + weapon->name() + HIR "����Ȼһ���Ϻȣ�����$n"
              HIR "�ͻ�������������硣\n" NOR;

        ap = me->query("combat_exp");
        dp = target->query("combat_exp");
        level=me->query_skill("duanyun-fu",1);
        me->add("neili", -30);
        if (ap / 2 + random(ap) > dp)
        {
		msg += HIR "$p" HIR "��$P" HIR "������ӿ�����ò���;"
                       "���У���һ�µ�ʱ��ʧ���Ȼ���\n" NOR;
                target->start_busy(level / 50 + 3);
	} else
        {
		msg += CYN "����$p" CYN "����$P" CYN "��ʽ����·��б"
                       "б������ʹ����δ��˿�����á�\n" NOR;
		me->start_busy(2);
	}
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 )
         {
         attack_time = random((int)me->query_skill("duanyun-fu", 1) / 10);
if (attack_time > 7) attack_time=7;
        message_combatd(msg, me, target);
        for(i = 0; i < attack_time; i++){
         msg = HIR "$N˫�������������ҿ���\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                                        }
         }
                me->start_busy(3);

	return 1;
}

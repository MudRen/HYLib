#include <ansi.h>
#include <combat.h>

#define KOU "��" HIM "�������" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon;
	int damage,extra,count;
	string msg;
        int ap, dp;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(KOU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("��ʹ�õ��������ԣ�����ʩչ" KOU "��\n");

        if ((int)me->query_skill("force") < 100)
                return notify_fail("����ڹ���򲻹�������ʩչ" KOU "��\n");

        if ((int)me->query_skill("bingpo-blade", 1) < 80)
                return notify_fail("��ı��Ǻ����������ң�����ʩչ" KOU "��\n");

	if ((int)me->query_skill("huagong-dafa", 1) < 125)
		return notify_fail("��Ļ����󷨻�򲻹�.\n");
        if ((int)me->query("neili") < 350)
                return notify_fail("�����������������ʩչ" KOU "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

	msg = HIM "$N" HIM "������Ȼһ�䣬ʱ������ʱ������ʱ������������磬ת˲"
              "��������$n" HIM "��\n" NOR;

        ap = me->query_skill("blade");
        dp = target->query_skill("parry");

        if (ap / 2 + random(ap) > dp)
	{
		damage = ap / 2 + random(ap / 2);
                me->add("neili", -100);
                damage = 150+me->query_skill("unarmed");
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "���$n" HIR "һ�������񣬱�����ɨ"
                                           "������Ѫ�Ľ���ʹ���ķΣ�\n" NOR;
		me->start_busy(2);
	} else 
	{
		msg += CYN "����$p" CYN "�����������ס�Ż�������$P"
                       CYN "�������У�ʼ���κβ��á�\n" NOR;
                me->add("neili", -50);
		me->start_busy(3);
	}
	message_combatd(msg, me, target);
        if ((int)me->query_skill("bingpo-blade", 1) > 160)
 {
 msg = HIW "$N��Ȼ������һ�ᣬ���λεĵ������չ��·���һƬ�׹�,ֱ��$n�����ţ�\n" NOR;
        message_vision(msg, me, target);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 )	
	 {  msg = HIW "$Nֻ��һ��ѣ��̵�˫��ʲô���������ˣ�$n��״��ϲ������������������ͬ�ķ�������\n" NOR;	
	    message_vision(msg, target,me);
	     extra = me->query_skill("bingpo-blade",1) / 50;
	    if(extra>4) extra = 4 ; target->start_busy(extra + count);
	  }else{
	       msg = "����$n������$N����ͼ������һ�����˹�ȥ��\n" NOR;
	       message_vision(msg, me, target);

               me->start_busy(3);
	       return 1;
           }
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
	me->add("neili", -150);

}
	return 1;
}

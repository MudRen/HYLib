// xian.c  ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon;
	int damage;
	int extra;
	string msg;

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || !me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
		
	if( (int)me->query_skill("yunlong-jian", 1) < 50 )
		return notify_fail("�����������������죬����ʹ�á��������֡���\n");
	                        
	if( (int)me->query_skill("yunlong-shengong", 1) < 50 )
		return notify_fail("��������񹦲����ߣ����ܡ�\n");
			
	if( (int)me->query("neili", 1) < 300 )
		return notify_fail("����������̫��������ʹ�á��������֡���\n");
			
	extra = me->query_skill("yunlong-jian",1) / 15;
	extra += me->query_skill("yunlong-jian",1) /15;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
if ((int)me->query_skill("yunlong-jian",1) > 249 && (int)me->query_skill("yunlong-shengong",1) > 250)
{
        msg = HIB "������������һ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "���Ļ�����֮�ڶ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIG "�ߴ���ʤ��֮��������!" NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        me->start_busy(1);
}
	msg = CYN "$N΢΢һЦ������һ����,��ʹ������Ԧ����������$n��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "��һ������"+HIR+"����$n����$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;   
        message_vision(msg, me, target);
  if( !target->is_busy() )
{
        target->start_busy(3);
}
        }
      	msg = HIR"ֻ��$N���н������һ������,�ڿն���,ٿ������$n��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "�ڶ�������"+HIM+"ɨ��$n������,$nֻ����ȫ��һ��ʹ��\n"NOR;   
                message_vision(msg, me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra);
        }
        msg = HIG  "����������ֱ�϶��£�ֻ��һ��������$n������" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "���һ������"+HIB+"ɨ��$n������Ѩ,$nֻ����ȫ�������᲻�����ˣ�\n"NOR;   
        message_vision(msg, me, target);
        target->add("neili",-extra*4);
        target->add("eff_neili",-extra*4);
        }
	me->add("neili",-300);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	me->start_busy(3);
	return 1;
}

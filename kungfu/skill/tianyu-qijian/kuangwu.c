//Edit by cloth 2000-09-19
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("tianyu-qijian",1);
        if ( extra < 200) return notify_fail("��������潣���������죡\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query("neili")<450)
                return notify_fail("�������������\n"); 
	if(((int)me->query_skill("bahuang-gong", 1) < 160 ) &&
	   ((int)me->query_skill("beiming-shengong", 1) < 160 ))
		return notify_fail("��ı����ڹ�������졣\n");

        me->add("neili",-350);
        weapon = me->query_temp("weapon");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

if (!me) return 0;
if (!target) return 0;
        message_vision(HIM"$Nʹ�������潣�еľ��У��������ݣ�һ���������������е�"+weapon->name()+"�������$n������һ����\n\n" NOR,me,target);        
	extra = me->query_skill("tianyu-qijian",1) / 10;
	extra += me->query_skill("tianyu-qijian",1) /10;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIR"�ڶ�����\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIC"��������\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIY"���Ľ���\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIG"���彣��\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIM"��������\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIW"���һ����\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        if (me->query("combat_exp")> target->query("combat_exp")/3 )
        {                
        msg = HIC "һ��������"+HIM+"����$n������,$nֻ�����˿�һ�䣡\n"NOR;   
                message_vision(msg, me, target);
		target->apply_condition("ss_poison", 35);
                if (!target->is_busy())
                target->start_busy(2);
        }
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3)
        {                
        msg = HIY "һ��������"+HIM+"����$n������,$nֻ�����˿�һ�䣡\n"NOR;   
                message_vision(msg, me, target);
		target->apply_condition("ss_poison", 35);
                if (!target->is_busy())
                target->start_busy(2);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 3)
        {                
        msg = HIR "һ��������"+HIM+"����$n������,$nֻ�����˿�һ�䣡\n"NOR;   
                message_vision(msg, me, target);
		target->apply_condition("ss_poison", 35);
                if (!target->is_busy())
                target->start_busy(2);
        }
       
        
        message_vision(WHT"$N�����߽������$n�����˸���æ���ң�\n" NOR,me,target);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);

        me->start_busy(3);


        return 1;
}


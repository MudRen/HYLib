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
        extra = (int)me->query_skill("murong-jianfa",1);
        if ( extra < 120) return notify_fail("���Ľ�ݽ������������죡\n");
        if((int)me->query_skill("canhe-zhi", 1) < 100 )
                return notify_fail("���ָ����δ���ɣ�����ʹ�ãۿ콣�ݣ�\n");        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�ۿ콣��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if ((int)me->query("neili")<400)
                return notify_fail("�������������\n"); 

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

        if (me->query_skill("shenyuan-gong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

        me->add("neili",-350);
        weapon = me->query_temp("weapon");
        message_vision(HIM"$Nʹ��Ľ�ݽ����еľ��Уۿ콣�ݣ�һ���������������е�"+weapon->name()+"�������$n������һ����\n\n" NOR,me,target);        

	me->add_temp("apply/attack", extra/6);	
	me->add_temp("apply/damage", extra);

        COMBAT_D->do_attack(me,target, weapon); 
        message_vision(HIW"��ɽ������\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIC"̩ɽ������\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIR"��ɽ���񽣣�\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIY"��ɽ������\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
        message_vision(HIB"��ɽ������\n" NOR,me,target);
        COMBAT_D->do_attack(me,target, weapon);
	me->add_temp("apply/attack", -extra/6);	
	me->add_temp("apply/damage", -extra);
        
        
        message_vision(WHT"$N�������������$n�����˸���æ���ң�\n" NOR,me,target);
        me->start_busy(2);
      
        return 1;
}

 // tie@fengyun
#include <ansi.h> 
#include <combat.h> 
inherit F_SSERVER;
int perform(object me, object target) 
{ 
        string msg; 
        int extra; 
        object weapon; 
        extra = me->query_skill("wuzhan-mei",1);
        if ( extra < 280) return notify_fail("��ģ���չ÷�ݻ��������죡\n");
        	
        if( !target ) target = offensive_target(me); 
        if( !target 
        ||      !target->is_character() 
        ||      !me->is_fighting(target) ) 
                return notify_fail("��÷����ȣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������̫��������ʹ�á��꼤÷������㡹��\n");

	if(me->query_skill("wuzhan-mei")<300)
	return notify_fail("�����չ÷������죬�������á��꼤÷������㡹��\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");

        me->add_temp("apply/attack", 100);
        msg = HIG "$N΢΢һЦ������һ����,��ʹ������Ԧ����������$n��\n"+HIW"��һ����÷��������" NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "�ڶ�����÷�����ȣ�" NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "����������亮÷��" NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���Ľ����꺮��ů��" NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���彣��÷�����ţ�"NOR; 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);
        me->add("neili",-380);
        me->start_busy(2); 
        return 1; 
}      

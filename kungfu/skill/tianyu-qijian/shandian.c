// ������ӿ
 
#include <ansi.h>
#include <combat.h> 
#include <skill.h>

inherit F_SSERVER;

int perform(object me, object target)
{
         string name,dodge_skill,msg;
         int i, j, p;
 
         object weapon = me->query_temp("weapon");
        
         if( !target ) target = offensive_target(me);
 
         if( !target || !me->is_fighting(target) )
                 return notify_fail("�����羪�硹ֻ����ս���жԶ���ʹ�á�\n");
         if(!weapon || weapon->query("skill_type") != "sword")
                 return notify_fail("�����ʹ����������ʹ�á����羪�硹��\n");   
         if( (int)me->query_skill("tianyu-qijian", 1) < 150 )
                 return notify_fail("��������潣��������죬ʹ���������羪�硹������\n");
         if( (int)me->query_skill("bahuang-gong", 1) < 150 )
                 return notify_fail("��İ˻����Ϲ��ȼ���������ʹ���������羪�硹������\n");
         if( (int)me->query_skill("force") < 150 )
                 return notify_fail("����ڹ��ȼ�����������ʹ�á����羪�硹��\n");
         if( (int)me->query_str() < 30 )
                 return notify_fail("�������������ǿ����ʹ���������羪�硹����\n");
         //if ( me->query_skill_mapped("sword") != "tianyu7gong")
         //       return notify_fail("�������޷�ʹ�á����羪�硹��\n");                                                                                 
         if( (int)me->query("max_neili") < 1000 )
                 return notify_fail("����������̫����ʹ���������羪�硹��\n");      
         if( (int)me->query("neili") < 500)
                 return notify_fail("����������̫����ʹ���������羪�硹��\n");
 
         me->set_temp("xtj_haichao", 1);
         message_vision(MAG"\n$N"+weapon->name()+MAG"΢΢�ζ��������������۷�ʱ��˫ü��������ǰ�磬һ�ɳ��ǵĽ�����������ӿ��ȥ��\n"NOR,me,target);
         i = me->query_skill("tianyu-qijian", 1)/2;
         j = me->query_skill("sword", 1)/2;
         me->add_temp("apply/strength", i);
         me->add_temp("apply/attack", j);
         me->add_temp("apply/damage", j); 
           msg = HIC "$w"HIC"��$N�þ���ָ���£����������������ƿ�֮����������������ɳ��۵ĺ�Х������ʹ���ĺ���������ƣ�" NOR;  
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg); 
           msg = HIC "$N�ӽ����裬һʱ�����ݺᣬ�����ྲ�ද����ʱ������ƽ�羵�Ĵ󺣣���ʱ����ŭ�����Σ��仯Ī�⣡" NOR;             
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);      
           msg = HIC "$Nÿһ��̬���������ۣ�ÿһ�����������ֳ��������ܵļ��ޣ����ľ��ּ��ң��γɾ��������������ƣ�" NOR; 
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);	
         me->add("neili", -300);

         me->add_temp("apply/strength", -i);
         me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -j);
	if (random(me->query("combat_exp")) > target->query("combat_exp")/3 ){
         message_vision(HIW"\nͻȻ�������һ�����죬һ�����绮��ҹ������"+weapon->name()+HIW"�ϣ�$NЮ�׵�֮������$n���˹�ȥ��\n"NOR,me,target);
	if (random(10)>3||target->is_busy()){
		message_vision(HIR"���$n����������$N�������ţ�" + weapon->name() + HIR"�ϵ�"HIC"�羢"HIR"�˻�����$n���ڡ�\n"NOR,me,target);
              p = 3+random(4);
              target->start_busy(p);
}
	else {
         dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);	
         me->add("neili",-50);
		}
		}
me->start_busy(2);
//	      me->start_perform(6,"�����羪�硹");
       return 1;
 }

 
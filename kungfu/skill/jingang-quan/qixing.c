// ruying ���Ǿۻ�
// campsun

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("�����Ǿۻ᡹ֻ����ս���жԶ���ʹ�á�\n");

      if( objectp(me->query_temp("weapon")) )
      return notify_fail("��������ʹ�á���շ�ħ����\n");
      
      if( (int)me->query_skill("jingang-quan",1) < 200 )
      return notify_fail("��Ĵ���ȭ������죬����ʹ�á���շ�ħ����\n");
      
      if( (int)me->query_skill("yijinjing",1) < 230 )
      return notify_fail("����׽�ȼ�����������ʹ�á���շ�ħ����\n");  
      
      if(me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("��û�������׽�ڹ����޷�ʹ�á���շ�ħ�����й�����\n"); 

if( (int)me->query_skill("buddhism", 1) < 180 )
                return notify_fail("��������ķ��ȼ�����������ʹ�á����Ǿۻ᡹��\n");
        
if( (int)me->query_str() < 28 )
                return notify_fail("��ı�������ǿ������ʹ�á����Ǿۻ᡹��\n");

      

        if( (int)me->query("neili") < 1200 )
                return notify_fail("����������̫��������ʹ�á����Ǿۻ᡹��\n");

        msg = HIR "$N˫ȭ������˲Ϣ��������ȭ���ֻ�$nȫ�����Ǵ���ȭ���������Ǿۻ᡹��\n" NOR;

        message_vision(msg, me, target);

        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1); 
              msg = HIR "$Nһȭ�ȳ�������һת������$n��࣬˫ȭ���٣�ͬʱ�򵽡�\n" NOR;
        message_vision(msg, me, target);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              
              msg= HIR "$N˫ȭ�����������꣬����$n�硢�ۡ��ء���������λ������������ݡ�\n" NOR;
        message_vision(msg, me, target);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
                 COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
              COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);     

        me->add("neili", -400);

        me->start_busy(2+random(2));

        return 1;
}

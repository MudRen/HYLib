#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me,object target)
{
     int d=me->query_skill("yanling-shenfa",1)/5;
        int j=me->query_skill("murong-daofa", 1)/5;
     int i=me->query_skill("xingyi-zhang", 1)/5;
	string msg;

        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
     
        if( !target || !me->is_fighting(target) )
                return notify_fail("��Ӱ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");                
       
        if( (int)me->query_skill("murong-daofa", 1) < 100 )
                return notify_fail("��ĵ�����δ���ɣ�����ʹ�õ�Ӱ�ƣ�\n");        
        if (!weapon || weapon->query("skill_type") != "blade"
        || me->query_skill_mapped("blade") != "murong-daofa")
                return notify_fail("������û�е����޷�ʹ�õ�Ӱ�ƣ�\n");
        if((int)me->query_skill("xingyi-zhang", 1) < 100 )
                return notify_fail("����Ʒ���δ���ɣ�����ʹ�õ�Ӱ�ƣ�\n");  
        if((int)me->query("neili") < 600 )
                return notify_fail("�������������㣬����ʹ�õ�Ӱ�ƣ�\n");      
        if((int)me->query_skill("blade", 1) < 100 )
                return notify_fail("��Ļ�������������죬�����ڵ����м���ʹ�õ�Ӱ�ơ�\n");
        if((int)me->query_skill("strike", 1) < 100 )
                return notify_fail("��Ļ����Ʒ�������죬�����ڵ����м���ʹ�õ�Ӱ�ơ�\n");     
        msg = YEL"\n$N���һ��ʹ����Ӱ�ƣ����浶�ߣ������м����������Ʒ�һ����$n��"NOR;
       me->add("neili", -250); 
     me->add("jing", -100);
   me->add_temp("apply/dodge", d); 
me->add_temp("apply/damage", (i+j)); 
  me->add_temp("apply/attack", (i+j)/2); 
if (random(2)==0) target->start_busy(3);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        weapon->unequip(); 
     msg = YEL"$N�������ƣ����η�ת��\n"NOR;
	me->add_temp("apply/strike", i/2); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      msg = YEL"$N���ƻ��������η�ת��\n"NOR;
me->add_temp("apply/strike", -i/2); 
        weapon->wield(); 
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ((int)me->query_skill("murong-daofa", 1)> 280)
{
if (random(2)==0) target->start_busy(3);
      msg = YEL"$N���ƶ�ת�����η�ת��\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      msg = YEL"$N�����Ϲۣ����η�ת��\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
      msg = YEL"$N���˺�һ�����η�ת��\n"NOR;
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}

me->add_temp("apply/damage", -(i+j)); 
  me->add_temp("apply/attack", -((i+j)/2)); 
   me->add_temp("apply/dodge", -d); 
        me->start_busy(2);
        return 1;
}

// canyun // bren

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

int i; 
i = me->query_skill("xingyi-zhang", 1)/2;        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("������ͬ�ԡ�ֻ����ս���жԶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("ʹ�á�����ͬ�ԡ�ʱ˫�ֱ�����ţ�\n");

        if( (int)me->query_skill("xingyi-zhang", 1) < 180 )
                return notify_fail("��������Ʋ�����죬����ʹ�á�����ͬ�ԡ���\n");

        if( (int)me->query_skill("shenyuan-gong", 1) < 180 )
                return notify_fail("�����Ԫ���ȼ�����������ʹ�á�����ͬ�ԡ���\n");

        if( (int)me->query_dex() < 25 )
                return notify_fail("���������ǿ������ʹ�á�����ͬ�ԡ���\n");

        if (me->query_skill_prepared("strike") != "xingyi-zhang"
        || me->query_skill_mapped("strike") != "xingyi-zhang")
                return notify_fail("�������޷�ʹ�á�����ͬ�ԡ����й�����\n");                                                                                
      

        if( (int)me->query("neili") < 700 )
                return notify_fail("����������̫��������ʹ�á�����ͬ�ԡ���\n"); me->add("neili", -300);
        me->add("jing", -40);
        message_vision(CYN "\n$N˫��һ�꣬��˫��֮���γ�һ��ҫ�۵ġ�"HIW"����"CYN"����\n" NOR,me, target);

        me->add_temp("apply/strength", i);
        me->add_temp("apply/dexerity", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i);
if (random(3)==0) target->start_busy(3);
if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/3)
{ 
msg = HIR"$N˫��������ǰ�����λ�������㽫��"HIW"����"HIR"������$n��̴��Ѩ��"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);
        
msg = HIG"������$N������ƣ�����һ�������¶�����Ϯ��$n��С����"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);
 
msg = HIR"ֻ��$N���������������һԾ�����������������$n��ͷ����"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);

msg = HIY"$N�ڿ���һ����ת��Я��"HIR"����֮��"HIY"��, ˫�ư���$n�ĵ��"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);
        me->add_temp("apply/dexerity", -i);
        me->add_temp("apply/damage", -i); 
        me->add_temp("apply/strength", -i);
        me->add_temp("apply/attack", -i);   

}
else 
{
msg = HIR"$N˫��������ǰ�����λ�������㽫��"HIW"����"HIR"������$n��̴��Ѩ��"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);
        
msg = HIG"������$N������ƣ�����һ�������¶�����Ϯ��$n��С����"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);
 
msg = HIR"ֻ��$N���������������һԾ�����������������$n��ͷ����"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);
        me->add_temp("apply/dexerity", -i);
        me->add_temp("apply/damage", -i); 
        me->add_temp("apply/strength", -i);
        me->add_temp("apply/attack", -i);   

call_out("perform2", 3, me, target);  
} 
message_vision(YEL "\n$Nһʽ������ͬ�ԡ����ӵ����쾡�£�˫��һ�֣��������У����ı�����
\n" NOR,me, target);     
       me->add("neili", -400);
        me->start_busy(2+random(2));

        return 1;
}
int perform2(object me, object target)
{ 
   string msg;
   int i; 
 i = me->query_skill("xingyi-zhang", 1)/2; 
if (!me || !target) return 0;
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");  

        if( (int)me->query("neili", 1) < 300 )
               return notify_fail("���Ҫ�ٳ��ڶ��У�ȴ�����Լ������������ˣ�\n");
        me->add_temp("apply/strength", i);
        me->add_temp("apply/dexerity", i);
        me->add_temp("apply/attack", i);
        me->add_temp("apply/damage", i);
msg = HIY"$N�ڿ���һ����ת��Я��"HIR"����֮��"HIY"��, ˫�ư���$n�ĵ��"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);
 
msg = HIC"ֻ��$Nб���ת�������ĳ����ƣ�����������ֱָ$n��в��"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);

msg = HIW"$N����Ԫ�񹦷��ӵ����ޣ��û���������Ӱ����$nȫ�����ֹ�ȥ��"NOR;
COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK,msg);



 me->add("neili", -400);
        me->add_temp("apply/dexerity", -i);
        me->add_temp("apply/damage", -i); 
        me->add_temp("apply/strength", -i);
        me->add_temp("apply/attack", -i);  
        me->start_busy(2);

        return 1;
}



// renmu-daofa ȼľ����
// by hunthu 

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, string arg)
{
      object weapon, target;
      int i, j, z;       
     j = me->query_skill("ranmu-daofa", 1);
     z = me->query_skill("yijinjing", 1)/10;
      i = me->query_skill("yijinjing",1)/2;
      weapon = me->query_temp("weapon");  
      

      if( !target ) target = offensive_target(me);

      if( !target || !me->is_fighting(target) )
           return notify_fail("�����ġ�ֻ����ս���жԶ���ʹ�á�\n");

        if (!weapon || weapon->query("skill_type") != "blade"
       || me->query_skill_mapped("blade") != "ranmu-daofa")
           return notify_fail("�������޷�ʹ�������ġ�������\n");


        if(me->query_skill("ranmu-daofa", 1) < 160 )
                return notify_fail("���ȼľ������򲻹���ʹ���������ġ�������\n");

        if(me->query_skill("blade", 1) < 140 )
                return notify_fail("��Ļ�������������죬ʹ���������ġ�������\n");

        if( (int)me->query_skill("force") < 200 )
                return notify_fail("����ڹ��ȼ�������ʹ���������ġ�������\n");

        if( (int)me->query_str() < 30)
                return notify_fail("�������������ǿ����ʹ���������ġ�������\n");

        if( (int)me->query_dex() < 30)
                return notify_fail("�����������Ѹ�ͣ�ʹ���������ġ�������\n");
 
       if(me->query_skill("yijinjing", 1) < 170 )   
                return notify_fail("����׽��Ϊ�������޷�ʹ�á����ġ�������\n");  

       if(me->query_temp("ranmu")) 
       return notify_fail("����������ʹ�á����ġ�������\n"); 

       if (me->query_temp("fumo"))
        return notify_fail("����������ʹ�á���շ�ħ���񹦡�\n"); 

        if (me->query("neili") < 800)
        return notify_fail("�������������\n");
        if (me->query("jing") < 400)
        return notify_fail("��ľ���������\n");
        me->add("neili", -500);
        me->add("jing", -300);
        me->add_temp("apply/strength", z);
        me->add_temp("apply/attack", j); 
        me->add_temp("apply/damage", j);
        me->set_temp("ranmu", 1);
        call_out("check_fight", 1, me, z, j, i);
        message_vision(HIR"$N���ƺ�Ҿ��ͻȻ����һ��������������Ͻ�շ�ħ����\n���еĵ���ʱ����һ�Ż��棬������������$n����Χס��\n"NOR,me,target);
        return 1;
}

void remove_effect(object me, int j, int z, object weapon)
{
       
    me->add_temp("apply/strength", -z);
    me->add_temp("apply/attack", -j);
        me->add_temp("apply/damage", -j);
    me->delete_temp("ranmu");
    tell_object(me, HIR"�㡸���ġ�����������ϣ����ص���");
    tell_object(me, "��\n" NOR);
}

void check_fight(object me, int z, int j, int i)
{
    object weapon;      
object target;
string msg;
    if (!me) return;
    if(!objectp(weapon = me->query_temp("weapon"))
     || weapon->query("skill_type") != "blade")
    {
        remove_effect(me, j, z, weapon);
        return;
    }
    if (i < 1 || !me->is_fighting()) {
        remove_effect(me, j, z, weapon);
        return;
    }
if (! target) target = offensive_target(me);
if (target && random(6)==0)
{
msg = HIR "�������棬ԡ�����룡\n"NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
    call_out("check_fight", 1, me, z, j, i-1);
}

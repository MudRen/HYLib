// fumo.c

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, string arg)
{
           object target;
      string msg;                                   
      int i,z;
           i = (int)me->query_str();
           z = (int)me->query_skill("jiuyin-zhengong",1)/5+(int)me->query_skill("dafumo-quan",1)/4;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("����ħ��ֻ����ս���жԶ���ʹ�á�\n");
             
      if( objectp(me->query_temp("weapon")) )
      return notify_fail("��������ʹ�á���ħ����\n");
      
      if( (int)me->query_skill("jiuyin-zhengong",1) < 100 )
      return notify_fail("��ľ����湦������죬����ʹ�á���ħ����\n");  
      
      if( (int)me->query_skill("dafumo-quan",1) < 180 )
      return notify_fail("��Ĵ��ħȭ������죬����ʹ�á���ħ����\n");
      
      if(me->query_skill_mapped("force") != "jiuyin-zhengong")
                return notify_fail("��û�����þ����湦���޷�ʹ�á���ħ�����й�����\n"); 

      if (me->query_skill_prepared("unarmed") != "dafumo-quan"
      || me->query_skill_mapped("unarmed") != "dafumo-quan")
                return notify_fail("�������޷�ʹ�á���ħ�����й�����\n");                                                                                 

      if( (int)me->query_str() < 25 )
      return notify_fail("��ı�������ǿ������ʹ�á���ħ����\n");
      
      if( (int)me->query("neili") < 1300 )
      return notify_fail("�������̫��������ʹ�á���ħ����\n");
      
      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô��ħȭ�����⹥������ħ����\n");
       
      msg = HIW"$NͻȻȫ��������죬����Ĭ���ħ��,��������湦��ȫ�������ʹ���������һ����\n" NOR;
      
      message_vision(msg, me, target); 
      if ((int)me->query_skill("jiuyin-zhengong", 1) > 300) i = i * 2;
      if (i> 200) i=200;
      me->add_temp("apply/strength", i);
      me->set_temp("fumo",1);  
      me->add("neili", - 1000);
      me->add("jing", - 250);  
if (!me->is_busy()) me->start_busy(2);
      call_out("check_fight", 1, me, i, z);
      
      return 1;
}
void remove_effect(object me, int i)
{
//    i = (int)me->query_str() * 2;
    if(me->query_temp("fumo")){
    me->add_temp("apply/strength", -i);
    me->delete_temp("fumo");
    tell_object(me,HIY"��ġ���ħ���˹���ϣ������ɫ�ÿ����ˡ�\n"NOR);
     }
//    else tell_object(me, "��\n" NOR);
}
void check_fight(object me, int i, int z)
{
  

    if (!me) return;
    if (me->query_temp("weapon")
       || me->query_temp("secondary_weapon")
       || me->query_skill_mapped("unarmed"!="dafumo-quan"))
    {
        remove_effect(me, i);
        return;
    }
    if (z < 1 || !me->is_fighting()) {
        remove_effect(me, i);
        return;
    }
    call_out("check_fight", 1, me, i, z-1);
}

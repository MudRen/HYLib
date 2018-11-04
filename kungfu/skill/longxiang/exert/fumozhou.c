// /kungfu/skill/longxiang
// by dubei

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

void remove_effect(object me)
{
    if(me && me->query_temp("mz_lx")){
      me->add_temp("apply/strength", -me->query_skill("longxiang", 1)/6);
      me->add_temp("apply/dexerity", -me->query_skill("longxiang", 1)/6);
      me->delete_temp("mz_lx");
      tell_object(me,HIR"��ġ�������ħ�䡹�˹���ϣ��е��ھ��������ˡ�\n"NOR);
      }
}
void check_fight(object me)
{
    if (!me) return;

    if (me->query_skill_mapped("force"!="longxiang") ||
        !me->is_fighting() || me->query("neili") < 100
        || me->query_temp("weapon")) {
        	remove_call_out("remove_effect"); 
                remove_effect(me);
                }
    else call_out("check_fight", 1, me);
}

int exert(object me)
{

      int i, z;

      if( (int)me->query_skill("longxiang",1) < 120 )
          return notify_fail("��Ҫ�е��������ϵ�������������������á�������ħ�䡹��\n"); 
      if( (int)me->query_skill("lamaism",1) < 120 )
          return notify_fail("��������ķ��������޷����á�������ħ�䡹��\n");      
      if( !me->is_fighting() )
          return notify_fail("��������ħ�䡹ֻ����ս���жԶ���ʹ�á�\n");
      if (me->query_temp("weapon"))
           return notify_fail("��������ħ�䡹����������ʹ�������ģ�\n");
      if( (int)me->query("neili") < 800 || (int)me->query("max_neili")<1200  ) 
                return notify_fail("�������������\n");
      if( (int)me->query_temp("mz_lx") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");
      if(me->query_temp("honglian"))        
                return notify_fail("������ʹ�á������𡹡�\n");  
      if(me->query_temp("combat_yield"))
           return notify_fail("Ŷ���������������򲻻����ء�\n");

      i = me->query_skill("longxiang", 1)/6;
      z = me->query_skill("lamaism")/3;
      me->add("neili", -500);

      message_vision(HIR "\n$NͽȻ���Ծ��˫��������չ�����������𡸽�����ħ�䡹��������ӿ������һ��һ��ļ�ǿ��\n\n" NOR, me);
      me->add_temp("apply/strength", i);
      me->add_temp("apply/dexerity", i);
      me->set_temp("mz_lx", 1);
      check_fight(me);
      call_out("remove_effect", z, me);
      me->start_busy(1); 
      return 1;
}


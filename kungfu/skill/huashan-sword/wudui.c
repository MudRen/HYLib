// wudui.c ��˫�޶�

#include <ansi.h>

inherit F_SSERVER;
void remove_effect(object me, int improve);
int perform(object me, object target, int improve)
{
      object weapon;
      weapon = me->query_temp("weapon");

      improve =(int)me->query_skill("huashan-sword", 1) / 5;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("��˫�޶�ֻ����ս���жԶ���ʹ�á�\n");

//      if( (string)me->query("gender") != "Ů��" )
//      return notify_fail("ֻ��Ů���Ӳ����ó���˫�޶ԡ�\n");	

      if (!weapon || weapon->query("skill_type") != "sword"
       || me->query_skill_mapped("sword") != "huashan-sword")
      return notify_fail("������û�н����޷�ʹ����˫�޶ԣ�\n");             

      if( (int)me->query_skill("huashan-sword",1) < 100 )
      return notify_fail("��Ļ�ɽ����������죬����ʹ����˫�޶ԣ�\n");
      
      if( (int)me->query_skill("sword",1) < 100 )
      return notify_fail("��Ļ��������ȼ�����������ʹ����˫�޶ԣ�\n");  

      if( (int)me->query_skill("zixia-shengong", 1) < 60 )
      return notify_fail("�����ϼ�񹦵ȼ�����������ʹ����˫�޶ԣ�\n");
      if (me->query_skill_mapped("force") != "zixia-shengong")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
      if( (int)me->query("max_neili") < 800 )
      return notify_fail("�������̫��������ʹ����˫�޶ԣ�\n");
	if( (int)me->query_temp("leidong") ) 
		return notify_fail("���Ѿ������׶��������ˡ�\n");

      
      if( (int)me->query("neili") < 500 )
      return notify_fail("�������̫���ˣ��޷�ʹ�ó���˫�޶ԣ�\n");   

      if( me->query_temp("wudui") )
      return notify_fail("������ʹ����˫�޶ԡ�\n");
                                                                                 
      message_vision(HIC"\n$NͻȻʹ����ɽ������һʽ����˫�޶ԣ���ʽһ������ֻ��$Nͦ��
ֱ������ʽ��磬����֮���������������ף������ѽ�$nȫ�����֡�\n"NOR, me,target);
      me->start_busy(2);
      me->add_temp("apply/strength", improve);
      me->add_temp("apply/attack", improve);
      me->add_temp("apply/dodge", improve);
      me->set_temp("wudui", 1);
      me->add("neili", -200);
      me->add("jing", -50);
      me->start_call_out( (: call_other, __FILE__, "remove_effect", me, improve :), improve );
      return 1;
}

void remove_effect(object me, object target)
{
      int improve;
      improve =(int)me->query_skill("huashan-sword", 1) / 5;
      me->add_temp("apply/strength", - improve);
      me->add_temp("apply/attack", - improve);
      me->add_temp("apply/dodge", -improve);
      me->delete_temp("wudui");
}
	
//Cracked by Kafei
// huaxuan.c ����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
void checking(object me);
int perform(object me, object target)
{
      int lvl;
      
      
      lvl = ((int)me->query_skill("hamagong", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;
	  if( !target ) target = offensive_target(me);
	   if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("�����λ�������֮��ֻ����ս���жԵ���ʹ�á�\n");

        if( (int)me->query_temp("gb_huixuan") )
                return notify_fail("���Ѿ�ʹ�������λ�������\n");

        if( (int)me->query_skill("shexing-diaoshou", 1) < 150 )
                return notify_fail("��Ĺ��򲻹���졣\n");
       
	if ((int)me->query_skill("hamagong", 1) < 80)
		return notify_fail("��ĸ�󡹦��򲻹���\n");

      if( (int)me->query("max_neili") < 1000 )
      return notify_fail("�������̫��������ʹ�����λ�������\n");
      if( (int)me->query("neili") < 200 )
      return notify_fail("�������̫���ˣ�����ʹ�����λ�������\n");   
	        if( (int)me->query("neili") < 300 )
      return notify_fail("��ľ���̫���ˣ�����ʹ�����λ�������\n");   
      message_vision(HIC"\nͻȻ$NԾ�𣬴�����裬������Ծ��˫�ֽʳ�����,������֮��,��������������һֻ���ࡢһֻ��ӥ�������һ�㡣\n"NOR, me);
      me->add("neili", -100); 
      me->add("jing", -100);      
	  me->set_temp("gb_huixuan",lvl/15);
	  me->add_temp("apply/attack",lvl/3);
	  
		me->start_busy(1);
		remove_call_out("checking");
		call_out("checking", 1, me,lvl/3);

      return 1;
}
void checking(object me)
{
	int i;
      int lvl;
      
      
      lvl = ((int)me->query_skill("hamagong", 1)+(int)me->query_skill("shexing-diaoshou", 1))/2;

       if( !living(me) || me->is_ghost())
        {
                me->delete_temp("gb_huixuan");
				me->add_temp("apply/attack",-lvl/3);
                return ;
        }
		if( !me->is_fighting())
        {
				me->delete_temp("gb_huixuan");
		        message_vision(HIW"\n$N�������˿����������ε����ϵ��ھ����˻�����\n"NOR, me);
				me->add_temp("apply/attack",-lvl/3);
				
                return ;
        }
		if( me->query_temp("gb_huixuan") <= 0 )
        {
				me->delete_temp("gb_huixuan");
		        message_vision(HIW"\n$N�������˿��������н�ʧ����֮�⡣\n"NOR, me);
				me->add_temp("apply/attack",-lvl/3);
				
                return ;
        }

		me->add_temp("gb_huixuan",-1);
		call_out("checking", 1, me,lvl);
		return;
}

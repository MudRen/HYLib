// fumo.c ����ȭ perform ��շ�ħ

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, string arg)
{
           object target;
      string msg;                                   
      int i,z;
           i = (int) (me->query_skill("jingang-quan",1) / 3);
           z = (int)me->query_skill("yijinjing",1)/5+(int)me->query_skill("jingang-quan",1)/4;
      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("����շ�ħ��ֻ����ս���жԶ���ʹ�á�\n");
             
      if( objectp(me->query_temp("weapon")) )
      return notify_fail("��������ʹ�á���շ�ħ����\n");
      
      if( (int)me->query_skill("jingang-quan",1) < 180 )
      return notify_fail("��Ĵ���ȭ������죬����ʹ�á���շ�ħ����\n");
      
      if( (int)me->query_skill("yijinjing",1) < 180 )
      return notify_fail("����׽�ȼ�����������ʹ�á���շ�ħ����\n");  
      
      if(me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("��û�������׽�ڹ����޷�ʹ�á���շ�ħ�����й�����\n"); 

      if( (int)me->query_str() < 25 )
      return notify_fail("��ı�������ǿ������ʹ�á���շ�ħ����\n");
      
      if( (int)me->query("neili") < 1000 )
      return notify_fail("�������̫��������ʹ�á���շ�ħ����\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");
       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 
        
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");

      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");
	if( (int)me->query_temp("zuida") ) 
		return notify_fail(HIG"����Ϣ�����ڰ�������У�һʱ�᲻���׽�񹦡�\n"NOR);
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 

     if( (int)me->query_temp("jingang") ) 
	return notify_fail(HIG"���Ѿ��ڴ�����ͨ�˹����ˡ�\n");
      
      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
       
      msg = HIR"$NͻȻȫ��������죬����Ĭ���շ�ħ��,�����׽�" +
               "���񹦣�����һ���ɫ��ȫ�������ʹ���������һ����\n" NOR;
      
      message_vision(msg, me, target); 
      me->add_temp("apply/strength", i);
      me->set_temp("fumo",1);  
      me->add("neili", - 600);
      me->add("jingli", - 250);  
            
      call_out("check_fight", 1, me, i, z);
        me->start_busy(1);
      return 1;
}
void remove_effect(object me, int i)
{
    i = (int) (me->query_skill("jingang-quan",1) / 3);
    if(me->query_temp("fumo")){
    me->add_temp("apply/strength", -i);
    me->delete_temp("fumo");
    tell_object(me,HIR"��ġ���շ�ħ���˹���ϣ������ɫ�ÿ����ˡ�\n"NOR);
     }
//    else tell_object(me, "��\n" NOR);
}
void check_fight(object me, int i, int z)
{
  

    if (!me) return;
    if (me->query_temp("weapon")
       || me->query_temp("secondary_weapon")
       || me->query_skill_mapped("cuff"!="jingang-quan"))
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


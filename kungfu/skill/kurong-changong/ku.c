//perform ku,���ݡ��ִ�
//14/02/99

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if( (int)me->query_skill("kurong-changong", 1) < 180 )
                return notify_fail("��Ŀ���������Ϊ�������޷�ʹ�á��ݡ��ִ󷨣�\n");

      if (me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("�����ڹ��С��ݡ��ִ���\n");
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");
      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");

        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 

       if(me->query_temp("anran")) 
// updated ����->��Ȼ (by xbd)
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 

      if( (int)me->query_con() < 35 )
                return notify_fail("��ĸ���̫�ͣ������޷�ʹ�á��ݡ��ִ󷨣�\n");
 
      if( (int)me->query("neili") < 600 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó����ݡ��ִ󷨣�\n");   
    
      if( (int)me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ��ô�����ʹ�á��ݡ��ִ󷨣�\n");   
                                                                                
      if( me->query_temp("pf_ku")   )
                return notify_fail("���������á��ݡ��ִ󷨣�\n");
      if( me->query_temp("pf_rong")   )
                return notify_fail("���������á��١��ִ󷨣�\n"); 
      message_vision(GRN"\n$N�������,˫���ſ��⻮�������ջ��ڵ�����𡸿ݡ��ִ󷨣�������ɢȫ������ɢ��һ��������\n\n" NOR, me);
   me->start_busy(2);
      me->set_temp("pf_ku",1); 
      me->add_temp("apply/armor", me->query_skill("kurong-changong", 1)/3); 
      me->add_temp("apply/dodge", me->query_skill("kurong-changong", 1)/3);
      me->add("neili", -600);    
   call_out("remove_effect", me->query_skill("kurong-changong", 1)/2+10, me);
      return 1;
}

void remove_effect(object me)
{
      if(me){
      me->delete_temp("pf_ku");
      me->add_temp("apply/armor", -me->query_skill("kurong-changong", 1)/3); 
      me->add_temp("apply/dodge", -me->query_skill("kurong-changong", 1)/3);
      message_vision(WHT"\n$N�������������һ������ɢȥ������ȫ��������\n"NOR, me);    
      }
}

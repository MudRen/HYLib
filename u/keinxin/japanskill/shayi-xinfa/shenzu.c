//���� exert shenzu

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if( (int)me->query_skill("shayi-xinfa", 1) < 180 )
                return notify_fail("���ɱ���ķ���Ϊ�������޷�ʹ�á����㡹��\n");

      if (me->query_skill_mapped("force") != "shayi-xinfa")
                return notify_fail("�����ڹ��С����㡹��\n");
        if( (int)me->query_temp("shayi") ) 
                return notify_fail(HIR"���Ѿ���ʹ��ɱ���ˡ�\n");

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
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 

 
      if( (int)me->query("neili") < 600 )
                return notify_fail("�������̫���ˣ��޷�ʹ�ó�ɱ�⣡\n");   
    
      if( (int)me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ��ô�����ʹ��ɱ�⣿\n");   
                                                                                
      if( me->query_temp("shenzu")   )
                return notify_fail("���������������ˣ�\n");
        if( (int)me->query_temp("shayi") ) 
                return notify_fail(HIR"���Ѿ���ʹ��ɱ���ˡ�\n");

      message_vision(HIC"\n$N�ٶ�ͻȻ�ӿ죡����Ʈ��������������������ɱ�⣡\n\n" NOR, me);
      me->start_busy(2);
      me->set_temp("shenzu",1); 
      me->add_temp("apply/armor", me->query_skill("shayi-xinfa", 1)/3); 
      me->add_temp("apply/dodge", me->query_skill("shayi-xinfa", 1)/3);
      me->add("neili", -600);    
   call_out("remove_effect", me->query_skill("shayi-xinfa", 1)/2+10, me);
      return 1;
}

void remove_effect(object me)
{
      if(me){
      me->delete_temp("shenzu");
      me->add_temp("apply/dodge", -me->query_skill("shayi-xinfa", 1)/3); 
      me->add_temp("apply/armor", -me->query_skill("shayi-xinfa", 1)/3);
      message_vision(HIG"\n$N���ٶȻָ���������������ôƮ�������ˡ�\n"NOR, me);    
      }
}

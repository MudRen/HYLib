//snowman 04/01/99

#include <ansi.h>
void remove_effect(object me);

int exert(object me)
{    
      if( (int)me->query_skill("yijinjing", 1) < 199 )
                return notify_fail("����׽�ڹ���Ϊ�������޷�ʹ�á���ղ������񹦡���\n");

      if (me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("�����ڹ��С���ղ������񹦡���\n");

      if( (int)me->query_con() < 25 )
                return notify_fail("��ĸ���̫�ͣ������޷�ʹ�á���ղ������񹦡���\n");
 
      if( (int)me->query("neili") < 1000 )
                return notify_fail("��Ŀǰ������̫���ˣ��޷�ʹ�á���ղ������񹦡���\n");   
    
      if( (int)me->query("neili") < 3800 )
                return notify_fail("���������Ϊ��ô�����ʹ�á���ղ������񹦡���\n");   
        if( (int)me->query_temp("liuyun") ) 
                return notify_fail(HIG"���Ѿ���Ĭ������ˮ�����ˡ�\n");

        if( (int)me->query_temp("qzj_tong") ) 
                return notify_fail("���Ѿ�����ͬ�齣�ˡ�\n");

       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

      if( me->query_temp("fumo")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥������շ�ħ����\n");
      if( me->query_temp("jingang")   )
      return notify_fail("������ʹ�ô���ȭ�����⹥����������ͨ����\n");
	if( (int)me->query_temp("zuida") ) 
		return notify_fail(HIG"����Ϣ�����ڰ�������У�һʱ�᲻���׽�񹦡�\n"NOR);
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("���Ѿ����˾����湦���ˡ�\n");
        if( (int)me->query_temp("hslj/powerup") )
        	return notify_fail("���Ѿ������򷨹������ˡ�\n");
       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 
                                                                                
      if( me->query_temp("fanzhen")   )
                return notify_fail("���������á���ղ������񹦡���\n");
       
      message_vision(HIY"\n$NͻȻ����һ������Ŀ¶�ȹ⣬���΢Ц��������ת����ʹȫ�����±����������ǡ���ղ������񹦡���\n\n" NOR, me);
      me->start_busy(1);
//      me->set_temp("tjj_jie", 1);
      me->set_temp("fanzhen",1); 
      me->add_temp("apply/armor", me->query_skill("yijinjing", 1)/2); 
      me->add_temp("apply/attack", me->query_skill("yijinjing", 1)/3);
      me->add_temp("apply/damage", me->query_skill("yijinjing", 1)/2);
      me->add("neili", -500);    
      call_out("remove_effect", me->query_skill("yijinjing", 1)/2+20, me);
//      me->start_exert(me->query_skill("yijinjing", 1)/4+10, "����ղ������񹦡�");
      return 1;
}

void remove_effect(object me)
{
      if(me){
//      me->delete_temp("tjj_jie",1); 
      me->delete_temp("fanzhen");
      me->add_temp("apply/armor", -me->query_skill("yijinjing", 1)/2);
      me->add_temp("apply/attack",-me->query_skill("yijinjing", 1)/3);
      me->add_temp("apply/damage",-me->query_skill("yijinjing", 1)/2);
      message_vision(HIR"\n$N˫�ֺ�ʮ��ɢȥ��������ȫ�����µġ���ղ������񹦡���\n"NOR, me);    
      }
}

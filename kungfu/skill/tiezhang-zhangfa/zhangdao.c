// �Ƶ�
#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if(!target ) target = offensive_target(me);
        if(!target || !me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n"); 
        if( objectp(me->query_temp("weapon")) )
                return notify_fail("�������ֲ���ʹ�á��Ƶ�����\n");       
        if((int)me->query("neili") < 500  ) 
                return notify_fail("�������������\n");
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
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 

       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 

        if((int)me->query_temp("tzzf") ) 
                return notify_fail("���Ѿ����Ƶ����˹��С�\n");
        if((int)me->query_skill("tiezhang-zhangfa", 1) < 120 )
                return notify_fail("��������Ʒ���������죬ʹ�������Ƶ�������\n");
        if((int)me->query_skill("force") < 140 )
                return notify_fail("����ڹ��ȼ�������ʹ�������Ƶ�������\n");
        if((int)me->query_str() < 25 )
                return notify_fail("�������������ǿ����ʹ�������Ƶ�������\n");
        if( (int)me->query_skill("guiyuan-tunafa", 1) < 120 )
                return notify_fail("��Ĺ�Ԫ�����ɷ��ȼ���������ʹ�������Ƶ���������\n");

   if (me->query_skill_mapped("unarmed") != "tiezhang-zhangfa"
     ||me->query_skill_prepared("strike") != "tiezhang-zhangfa")
                return notify_fail("��û�а�������Ϊ�����мܺͱ�Ϊ�Ʒ���\n");


        skill = me->query_skill("tiezhang-zhangfa") ;
        skill = skill + me->query_skill("tiezhang-zhangfa")*2;
        skill = skill / 3+1;
        me->add("neili", -((int)me->query_skill("tiezhang-zhangfa",1)+100));

        message_vision(YEL "$NͻȻ��ɫ�԰ף�˫�ֲ������漴�������һ����һ˫������ɫ���ѩ�ף�����һ����ֵĹ�â��\n" NOR, me, target);
        me->set_temp("tzzf", 1);
        me->add_temp("apply/attack", skill);
        me->add_temp("apply/defense", skill*2);
        me->add_temp("apply/damage", skill*2);
        me->add_temp("apply/armor", skill*2);
                me->start_busy(2);     
        me->add("neili",-200);
        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill/2);
        return 1;

}

void remove_effect(object me, int amount)
{        
        int skill;
if (me)
{
        skill = me->query_skill("tiezhang-zhangfa") ;
        skill = skill + me->query_skill("tiezhang-zhangfa")*2;
        skill = skill / 3+1;
		me->delete_temp("tzzf");
                 me->start_busy(1);     
        me->add_temp("apply/attack", -skill);
        me->add_temp("apply/defense", -skill*2);
        me->add_temp("apply/damage", -skill*2);
        me->add_temp("apply/armor", -skill*2);
}
        message_vision(YEL "\n$N�Ƶ��˹���ϣ�˫���𽥻ָ���ԭ״��\n" NOR, me);        
}

// luiyun.c ����ˮ��

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
        object weapon;  
        string msg;
        int d_count, count, qi, maxqi, skill;

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

        if( !me->is_fighting() )
        return notify_fail("������ˮ�䡹ֻ����ս����ʹ�á�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");
        if ((int)me->query_temp("shield"))
                return notify_fail("���Ѿ����˻��������ˡ�\n");
        if( me->query_temp("yuxiao/tianwu") )
                return notify_fail("���������á�������衹�ķ���\n");

       if(me->query_temp("anran")) 
       return notify_fail("����������ʹ�á���Ȼ��������\n"); 
       if(me->query_temp("wdpowerup") )
       return notify_fail("����������ʹ�á��嶾�񹦡��ľ�����\n"); 
       if(me->query_temp("zhuihun/lpf")) 
       return notify_fail("������ʹ���嶾׷�깳֮�������硹\n"); 


    if( (int)me->query("neili") < 400 )
                return notify_fail("��������������ߣ�\n");

        if( (int)me->query_skill("xuantian-wuji", 1) < 60)
                return notify_fail("��������޼�������Ϊ����������ʹ������ˮ��! \n");

        if( (int)me->query_skill("strike", 1) < 80 )
                return notify_fail("��Ļ����Ʒ��������ң��޷�ʹ������ˮ�䣡\n");

        if( me->query_skill_mapped("strike") != "kunlun-zhang") 
                return notify_fail("��û�м��������ƣ��޷�ʹ������ˮ�䣡\n");
   if(me->query_skill_mapped("force") != "xuantian-wuji" )
	return notify_fail("��û���������޼���\n");

//        if( me->query_temp("apply/strength", 1) > 1 )
//                return notify_fail("�㻹��ʹ��̫����һ��Ĺ��򣬲���ʹ������ˮ�䣡\n");
       
//        if( me->query_temp("apply/dexerity", 1) > 1 )
//                return notify_fail("�㻹��ʹ��̫����һ��Ĺ��򣬲���ʹ������ˮ�䣡\n");
        
msg = HIR "$N���һ��ʹ���������еľ�ѧ������ˮ�䡹��������Ȼ���ӣ������ɨ���˵����ţ�\n" NOR;
        
        qi = me->query("qi");
        maxqi = me->query("max_qi");
        skill = (int) (me->query_skill("kunlun-zhang",1) / 3);
        count = (int) (me->query_skill("kunlun-zhang",1) / 3);
        d_count = (int) (me->query_skill("kunlun-zhang",1) / 5);

        if(qi > (maxqi * 0.1))
        {       
        message_vision(msg, me, target);

                me->add_temp("apply/strength", count); 
                me->add_temp("apply/dexerity", d_count);
                me->add_temp("apply/armor", count+100);
                me->add_temp("apply/damage", count+100);
                me->set_temp("liuyun", 1);
                //me->start_busy(3);     
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

                me->add("neili", -300);
        return 1;
        }
        else{
                msg = HIR "$Nƴ����������ʹ�����������е��ռ�����������ˮ�䡹�� ȫ�����һ����, �������ͬ���ھ�!\n" NOR;
                message_vision(msg, me, target);
                me->add_temp("apply/strength", count);
                me->add_temp("apply/dexerity", d_count);
                me->add_temp("apply/armor", count+100);
                me->add_temp("apply/damage", count+100);
                me->set_temp("liuyun", 1);
                //me->start_busy(3);     
                me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0 :), 2);
                me->add("neili", -300);

                return 1;


        }
}

void remove_effect(object me, int aamount, int damount)
{
        int d_count, count;
        count = (int) (me->query_skill("kunlun-zhang",1) / 3);
        d_count = (int) (me->query_skill("kunlun-zhang",1) / 5);
        
        if ( (int)me->query_temp("liuyun") ) 
        {
                me->add_temp("apply/strength", -count); 
                me->add_temp("apply/dexerity", -d_count);
                me->add_temp("apply/armor", -(count+100));
                me->add_temp("apply/damage", -(count+100));
                me->delete_temp("liuyun");
                tell_object(me, HIY "��ġ�����ˮ�䡹��������ϣ��������ջص��\n" NOR);
                me->start_busy(2);
        }
}


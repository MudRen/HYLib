// by sinb

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        int i;
        string msg;
        
        if (me->query_condition("killer") &&
            environment(me)->query("no_fight")) 
        {
                tell_object(me, HIR "�㷢��������񹦺����ܵ����ƣ���Ѫδ���Զ��ָ���\n" NOR );
        }
        else
        {
                tell_object(me, HIR "������񹦷�������Ч���о���ʧ����Ѫ�������ָ���\n" NOR );
                message_vision(HIW "$N�۾������������â�����ϵ��˿��漣��������ˡ�\n" NOR, me);
        
                me->set("eff_qi", me->query("max_qi"));     
                me->set("qi", me->query("eff_qi"));
                me->add("neili", -100);     
        }
        
        me->apply_condition("mingyu_qizu", duration - 1);
        
        if( duration < 1 ) 
        {
                me->delete_temp("qizu");
                message_vision(HIC "$N�ġ����㡹�湦������ϣ���ɫ��ʱһƬ�԰ס�\n" NOR, me);

                return 0;
        }
        return CND_CONTINUE;
}


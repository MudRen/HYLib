 //mimicat@fy4
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{
        int bonus;
        

        if( !target)
                return notify_fail("��Ҫ������Ϊ˭���ˣ�\n");
        
        if( !living(target) )
                return notify_fail(target->name() + "�Ѿ��޷�������ĺ����ˡ�\n");
                
        if( (int)me->query("neili") < 500 )
                return notify_fail("��ķ���������\n"); 
        if (target==me) {
                message_vision(
                YEL "$N˫���������裬£����ǰ����������ȵ������\n"
                MAG "���Ƶ�������$N˫�Ƽ�ӿ����������$Nͷ����Ȼ��������ʧ�� \n\n" 
                WHT "����ɢȥ��$N��ͷ�Ǻ�ˮ�����ƽ������ϡ� \n"NOR,
                        me); 
        } else
                message_vision(
                YEL "$N˫���������裬£����ǰ����������ȵ������\n"
                MAG "���Ƶ�������$N˫�Ƽ�ӿ����������$nͷ����Ȼ��������ʧ�� \n\n" 
                WHT "����ɢȥ��$N��ͷ�Ǻ�ˮ��$n�����ƽ������ϡ� \n"NOR,
                        me, target );  
        target->receive_curing("qi", 10 + (int)me->query_skill("magic")*8);
        target->receive_curing("jing", 10 + (int)me->query_skill("magic")*5);
        target->receive_curing("jingli", 10 + (int)me->query_skill("magic")*5);
        
        bonus = (me->query("combat_exp")-4000000)/15000;
        if (bonus<0) bonus=0;
        if (bonus>200) bonus = 200;
        
        me->add("neili", bonus-500);
        
        me->start_busy(2);
        return 1;
}    

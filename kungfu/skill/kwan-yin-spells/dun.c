 //by xiaolang
 //mimicat@fy4
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{       
        object room;
        int marktime,extra;
        extra=me->query_skill("kwan-yin-spells",1);
        

        if(extra<120) return notify_fail("��Ĺ����������䲻��������\n");      
        if( (int)me->query("neili") < 100 )
                return notify_fail("��ķ���������\n");                
        if (me->is_busy())
                return notify_fail("��������æ��\n");
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ������̫�飡\n");
        if( me->is_ghost())
                return notify_fail("����޷�ʹ������̫�飡\n");
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("�˵ز���ʹ��ʱ��ת����\n");
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
                || environment(me)->query("no_fly"))
                return notify_fail("�˵ز���ʹ��ʱ��ת����\n");  

if( !environment(me)->query("no_fight"))
return notify_fail("ֻ�а�ȫ�ص����ʹ��ʱ��ת����\n");  

if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR
       ||environment(me)->query("magicroom"))
return notify_fail("ֻ�а�ȫ�ص����ʹ��ʱ��ת����\n");           
        me->add("neili", -50);
        me->start_busy(1);
        message_vision( HIR "$N���˫�ۣ�˫�ֺ�һ���ں���ţ����ݣ�����һ������$N�Ƽ�ɳ���������¡�\n" NOR, me);
        room = environment(me);
        marktime=1500+random((me->query_skill("kwan-yin-spells",1)-80)*100);
        me->set_temp("timemark",base_name(room));
        me->set_temp("timemark_time",time()+marktime);
        return 1;
}   

 //mimicat@fy4
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{       
	string roomname;
        object room;
        int mana,extra;
        
        mana=me->query("neili");
        extra=me->query_skill("kwan-yin-spells",1);
        

        if(extra<120) return notify_fail("��Ĺ����������䲻��������\n");      
        if( (int)me->query("neili") < 100 )
                return notify_fail("��ķ���������\n");                
        if (me->is_busy())
                return notify_fail("��������æ��\n");
        if( me->is_fighting() )
                return notify_fail("ս�����޷�ʹ�ð����������䣡\n");
        if( me->is_ghost())
                return notify_fail("����޷�ʹ�ð����������䣡\n");
        if( !(roomname=me->query_temp("timemark")))
                return notify_fail("��û���趨����㡣\n");
        if( time()>me->query_temp("timemark_time"))
                return notify_fail("���趨�Ķ�����Ѿ�ʧЧ�ˡ�\n");
        if (domain_file(file_name(environment(me)))=="eren2")
                return notify_fail("�˵ز���ʹ�ð����������䡣\n");
        if(environment(me)->query("no_fly")||environment(me)->query("no_death_penalty")
                || environment(me)->query("no_fly"))
                return notify_fail("�˵ز���ʹ�ð����������䡣\n");  
         
        me->add("neili", -50);
        if( random(mana/5+extra*2) <100)      {
        message_vision( HIR "$N����˫�ۣ���ϥ���������������Ļ����ʲô��û�з�����\n" NOR, me);
                 return notify_fail("��ģ۰������������ʧ���ˡ�\n");      
                }
        message_vision( HIR "$N�׿���������š����������ۡ���ͻȻ֮�䣬$N��Ȼ��ʧ������Ӱ��\n" NOR, me);
        room = load_object(roomname);
        me->move(room);
        message( "vision", HIR "\n��Ȼ���һƬ��⣬"+me->query("name")+"���ƶ�����\n\n" NOR,
                room, ({ me }) );
        return 1;
}   

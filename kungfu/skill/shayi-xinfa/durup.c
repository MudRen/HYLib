 // void_sense.c
#include <ansi.h> 
inherit F_SSERVER;
int exert(object me, object target)
{
        int lvl,i,extra;
        object env, *inv;
        
        
        if(me->query_temp("ninjitsu_durup")) return notify_fail("�������Ѿ����ھ���ļ��ȿ���״̬�ˡ�\n");
        
        lvl = (int) me->query_skill("ninjitsu",1);
                
        if ( (int) me->query_skill("ninjitsu",1) <= 150)
                return notify_fail("�����������ߣ�\n");
        if( target != me ) 
                return notify_fail("��ֻ�������Լ������ϡ�\n");        
            
        if( me->query("neili") < 300 )
                return notify_fail("�������������\n");
        if( me->query("jing") <= 250 )
                return notify_fail("��ľ�������\n");
        me->add("neili", -300);
        me->receive_damage("jing", 250);
        
        extra=lvl/5;
        if (extra > 300) extra=300;
        me->add_temp("apply/dexerity",extra);
        me->set_temp("ninjitsu_durup",1);
        message_vision(HIM "$N���۹������룬�ƺ��Ѿ���һ��ǿ��ľ������������ƣ�����\n" NOR, me);
            
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,extra:), lvl/10);
        if( me->is_fighting() ) me->start_busy(2);
        return 1; 
}
void remove_effect(object me,int extra)
{
        me->add_temp("apply/dexerity", - extra);
        me->delete_temp("ninjitsu_durup");
        message_vision(HIW"$N������ָ������������Ѿ��ص�������״̬��\n"NOR,me);
        
}     

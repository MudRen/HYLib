 // �����Ŀ�ɱ��,�ڶ�ʱ���ڴ���ȵ��������,���ǲ���perform.
#include <ansi.h> 
inherit F_SSERVER;
int exert(object me, object target)
{
        int lvl,i,extra;
        
        lvl = (int) me->query_skill("ninjitsu",1);
        
        
        if ( (int) me->query_skill("ninjitsu",1) <= 150)
                return notify_fail("�����������ߣ�\n");
        
        if( target != me ) 
                return notify_fail("��ֻ�ܽ��ۿ�ɱ�������Լ������ϡ�\n");       
                
        if(me->query_temp("ninjitsu_berserk")) 
                return notify_fail("��������Ѿ�����������޶ȣ��޷����������ˡ�\n");
        
        if( me->query("neili") < 300 )
                return notify_fail("�������������\n");
        if( me->query("qi") <= 150 )
                return notify_fail("��ľ�������\n");
    
        me->add("neili", -300);
        me->receive_damage("qi", 150);
        extra=lvl/5;
        if (extra > 300) extra=300;
        me->add_temp("apply/strength",extra);
        me->set_temp("ninjitsu_berserk",1);

        message_vision(HIR "$N���һ����������Ҫ�γ�Ѫ��.\n"NOR,me);
        tell_object(me,WHT"    ��ֻ����������������,�޴���й������\n" NOR, me);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,extra:), extra*4);
        if( me->is_fighting() ) me->start_busy(2);
        return 1; 
}
void remove_effect(object me,int extra)
{
        me->add_temp("apply/strength", -extra);

        me->delete_temp("ninjitsu_berserk");
        tell_object(me, HIG"������������ƽ������\n"NOR);
}  

// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("��ֻ�ܽ���Ī�޳��������Լ������ϡ�\n");
        if( (int)me->query("neili") < 100 )     return
        notify_fail("�������������\n");
        if( (int)me->query_temp("wuchen") ) return 
	notify_fail("���Ѿ���ʩչ��Ī�޳����ˡ�\n");
	skill = me->query_skill("nodust-steps",1);
	if(skill < 150) return notify_fail("����޳���̫���ˣ�\n");
	 me->add("neili", -100);
        message_vision( HIR
"$N����һԾ��ʹ���޳������еģ�Ī�޳��ݣ���Ӱ��磬�޴����ڣ�\n" NOR, me);
        me->add_temp("apply/dodge", skill/7);
        me->set_temp("wuchen", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/7 :), skill/3);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("wuchen");
        tell_object(me, "��ģ�Ī�޳���ʩչ��ϣ������ȶ���������\n");
}
 

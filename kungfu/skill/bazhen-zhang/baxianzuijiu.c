// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int perform(object me, object target)
{
        int skill;
        if( target != me ) return 
	notify_fail("��ֻ�ܽ��۰�����ƣ������Լ������ϡ�\n");

        if( (int)me->query("neili") < 100 )     return
        notify_fail("�������������\n");
        if( (int)me->query_temp("zuixian") ) return 
	notify_fail("���Ѿ���ʩչ�۰�����ƣ��ˡ�\n");

	skill = me->query_skill("bazhen-zhang",1);
	if(skill < 100) return notify_fail("��������书̫���ˣ�\n");
if (skill > 200) skill=200;
	 me->add("neili", -100);
        message_vision( HIR
"$N��ҡ�Ұڣ�ٲȻ���������²��еģ۰�����ƣݣ���������ҡ�ڲ�����\n" NOR, me);
        me->add_temp("apply/defense", skill/3);
        me->set_temp("zuixian", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 
skill/3 :), skill/3);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/defense", - amount);
        me->delete_temp("zuixian");
        tell_object(me, "��ģ۰�����ƣ�ʩչ��ϣ������ȶ���������\n");
}
 

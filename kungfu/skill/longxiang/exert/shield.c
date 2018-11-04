// shield.c ������

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

int exert(object me, object target)
{
        int skill;
	int i = (int)me->query_skill("longxiang", 1);
	int t = i/40;

        if( target != me ) 
                return notify_fail("��ֻ����������������˻����񹦡�\n");

        if( (int)me->query("neili") < 100  ) 
                return notify_fail("�������������\n");
        if( (int)me->query_temp("longxiang") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");

        if( (int)me->query_temp("shielded") ) 
                return notify_fail("���Ѿ����˹����ˡ�\n");
        if( (int)me->query_temp("powerup") ) 
                return notify_fail("�������ñ�Ĺ�����\n");

        if( (int)me->query_skill("longxiang", 1) < 20)
                return notify_fail("������������������\n");

        skill = me->query_skill("longxiang");
        me->add("neili", -100);

	message_vision(
	HIR"$N����Ĭ������������ԣ��ֽ�Ħ��֧���ŭӡ������"+t+"��"+t+"��֮����\n" +
	HIW"$N����ɰʯ���ݣ���Ȼ������һ����ӣ�\n"
	NOR, me);
        message_vision(
        MAG "$N����һ�������������񹦣�����������������һ����������ȫ��\n" NOR, me);

        me->add_temp("apply/armor",  skill/2);
        me->add_temp("apply/defense",  skill/2);
        me->set_temp("shielded", 1);
        me->set_temp("longxiang", 1);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill/3 :), skill/3);

        if( me->is_fighting() ) me->start_busy(2);

        return 1;
}

void remove_effect(object me, int amount)
{
        int skill;
        skill = me->query_skill("longxiang");
        me->add_temp("apply/armor",  -skill/2);
        me->add_temp("apply/defense",  -skill/2);
        me->delete_temp("shielded");
        me->delete_temp("longxiang");
        tell_object(me, "��Ļ�����������ϣ��������ջص��\n");
}

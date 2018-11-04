// feiying.c ������Ӱ��

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, int amount);

int perform(object me, object target)
{
        int skill;

        if( !target ) target = me;
        if(!me->is_fighting())
                return notify_fail("������Ӱ��ֻ����ս����ʹ�á�\n");

        
        if( (int)me->query("neili") < 500  ) 
                return notify_fail("�������������\n");
        if( (int)me->query("jing") < 200  ) 
                return notify_fail("��ľ���������\n");
        if( (int)me->query_temp("feiying") ) 
                return notify_fail("���Ѿ������ÿ�����Ӱ���ˡ�\n");
        if( (int)me->query_skill("pixie-jian", 1) < 120 )
                return notify_fail("��ı�а������û���ɣ��޷�ʹ�ÿ�����Ӱ����\n");
        if( (int)me->query_dex() < 30  )
                return notify_fail("�����̫�ͣ�����ʹ�ÿ�����Ӱ����\n");
       
	if( (int)me->query_skill("kuihua-feiying", 1) < 50 )
		return notify_fail("��Ŀ�����Ӱ��������졣\n");

	if( (int)me->query_skill("kuihua-xinfa", 1) < 60 )
		return notify_fail("��Ŀ����ķ�������졣\n");

        skill = me->query_skill("kuihua-feiying") / 3;
        skill = skill + me->query_skill("pixie-jian");
        skill = skill / 4;
        me->add("neili", -200);
//        me->add("jing", -150);
        me->receive_damage("qi", 50);

        message_vision(
        MAG "ֻ��$N�������һ����ƾ�շ�����س��࣬����Ʈ������������Ӱ��һ�㡣\n" NOR, me);
        tell_object(me, MAG "��Ĭ�˿�����Ӱ�����ھ���й��������ƾ��̧��������\n" NOR);

        me->add_temp("apply/dodge", skill);
        me->set_temp("feiying", 1);

        me->start_call_out( (: call_other, this_object(), "remove_effect", me, skill :), skill);

        if( me->is_fighting() ) me->start_busy(1);

        return 1;
}

void remove_effect(object me, int amount)
{
        me->add_temp("apply/dodge", - amount);
        me->delete_temp("feiying");
        tell_object(me, MAG "��һ�������Ӱ���Ѿ�ʹ�꣬���ָֻ�������\n" NOR);
}


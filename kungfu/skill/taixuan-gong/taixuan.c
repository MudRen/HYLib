// kungfu/skill/taixuan-gong/taixuan
//����II���������䣩
//����lywin 2000/6/10

// powerup.c
#include <ansi.h>
inherit F_CLEAN_UP;
void remove_effect(object me, int amount);
int exert(object me, object target)
{
        int skill;
        if( target != me ) return
            notify_fail("��ֻ�ܶ��Լ���["+HIW+"����̫��"+NOR+"]\n"NOR,);
	if ((int)me->query_skill("taixuan-gong", 1) < 100)
		return notify_fail("���̫����̫���ˡ�\n");
        if( (int)me->query("neili") < 100 ) return
            notify_fail("�������������\n");
        if( (int)me->query_temp("powerup") ) return
            notify_fail("���Ѿ����˹����ˡ�\n");
        if( (int)me->query_temp("powerupxtg") ) return
            notify_fail("���Ѿ���������ˡ�\n");
        if( (int)me->query_temp("poweruptxg") ) return
            notify_fail("���Ѿ�����̫�����ˡ�\n");
        if( (int)me->query_temp("powerupkh") ) return
            notify_fail("���Ѿ����˿����޵й��ˡ�\n");
        if( (int)me->query_temp("jiuyin/powerup") )
        	return notify_fail("���Ѿ����˾����湦���ˡ�\n");
        if( (int)me->query_temp("hslj/powerup") )
        	return notify_fail("���Ѿ������򷨹������ˡ�\n");
        skill = me->query_skill("force");

        me->add("neili", -100);
        me->receive_damage("qi",0);

        message_combatd(
HIW"$NͻȻһ�����ʣ�����������һ��ʫ��������ϸ��֮�²��ɴ󾪣��������������µ��湦[̫����]��\n" NOR, me);
        me->add_temp("apply/attack", skill/3);
        tell_object(me,HIR"��Ĺ����������!\n"NOR);
        me->add_temp("apply/dodge", skill/3);
        tell_object(me,HIR"��ķ����������!\n"NOR);
        me->set_temp("powerup", 1);
        me->set_temp("poweruptxg", 1);
        me->add_temp("apply/strength",skill/20);
        tell_object(me,HIG"������������!\n"NOR);
        me->add_temp("apply/dexerity",skill/20);
        tell_object(me,HIG"����ٶ������!\n"NOR);
        me->add_temp("apply/constitution",skill/20);
        tell_object(me,HIG"��ĸ��������!\n"NOR);
        me->add_temp("apply/intelligence",skill/20);
        tell_object(me,HIG"������������!\n"NOR);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/3:),skill);
        if( me->is_fighting() ) me->start_busy(3);
        return 1;
}

void remove_effect(object me, int amount)
{
        int skill;
        skill = me->query_skill("force");
        me->add_temp("apply/attack", - skill/3);
        me->add_temp("apply/dodge", - skill/3);
        me->delete_temp("powerup");
        me->delete_temp("poweruptxg");
        me->add_temp("apply/strength",- skill/20);
        me->add_temp("apply/intelligence",- skill/20);
        me->add_temp("apply/constitution",- skill/20);
        me->add_temp("apply/dexerity" , - skill/20);

        tell_object(me, "���["+HIW+"����̫��"+NOR+"]������ϣ��������ջص��\n");
}


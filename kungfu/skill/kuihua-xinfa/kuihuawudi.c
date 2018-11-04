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
            notify_fail("��ֻ�ܶ��Լ���["+HIR+"�����޵й�"+NOR+"]\n"NOR,);
	if ((int)me->query_skill("kuihua-dafa", 1) < 200)
		return notify_fail("��Ŀ�����̫���ˡ�\n");
        if( (int)me->query("neili") < 500 ) return
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

        me->add("neili", -500);
        me->receive_damage("qi",20);

        message_combatd(
HIW"$NͻȻ���� ��!��!��!��!��Ц����,���������һ��[ȫ��������ȣ�Ʈ����ȥ��ֱ������]��\n" NOR, me);
        me->add_temp("apply/attack", skill/4);
        tell_object(me,HIR"��Ĺ����������!\n"NOR);
        me->add_temp("apply/dodge", skill/4);
        tell_object(me,HIR"��ķ����������!\n"NOR);
        me->set_temp("powerup", 1);
        me->set_temp("powerupkh", 1);

        me->add_temp("apply/strength",skill/25);
        tell_object(me,HIG"������������!\n"NOR);
        me->add_temp("apply/dexerity",skill/25);
        tell_object(me,HIG"����ٶ������!\n"NOR);
        me->add_temp("apply/constitution",skill/25);
        tell_object(me,HIG"��ĸ��������!\n"NOR);
        me->add_temp("apply/intelligence",skill/25);
        tell_object(me,HIG"������������!\n"NOR);
        me->start_call_out((:call_other,__FILE__,"remove_effect",me,skill/5:),skill);
        if( me->is_fighting() ) me->start_busy(4);
        return 1;
}

void remove_effect(object me, int amount)
{
        int skill;
        skill = me->query_skill("force");
        me->add_temp("apply/attack", - skill/4);
        me->add_temp("apply/dodge", - skill/4);
        me->delete_temp("powerup");
        me->delete_temp("powerupkh");
        me->add_temp("apply/strength",- skill/25);
        me->add_temp("apply/intelligence",- skill/25);
        me->add_temp("apply/constitution",- skill/25);
        me->add_temp("apply/dexerity" , - skill/25);
        tell_object(me, "���["+HIR+"�����޵й�"+NOR+"]������ϣ��������ջص��\n");
}


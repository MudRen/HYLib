#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string name() { return "baituo_poison"; }

string chinese_name() { return "���չ��߷�"; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + YEL"ȫ���Σ���ס�Ĳ�����ȫ�����������������\n"NOR, environment(me), me);
                tell_object(me, YEL "ȫ���Σ���ס�Ĳ�����ȫ���������������!�����ǰ��չ��߷۷����ˣ�\n" NOR );

        me->set_temp("apply/attack", -50);
  tell_object(me,HIG"��Ĺ�����������!\n"NOR);
        me->set_temp("apply/dodge", -50);
  tell_object(me,HIG"��Ķ�����������!\n"NOR);
        me->set_temp("apply/defense", -50);
  tell_object(me,HIG"��ķ�����������!\n"NOR);

        if (!me->is_busy())
        me->start_busy(3);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

string name() { return "shenlong_poison"; }

string chinese_name() { return "��������ɢ"; }

int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + HIY"���з�ʹ��ȫ��ס�Ĳ������ѳԵĶ���ȫ���³����ˡ�\n"NOR, environment(me), me);
                tell_object(me, HIY "���з�ʹ��ȫ��ס�Ĳ������ѳԵĶ���ȫ���³�����!��������������ɢ�����ˣ�\n" NOR );

        me->set("food",0);
        me->set("water",0);
        if (!me->is_busy())
        me->start_busy(8);
        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;


string name() { return "tiezhang_yang"; }

string chinese_name() { return "���ƴ�����"; }



int update_condition(object me, int duration)
{
        if( duration < 1 ) return 0;

 message("vision", me->name() + RED"�ƺ�һ����˫Ŀ͹�������������˿��Ѫ��\n"NOR, environment(me), me);
                tell_object(me, RED "��ֻ�����ﴦ�����٣�������ǧ�����һ���������ڡ���\n" NOR );
me->add("neili",-me->query("neili")/4);
        if (!me->is_busy())
        me->start_busy(3);


        me->apply_condition(name(), duration - 1);

        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}






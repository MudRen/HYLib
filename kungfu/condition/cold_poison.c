#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

int update_condition(object me, int duration)
{
        if( !living(me) ) {
                message("vision",HIY + me->name() + "ɪɪ������ȫ�����һ�㱡���İ�˪����\n"NOR, environment(me), me);
        }
        else {
if (userp(me))
{
                tell_object(me, HIY "��Ȼһ�ɺ������Ʊ�����ѭ���ֱۣ�Ѹ�����׵��������ţ����еĺ��������ˣ�\n" NOR );
                message("vision", HIY + me->name() + "ȫ���������ظ��ֱ�죬����Ƭ�̣��촽Ҳ���ˣ���ɫ����������ס�\n"NOR,
                                environment(me), me);
}
        }
        me->receive_damage("qi", 50);
        if(userp(me))
        me->receive_wound("jing", 20);
        else me->receive_wound("jing", 40);
        if(!me->is_busy()) me->start_busy(3);
        me->apply_condition("cold_poison", duration - 1);
        if( duration < 1 ) return 0;
        return CND_CONTINUE;
}

string query_type(object me)
{
	return "poison";
}



#include <ansi.h>
#include <login.h>

int update_condition(object me, int duration)
{
        if (duration < 1) {
           tell_object(me, HIY "��Ѳ��ʱ���ѹ�������Ĵ��鿴��ϣ����Ի�ȥ������task ok)�ˣ�\n" NOR);
            return 0;
        }
        if (!duration) return 0;
        me->apply_condition("wudu_xunshan2", duration - 1);
        return 1;
}

string query_type(object me)
{
        return "job";
}


// move.c

#include <ansi.h>
inherit SKILL;
void skill_improved(object me)
{
        int s;

        s = me->query_skill("move", 1);
        if( s%10==9 && (int)me->query("agi") < s/5) {
                tell_object(me, HIW "����������Ṧ������ٶ�����ˡ�\n" NOR);
                me->add("agi", 2);
        }
}

int learn_bonus()
{
	return 0;
}
int practice_bonus()
{
	return 0;
}
int black_white_ness()
{
	return 0;
}


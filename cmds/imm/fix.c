#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me)
{
    int i;
    object obj;

if (me->query_temp("apply/attack")<0)
{
me->set_temp("apply/attack",0);
}
if (me->query_temp("apply/defense")<0)
{
me->set_temp("apply/defense",0);
}
if (me->query_temp("apply/dodge")<0)
{
me->set_temp("apply/dodge",0);
}
if (me->query_temp("apply/dexerity")<0)
{
me->set_temp("apply/dexerity",0);
}
if (me->query_temp("apply/strength")<0)
{
me->set_temp("apply/strength",0);
}
if (me->query_temp("apply/damage")<0)
{
me->set_temp("apply/damage",0);
}
if (me->query_temp("apply/armor")<0)
{
me->set_temp("apply/armor",0);
}
if (me->query_temp("apply/intelligence")<0)
{
me->set_temp("apply/intelligence",0);
}
if (me->query_temp("apply/karey")<0)
{
me->set_temp("apply/karey",0);
}
if (me->query_temp("apply/percao")<0)
{
me->set_temp("apply/percao",0);
}
if (me->query_temp("apply/constitution")<0)
{
me->set_temp("apply/constitution",0);
}

    write(HIR"�ָ�״̬�ɹ�������SCORE�鿴��\n"NOR);
    return 1;
}

int help(object obj)
{
  write(@HELP
ָ���ʽ : fix

���ô�ָ�����ȫ�ָ���ҵĳ�ʼ��״̬��
HELP
    );
    return 1;
}


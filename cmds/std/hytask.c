// by Tie@fy3 hehe
#include <ansi.h>
int main(object me, string str)
{
	string output;
        if(me->is_busy())
        return notify_fail("��������æ��\n");

        me->add("jing",-20);
        me->start_busy(2);

    output = HIR"�� "HIW"���´���"HIR" ��"HIG" �����\n" NOR; 
    output += ""HIW"��������������������������������������������������������������������������\n"NOR"";   
    output += TASK_D->dyn_quest_list();  
    output += ""HIW"��������������������������������������������������������"HIG" ����II"HIW" ��������\n\n"NOR""; 

	me->start_more(output);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ: hytask
����ļ�: help tasks

���ָ����������֪Ŀǰ����������.

HELP
	);
	return 1;
}

// emote.c (Mon  09-04-95)

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string str)
{
if (me->query("combat_exp") < 500 )
{
        if ( ((int)time() - (int)me->query_temp("emote_time")) < 1 )
        return notify_fail("�л��ú�˵Ŷ��\n");
}

                     me->set_temp("emote_time", time());
    if (!str) {
        write(CYN"�㿴��������ḻ��\n"NOR);
        tell_room(environment(me), CYN+(string)me->name()+
		"����������ḻ��\n" +NOR, me);
        return 1;
    }
    write(CYN"��"+str+"\n"NOR);
    tell_room(environment(me), CYN+(wizardp(me)? "":"->")+(string)me->name()+
        str+"\n"+NOR, me);
    return 1;
}
 
int help(object me)
{
	write(@HELP
ָ���ʽ: emote <������>

���ָ�����������һ��ϵͳû��Ԥ��Ķ�����, ϵͳ�Ὣ��������
�����ּ��������������ʾ��������ͬһ���ط������￴. Ϊ�˱�����
������, ���������Ĵʾ�ǰ������ -> �Թ�����. (��ʦ���ڴ�
��.)

����: emote ����������
��ῴ��: ������������
�����˻ῴ��: ->��������������

����, ���Ӿ����������.

���ָ��: semote
HELP
	);
        return 1;
}

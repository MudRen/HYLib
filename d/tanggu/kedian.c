// /d/tanggu/kedian.c ϲ����ջ
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ϲ����ջ");
        set("long", @LONG
�������ٵ������˽��������ĵط��������������ġ�ϲ����ջ����һ¥��
�������ںȲ��������顣��С���������µ�æ������̨�����ϰ����������ڡ�
��̨������һ�����ӡ�
LONG );
        set("no_sleep_room",1);
        set("no_fight",1);
        set("exits", ([
                "north" : __DIR__"stxijie1",
		"up" : __DIR__"kedian2"
	]));

	set("objects", ([
                __DIR__"npc/xiaoer" : 1,
      	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ((string)me->query_temp("rent_paid")!="ϲ����ջ" && dir == "up" )
		return notify_fail(CYN"��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n"NOR);
	if ((string)me->query_temp("rent_paid")=="ϲ����ջ" && dir == "north")
		return notify_fail(CYN"��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ����˻���ΪС���ź����أ�\n"NOR);
	return ::valid_leave(me, dir);
}

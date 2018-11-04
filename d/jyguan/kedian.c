// Room: /jyguan/kedian.c
// YZC 1995/12/04,1998/10/08 Shark Edit  

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLINK+HIY"�м��ջ"NOR);
	set("long", @LONG
	����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡�����ؿ��̶�ѡ��������ţ���
������������������صķ������顣��С����������æ������ת���Ӵ��Ÿ�������
�Ŀ��ˡ��͵�����˴Ӳ�¶�棬��������˭���и��ָ����Ĳ²⡣ǽ�Ϲ���һ����
��(paizi)��
LONG
	);

	set("no_fight", 1);
	set("valid_startroom", 1);
        set("no_sleep_room",1);

	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ��ʮ���������޶��ۡ�\n",
	]));

	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));

	set("exits", ([
		"east" : __DIR__"townroad1",
		"up" : __DIR__"kedian2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{

	if ( !me->query_temp("rent_paid") && dir == "up" )
	return notify_fail("��С��һ�µ���¥��ǰ������һ���������ţ����ס����\n");

	if ( me->query_temp("rent_paid") && dir == "east" )
	return notify_fail("��С���ܵ��ű���ס���͹��Ѿ��������ӣ����᲻ס��������أ�
���˻���ΪС���ź����أ�\n");

	return ::valid_leave(me, dir);
}

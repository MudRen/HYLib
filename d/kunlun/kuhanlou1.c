// kuhanlou1.c (kunlun)
// Date: cck 6/6/97

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "�ຮ¥һ��");
	set("long", @LONG
�����ǿຮ¥�ĵײ㡣�ຮ¥�ṹ�򵥣�����ΪŨ�ܵ���ɼ��Χ��ȡ����
��÷�����Կຮ����֮�⣬����������ǰ��Ϊ�˼�����������ɵ��Ӷ����ģ�
���Ͽ���������ľ¥�����ƶ��ϣ��ƺ����޾�ͷ����ש���൱�ྻ����
���������˴�ɨ��
LONG
	);

	set("exits", ([
		"up" : __DIR__"kuhanlou2",
		"out" : __DIR__"shanlin1",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
		if (dir == "up" ) me->set_temp("count", 1);
	else 			 me->add_temp("count", -1);

	return ::valid_leave(me, dir);
}



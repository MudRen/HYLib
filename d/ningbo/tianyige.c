// Room: /u/beyond/ningbo/tianyige.c ��һ��
// Beyond make 1997.6.8
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "��һ��");
	set("long", @LONG
��һ�������ഫΪ���׾����С���һ��ˮ��������֮��֮˵������ȡ��
ˮ���֮�⡣������ʯΪɽ����ֲ��ľ����ǽ��һ��ͤ���Ա߳���С�Ŵ�Խ
��ʯ֮�䣬��ʯ��ʨ�����򡢻��ȶ��ɽ�ơ���������»�������١�֮
�͡��������룬��Ȥ���
LONG
	);

	set("exits", ([
"northwest" : __DIR__"qsddao",
		"west" : __DIR__"shilu",
                "southeast" : __DIR__"aywsi",
	]));
	setup();
        replace_program(ROOM);
}

// Room: /d/tangmen/qianliju.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ǧ���");
	set("long", @LONG
    ����һ����������ݣ���ӳ��һƬ÷���С�������Ȫ���ȣ����ﻨ�㣬����
�������š�ϸ�����и����������Ϊ���ƣ����Ӿ�������Ĵ���ɫ�󵭻ƣ�����ȥ
�ָк����ʡ�����������ŵ�������̫̫�ľ��ҡ�ʱ��ʱ�����ŵ���������̫̫���
���⡣
LONG
	);
	

	set("exits", ([
		
		
		"east" : __DIR__"huayuan12",
	]));
	set("objects", ([
		__DIR__"npc/tang" : 1,
	]));


	setup();
	replace_program(ROOM);
}


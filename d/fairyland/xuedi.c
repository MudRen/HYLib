// Room: /u/qingyun/jyzj/xuedi.c
// Written by qingyun
// Updated by jpei

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIW"ѩ��"NOR);
	set("long", @LONG
����ɽ����Ƨ��������ɽ�Ͼ��������ѩ��������һ�����µ��·�������
��ѩ����������ֱ�����˫Ŀ�������и�ѩ��(xuedui)��
LONG	);
	set("exits", ([
		"northeast" : __DIR__"xuedi1",
	]));
        set("item_desc", ([
		"xuedui"  : "��һ������ѩ�ѣ�������ݷ׷ɣ�ԭ����ũ�һ���Ĳݶѣ��������������˼ҡ�\n"
	]));
	set("outdoors", "kunlun");
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

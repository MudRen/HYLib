// Room: /d/sandboy/to_wudang.c

inherit ROOM;

void create()
{
	set("short", "С·");
	set("long", @LONG
һ���������ֵ�С·,һֱͨ�������é�ݴ���,Զ����ɽ����,��˵
�ľ����䵱ɽ,ɽ��ס������.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"trees2",
  "west" : __DIR__"to_wudang2",	
]));
set("outdoors","/d/jiangnan");

	setup();
	replace_program(ROOM);
}

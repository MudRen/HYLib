// Room: /d/jingzhou/baita1.c
// congw
inherit ROOM;

void create()
{
	set("short", "����һ¥");
	set("long", @LONG
�����Ǳ�����һ¥������������Ƹߣ������̲�סҪ�Ǹ�������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "up" : __DIR__"baita2",
  "out" : __DIR__"baita",
]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

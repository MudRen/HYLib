// Room: /d/jingzhou/baita2.c
// congw
inherit ROOM;

void create()
{
	set("short", "������¥");
	set("long", @LONG
�����Ǳ�������¥������������Ƹߣ�һ��΢�紵��,˵��������ˬ,
���ݳǵķ��Ҳ�����۵ס�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  
  "down" : __DIR__"baita1",
]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

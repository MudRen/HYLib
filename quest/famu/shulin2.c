// Room: /d/jindezheng/shulin2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
һƬ������,�������˺��һ����Ҷ.��һ��С����Լ��������,ǰ 
���ƺ�������һ������. 
LONG
	);
	set("no_sleep", 1);
	set("no_dazuo", 1);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/songque.c" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"zuanjiao",
  "north" : "d/city/jiaowai4",
//  "southwest" : __DIR__"x",
]));
	set("outdoors", "jindezheng");

	setup();
	replace_program(ROOM);
}

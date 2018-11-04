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
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/songque.c" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "northeast" : __DIR__"shulin1",
  "west" : __DIR__"zuanjiao",
  "south" : __DIR__"peifang",
  "southwest" : __DIR__"lu1",
]));
	set("outdoors", "/d/jindezheng");

	setup();
	replace_program(ROOM);
}

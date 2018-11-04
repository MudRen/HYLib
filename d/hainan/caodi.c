// Room: /d/hainan/caodi.c

inherit ROOM;

void create()
{
	set("short", "�ݵ�");
	set("long", @LONG
һƭ����ݵ�,¶��ҷ�,ʱ�а�ɫС�ô�����´ڹ�.�ʵ��׷�,΢ 
������,��ǰ��������.ǰ�治Զ�ĵط���һ��С·. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"road1",
  "southwest" : __DIR__"outtree2",
]));
	set("outdoors", "/d/hainan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/hudie.c" : 2,
]));

	setup();
	replace_program(ROOM);
}

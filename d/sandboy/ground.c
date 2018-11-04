// Room: /d/sandboy/ground.c

inherit ROOM;

void create()
{
	set("short", "ɹ�ȳ�");
	set("long", @LONG
���ົʵ��һƬɹ�ȳ�,���߶��˼������ݶ�,�Ա�һ����µ�,������
�ü��ٽ���.�򶫿�,��һ�Ÿߴ������,�����л��˼�.
LONG
	);
set("valid_startroom",1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"home",
  "east" : __DIR__"undertree",
  "west" : __DIR__"daotian2",
  "south" : __DIR__"road2",
]));
	set("outdoors", "/d/jiangnan");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/kid.c" : 1,
  __DIR__"npc/kid1.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

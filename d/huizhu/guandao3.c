// Room: /d/huizhu/guandao3.c

inherit ROOM;

void create()
{
	set("short", "�ٵ�");
	set("long", @LONG
���������Ӿ���������صĹٵ��������Ǿ��Ƿ�������ͨ������
�ء�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man1.c" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guandao2",
  "northeast" : __DIR__"guandao4",
]));

	setup();
	replace_program(ROOM);
}

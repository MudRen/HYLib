// Room: /d/sandboy/inreed1.c

inherit ROOM;

void create()
{
	set("short", "«έ����");
	set("long", @LONG
���ϰ���Ʈ��,ͷ��ѩ�׵�«�����Ʈɢ,���������������,����«έ
��������,����һ��,������һ����.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"inreed",
]));
	set("outdoors", "/d/jiangnan");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dayan.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

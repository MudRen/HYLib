// Room: /d/yandang/jiudian.c

inherit ROOM;

void create()
{
	set("short", "С�Ƶ�");
	set("long", @LONG
����һ������ˮ�Ʒ���С��,���ŷ������ڶ�����,���������,��
����·,������������,���׿յ��ϴ���һ������,���������������,��
�˶���,С��û������,ֻ������ǰ������һ��'��'�ֵĲ���.
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/girl.c" : 1,
  __DIR__"npc/tianlaodie.c" : 1,
]));
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"shanxia",
  "south" : __DIR__"xiaolu",
]));
	set("outdoors", "/d/yandang");

	setup();
	replace_program(ROOM);
}

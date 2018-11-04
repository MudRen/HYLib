// Room: /d/yandang/jiedao.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
ܽ����Ľֵ�һ����ƽƽ����,��Ȼ��ֵ��������������ʷ,����
���˴������ֵ��߹�,��ʯ��·����һ��û��,Ψ������ǳǳ�Ľ�ӡ��˵
�Ź�ȥ��һ��.�ֵ��Ķ�������ӻ���.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/xieyin.c" : 1,
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"jiedao1",
  "north" : __DIR__"jiedao2",
  "east" : __DIR__"cahuopu",
   //"west" : "/u/legato/simiao",
]));
	set("outdoors", "/d/yandang");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

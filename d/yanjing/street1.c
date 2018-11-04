// Room: /d/yanjing/street1.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
ʢ���Ľ�Ķ���,��������,��������,ÿ��һ�ӶӵĽ������֮ʱ,
���ֵĽֵ���ʱ���һƬ����,�����ߵĻ�Ȯ�����ҷͽ�.��ֵ��Ķ���
��һ��ҩ��,�������˻�ͦ��.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/person.c" : 1,
]));
	set("outdoors", "yanjing");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"street4",
  "south" : __DIR__"street",
  "east" : __DIR__"yaopu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

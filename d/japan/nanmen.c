// Room: /d/japan/nanmen.c

inherit ROOM;

void create()
{
         set("short", "������");
	set("long", @LONG
����ǰ����һ���ǳ�,�ߴ�ĳ�ǽΧ���˼����һƬ�ռ�.��������
�׿��ı�ʿ�ڳ��ſ�վ�ø�ľ���Ƶ�,�м���������ʿ��װ���˲�ʱ���
���˵İ���.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"jiedao",
  "south" : __DIR__"road1",
]));
         set("objects", ( [ /* sizeof() == 1 */
              __DIR__"npc/chengwei":3,
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/jindezheng/street3.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
�����ֵ��ӱ�����,���˵ĵ�������,����Ǹ�������,ֻ���㶫 
�������Ǹ�����,����һ�ҹŶ���,�Ӵ�����,�ɾͳ�������. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"gudong-shop",
  "south" : __DIR__"shulin1",
  "north" : __DIR__"street2",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingfuren.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

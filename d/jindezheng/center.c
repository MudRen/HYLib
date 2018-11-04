// Room: /d/jindezheng/center.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������,�ֵ��������Ϲ�,�˴��������˾͸�����,�������� 
��,���Ż���������Ů,�����˹͵Ľŷ�......��������. 
LONG
	);
	set("no_clean_up", 0);
	set("valid_startroom", "1");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"street1",
  "south" : __DIR__"street2",
]));
	set("outdoors", "/d/jindezheng");
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/renfanzi.c" : 1,
  __DIR__"npc/kid.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/jindezheng/street2.c

inherit ROOM;

void create()
{
	set("short", "�ֵ�");
	set("long", @LONG
����һ����ʯ���̳ɵĽֵ�,ȫ�����صĴ������˶����˴�������, 
żȻ����Ⱥ��,�㻹�ܼ����𷢱��۵�����.�ֵ���������һ�Ҳ��,�� 
���������˻�ͦ��. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"tea-room",
  "north" : __DIR__"center",
  "south" : __DIR__"street3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/dadao.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/sandboy/inreed.c

inherit ROOM;

void create()
{
	set("short", "«έ����");
	set("long", @LONG
���涼�����������«έ,����ɫ��«έ���Ͽ����˰�ɫ��«��,΢�紵
��,«���������.������һƬ����,�����ĺ�ˮ��û������.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"reed",
  "west" : __DIR__"inreed1",
  "east" : __DIR__"inreed2",
]));

	setup();
	replace_program(ROOM);
}

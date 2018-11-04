// Room: /d/sandboy/yuanzi.c

inherit ROOM;

void create()
{
	set("short", "СԺ��");
	set("long", @LONG
һ���߸ߵ��ż���Ժ�Ӻ����ݸ��˿���.���������������Сé��,��
����������д������˵���ζ,�����é���в�ʱ��������������.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "south" : (: look_door,     "south" :),
]));
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"cook",
  "west" : __DIR__"pigroom",
  "south" : __DIR__"home",
  "north" : __DIR__"room1",
]));

	setup();
	replace_program(ROOM);
}

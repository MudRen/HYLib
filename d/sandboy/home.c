// Room: /d/sandboy/home.c

inherit ROOM;

void create()
{
	set("short", "��");
	set("long", @LONG
��ǰ��һ����,һȦʯͷ�����Χǽ������Χ������,��ϸ��ʱ,����
���������ݾ����ݶ�,Χǽ�ϳ�������.Χǽ��������һȦī��ɫ��̦޺.
����ľ���Ű�����.
LONG
	);
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "north" : (: look_door,     "north" :),
]));
	set("outdoors", "/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"yuanzi",
  "south" : __DIR__"ground",
]));

	setup();
	replace_program(ROOM);
}

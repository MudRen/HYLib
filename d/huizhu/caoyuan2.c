// Room: /d/huizhu/caoyuan2.c

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
�������������ݣ��������糿��¶�顣��ͬһ����ɫ�Ĵ�̺�Ӱ㡣
��Ⱥ��ţ��������̺�������ŵĵ�㻨�䡣����Ĺ�������Ӷ�����
��Ƥ�ޣ����Ų�ԭ�ϵ����衣
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/sheep.c" : 2,
]));
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"caoyuan",
]));
    set_temp("wayao2",2);
	setup();
	replace_program(ROOM);
}

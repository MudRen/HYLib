// Room: /d/huizhu/caoyuan1.c

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
���۵���ݾͲ��ڽ��£����ϸ���Ʈ��������Ĺ��������С������
��Ƥ��������ţ��Զ����ɽɽ���߲����ʣ�һ�ߵĺ�ˮ�ھ����Ĳ�������
ͷ��ӥ���ų���ڿ��л���������
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/ox.c" : 1,
]));
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"caoyuan",
    "north" : __DIR__"caoyuan4",	
]));
	set("outdoors", "huizhu");
	set("no_clean_up", 0);
    set_temp("wayao2",2);
	setup();
	replace_program(ROOM);
}

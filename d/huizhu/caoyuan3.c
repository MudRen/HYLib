// Room: /d/huizhu/caoyuan3.c

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
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"caoyuan",
]));
    set_temp("wayao2",2);
	setup();
	replace_program(ROOM);
}

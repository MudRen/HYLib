// Room: /d/yandang/nvkefang.c

inherit ROOM;

void create()
{
	set("short", "Ů�ͷ�");
	set("long", @LONG
������пͷ�,����Ĳ�������̫����.��ǽ������������,������
��ѩ�׵�����,���ϰ����廨�����.����Ӻ���Ĵ������������,һ
�ҽ�ů,��ǰ����ױ̨�ϵĻ�ƿ�л����ż�֦÷��.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yuanluo",
]));
	set("outdoors", "/d/yandang");
	set("no_magic", 1);
	set("no_fight", 1);
	set("sleep_room", 1);
	set("hotel",1);

	setup();
	replace_program(ROOM);
}

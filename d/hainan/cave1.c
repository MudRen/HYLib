// Room: /d/hainan/cave1.c

inherit ROOM;

void create()
{
	set("short", "Сɽ��");
	set("long", @LONG
�ıߵ���ʯ��ᾲ�ƽ,���Ĺ����Ѿ������������ȫ��ס��.��ǰ 
����ڵ�һƬ.ͨ��ʮ����խ,��ֻ��С�ĵ�������ʯǰ��. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"cave",
  "northwest" : __DIR__"cave3",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/mouse.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

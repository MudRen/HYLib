// Room: /d/hainan/shatan.c

inherit ROOM;

void create()
{
	set("short", "ɳ̲");
	set("long", @LONG
��׵�ϸɳ����һƥ��ɫ��˿��,����Ľ�������.һ���ǲ������� 
�Ĵ�,΢�̵ĺ������к����ڷ���.��һ�߾�����᾵���ʯ,���������� 
���ĺ�ˮ��ˢ,�Ѿ����ʮ�ֹ⻬. 
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"npc/girl.c" : 1,
  __DIR__"obj/hailuo.c" : 1,
  __DIR__"obj/beike1.c" : 1,
		__DIR__"npc/man5":1,
		__DIR__"npc/man1":1,			
]));
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"haibian.c",
  "west" : __DIR__"underhill",
  "south" : __DIR__"shatan",
]));

	setup();
	replace_program(ROOM);
}

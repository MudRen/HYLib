// Room: /d/sandboy/well.c

inherit ROOM;

void create()
{
	set("short", "ˮ��");
	set("long", @LONG
һ�ڹ��ϵ�ˮ��,�������СС��ͤ��,һ�����װ�ھ����Ϸ�,��ͷ
��ʱ,�峺�ľ�ˮ��ӡ�����Ӱ��,ɭɭ�ĺ�����ˮ����ð����.
LONG
	);
	set("no_clean_up", 0);
set("outdoors","/d/jiangnan");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"huangni",
  "south" : __DIR__"undertree",
]));

	setup();
	replace_program(ROOM);
}

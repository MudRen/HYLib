//Cracked by Kafei
// Room: /d/xixia/piandian2.c

inherit ROOM;

void create()
{
	set("short", "ƫ��");
	set("long", @LONG
�����ǻ����޹��ߵ�ƫ���������ֵ��ʱ��Ϣ�ĵط�, ͬ��Ҳ
���󣬵����˺ü������ӣ�����ȴ���ࡣ
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qingong.c",
  "south" : __DIR__"yushufang",
]));
	set("objects", ([
		__DIR__"npc/shiwei" : 3,
	]));
	setup();
	replace_program(ROOM);
}

//Cracked by Kafei
// Room: /d/xixia/piandian.c

inherit ROOM;

void create()
{
	set("short", "ƫ��");
	set("long", @LONG
�����Ǻ󹬱��ϵ�ƫ���Ȼ����ȴ�����룬�м������Ӻ�һ
�����ӣ�����Ů����Ϣ�ĵط���
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"garden",
  "east" : __DIR__"hougong",
]));
	set("objects", ([
		__DIR__"npc/gongnu" : 2,
	]));
	setup();
	replace_program(ROOM);
}

// Room: /d/yandang/shanxia.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
·�濪ʼ��᫲�ƽ,̧ͷ��,�ߴ���㵴������ͷ��,����Ҫ����
��һ��,�ٹ�ȥ��Ҫ��ɽ��,����ǰ�������ɽ��,���鲻�Խ���ҡ��ҡ
ͷ,���Լ�,�ܲ��ܹ�ȥ��?
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiudian",
  "westup" : __DIR__"shanlu",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/yandang/shandong1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������鴫,��һƬ�߸ߵ͵͵�ɽ����,����������Ʈ��,
������ϸ����ʱ,ȴһ������.���бȽϳ�ʪ,ʱ��������ˮ��Ӷ�����
������,'��'��һ��.������͸�춴,�����Ǻ��鶴.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "out" : __DIR__"shanlu8",
  "westup" : __DIR__"shandong2",
  "eastup" : __DIR__"shandong3",
]));

	setup();
	replace_program(ROOM);
}

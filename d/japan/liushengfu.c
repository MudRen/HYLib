// Room: /d/japan/liushengfu.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������ʿ����Ӣ�۵ļ�,�����ĵ����ǼҴ�,��˵�Ѿ����˾����
��������ĵز�.���Ű�ʦ���˸����������ﲻ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "japan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"xuanguan",
  "north" : __DIR__"jiedaoe3",
]));

	setup();
	replace_program(ROOM);
}

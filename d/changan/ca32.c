// Room: /d/changan/ca32.c
// This is a room made by roommaker. write by Fan. :)

inherit ROOM;

void create()
{
	set("short", "��ٵ�");
	set("long", @LONG
����һ��������ֱ�Ĺٵ�������ݵ���ʮ���ۡ�����ͨ����
����������ֱ�ﳤ���ǡ�
LONG
);
	set("no_clean_up", 0);
	set("outdoors", "changan");
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dongmen",

           "south" : "/d/quanzhen/ximen",
]));

	setup();
	replace_program(ROOM);
}

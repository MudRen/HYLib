// Room: /d/yandang/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "��ڷ�");
	set("long", @LONG
ԭ��Ϸʨ��.�ڼ�ʯ�ƴ���,����ʨ��.�����忴,����һ����ñ��,
��˽�����ڷ�.���120����,��150����.�屳����ʯ���,�������
����.�ڷ���,��ɽ����Ϊ��嶴.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"shanlu3",
  "southdown" : __DIR__"shanlu",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guest.c" : 2,
]));

	setup();
	replace_program(ROOM);
}

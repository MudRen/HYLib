// Room: /d/yandang/xiyaotai.c

inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
����һƬƽƽ������ʯ��,�������,��������,�����±���,�д˴�
Ψһ��һ�ù���,֦Ҷ��ï,���µ��������Ӻ�����,���м�ֻ��������
�����ر���.�򶫿ɵ�������.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dongwai",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/baiyi_ren.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

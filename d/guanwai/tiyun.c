// Room: /d/guanwai/tiyun.c

inherit ROOM;

void create()
{
	set("short", "���Ʒ�");
	set("long", @LONG
�����山����һɽ�壬�弹���ݺ��ٲ���Զ�����ڰ����ƣ��������ݣ�
�������Ʒ塣
LONG
	);
	set("outdoors", "guanwai");
	set("exits", ([ /* sizeof() == 3 */
//  "north" : "/u/skyzxm/huayuan",
  "south" : __DIR__"yuzhu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

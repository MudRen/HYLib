// Room: /d/yanjing/yanjinyuan/yanjinyuan.c

inherit ROOM;

void create()
{
	set("short", "�о�Ժ");
	set("long", @LONG
��ǰ��һ�����ݣ����г��������֣���������ߣ��������ţ�ǽ�����ɣ�
����һ��СС�ĳǱ�����Χ���ɭɭ����ס�����⣬Զһ���ľ���Ϳ������ˡ�
�������������ء�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "yanjing");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shouwei.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

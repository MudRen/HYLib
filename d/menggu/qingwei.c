// Room: /d/menggu/qingwei.c

inherit ROOM;

void create()
{
	set("short", "����Ӫ");
	set("long", @LONG
����Ӫ��רΪ������ľ����������������,������ľ���Զ���ӵܻ�
�书��ǿ��,��λ��һ��ʿ��֮��.�ɹ��˳�����ʵ,����Ӫ���г���Щ��ǹ��
��û��Щʲô�ݳ޶���.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/qingwei2.c" : 2,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"road2",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/menggu/boershu.c

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
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

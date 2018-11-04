// Room: /d/huizhu/caoyuan.c

inherit ROOM;

void create()
{
	set("short", "��ԭ");
	set("long", @LONG
�����Ĳ�ԭ���������ǰ����Ⱥ��ţ��Χ��������ߣ�Զ����ؽ���
����ʱ�д�Ƭ���̳�ӿ��ɲ�Ǽ����������أ����Ǹ����ʱ�����ֵ�
����硣
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/huizhushaonv.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 4 */
  "southup" : __DIR__"xiepo",
  "north" : __DIR__"caoyuan1",
  "west" : __DIR__"caoyuan2",
  "east" : __DIR__"caoyuan3",
]));
    set_temp("wayao2",2);
	setup();
	replace_program(ROOM);
}

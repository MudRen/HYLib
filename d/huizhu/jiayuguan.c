// Room: /d/huizhu/jiayuguan.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
�����س��ǻ������ض��ģ��������ߣ��������ݳǷ��綷.Զ����
Į��ɳ��������ա����˹ؾͲ�������ԭ���档�����ؾ������е�����
���صı�����ϸ�̲��ų������Ա��
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man2.c" : 3,
]));
	set("no_clean_up", 0);
	set("outdoors", "huizhu");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"guanwai",
  "east" : __DIR__"guandao1",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/yanjing/cave1.c

inherit ROOM;

void create()
{
	set("short","��������");
	set("long", @LONG
���ߵĵ���ͻȻ��ʧ,��ǰһ��,���ǵ��˸��յ���������֮��.
����Ŀ����лص���Ѫ����,���ߵ��ҽ�������ϡ���Ÿ���Ӱ,���
�Ǽ��߰׹�����.
LONG
	);
	set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/meichaofeng.c" : 1,
//  "/d/menggu/npc/clone/clothbaigu.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"didao1",
]));

	setup();
	replace_program(ROOM);
}

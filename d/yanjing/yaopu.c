// Room: /d/yanjing/yaopu.c

inherit ROOM;

void create()
{
	set("short", "�ش�ҩ��");
	set("long", @LONG
�����������,һ�����ŵĽ�������"�ش���",һ���Ͻ�Сҩ��«����
����ҡҡ�λ�,������һ�ﳤ�Ĺ�̨,����Сҩ�ư��ڹ�̨֮��,�����Ǹ�
�ߵ�ҩ��,һ����С�ɵĳ������Ǹ�����ҩ��.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhaosanqian.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"street1",
]));

	setup();
	replace_program(ROOM);
}

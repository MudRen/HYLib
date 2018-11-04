// Room: /d/hainan/ontree.c

inherit ROOM;

void create()
{
	set("short", "С����");
	set("long", @LONG
���С����Ȼ���ܹ���ȫ�е��������.������ɽ��һ�ߵ�С����
�Ѿ��ڲ��ϱ���.��ʯ�����ĵ���ȥ,�����ǰ��һ��Сɽ��.��Ҫ����
�������ܽ�ȥ.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/wudang/npc/monkey.c" : 1,
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"underhill2",
  "enter" : __DIR__"cave",
]));
	set("outdoors", "/d/hainan");
	set("item_desc", ([ /* sizeof() == 1 */
  "С��" : "С�����ڳ��ܲ����������,��Ҫ����,�����
�����ȥ�Ļ�,���ǸϿ���(climb)��ȥ��!
",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/yanziwu/xiaoting.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ��С��,���䲻��,���õ�Ҳ���¡������ķ��㣬������Ƣ��
ֻ��ǽ�Ϲ��ż�������,������Ϊ����,���ڲ�ס��������֮����������
�ܾ��ɵذ���Щ����(table)������(chair)��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"qinyun",
  "north" : "/u/skyzxm/syj",
  "east" : __DIR__"cuixia",
  "south" : __DIR__"chufang",
]));
	set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/gao" : 2,
  __DIR__"obj/cha" : 1,
  __DIR__"npc/susu" : 1,
]));
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 2 */
  "chair" : "һֻ������ƵĿ��Σ�����ȥҡҡ�λΣ������Ү��
",
  "table" : "һ�ŵ��ŵ���ľС�����������ˮ���̺��������ߡ�
",
]));

	setup();
	replace_program(ROOM);
}

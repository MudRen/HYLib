// Room: /d/hainan/underhill.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������,�����ͷ���ӹ�.һ�����¾��ں�ب����ǰ.��ͺ��ɽ�ڴ�
�ݲ���.��ʹԳ��Ҳ�޷��ʵ�.ɽ�ڵ�����������΢��,�γ�һ�����겻��
����ı����ش�.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("item_desc", ([ /* sizeof() == 1 */
  "ɽ��" : "����,���ֵط��ǲ���������ȥ��.
",
]));
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shatan",
  "south" : __DIR__"underhill2",
]));

	setup();
	replace_program(ROOM);
}

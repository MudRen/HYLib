// Room: /d/yandang/shanlu5.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������̶��,��һ���ʯ,��״��Բƽ��,�м���һ������,���ƹ�
��.����ĥ��,�׳�'��ĥ��'.�巽�л�ʫ��'����ʼ����,����������,
��֪�����,�������˲�.',������ͤ(ting).
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("item_desc", ([ /* sizeof() == 1 */
  "ting" : "����һ������Сʯͤ,������ͤ,��˵�������в���һ������,��
�������ø����Сͤ�й�.
",
]));
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shanlu4",
  "northeast" : __DIR__"shanlu6",
  "westdown" : __DIR__"shanlu7",
]));
	setup();
	replace_program(ROOM);
}

// Room: /d/menggu/downxuanya.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���͵�ɽ�±���,Į���ຮ�ķ�ɳ��ʴ,ɽ�¸��ǹ⻬�վ�.������
��ƽƽ��ɽʯ�����,����ɫ��ɽʯ��������,ֱ������еİ������.
��ͷ��ɫ�Ĵ��Χ����ɽ�±ߵ�һ����������.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/baidiao.c" : 2,
]));
	set("outdoors", "menggu");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"yading",
  "east" : __DIR__"xiaolu",
]));

	setup();
	replace_program(ROOM);
}

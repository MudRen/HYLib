// Room: /d/yandang/shimeng.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
���Ŷ���ɽ·����,�ɿ���ǰ�����Ҷ�����Ϫ�������,���Գ�Ϊʯ
��,��������,������֮��,���������÷��.��ͷ������ϡ����ɽԳ
�İ���,������Ϣ.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/yandang");
	set("exits", ([ /* sizeof() == 2 */
  "southup" : __DIR__"tianzhu",
  "north" : __DIR__"luoyan1",
]));

	setup();
	replace_program(ROOM);
}

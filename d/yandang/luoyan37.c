// Room: /d/yandang/luoyan37.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������г�����������,�۲͵ĵط�,����������,��ط��Ե�С��
Щ,ȴ���µĶ�,���е�һ������ľ��Բ�������ʮ����ͬ��,͸�����ⴰ
����ȥ,���ǻ�԰.
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"luoyan36",
]));

	setup();
	replace_program(ROOM);
}

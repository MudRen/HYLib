// Room: /d/menggu/byriver.c

inherit ROOM;

void create()
{
	set("short", "ˮ����");
	set("long", @LONG
��ԭ�ϵ�һ��Сˮ��,�����Ǽ��ð��ή������.���ߵ���ݰ����˵�ˮ
��,��ˮ��Щ����.���ı����Ǹ�����,�����Ǹ��ɲݶ�,�Աߵ�һ��Сé����
Ȼ��ª,��Ȼ�ܿ������ϵķ��.
LONG
	);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"river",
  "northeast" : __DIR__"chulan",
  "east" : __DIR__"caodui",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

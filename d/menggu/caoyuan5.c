// Room: /d/menggu/caoyuan5.c

inherit ROOM;

void create()
{
	set("short", "�ɹŲ�ԭ");
	set("long", @LONG
���ƴ��������տ��ٵ��ƶ�����,�������������ڲ�ס����,����
�¾��ǹ�����ɹŲ�ԭ,Զ��������������һƬ�����Ӫ��,�Ǿ�����ľ
��Ĳ���.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"caoyuan6",
  "south" : __DIR__"caoyuan4",
]));

	setup();
	replace_program(ROOM);
}

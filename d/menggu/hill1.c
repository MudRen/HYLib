// Room: /d/menggu/hill1.c

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
ϡ��Ĺ�ľ,�ݴ�.�¶��Ƚ�ƽ��,������һ���,һ��,�����һƬ��
�ƻ����ƶ�����,��Ƶ��¹��¼����׻�Ư�Ʋ���.����Ĳݴ����ƺ���Щ
���������Ű׹�.
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kezhene.c" : 1,
]));
	set("no_clean_up", 0);
	set("outdoors", "menggu");
	set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"caocong",
  "northwest" : __DIR__"caocong1",
  "westdown" : __DIR__"shulin",
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/hainan/shutang.c

inherit ROOM;

void create()
{
	set("short","�����ֲؾ���");
	set("long", @LONG
��䷿������ܰ��˼����ž���ļ���,�����������,�������Ǳ� 
��һ�������Ҳ��ԶԶ����.�����������һ�������Ļ�,�ͻᷢ��,���� 
����Ķ������ָ����ɵ��书�ؼ�. 
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "down" : __DIR__"chucang.c",
  "east" : __DIR__"jingtang",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/jinggui.c" : 1,
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/hainan/outtree2.c

inherit ROOM;

void create()
{
	set("short", "�һ�����");
	set("long", @LONG
��ǰ����һƬѤ�õ��һ���,һ����ȥ,ֻ�ܿ���һƬ����ǳǳ�ķ�
��,������ؼ�ֻʣ��������ɫ,���־���ֻ�����ξ��п���.���ߴ�����
�������,�˵ط��˼�.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/hainan");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"taotree1",
  "northeast" : __DIR__"caodi",
]));

	setup();
	replace_program(ROOM);
}

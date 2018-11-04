// Room: /d/jindezheng/yuanzi.c

inherit ROOM;

void create()
{
	set("short", "Ժ��");
	set("long", @LONG
����һ����԰,���߶��ǿⷿ,���������æ���Ŵӷ�������һ��һ 
���İ�����д���,����Щ�˲��ϵİѰ���Ĵ���װ���ͽ���������, 
�������ȴ������һ�����Ķ���,�Ӻ�Ժ�����˳�ȥ. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"matou",
  "out" : __DIR__"china-shop",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tiaofu.c" : 2,
]));

	setup();
	replace_program(ROOM);
}

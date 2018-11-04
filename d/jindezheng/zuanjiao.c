// Room: /d/jindezheng/zuanjiao.c

inherit ROOM;

void create()
{
	set("short", "שҤ");
	set("long", @LONG
�߳�����,�ͼ���һ��שҤ,ǰ���С,��ֱ�ɵĶ쵰��,�����ɸ� 
Լ���׵ı����̴�,Ҥ����һ�Ѷѵ���ľ.�ü���������ʹ�����Ÿ���� 
��,��Ҥ�йķ�. 
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "/d/jindezheng");
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"shulin2",
  "west" : __DIR__"songlin",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shaoyao.c" : 2,
]));

	setup();
	replace_program(ROOM);
}

// Room: /d/zhongzhou/yanling2.c

inherit ROOM;

void create()
{
	set("short", "ƽ����·");
	set("long", @LONG
�������ƽ����·����ƽ���ǵ�һ���Ͻ֡����ߵķ��ݿ���ȥ�Ѿ��ܳ�
���ˡ�·����������ģ�ż����һ������·��������ǰ�ߣ����������Ŀ�
������¥�ˡ�Ҫ������ǵĻ�����Ҫ�Ͻ����ˡ�Ҫ��Ȼ�ȳ��Ź��ˣ����
�Ƕ������ˡ�
LONG
	);
set("outdoors","pingan");

        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shop4",
  "north" : __DIR__"zuixianlou",
  "east" : __DIR__"west2",
  "west" : __DIR__"pinganmen",
]));
//	set("objects", ([ /* sizeof() == 1 */
//  __DIR__"npc/man6" : 1,
//]));

	setup();
	replace_program(ROOM);
}

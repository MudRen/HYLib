//nan1
  

inherit ROOM;

void create()
{
	set("short", "ƽ�����Ͻ�");
	set("long", @LONG
����ƽ���ǵ��Ͻ֣����Ľֵ������˲�������һ�����ڽֵ���
����������������һ�����ݡ������һ�ҿ�ջ��һ���������������
��������֪����һ�Ҳ�С�Ŀ�Ǯջ��
LONG
	);
set("outdoors","/d/pingan");

        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
	set("exits", ([
		"east" : __DIR__"xiaochi",
		"south" : __DIR__"nan2",
		"west" : __DIR__"pingankezhan",
		"north" : __DIR__"guangchang",
	]));
//	set("objects", ([
//		__DIR__"npc/man1" : 2,
//	]));

	setup();
	replace_program(ROOM);
}


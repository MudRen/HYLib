//west1
inherit ROOM;
void create()
{
  set ("short", "ƽ����·");
  set ("long", @LONG
�������ƽ����·����ƽ����һ���Ͻ֡����ߵķ��ݿ���ȥ�Ѿ��ܳ�
���ˡ�·����������ģ�ż����һ������·��������ǰ�ߣ����������Ŀ�
������¥�ˡ�·�����м������꣬�������з��ߵ꣬��������Ӧ�ò���.
LONG);

set("outdoors","pingan");

        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

  set("exits", ([  
    "west" : __DIR__"west2",
    "south" : __DIR__"shop1",
    "north" : __DIR__"shop2",
    "east"  : __DIR__"guangchang",
]));
//	set("objects",([
//		__DIR__"npc/man3":1,
//	]));
       
	 setup();
        replace_program(ROOM);
}

//dong1

inherit ROOM;

void create()
{
  set ("short", "ƽ����·");
  set ("long", @LONG
����ƽ���ǵ�һ����·�����������ƽ���ǡ�·������һ��
���,��˵ר���书��,�����в�����,��һ�����.ǰ��Ķ��Ż�
û�п���.
LONG);

set("outdoors","pingan");

        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

  set("exits", ([
    "west" : __DIR__"dong1",
    "north" : __DIR__"wuguan",
    "south"  : __DIR__"shop5",
]));

//	set("objects" , ([
//		__DIR__"npc/man6" : 1,
//	]));
         setup();
        replace_program(ROOM);
}

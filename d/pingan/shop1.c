
inherit ROOM;

void create()
{
        set("short", "ƽ��������");
        set("long", @LONG
������ƽ�������������꣬ʮ�˰����ű���������Ӧ�о���,�������
������Ҫ�������򼸼����ֵ�����,������������ܲ���.
LONG
        );
        set("exits", ([
		"north" : __DIR__"west1",
        ]));
        set("objects", ([
                __DIR__"npc/weaponer": 1,
        ]) );
        set("no_dazuo",1);set("no_kill",1);set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
        set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);

}


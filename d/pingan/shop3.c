
inherit ROOM;

void create()
{
        set("short", "��������ҩ��");
        set("long", @LONG
��������������������ҩ��,һ��ŨŨ��ҩζ���㼸����Ϣ��
���Ǵ�ҩ���ϵļ��ٸ�С ������ɢ�������ġ�����ֻ��һ��С
���վ�ڹ�̨���к��Ź˿͡�
LONG
        );
        set("exits", ([
		"south" : __DIR__"west2",
        ]));
        set("objects", ([
                __DIR__"npc/huoji": 1,
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


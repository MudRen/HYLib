// Room: /d/sandboy/daotian2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��Ӳӵ�һƬ����,΢������,��������,Զ��ȥ,һƬ��ɫ,ֱ�������
��ͷ.����������ҡ����������,�����Ž���ĺ��ճ�.������һƬɹ�ȳ�.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
        set("exits", ([
                "north" : __DIR__"daotian1",
                "south" : __DIR__"daotian3",
                "west" : __DIR__"liechang2",
                "east" : __DIR__"yutian2",
        ]));
//        set("no_fight",1);
//        set("no_beg",1);
//        set("no_steal",1);
	set("objects", ([
		__DIR__"non/nontian" : 2,
	])); 

	setup();
	replace_program(ROOM);
}

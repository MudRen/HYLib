// Room: /d/sandboy/daotian3.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��Ӳӵ�һƬ����,΢������,��������,Զ��ȥ,һƬ��ɫ,ֱ�������
��ͷ.����������ҡ����������,�����Ž���ĺ��ճ�.��ȥ�����﹡ͨ��
С��ׯ.������һƬɽ��.
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "jiangnan");
        set("exits", ([
                "north" : __DIR__"daotian2",
                "west" : __DIR__"liechang3",
                "east" : __DIR__"yutian3",
        ]));
//        set("no_fight",1);
//        set("no_beg",1);
//        set("no_steal",1);
	set("objects", ([
		__DIR__"non/nontian" : 1,
	])); 

	setup();
	replace_program(ROOM);
}

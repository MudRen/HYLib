// Room: /d/jingzhou/guangchang
// netkill /98/8/14/        congw /98/08/29 modify


inherit ROOM;

void create()
{
        set("short", "��������" );
        set("long", @LONG
�����Ǿ��ݵ�����Ҫʮ��·�ڣ������������������֣��ϱ�ס��һЩ
���ǵĸ��ˣ������ǹٸ�������һ���õط����������Ĵ������˶��ڴ�
��ţ���Ϣ�Ժ��ٸ�·��
LONG
        );
        set("exits", ([
		"east" : __DIR__"dongdajie1",
 		"west" : __DIR__"xidajie1",
		"north" :__DIR__"beidajie1",
 	        "south" :__DIR__"nandajie1",
	]));
	set("no_fight",1);

//set("objects", ([
//	"/tudi":1,//��������ϵͳʹ�� JackyBoy
//        "/d/npc/bukuai" : 1,
//  ]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
//	call_other("/clone/board/quest_b","???");
        replace_program(ROOM);
}


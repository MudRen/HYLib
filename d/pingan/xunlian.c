//canchang
  

inherit ROOM;

void create()
{
	set("short", "ѵ������");
	set("long", @LONG
������ƽ����Ϊ����ѵ���书�ĵط��������м���ľ�ˣ���������������
ע��,��������,����ƽ��֮���ı���.
LONG
	);
         set("no_steal",1);
//         set("pingan",1);
         set("no_beg",1); 	

	set("exits", ([
		"east" : __DIR__"nan3",
	]));
        set("objects", ([
		__DIR__"npc/mu-ren" : 1,
		__DIR__"npc/mu-ren2" : 1,
		__DIR__"npc/mu-ren3" : 1,
		__DIR__"npc/mu-ren4" : 1,
		__DIR__"npc/mu-ren5" : 1,
	]));


	setup();
	replace_program(ROOM);
}


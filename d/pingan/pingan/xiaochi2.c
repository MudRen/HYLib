//canchang
  

inherit ROOM;

void create()
{
	set("short", "С�Ե���");
	set("long", @LONG
������С�Ե�ĳ���,���ڵ����������ܲ���,�����,���˵Ĵ�ʦ���е�������
����,ֻ������æ���ҵ��ڸɻ�.
LONG
	);
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	

	set("exits", ([
		"west" : __DIR__"xiaochi",
                "east" : __DIR__"xiaochi3",
	]));
        set("objects", ([
		__DIR__"npc/shifu" : 1,
	]));

	setup();
	replace_program(ROOM);
}


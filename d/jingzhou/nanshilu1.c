// Room: /d/jingzhou/nanshilu1
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "��ʯ·" );
        set("long", @LONG
����һ������ʯ�̳ɵ�·����Ȼ��Щ������ȴ�ܿ�������ȥ����
�����ˡ�����ǰ��һƬ��ʯ����ס��ȥ·����˵�ǵ��������Ϊ����
ֹ���׷�϶���ġ�
LONG
        );
	set("objects", ([
		__DIR__"npc/boy" : 1,
		__DIR__"npc/girl" : 1,
                __DIR__"npc/kid" :1,
	]));

        set("exits", ([
  
  "north" :__DIR__"nanshilu",
  "southup" :  "/d/kunming/road1",
]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}


// Room: /d/jingzhou/jznanmen
// netkill /98/8/14/


inherit ROOM;

void create()
{
        set("short", "��������" );
        set("long", @LONG
���������ݵ����ţ������������Ǿ���Ҫ�أ���˳�ǽ��ʵ�ޱȣ���
¥�߸��������ɴ����ϣ���ȥ���ϵ�·�������Ǳ�ɽ��·Զ���ܲ����ߣ�
��ɵö��ע��һЩ��

LONG
        );
	set("objects", ([
		__DIR__"npc/bing" : 2,
]));

        set("exits", ([
  
  "north" :__DIR__"nandajie2",
  "south" :__DIR__"nanshilu",
]));

        set("no_clean_up", 0);
        set("outdoors", "jingzhou");

        setup();
        replace_program(ROOM);
}


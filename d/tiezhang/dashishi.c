// Room: /u/bobo/tiezhang/dashishi.c

inherit ROOM;

void create()
{
        set("short", "��ʯ��");
        set("long", @LONG
����ʯ���ϻ����ȼ���ţ�ǽ�����ܷ����˴����䣬��һ���������鱦
�ƽ��м�����Ϲ��Ŷ�������������һ����һ�����������ţ��������һƬ
�����ƶ�Ʈ���ڿ��С�
LONG
        );

        set("exits", ([ 
"out" : __DIR__"taijie-2",
]));
        set("objects", ([
        __DIR__"obj/jia2" : 1,
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);        
}


// /d/jingzhou/chibi1.c
// netkill /98/9/10/


inherit ROOM;

void create()
{
        set("short",  "С·" );
        set("long", @LONG
����һ��ͨ�򽭱ߵ�С·��·ʮ�ֵĶ�����������С��һ�㣬��
�ܾ����ĵģ�ֻ�ŵ�����質��������
LONG
        );
        set("outdoors", "jingzhou");

        set("exits", ([
                "northup" : __DIR__"qingshan",
		"southdown" : __DIR__"chibi2",                
        ]));

             
        setup();
        replace_program(ROOM);
} 

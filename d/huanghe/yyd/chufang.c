// ���� chufang.c
// zly 1999.06.10
 
inherit ROOM; 
 
void create() 
{ 
        set("short", "����");
        set("long", @LONG
�����������ĳ�������һ���ţ�һ�������˱Ƕ�����Ѭ����ֱ����
ˮ����̨���������̣��������������Ĳ��٣���ʦ����æµ�š�
LONG
        );

        set("exits", ([ 
            "east" : __DIR__"dating",
]));

        set("objects", ([
                    __DIR__"obj/niurou" : 1,
             __DIR__"obj/liyu" : 1,        
             __DIR__"obj/sansi" : 1,
           __DIR__"obj/fan" : 1,
                   ]));

        setup();
}


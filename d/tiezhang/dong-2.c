// room: dong-2.c
// zqb


inherit ROOM;



void create()
{
        set("short", "ɽ��");
        set("long", @LONG
    һ���������ɽ�����ڳ�����һ���������ס������ʯ����������
̦޺����������ʪ�ֻ�����ʯ���ƺ����˹�����ģ������ܵ�ʯ�������ܿ�
������ĺۼ�����վ�����һ�ɿ־���Ȼ�������ƺ�������ʱ���ᱻ��Ƭ
�ڰ����ɵ���
LONG
        );
        set("exits", ([
            "out" : __DIR__"dong-1",
            "enter" : __DIR__"dong-3",
]));

        set("objects", ([
               
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}



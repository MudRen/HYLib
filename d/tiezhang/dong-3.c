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
            "out" : __DIR__"dong-2",
            "enter" : __DIR__"trdx",
]));

        set("objects", ([
               
        ]));

        set("no_clean_up", 0);

        setup();
        //replace_program(ROOM);
}



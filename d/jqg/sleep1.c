// Room: sleeproom1.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵�������е�����Ϣ�ң���
��������ֻ���м���ż�����ʰ����������Ĵ󴲣����ϻ���һЩ�ޱ���
���ž�������˯����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);
        set("exits", ([
                "south" : __DIR__"lang4",
        ]));         
        setup();
}

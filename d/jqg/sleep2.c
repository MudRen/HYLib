// Room: sleeproom2.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������Ů������Ϣ�ң���
��������ֻ���м���ż�����ʰ����������Ĵ󴲣����ϻ���һЩ�ޱ���
���ž�������˯����
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);
        set("exits", ([
                "north" : __DIR__"lang4",
        ]));         
        setup();
}

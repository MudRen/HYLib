// Room: xiuxishi.c

inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
���Ǽ�������᷿�����Ŵ������ţ����ߺܻ谵������������
ֻ���м����һ����ʰ����������Ĵ󴲣����ž�������˯����
LONG );

        set("sleep_room", 1);
        set("no_clean_up", 0);
        set("no_fight", 1);
        set("exits", ([
            "east" : __DIR__"qing",
        ]));

        setup();
}

inherit ROOM;

void create()
{
        set("short", "���ָ���");
        set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴������࣬
�����ϵ��������������������һ���ң����顰���ָ����������֡�
LONG
        );

        set("exits", ([
                "south" : __DIR__"wanjing",
                "north" : __DIR__"dayuan1",
        ]));

        set("objects", ([
                __DIR__"npc/wolfdog" : 2,
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}



// wdroad5.c
// netkill /98/8/17
inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����ܾ����ĵġ����������ƺ���������·��
LONG
        );
        set("outdoors", "wudang");

        set("exits", ([
                
                "northwest" : __DIR__"wdroad6",
                "northeast" : "/d/wudang/wdroad2",
                "south" : __DIR__"wdroad4",
        ]));

        setup();
        replace_program(ROOM);
}

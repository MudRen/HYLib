// shanlu4.c ɽ·
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
������ɽ·�ľ�ͷ�����������һƬС���֣��۶��򶫣���������
ɽ��ɽ���ˡ�
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "northwest" : __DIR__"shanlu2",
                "eastup" : __DIR__"shanjiao",
                "northup" : "/d/quanzhen/taiyi/taiyici",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

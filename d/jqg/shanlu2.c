// shanlu2.c 
// By River@sj 99.5.20
inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
������һ�����Ѷ��ϵ�ɽ��С·�ϣ�����ʮ�ֻ�����ǰ�治Զ������һЩ
С���֣���������С·��֪ͨ�����
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "northwest" : __DIR__"shanlu1",
                "southeast" : __DIR__"shanlu3",
        ]));

        setup();
        replace_program(ROOM);
}

// shanlu2.c 
// By River@sj 99.5.20
inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
������һ�����Ѷ��ϵ�ɽ��С·�ϣ�����ʮ�ֻ�����ǰ�治Զ������һЩ
С���֣���������С·����ͨ��һ��СϪ����
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "north" : __DIR__"xibian",
                "southeast" : __DIR__"shanlu2",
        ]));

        setup();
        replace_program(ROOM);
}

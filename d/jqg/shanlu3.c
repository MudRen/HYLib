// shanlu3.c 
// By River@sj 99.5.20
inherit ROOM;

void create()
{
        set("short", "ɽ��С·");
        set("long", @LONG
������һ�����Ѷ��ϵ�ɽ��С·�ϣ�����ʮ�ֻ�����ǰ�治Զ������һЩ
С���֣��������ͨ�������ǵ���ʯ�������������С·��֪ͨ�����
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "northwest" : __DIR__"shanlu2",
                "southdown" : "/d/sdxl/conglin1",
        ]));

        setup();
        replace_program(ROOM);
}

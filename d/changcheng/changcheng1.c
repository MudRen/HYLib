// Room: /d/wizhome/incahome/changcheng1.c
// Date: inca 98/08/13

#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", WHT "����");
        set("long", WHT@LONG
������Ǿ���������--���ǡ�վ�ڳ���������Կ�������Ⱥɽ���ƣ�ɽ��
�������ǰ����Ĺ�ľ�ԣ����Ŀ��ȥ����µĳ���˳��ɽ����һ������������
���������ȥ��
LONG
NOR        );

        set("outdoors", "changcheng");

        set("exits", ([
                "west" :__DIR__"changcheng2.c",
                "east" :__DIR__"juyguan.c",
        ]));

        setup();
        replace_program(ROOM);
}

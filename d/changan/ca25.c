// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIG "����ɽ" NOR );
    set("long", @LONG
�����������ɽ������ͬһ�����統�ڳ������档���ں������
���������̫���񣬹��ֳ�̫��ɽ��
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "southdown":__DIR__"ca24",
       "eastdown":__DIR__"ca26",
]));
    setup();
    replace_program(ROOM);
}

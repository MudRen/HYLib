
// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIY "��¥" NOR);
    set("long", @LONG
��¥����������һʮ���ꡣ����ʯΪ��������ľΪ��¥��¥����
�Ҿ���һ�ڣ����Ա�ʱ����¥��˵�����
LONG
);
    set("exits", ([
       "south":__DIR__"ca18",
]));
    setup();
    replace_program(ROOM);
}

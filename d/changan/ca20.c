
// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIY "��¥" NOR);
    set("long", @LONG
��¥����������һʮ���ꡣ����ʯΪ������שΪ¥�����غ�ʵ��
��¥�ڰ��Ŵ��һ�ţ��ഫ���������ڴ˻��ĵ㽫�������ݳǶ�����
����
LONG
);
    set("exits", ([
       "south":__DIR__"ca17",
]));
    setup();
    replace_program(ROOM);
}

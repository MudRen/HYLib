
// This is a room made by wsl.
#include <ansi.h>
inherit ROOM;
void create()
{
    set("short",HIW "����" NOR);
    set("long", @LONG
����������������ĳ������֡��ഫ���ڱ���Ԫ����䡣������
��ʯĹ־�������Ժ����壬���͸��������ֱʡ������׭��������Ŀ
������������������ʯ�̣�ֱ�������ۻ����ҡ�
LONG
);
    set("exits", ([
       "east": __DIR__"ca13",
       "north":__DIR__"ca23",
]));
    setup();
    replace_program(ROOM);
}

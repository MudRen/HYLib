// /d/kunming/road4
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "��ʯ̲" NOR);
        set("long", @LONG
�����ʯ������·�������ߣ���С�ľ�Ҫˤ��������������Ƭʯ̲����
�ǳ������ߡ�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "southdown" : __DIR__"road5", 
                "northeast"  :__DIR__"road2",
                
        ]));

        setup();
        replace_program(ROOM);
}

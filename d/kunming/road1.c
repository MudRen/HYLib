// /d/kunming/road1
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
                "south" : __DIR__"road3", 
                "southwest" : __DIR__"road2",
                "northdown" : "/d/jingzhou/nanshilu1",
        ]));

        setup();
        replace_program(ROOM);
}

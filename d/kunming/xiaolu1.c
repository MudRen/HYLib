// /d/kunming/xiaolu1
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "С·" NOR);
        set("long", @LONG
һ��С·����Ϊ��ƽ������������һЩ��ʯ�����ι�״��������
Ȥ ��
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "north" : __DIR__"xiaolu", 
                "south"  :__DIR__"shilin",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}

// /d/kunming/xiaolu
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "С·" NOR);
        set("long", @LONG
һ��С·����Ϊ��ƽ������������һЩ��ʯ�����ι�״��������
Ȥ��һֱ����ȥ�Ϳ��Ե��������ˣ���ȥ�������µ�ԭʼɭ��.
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "north" : __DIR__"yunnan4", 
                "south"  :__DIR__"xiaolu1",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}

// /d/kunming/road7
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "ɽ·" NOR);
        set("long", @LONG
������һ����᫵�ɽ·�ϣ������ϣ��ͽ������ƹ��ԭ�ˡ�������һ��
�����סȥ·��
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
		"south": __DIR__"yunnan",
                "north"  :__DIR__"road6",
                
        ]));

             
       setup();
        replace_program(ROOM);
}

// /d/kunming/shilin2
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "ʯ��" NOR);
        set("long", @LONG
������״�����ʯͷ���е����ˣ��е��������е����������
��һ���߷壬ȴ���������������Ϊ�������塣
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "northup" :__DIR__"lianhua",
                "east" : __DIR__"shilin1", 
                "southwest"  :__DIR__"qingshilu",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}

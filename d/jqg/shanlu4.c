// shanlu4.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long", @LONG
�˴���һ�����ɽ·����������������������Ω�������ȵף����Է��ۣ�
��ɽ�żţ�΢��������ãã����ֻ��һ�˶��ѡ�
LONG
        );

    set("exits", ([ 
		"east"  : __DIR__"shanlu5",
                "west"  : __DIR__"shanding",                     
    ]));

    set("outdoors", "�����");
    setup();
    replace_program(ROOM);
}

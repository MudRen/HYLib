// shanlu5.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long", @LONG
�˴���һ�����ɽ·����������������������Ω�������ȵף����Է��ۣ�
��ɽ�żţ�΢��������ãã����ֻ��һ�˶��ѡ���ǰ����������·����һ
ʱ����֪����һ���߲��ǡ�
LONG
        );

    set("exits", ([ 
		"northup"  : __DIR__"shanlu6",
  		"eastup"  : __DIR__"shanlu9",
                "west" : __DIR__"shanlu4",  	
    ]));

    set("outdoors", "�����");
    setup();
    replace_program(ROOM);
}

// shanlu9.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long", @LONG
�㲻���ѵ��˹ȶ�������������֮����̧ͷ��һ��ɽ�����������Ǿ�
��֮�صľ���塣��ɽ���������һ��ɽ�£���֪�������֮ǰ���������Ͽ�
�ˡ��ϳ��¡����֡�ɽ��������Ԩ����Ԩ�������������������ס�
LONG
        );

    set("exits", ([ 
		"westdown"  : __DIR__"shanlu5",
  		"eastup"  : __DIR__"shanlu10",                 	
    ]));

    set("outdoors", "�����");
    setup();
    replace_program(ROOM);
}

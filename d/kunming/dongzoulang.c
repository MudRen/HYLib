// /d/kunming/dongzoulang.c
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "������" );
        set("long", @LONG
һ���ɾ������ȣ������濴ȥ���������͵���԰��ķ羰��ֻ��
���ּ�ɽ��ʯ���滨��ݣ��������֮���ɡ�
LONG
        );
          set("outdoors", "kunming");

        set("exits", ([
		"west"   :__DIR__"wangfu1",
		"east"   :__DIR__"dongzoulang1"
                
        ]));

        setup();
	replace_program(ROOM);	       
}
	  		
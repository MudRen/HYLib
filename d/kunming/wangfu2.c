// /d/kunming/wangfu1
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "��������" );
        set("long", @LONG
������������������������̫ʦ�Σ�ǽ�Ϲ���һ���ֻ������õ�
�򵥣���ࡣ����յ�����û��һ���ˣ�����ƽ����ƽʱ����������
��ֻ�м������˲�ʱ����ɨһ�¡�
LONG
        );
          set("outdoors", "kunming");

        set("exits", ([
                "south"    :__DIR__"wangfu1",         
                
        ]));

        setup();
	replace_program(ROOM);	       
}
	  		
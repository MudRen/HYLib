// /d/kunming/xiangfan.c
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "�᷿" );
        set("long", @LONG
һ�䲻����᷿����ʰ��ʮ�ָɾ��������Ǽ���ƽ�����֮�ã�
һ��С����͸��Щ�����ˣ��Ե�ʮ�ֵ����ġ�
LONG
        );
          
        set("exits", ([
		"west"   :__DIR__"dongzoulang1",
	
        ]));
	set("sleep_room",1);

        setup();
	replace_program(ROOM);	       
}
	  		
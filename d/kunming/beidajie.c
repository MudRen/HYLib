// /d/kunming/jinrilou
// netkill /98/9/11/


#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",  "�����" );
        set("long", @LONG
�����ڱ�����ϣ������������˺��٣�������һ����ΰ�Ĵ��ţ��Ǿ���
ƽ����������Ĺ�ۡ�ˡ�·��������������Ŵ������Ե�ʮ��Ư������ʱ��
�м������������߶���
LONG
        );
         set("outdoors", "kunming");

        set("exits", ([
                "south"    :__DIR__"jinrilou",
		"north"   :__DIR__"wangfu",
                
                
        ]));

             
        setup();
	replace_program(ROOM);
       
}

	  		
// /d/kunming/yunnan3
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "ԭʼɭ��" NOR);
        set("long", @LONG
�߽�ԭʼɭ�֣�ֻ������ããȫ�ǲ��������������գ����ܹ���
�ܰ����ֲ��嶫������������˭�����������ڳ�ȥ�ˡ��Һõ��������
���ʱ��������һ��·�������㲻�����޳��ˣ�ҲҪ�����ζ�������
�Ի��ǿ��뿪���
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "east" : __DIR__"yunnan2", 
                "southwest"  :__DIR__"yunnan4",
                
        ]));

             
        setup();
        replace_program(ROOM);
}

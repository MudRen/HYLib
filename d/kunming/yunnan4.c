// /d/kunming/yunnan4
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "ԭʼɭ��" NOR);
        set("long", @LONG
�߽�ԭʼɭ�֣�ֻ������ããȫ�ǲ��������������գ����ܹ���
�ܰ����ֲ��嶫������������˭�����������ڳ�ȥ�ˡ��Һõ��������
���ʱ��������һ��·���������Ͼ��߳�ɭ���ˣ���������������ˮ
����
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "northeast" : __DIR__"yunnan3", 
                "south"  :__DIR__"xiaolu",
                "north"  :"/d/baling/edao14",	
                "west"  :__DIR__"yunnan5",
                
        ]));

             
        setup();
        replace_program(ROOM);
}

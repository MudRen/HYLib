// /d/kunming/shilin
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "����ͤ" NOR);
        set("long", @LONG
������ʯ����ߵ�һ���壬������һСͤ���治֪�������
��������ģ����ۿ�ȥ��ֻ������ʯ��(feng)����,һʱ���۾���
�����ˡ�
LONG
        );
        set("outdoors", "kunming");
        set("exits", ([
                
                "up"  :__DIR__"lianhua",        
               
        ]));
             
        setup();
        replace_program(ROOM);
}

// /d/kunming/yunnan
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", RED "����·" NOR);
        set("long", @LONG
�����ƹ��ԭ��������Ϊ�˺�ɫ��������ø����£����ۿ�ȥ��ֻ
������ԭʼɭ�ֲ����߼ʣ����ʱ�����ĸ�־Զ��һ�ɺ���ӿ��������
��Ҫ��һ������ҵ��
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "southwest" : __DIR__"yunnan1", 
                "north"  :__DIR__"road7",
                
        ]));

             
        setup();
        replace_program(ROOM);
}

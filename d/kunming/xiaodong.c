// /d/kunming/xiaodong
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN "ɽ·" NOR);
        set("long", @LONG
����һ��С������Ȼ����ȴ��ʰ�ĸɸɾ����������Ͽ���һ��
�촰����һ�����Ӵ�����ȥ���������˽������Ե������������ǽ
��һ��С����һ��С���ӡ�
LONG
        );
        set("sleep_room",1);
        set("no_fight",1);
        
        set("exits", ([
                "up" : __DIR__"lianhua", 
                "out"  :__DIR__"shijianchi",
                
        ]));

             
        setup();
        replace_program(ROOM);
}

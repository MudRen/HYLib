// /d/dali/changting
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "ʮ�ﳤͤ" NOR );
        set("long", @LONG
һ��Сͤ�ӣ�רΪ�����ͱ�����ʱ��Ϣ���ã�һ���Ϳ�Ҳ��
����Ϊֹ��ʷ�г�ʮ�����ͣ����ɴ˶�����������һ��С����Ϊ
������Щ�׾ƣ�ʳ�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "east" : __DIR__"dxiaolu1", 
                "west"  :"d/dali/road1",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}

//kantai ��̨

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIW"����̨"NOR);
        set("long", @LONG
�������Խ�ɽׯ�Ŀ�̨��ɽׯ�ڵĸ�����֣����������д����գ����ַ�
���������������У������ޱȡ�
LONG
        );
        set("exits", ([        
        "out" : __DIR__"zongtai",
        ]));
        
        set("no_fight", "1");
        set("no_sleep_room", 1);
        set("objects", ([ /* sizeof() == 1 */
                __DIR__"obj/sxj2" : 1,
        ]));
     
        setup();
}


//shulin.c ����

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIG"����"NOR);
        set("long", @LONG
����һƬ���֡���ʮ�ɸߵĴ�������һ�飬��ʵ��֦Ҷ��һ�����ɡ����
����գ��������ڵ�˿��Ҳ�ޡ������������У������µ���Ҷ�ȵ�ɳɳ�졣
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([
        "southeast" : __DIR__"caodi6",
        "northeast" : __DIR__"caodi7",
        "north" : __DIR__"shulin6",
        "south" : __DIR__"shulin4",

        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "�Խ�ɽׯ");

        setup();
}



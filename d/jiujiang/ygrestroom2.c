//Edit By Subzero
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", "��Ϣ��" );
        set("long", @LONG
������ǹ�������ʱ��Ϣ�ĵط������ϰڷ�������ı��죬����ȥ
�����˸е�����˯����
LONG);

        set("sleep_room", 1);
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_get", 1);
        set("exits", ([
        "east" : __DIR__"ygrestroom1",
        ]));

        setup();
}

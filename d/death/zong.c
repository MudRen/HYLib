// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ����˾");
        set("long", @LONG
������˾���������һ������׵Ľ����������ϣ�������λ�ڽ���
ʿ������ƮƮ���ɷ���ǡ�
LONG
        );
        set("exits", ([
		"southeast" : __DIR__"naihe2",
        ]) );
        set("objects", ([
                __DIR__"npc/yuefei":1,
        ]) );
	set("coor/x",-1030);
	set("coor/y",-10);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 

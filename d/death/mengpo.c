// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
һ��СС����վ��С����ܺڣ�ֻ�ж��ߵĴ�����һ˿����͸��
���ƵĴ�ֽ������ڡ��ܶ��Ӱ�ڽ�����ζ�����Щһ���Ͳ����ˡ�
LONG
        );
        set("exits", ([
		"north" : __DIR__"aihe",
        ]) );
        set("objects", ([
                __DIR__"npc/mengpo" : 1,
        ]) );
	set("coor/x",-1020);
	set("coor/y",-100);
	set("coor/z",-290);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 

// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ɽ��");
        set("long", @LONG
����������У������ѱ棬�����Կգ����������ǹ���������
������һ���ߵ���Ӱ�٣��࿴���Ҿ�������˵�ñ��������ˣ���սս��
���ļ���ǰ�У���������������
LONG
        );
        set("exits", ([
		"northup" : __DIR__"beiyin",
		"south" : __DIR__"diyu",
        ]) );
	set("coor/x",-1020);
	set("coor/y",-60);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 

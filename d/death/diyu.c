// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
��������ɽ��Ⱥ�����裬�»���ɢ������֮���������ڶ����㲻�ɵ�
����񱼣�ת���Ѿ����������ţ�һ����ţ�����ʮ�˲��������������
����֮���ڴ˹�Ѻ���̡�
LONG
        );
        set("exits", ([
		"north" : __DIR__"shandao",
		"down" : __DIR__"diaojin",
        ]) );
        set("objects", ([
                __DIR__"npc/ghost" : 5,
        ]) );
	set("coor/x",-1020);
	set("coor/y",-70);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 

// TIE@FY3
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "ڤ�����");
        set("long", @LONG
�����ѵ�ڤ������ģ�·��������ڤ����˾���ƹ������ֻأ�
��Ϊ�ң�Т���ڣ��壬���ƳͶ�����ѭ�������˱�Ӧ����������
�޲�ǰ��һ�ã��Ծ�����
LONG
        );
        set("exits", ([
                "north" : __DIR__"naihe",
		"south" : __DIR__"yanluo",
		"northwest" : __DIR__"zong",
		"southwest" : __DIR__"jie",
		"northeast" : __DIR__"xiao",
		"southeast" : __DIR__"yi",
        ]) );
        set("objects", ([
		__DIR__"npc/panguan" : 1,
 		__DIR__"npc/niutou" : 3,
		__DIR__"npc/mamian" : 3,
       ]) );
	set("coor/x",-1020);
	set("coor/y",-20);
	set("coor/z",-100);
	set("deathroom",1);set("no_fight",1);set("no_dazuo", "1");setup();
        replace_program(ROOM);
}
 

// townroad.c С��·
// Town of mingjiao  
// Ver 1.0 10/8/1998 by Shark

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "С �� �� ��");
	set("long",   @LONG
��������С��Ψһ��һ���ֵ�����ʱ�з�ɳϮ����������һ���ӻ��̣�
��������һ��ɨ�㣬���ǼҾƹݡ�
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
                "west" : __DIR__"zahuopu",//�ӻ���
             	"east" : __DIR__"jiudian",//�ƹ�
                "south" : __DIR__"townroad1",
                "north" : __DIR__"town",
//                "northwest" : __DIR__"luzhou",
//                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
//                "southeast" : __DIR__"town",
	]));
	
  	set("objects", ([
		"/d/shaolin/npc/tiao-fu" : 1,
        ]));
	
	setup();
	replace_program(ROOM);
}


// townroad1.c С��·
// Town of mingjiao  
// Ver 1.0 10/8/1998 by Shark

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "С �� �� ��");
	set("long",   @LONG
��������С��Ψһ��һ���ֵ�����ʱ�з�ɳϮ���������м��ջ����
���Ǽҵ��̣��ϱ����������������Ͼ���ȥ����ɽ��·�ˡ�
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
                "west" : __DIR__"kedian",//�м��ջ
             	"east" : __DIR__"dangpu",//����
                "south" : __DIR__"longwangmiao",//������
                "north" : __DIR__"townroad",
//                "northwest" : __DIR__"luzhou",
//                "northeast" : __DIR__"shaqiu1",
                "southwest" : __DIR__"huangmo",//ȥ����ɽ
//                "southeast" : __DIR__"town",
	]));
	
  	set("objects", ([
                __DIR__"npc/shangren" : 1,
        ]));
	
	setup();
	replace_program(ROOM);
}


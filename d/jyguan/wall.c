// wall.c ����
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIG "�� �� �� ��");
	set("long", @LONG
����ǵ���Ϊ��������ɽ������У���ϧ�����˲ƣ���ʹ�������գ�������������
�����ɵĳ��ǡ���֪���������˶��ٱ��˵Ĺ��¡����ٰ��յ�ʬ��...
    ����������ʹ���������ڵ����޲����ǣ����ǿ���ȥ�ǳ����ۣ�����������
����������...
LONG
	);
        set("outdoors", "jyguan");
	

	set("exits", ([
		"southeast" : __DIR__"road4",
		"east" : __DIR__"luzhou1",
		"northeast" : "/d/changcheng/changcheng21",
	]));
	
		
	setup();
	replace_program(ROOM);
}


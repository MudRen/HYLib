// huangmo2.c ��Į
// shamo can to shaqiu
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIY "��Į");
	set("long",  @LONG
����������ããɳ����ɳ�������ż�����Կ���Щ����ɫ���������ĵط�
��Ȼ����һ��·����ϡ���ϣ������Ǿ����������ߡ�
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([		
                "east" : __DIR__"huangmo3",
                "northeast" : __DIR__"huangmo1",
	]));
	
		
	setup();
	replace_program(ROOM);
}


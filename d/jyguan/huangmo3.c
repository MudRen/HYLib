// huangmo3.c ��Į
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
                "southwest" : __DIR__"huangmo4",
                "west" : __DIR__"huangmo2",
	]));
	
		
	setup();
	replace_program(ROOM);
}


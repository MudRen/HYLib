// road7.c ��ظ�ԭ-ɽ·���ɶ�
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "ɽ·");
	set("long", @LONG
����������ظ�ԭ��������ء�����һ·��ν��������һ����ȫ������
ʮ��֮���ɶ�������Ϊ֮��ͨ�����˹�����
LONG
	);	
        set("outdoors", "qingzh");

	set("objects", ([
"quest/skills2/wunon/dalie/dalie" : 2,
	]));

	set("exits", ([
		"southeast" : __DIR__"road8",
		"west" : "/d/xizang/shudao2",
//		"southwest" : __DIR__"xroad",
		"northup" : __DIR__"road6",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
	
	setup();
	replace_program(ROOM);
}

/*	
void init()
{
	object ob;
	int ioqi;
	
	ob = this_player();
	ioqi = 500 / (int)ob->query("int") + 2;
        if((int)ob->query("qi") < 50) 
                 message("vinson",HIR"���Ȼ�е��������������巢�����Ǹ�ԭ��Ӧ��ЪϢһ������߰ɣ�\n"NOR, ob);
	ob->improve_skill("dodge", 0.1 * (int)ob->query_skill("dodge", 1));
        ob->receive_damage("qi", ioqi );
}
*/		


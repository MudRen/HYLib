// road3.c ��ظ�ԭ
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","��ظ�ԭ");
	set("long", @LONG
����������ظ�ԭ�����ﺣ��̫�߿���ϡ����ֻһ���������������������ˡ�
�����˼ʺ�������Բ���ﲻ�����̣���ֻ��β��ߵó�ȥ...
LONG
	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"south" : __DIR__"road4",
		"northeast" : __DIR__"road2",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
	
	setup();
//	replace_program(ROOM);
}

	
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
		


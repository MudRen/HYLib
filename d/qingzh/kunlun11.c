// kunlun11.c ����ɽ
// west to jiayuguan,est to lanzhou
// Ver 0.1 08/15/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIW "����ɽС·");
	set("long", @LONG
��·��խ��᫣��ְ�͹��ƽ���ߵ�ɷ�����ˡ�������·��������������һ
�������ֻ��ͷ�Ρ�
    ��ѩƮƮ���
LONG
	);	
        set("outdoors", "qingzh");

	set("exits", ([
		"northup" : __DIR__"kunltop",
		"southwest" : __DIR__"kunlun10",
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
	ioqi = 300 / (int)ob->query("int") + 3;
        if((int)ob->query("qi") < 50) 
                 message("vinson",HIR"���Ȼ�е��������������巢�����Ǹ�ԭ��Ӧ��ЪϢһ������߰ɣ�\n"NOR, ob);
	ob->improve_skill("dodge", 0.1 * (int)ob->query_skill("dodge", 1));
        ob->receive_damage("qi", ioqi );
}
*/		


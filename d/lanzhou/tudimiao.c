// Room: /lanzhou/tudimiao.c
// xws 1998/10/14 

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������������������һ�����ع��������������������ƣ��������������
�����ڴ�������ݡ����˵��ˣ�Ҳ��Ҫ�����������Ϲ��Ͼ���������ݡ�
LONG
	);
	set("no_fight", "1");
	set("no_steal", "1");
	set("no_hit", "1");
	set("no_kill", "1");
	set("exits", ([
		"north": __DIR__"dongdajie1",
	]));
       	setup();
	//replace_program(ROOM);
}

void init()
{
   object me;
    me=this_player();
me->set("startroom",base_name(environment(me)));
    return;
}

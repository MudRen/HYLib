// Room: /city/wumiao.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;
void create()
{
	set("short", "ƽ������");
	set("long", @LONG
�����������������������������Ϸ������������顰���Һ�ɽ����
���ҡ����������Ƕ�š����ұ������ĸ����֡����˵��ˣ��������������Ϲ�
�Ͼ���������ݡ��Ա��ƺ���һ�����š�
LONG );
	set("no_fight", "1");
	set("no_dazuo", "1");
         set("pingan",1);
	set("no_steal", "1");
	set("no_sleep_room", "1");

        set("valid_startroom","1");

	set("exits", ([
		"east" : __DIR__"bei2",
	]));
        set("objects", ([
  __DIR__"npc/sighmoon" : 1,
	]));
	setup();
        "/clone/board/wiz2_b"->foo();
}

void init()
{
	object me;
	me=this_player();
	me->set("startroom",base_name(environment(me)));
	return;
}

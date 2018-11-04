// Room: /d/songshan/cangku.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <room.h>

void create()
{
	set("short", "�ֿ�");
	set("long", @LONG
����һ���ֿ⣬�����ܲ�͸�硣��һ���ű��ŵ�һ��ùζ�����ݵ�
�ҳ����ɶѳɶѵ���Ʒ����������䷿�䡣
LONG );
	set("exits" , ([
		"north" : __DIR__"westting",
	]) );
	set("objects" , ([
		__DIR__"npc/beixin" : 1,
		__DIR__"npc/huwan" : 1,
		__DIR__"npc/huxin" : 1,
		__DIR__"npc/huyao" : 1,
		__DIR__"npc/huzhi" : 1,
		__DIR__"npc/niupi" : 1,
		__DIR__"npc/shadai" : 1,
		__DIR__"npc/tengjia" : 1,
		__DIR__"npc/tiejia" : 1,
	]) );
	set("no_clean_up", 0);
	set("coor/x", -40);
	set("coor/y", 890);
	set("coor/z", 90);
	setup();
	create_door("north" , "ľ��", "south" , DOOR_CLOSED);
	replace_program(ROOM);
}


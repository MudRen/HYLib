//Cracked by Kafei
// /d/bwdh/sjsz/egarden.c

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create()
{
		  set("short", HIC"��԰"NOR);
		  set("long", @LONG
����һ��԰�ӣ�ͥԺ���ģ����ֻ������ǲ��١��ٻ����ţ�ɽʯ��׾��
�������壬���ɴ��񣬾���ɷ�����ˡ��峺��Ϫ����������һ��Сͤ�ӣ�
����Ϫˮ��������ȥ��
LONG
		  );
		  set("exits", ([ /* sizeof() == 2 */
				"north" : __DIR__"ezoulan",
				"west" : __DIR__"room_09",
				"out" : __DIR__"egate",
		  ]));

		  set("cost", 0);
		  create_room();
		  setup();
}

void init()
{
	init_room();
}

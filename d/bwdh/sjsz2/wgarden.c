//Cracked by Kafei
// /d/bwdh/sjsz/wgarden.c
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
				"east" : __DIR__"room_01",
				"out" : __DIR__"wgate",
		  ]));

		  set("cost", 0);
 	          set("outdoors", "city");
		  create_room();
		  setup();
}

void init()
{
	init_room();
}


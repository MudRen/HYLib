//Cracked by Kafei
// Room: /d/xixia/chaifang.c

inherit ROOM;
#include "room.h"
void create()
{
	set("short", "��");
	set("long", @LONG
�����Ǽ䲻С�Ĳ񷿣�������������˸ߵ��Ϻ�ľ��ɢ����ľ
ͷ���е����㣬����Ĳ��һ����ÿ��һ�δӳ����������������
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"yushanfang",
  "east" : __DIR__"bianmen",
]));
	create_door("east","ľ��","west",DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

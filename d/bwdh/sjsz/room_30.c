//Cracked by Kafei
// group bwdh/room 30
// sdong 10/03/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", BLU"������"NOR);
	 set("long", @LONG
������ҹ��߰������������˺ܶ���飬Ѫ���߰ߣ�������
��͸��Ѫ�����͸�ʬζ��ʹ���ܵ��쳣�Ĵ̼�������סѪ�����š�
LONG
	 );
	 set("exits", ([
		  "south"      : __DIR__"room_29",
	 ]));
	 create_room();
	 set("objects", ([
		  __DIR__"obj/box" : 1,
	 ]));
    setup();
}

void init() {
    init_room();
}

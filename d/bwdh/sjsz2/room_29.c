//Cracked by Kafei
// group bwdh/room 28
// sdong 10/03/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create() {
	 set("short", HIB"������"NOR);
	 set("long", @LONG
������ҹ��߰���������ʯ����Ѫ���߰ߣ������ǵ���
���Ŀ��ۡ��еĵط����н�ӡ����Ȼ���ڹ��������ӡ��
�ġ���������͸��Ѫ�����͸�ʬζ��ʹ���ܵ��쳣�Ĵ̼���
����סѪ�����š�
LONG
	 );
	 set("exits", ([
		  "up"      : __DIR__"room_28",
		  "north"   : __DIR__"room_30",
	 ]));
    create_room();
    set("objects", ([
		  __DIR__"npc/master" : 1,
	 ]));
    setup();
}

void init() {
    init_room();
}

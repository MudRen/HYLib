//Cracked by Kafei
// group bwdh/room 28
// Apache 09/27/98

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"
void open_basement();

void create() {
    set("short", HIW"������"NOR);
    set("long", @LONG
����������ʯ����Ѫ���߰ߣ������ǵ������Ŀ��ۡ�
�еĵط����н�ӡ����Ȼ���ڹ��������ӡ�ϵġ�������
��͸��Ѫ�����͸�ʬζ��ʹ���ܵ��쳣�Ĵ̼�������סѪ
�����š�
LONG
	 );
	 set("objects", ([
		  __DIR__"npc/master" : 1,
	 ]));
	 set("exits", ([
		  "north"     : __DIR__"room_23",
		  "east"      : __DIR__"room_26",
		  "south"     : __DIR__"room_24",
		  "west"      : __DIR__"room_21",
	 ]));
	 create_room();


	 set("bwdhpk",1);setup();

	 call_out("open_basement",2);
}



void init() {
	 init_room();
	 call_out("open_basement",1);
}

void open_basement()
{

	 if( query("exits/down") ) return ;

	 if( !present("master") )
	 {
		if( !query("exits/down") )
			message("vision",HIR"ֻ�����һ���죬�����Զ�����һ�ȴ��š�\n\n"NOR,this_object() );
		 set("exits/down",__DIR__"room_29");
	 }
	 else delete("exits/down");

	 remove_call_out("open_basement");
	 call_out("open_basement",10);
}

//Cracked by Kafei
// sdong, 3/18/2000

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create()
{
        set("short","ʯ��");

        set("long",@LONG
����ɽʯ��������Խ�ɽׯ�У�Ҳ��֪ͨ���δ���ֻ��Ũ����죬Խ
��Խ����ɭ����ʱ����Ұ�޺����������������з�ë��
LONG);

          set("exits",([ "up" : __DIR__"etower4",
                         "down" : __DIR__"etower2",
                      ])
              );
          set("cost",2);
	create_room();
          set("bwdhpk",1);setup();
}

void init()
{
        init_room();
}


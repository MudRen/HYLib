//Cracked by Kafei
// sdong, 3/18/2000

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

void create()
{
        set("short","��̨");

        set("long",@LONG
�����Ȼ��һ���߸ߵ���̨�����������������š���������Կ����Խ�ɽׯ
��ÿһ�����䣬������ש���ߣ�������ޡ����������ڲص�ɱ����ȴ���˲�����
���������ָ��֣�һ�����ӵ������Դ���
LONG);

          set("exits",([ 
                         "down" : __DIR__"wtower6",
                      ])
              );
          set("cost",3);
          set("outdoors", "city");
		  create_room();
          set("bwdhpk",1);setup();
}


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

          set("exits",([ "up" : __DIR__"etower2",
                         "down" : __DIR__"room_09",
                      ])
              );
          set("cost",2);
	create_room();
          setup();
}

void init()
{
        init_room();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        object wp, *inv;
        int i, j=0;

        if ( dir == "up" )
        {
			inv = all_inventory(this_object());
    
			for (i = 0; i < sizeof(inv); i++)
				if ( objectp(inv[i]) && living(inv[i]) && (inv[i]->query("sjsz/team_name") != me->query("sjsz/team_name")) && inv[i]->query("id") !="sheying shi" )
                {
                        j++;
                        if (objectp(wp = inv[i]->query_temp("weapon")))
                                message_vision("$N��$n�ȵ�������аħ������Ҫ�����·���������������е�"
                                + wp->query("name")+ "��Ӧ����Ӧ��\n", inv[i], me); 
                        else 
                                message_vision("$N��$n�ȵ���ֻҪ���ڣ�����аħ���������������·��\n", inv[i], me);
                }
           
	        if (j) return notify_fail("\n");    
        }
        
        return ::valid_leave(me, dir);
}


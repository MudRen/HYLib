// /d/kunming/qiao
// netkill /98/8/14/


#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR "��ľ��" NOR);
        set("long", @LONG
һ����ľ�ţ�Ҳ��֪��ʲôʱ��������ģ���������ҡҡ�λΣ�����
Σ�գ���ʱҪ���ӵĻ���ֻ�����������������ȥ��ֻ������������һ
����ȥ���϶�û����
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"road6", 
                "north"  :__DIR__"road5",
                
        ]));
        set("objects", ([
            "d/kunming/npc/qiangdao" : 2,
	]));
        setup();
}

int valid_leave(object me, string dir)
{               if ( me->query_temp("dirs1") && (dir=="south"))
                return ::valid_leave(me, dir);

                if ( me->query_temp("dirs2") && (dir=="north"))
                return ::valid_leave(me, dir);

	        if ( !me->query_temp("dirs") && ( dir == "south" || dir =="north" ) &&
		objectp(present("qiang dao", environment(me))))
	        return notify_fail("ǿ������һ�� ��˵��������Ǯ������ţ�����������\n");
		
                return ::valid_leave(me, dir);

}


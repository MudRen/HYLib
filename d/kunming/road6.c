// /d/kunming/road6
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "�����ϰ�" NOR);
        set("long", @LONG
�������˳���������ֻ�����ι��������Ͻ�ˮ����ȥ��������
��һ�鱮(bei),ǰ�治Զ��������ľ�š�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"road7", 
                "north"  :__DIR__"qiao",
                
        ]));
         set("item_desc", ([
                "bei" : "һ��ʯ��������д�ţ�\n\n\n" +
                        "**************** \n" +
                        "* ��   ��   ͨ * \n" +
                        "**************** \n\n\n\n" ,
                 ]));

        setup();
        
}

int valid_leave(object me, string dir)
{
	if ( dir == "south" || dir == "north" )
            { me->delete_temp("dirs");me->delete_temp("dirs2");}
        if (dir == "north") me->set_temp("dirs1",1);

	return ::valid_leave(me, dir);
}
// /d/kunming/road5
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "��������" NOR);
        set("long", @LONG
�������˳���������ֻ�����ι��������Ͻ�ˮ����ȥ��������
��һ�鱮(bei),ǰ�治Զ��������ľ�š�
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"qiao", 
                "northup"  :__DIR__"road4",
                
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
	if ( dir == "south" || dir == "northup" ) 
            {me->delete_temp("dirs"); me->delete_temp("dirs1");}
        if (dir == "south") me->set_temp("dirs2",1);
	return ::valid_leave(me, dir);
}
// /d/xingxiu/shamo1.c
// Jay 3/17/96
#include <room.h>
inherit ROOM;
void create()
{ 
       set("short","���ԭ");
       set("long", @LONG
���߽���������಻���Ĵ��ԭ�������Ǵ�����ݣ�������Ļ�
�治���ߣ�������ƥ�����������ǵĺ����⡣
LONG);
        set("outdoors", "shamo");
        set("exits", ([
                "east" : __DIR__"caoyuan"+(1+random(4)),
                "west" : __DIR__"caoyuan"+(1+random(4)),
                "south" : __DIR__"caoyuan"+(1+random(4)),
                "north" : __DIR__"caoyuan"+(1+random(4)),
        ])); 
        set("no_select",1);            
        setup();
}

int valid_leave(object me, string dir)
{
        if ( dir == "west") me->add_temp("mark/steps",1);
        if ( dir == "east") me->add_temp("mark/steps",-1);

     if (me->query_temp("mark/steps") == 8){
         me->move(__DIR__"dongchengmen");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"�Ӷ��ߵĴ��ԭ���˹�����\n", ({ me }));
         return notify_fail("���۵ð���������߳��˴��ԭ��\n");
         }  
     if (me->query_temp("mark/steps") == -8){  
         me->move(__DIR__"caoyuan");
         me->delete_temp("mark/steps");
         tell_room(environment(me), me->name()+"�����ߵĴ��ԭ���˹�����\n", ({ me }));
         return notify_fail("���۵ð���������߳��˴��ԭ��\n");
         }
        return ::valid_leave(me,dir);
}

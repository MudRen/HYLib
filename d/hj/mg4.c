// mg4.c �Թ�
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "�߲��Թ�" NOR);
        set("long", @LONG
��Խ��Խ���£���֪��ǰ������ʲô����������������������
������������ǰ����
LONG);
        set("no_sleep_room", 1);
        set("exits", ([
              "east" : __DIR__"mg3",
              "west" : __DIR__"mg3",
              "south" : __DIR__"mg3",
              "north" : __DIR__"mg3",            
        ]));        
        setup(); 
}
int valid_leave(object me, string dir)
{
       if (dir == "west") me->add_temp("mark/steps",1);
       if (dir == "east") me->add_temp("mark/steps",-1);         
       if (me->query_temp("mark/steps") == 5){
            me->move(__DIR__"mg-indoor");
            me->delete_temp("mark/steps");
            return notify_fail("�������ţ�ͻȻ����ǰ���������һЩ������\n");
return 1;
         }  
     if (me->query_temp("mark/steps") == -5){  
           me->move(__DIR__"mg2");
           me->delete_temp("mark/steps");
           return notify_fail("�������ţ�ͻȻ����ǰ���������һЩ������\n");
return 1;
        }           
        return ::valid_leave(me, dir);
}

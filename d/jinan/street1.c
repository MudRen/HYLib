 // street1.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","���ϴ��");
  set("long",@LONG
���Ǽ��ϳǵĴ�֣�·���������ﲻ��������ȥ��������������������һ��
����Ǯ�˳����������������Ĳ�ҩ��Ҳ�������ʹ������Զ����ؤ��Ҳ��
�����������á��˴����Ǽ��ϳǵĳ��ţ�������������ɰ��Ķĳ������á���
����˲��Ǵ������棬���Ǵ�ͷɥ������ˮ�������ò����֡�
LONG
  );
  set("exits",([
         "north":__DIR__"gate",
         "south":__DIR__"street2",
                 //"east" : __DIR__"casino1",
               ]));
    set("outdoors", "jinan");
       set("objects", ([
                __DIR__"npc/mimicat" : 1,
       ]) ); 
        set("coor/x",30);
        set("coor/y",1970);
        set("coor/z",0);
        setup(); 
    replace_program(ROOM); 
}        

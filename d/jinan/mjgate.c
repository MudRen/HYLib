 // mjgate.c
#include <room.h>
inherit ROOM;
void create()
{
  set("short","�齫�ݴ�Ժ");
  set("long",@LONG
ÿ���ط����жĳ����еĶĳ��ڵ��ϣ��еĶĳ��ڵ��£��еĶĳ��������еĶ�
�����ܹ������еĶĳ��ĵúܴ��еĶĳ��ĵú�С��������ֻҪȥ�ģ�����ʱ����
���ܰ��Լ������Ŷ���������ӹٷ�Ϊ�˴���Ķģ��ر������е��齫�ݣ�����һ��
�ɳ��ӹٷ������齫�ݣ�ֻ��Ϊ���ô�����֡�
LONG
  );
  set("exits",([
         "east":__DIR__"street4",
         "west":__DIR__"mjroom",
               ]));
    set("objects", ([
    __DIR__"npc/girl" : 1,
                    ]) );
    set("outdoors", "jinan");
    set("no_magic",1);
    set("NONPC",1);
//    set("throw_exit", "east");
        set("coor/x",20);
        set("coor/y",1910);
        set("coor/z",0);
        setup();
    replace_program(ROOM); 
}        

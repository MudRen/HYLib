 // street3.c
#include <room.h>
inherit ROOM;
// #include "/questnpc/lovestory1/event_place.h"
void create()
{
  set("short","����̨");
  set("long",@LONG
������Ǽ��ϳ�ÿ������ʥ�˵ļ�̨��̨��������ʯ����һ����š�����
̨������һ����š�ʥ����Ȥ������˵������ӵ����������������������̨�£�
����̡���¡��������֮��������һһ�����ɼѻ��������ɣ������
�˶�����ݣ�����̨�������£��߸��������������࣬����Щ���ֵĺ�լ��
LONG
  );
  set("exits",([
         "northdown":__DIR__"street2",
         "southdown":__DIR__"street4",
         "westdown":__DIR__"qiyuan1",
               ]));
        set("objects", ([
        __DIR__"obj/shibei1" : 1,
//            "/obj/specials/ding/ding_jn" : 1,
                        ]) );
    set("outdoors", "jinan");
        set("coor/x",30);
        set("coor/y",1930);
    set("coor/z",20);
        setup();  
}  
/* int valid_enter(object me)
{ 
        if(me->query("lovestory1"))
                add_trigger_count(me);
        return 1;
}     */ 

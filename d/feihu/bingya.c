// ����
// by steel 
#include "ansi.h"
inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
	����֮��,˷���絶,�������������ۡ����Ϲ�ͺͺ�ģ��ƺ�ʲô
��û�С���ϸһ�������µ�������һ���ʯ����������Ȼ���ɵġ�    
LONG
	);
        set("objects",([
             __DIR__"obj/bigstone" : 1,
             ]) );
	setup();
	
}
void init()
{
  add_action("do_climb","climb");
 
}
int do_put(string arg)
{

}
int do_climb(string arg)
{
    object me;
    object obj;
    int dodge;
    me=this_player();
    if(!arg) return 0;
     if(arg!="down")
         return notify_fail("��Ҫ��ʲô��\n");
    message_vision(HIB"$Nץ�����¼��ʯ��,���ѵ�������ȥ��\n"NOR,me);
    dodge=me->query_skill("dodge",1);
    if(obj=me->query_temp("armor/boots"))
    {
      if(obj->query("id")=="snow boots")
       {
        if(dodge>80){
            me->add("jing",-80);
            me->add("qi",-80);
            tell_room(__DIR__"hill2",me->name()+"ƽ���Ĵ�����������\n");
            me->move(__DIR__"hill2");
            return 1;  
          }
      else
       {
            if(dodge<=60)
             {
               call_out("to_die",2);
               return 1;
             } 
             else
             { 
               call_out("to_yun",2);return 1;
              }
       }
     }
    }
    else
    {
      if(dodge<=60)
             {
               call_out("to_die",5);
               return 1;
             } 
             else
             { 
               call_out("to_yun",5);
               return 1;
             }
    }    
}

void to_die()
{
     message_vision(HIR"����!$N����һ��,�Ӱ����ˤ��������\n"NOR,this_player());  
     this_player()->die();
}
void to_yun()
{
     message_vision(HIR"����!$N����һ��,�Ӱ����ˤ��������\n"NOR,this_player());     
     this_player()->unconcious();
     this_player()->move(__DIR__"hill2");
}    

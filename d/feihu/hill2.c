//�캮ɽ
// by steel 
#include "ansi.h"
inherit ROOM;
//int to_die();
//int to_yun();

void create()
{
	set("short", "�캮ɽ��");
	set("long", @LONG
        ���������캮ɽ��ɽ��,ֻ���·�β�,��Ϊ�ն񡣾�����ɽ��֮
�ϣ���һ�����³��������ϸ���������Ϻ����и���ĺۼ����ƺ�����
˳������ȥ��    
LONG
	);
	
       set("exits", ([
		"southdown" : __DIR__"hill1",
        ]) ); 
	setup();
}
void init()
{
    add_action("do_climb","climb");
}
int do_climb(string arg)
{
    object me;
    object obj;
    int dodge;
    me=this_player();
    if(!arg) return 0;
    if(arg!="bingya")return notify_fail("��Ҫ��ʲô��\n");
    dodge=me->query_skill("dodge",1);
    if(obj=me->query_temp("armor/boots"))
    {
       message_vision(HIB"$N��ץ�������ϵ�ʯ�죬����������ȥ��\n"NOR,me);

      if(obj->query("id")=="snow boots")
       {
        if(dodge>80){
            me->add("jing",-80);
            me->add("qi",-80);
            tell_room(__DIR__"bingya",me->name()+"ƽ���Ĵ�����������\n");
            me->move(__DIR__"bingya");
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
               call_out("to_si",5);
               return 1;
             } 
             else
             { 
               call_out("to_yun",5);return 1;
             }
  }    
}

int to_si()
{
     message_vision(HIR"����!$N����һ��,�Ӱ����ˤ��������\n"NOR,this_player());  
     this_player()->die();
     return 1;
}
int to_yun()
{
     message_vision(HIR"����!$N����һ��,�Ӱ����ˤ��������\n"NOR,this_player());     
     this_player()->unconcious();
     return 1;
}

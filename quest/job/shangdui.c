//snowman 28/02/98
#include <ansi.h>
inherit ITEM;
int j=3;
void create()
{
        set_name("�����ڶ�", ({ "changfeng"}));
        set("unit", "ֻ");
        set_weight(90000000);
        set("long", "
һֻԶ���������ڶӣ���������˻���м��
��һ�����죬�ƺ�д�š������ھ֡��ĸ����֡�����\n");
        set("no_get", 1);
        set("no_drop", 1);
	 set("no_put",1);
}

void init()
{ remove_call_out("aaa");
  call_out("aaa", 120, this_object());  
  add_action("do_rob", "qiang");
}

int do_rob()
{
   object me, ob;   
   string arg;
   int stage, i;
   me = this_player();
   ob = this_object();
   stage = 0;
   arg = query("arg");

   if(!living(me)) return 0;
   if(!me->query_temp("rob_start")) 
       return notify_fail("�㵨�Ӳ�С�������ڳ����ھ�ͷ�ϴ�ע�⣿\n");
   if(objectp(present("biaoshi", environment(me))))
       return notify_fail("������ʦ�����书�������㻹���ȴ�����ǰ�����˵�ɣ�\n");  

   message_vision(HIY"$N����$n���һ����"+me->name()+"�ڴˣ��������ǵ�Ǯ������\n"NOR, me, ob);
   me->set_temp("xx_rob", 1);
   me->start_busy(3);
   remove_call_out("make_bs");
   call_out("make_bs", 1, me, ob); 
   return 1;     
}
void make_bs(object me, object ob)
{
   object obj, obj1;
	if (j>0){
	  obj = new(__DIR__"biaoshi");
         obj->move(environment(me));
	  obj->do_copy(me);
         obj1 = new(__DIR__"biaoshi");
         obj1->move(environment(me));
 	  obj1->do_copy(me);
          j=j-1;     }
else {
       message_vision(HIW"$N���Ѿ����˱������������Ĳ���ȫ�����ڻ��\n"NOR, me);    
       obj=new(__DIR__"red");
       obj->move(me);
       obj->set("owner", me->query("id"));
       me->add("combat_exp", 100);
       me->add("shen", -100);
	tell_object(me,"�㱻������\nһ�ٵ㾭��ֵ��\n");
       me->delete_temp("rob_start");
       me->delete_temp("xx_rob");
       me->delete_temp("rob_job");
       me->delete_temp("j");       
       message_vision("$Nת������Сɽ��Ͳ����ˡ�\n",ob);
       destruct(ob);
    }
}

void aaa(object me)
{
       message_vision("$Nת������Сɽ��Ͳ����ˡ�\n",me);       
       destruct(me);
       return;
}


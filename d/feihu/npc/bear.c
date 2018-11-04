//�����
//by steel
#include "ansi.h"
inherit NPC;

void create()
{
  set_name("�����",({"bear","bigbear"}));
  set("race","Ұ��");
  set("age", 5);
  set("long","����һͷ�����Ĵ���ܡ�ëɫ�����ܺã�\n");
  set("attitude","aggressive");
  
  set("str",60);
  set("cor",30);
 
  set("limbs",({ "ͷ��", "����", "�Ȳ�", "�β�","ǰ��",}) );
  set("verbs",({"bite"}) );
  set("combat_exp",50000);
  set_temp("apply/attack", 50);
  set_temp("apply/damage", 1000);
  set_temp("apply/armor", 100);
  set_temp("apply/defence",1000);  
  setup();
}

void init()
{  
    add_action("do_name","pou");
}

int do_name(string arg)
{
   object me,obj,heart;
   string str;
   me=this_player();
   obj=this_object();
   if(!living(obj)) 
   {
    message_vision(HIW"$N��ʬ�嶼���Ź�,�㻹������?\n"NOR,me); 
    return 0;            
   }  
   if(!arg||arg=="") return notify_fail("�����ʿ���ô��\n");
   sscanf(arg,"%s",str);
   if(str!="bear")   return notify_fail("����û���ⶫ��!\n");
   if(!obj->query_temp("yun"))
   {
    message_vision(HIW"$Nû�������ǻ����������\n"NOR,me); 
    return 1;                                     
   }
  else
  {
   heart=new("/d/feihu/obj/bearheart");
   heart->set_amount(1);
   message_vision(HIR"$N������ͷ�������ܣ�����������ز���ȥ...\n"NOR,
   me);
   heart->move(this_player());
   message_vision(HIY"$N�õ���һ������!!"NOR,me);
   obj->delete_temp("yun");     
   obj->die();
   return 1;
   }
}

void unconcious()
{
        this_object()->remove_all_enemy();
        message("system", HIR "\n�����ǰһ�ڣ�����ʲôҲ��֪����....\n\n" NOR,
		this_object());
	write(HIR"\n����ܿ첻����,�춯��!!\n"NOR);
	set("jing", 0);
	set("qi", 0);
	
	COMBAT_D->announce(this_object(), "unconcious");

	call_out("revive", random(100 - query("con")) + 30);
        this_object()->set_temp("yun",1); 
}

varargs void revive()
{
  ::revive();
  this_object()->set_temp("yun",0);
} 

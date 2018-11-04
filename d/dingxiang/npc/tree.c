
inherit ITEM;

void create()
{
   set_name("����", ({ "tree" }) );
   set_weight(4000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "��");
     set("long","����һ�ô�������������и�ӥ����\n");
   }
   
   setup();
}

int is_get_of(object ob,object obj)
{
   return notify_fail("�밮����ľ��\n");
}

void init()
{
  object ob;
  
  add_action("do_claw","pa");
  
  ob=previous_object();
  
  if(!ob->query("bai_dun_quest_obj")) return;
  if(!query("no_hawk")){
    set("no_hawk",1);
    remove_call_out("hawk_come");
    call_out("hawk_come",15,ob);
  }
}

void hawk_come(object ob)
{
  if(!ob) return;
  
  tell_object(environment(this_object()),"ֻ��һ����Х��һֻӥ�����Ϸ��£���"+ob->name()+"���߷��ˣ�\n");
  destruct(ob);
  set("hawk_fly",1);
}

int do_claw()
{
   object ob;
   
   ob=this_player();
   
   if(!query("hawk_fly"))
   return notify_fail("������ֻӥ��������ȥ������ģ�\n");
   
   message_vision("$N��������ȥ��\n",ob);
   
   ob->move(__DIR__"shuding");
   return 1;
}
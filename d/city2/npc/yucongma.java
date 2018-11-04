#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name(HIC "������" NOR, ({ "yu cong ma","yu","ma"}));
	set("race", "Ұ��");
	set("gender", "����");
	set("age", 2+random(3));
	set("long", "����һƥ������������ǧ�ҹ�а˰١�\n"+
		"��ҿ���������ȥ�κεط�(ride/down)��\n");
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("combat_exp",50000);
	set("attitude", "peaceful");

	set("limbs", ({ "ͷ��", "����", "β��","����","ǰ��" }) );
	set("verbs", ({ "bite","hoof","knock" }) );
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	setup();
}

void init()
{
 add_action("do_ride", "ride");
 add_action("do_go", "go");
 add_action("do_down", "down");
}


int do_ride ( )
{
    string dir,dir2;
    object ob = this_player () ;
    if(ob->query("meili")<20)
    {
      message_vision("$NһԾ�������������ֻ�����������쳤Х��ͻȻ��Ȼһ��......\n"
                     HIR "��$N�ݺ�ˤ���˵���,���$N���˵����ˡ�\n" NOR,ob);
      ob -> receive_damage ("qi",50) ;
      ob -> receive_wound  ("qi",50) ;
      remove_call_out("kill_ob");
      call_out("kill_ob", 1, ob);
      return 1;
    }
   if( objectp(query("rider"))) 
   {
    return notify_fail("���������Ѿ������ˣ�\n" ) ;
   }
   else
   {    
   ob->set_temp("onhorse",1);
   this_object()->set("rider",this_player());
   message_vision("$NһԾ�������������\n" , ob );
   this_object()->set_leader(this_player());
   command("follow "+ob->query("id"));
   write("������Ҫȥ�ĵ���, ʾ��(go baituo):\n"+
   "baituo: ����ɽ\nshaolin: ������\nyangzhou: ���ݳ�\n"+
   "beijing: ������\ntaohua: �һ���\nxingxiu: ���޺�\n"+
	"xueshan: ѩɽ��\n"+
  "huashan: ��ɽ\nhaigang: ����\n");
   return 1; 
  }	
}

int do_down()
{
  object ob;
  ob = this_player () ;
  if(!objectp(query("rider"))) return notify_fail("����û�ˡ�\n");
  if(ob->query_temp("onhorse"))
  {
  message_vision("\n$N����һת��Ծ����������̬ʮ��������\n" , ob );
  delete("rider");
  command("follow none");
  ob->delete_temp("onhorse");
  }
  else 
  switch(random(3))
  {
   case 0: 
   message_vision("\n$Nһ�Ѱ����ϵ��������������Լ�����ȥ��\n" , ob );
   command("follow none");
   query("rider")->delete_temp("onhorse");
   delete("rider");
   ob->set_temp("onhorse");
   break;
   case 1: 
   case 2:
   message_vision("\n$N������ϵ�����������,��û�гɹ���\n" , ob );
   }	  
  return 1;
 }

int do_go ( string arg )
{
   object ob ;
   ob = this_player () ;
   if( !arg || arg=="" )  return notify_fail("��Ҫȥ�Ķ���\n");
   if(!ob->query_temp("onhorse")) return notify_fail("�㻹û����\n");
   if( arg=="baituo" ) 
   {
   message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
   ob->move("/d/baituo/damen");
   this_object()->move("/d/baituo/damen");
   message_vision("\nֻ��$N������������������\n" , ob );
   message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="xueshan" ) 
   {
   message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
   ob->move("/d/xueshan/shenghu") ;
   this_object()->move("/d/xueshan/shenghu");
   message_vision("\nֻ��$N������������������\n" , ob );
   message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="taohua" ) 
   {
   message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
   ob->move("/d/taohua/dayuan") ;
   this_object()->move("/d/taohua/dayuan");
   message_vision("\nֻ��$N������������������\n" , ob );
   message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="huashan" ) 
   {
   message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
   ob->move("/d/huashan/path1") ;
   this_object()->move("/d/huashan/path1") ;
   message_vision("\nֻ��$N������������������\n" , ob );
   message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
   ob->delete_temp("onhorse");
   delete("rider");
   command("follow none");
    return 1 ;
   }
   if( arg=="beijing" ) 
   {
   message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
   ob->move("/d/city2/tian_anm") ;
   this_object()->move("/d/city2/tian_anm") ;
   message_vision("\nֻ��$N������������������\n" , ob );
   message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="xingxiu" ) 
   {
   message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
   ob->move("/d/xingxiu/xxroad2") ;
   this_object()->move("/d/xingxiu/xxroad2") ;
   message_vision("\nֻ��$N������������������\n" , ob );
   message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="shaolin" ) 
   {
   message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
   ob->move("/d/shaolin/shanmen") ;
   this_object()->move("/d/shaolin/shanmen") ;
   message_vision("\nֻ��$N������������������\n" , ob );
   message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="yangzhou" ) 
   {
   message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
   ob->move("/d/city/guangchang") ;
   this_object()->move("/d/city/guangchang") ;
   message_vision("\nֻ��$N������������������\n" , ob );
   message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   if( arg=="haigang" ) 
   {
   message_vision("\nֻ��$N������һ�У���������ǰ���۶�ȥ��\n" , ob );
   ob->move("/d/city2/haigang") ;
   this_object()->move("/d/city2/haigang") ;
   message_vision("\nֻ��$N������������������\n" , ob );
   message_vision("\n������ǰ��$N����һת��Ծ����������̬ʮ��������\n" , ob );
   delete("rider");
   ob->delete_temp("onhorse");
   command("follow none");
    return 1 ;
   }
   return notify_fail("û������ط�\n");
}

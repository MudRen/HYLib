
inherit NPC;

void create()
{
   set_name("С��",({ "xiao he","he" }) );
        set("gender", "Ů��" );
        set("age", 22);
   set("long", "����[����¥]�Ĺ���С�ɡ���\n");
   set("jinv",1);
   set("combat_exp", 1000);
   set("str", 10);
   set("per", 25);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/baishayi")->wear();
  
}

void init()
{
	object ob,ob2;
	ob=this_player();
	ob2=this_object();
	::init();
	if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	call_out("welcome",1,ob,ob2);
	
}

void welcome(object ob,object ob2)
{
   if(!ob||!present(ob,environment())||ob2->is_fighting()) return;
	switch(random(2))
	{
	case 0: message_vision("$NЦ��:�ϣ���λ�͹٣���������!\n",ob2);break;
	case 1: message_vision("$N��$nЦ��������[����¥]�Ĺ���ɶ���Ư���ģ��������⣡\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}


inherit NPC;

void create()
{
   set_name("С��",({ "beauty" }) );
        set("gender", "Ů��" );
        set("age", 18);
   set("long", "�����ϲ�����Ů��������۶�������;�ɫ��\n");
       
   set("combat_exp", 10000);
   set("str", 14);
   set("per", 27);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/shayi")->wear();
   add_money("coin", 50);
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
	case 0: message_vision("$N΢΢Ц��Ц��\n",ob2);break;
	case 1: message_vision("$N��$n���˸���.\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}


inherit NPC;

void create()
{
   set_name("С�к�",({ "boy" }) );
        set("gender", "����" );
        set("age", 12);
   set("long", "����һ��С�к�������������δ�ѣ�ͯ�����֡�\n");
       
   set("combat_exp", 50);
   set("str", 10);
   set("per", 22);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
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
	case 0: message_vision("$N����Ц��:�⼸���˺öడ��̫������!\n",ob2);break;
	case 1: message_vision("$N����ؿ��˿�$n\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}


inherit NPC;

void create()
{
   set_name("����",({ "old" }) );
        set("gender", "����" );
        set("age", 60);
   set("long", "����һ���þ��¹ʵ����ߡ�\n");
       
   set("combat_exp", 150);
   set("str", 18);
   set("per", 20);
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
	case 0: message_vision("$N̾��������֮�������հ���!\n",ob2);break;
	case 1: message_vision("$N���˿�$n��˵������λ"+RANK_D->query_respect(ob)+",Ҳ���������ֵ���?\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}

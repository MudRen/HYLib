
inherit NPC;

void create()
{
   set_name("��С��",({ "xiao er","xiao","er" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "�������С��ջ�ĵ�С����ÿ��æ��æȥ��\n");
       
   set("combat_exp", 200);
   set("str", 18);
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
	case 0: message_vision("$NЦ��:�𿴱���ջС����������!\n",ob2);break;
	case 1: message_vision("$N��$nЦ������λ�͹�����!\n",ob2,ob);
	}
	remove_call_out("welcome");
	return;
}

int accept_object(object who,object ob)
{
	if(ob->query("money_id") && ob->value() >= 500)
	{tell_object(who,"��С��΢Ц������λ�͹٣������ȥ��Ϣ��!\n");
	 who->set_temp("gived_money",1);
	}
    else tell_object(who,"��С��Ц��������ס�ޣ�һ��5������.\n");
    return 1;
}

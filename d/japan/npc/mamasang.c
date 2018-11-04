
inherit NPC;
void create()
{
        set_name("����ɣ",({"mama sang","laobao"}));
	set("gender","Ů��");
	set("age",40);
       set("title","�񻧼˹�");
	set("long",
                 "���ú������޵�����Ů�ӣ����ͷ�����������Ц�Ŀ����㡣\n");
	set("combat_exp",2000);
	set_temp("apply/attack",15);
	set_temp("apply/defense",15);
	set_skill("unarmed",20);
	set("mingwang",-1);
	set_skill("dodge",30);
	set("attitude", "friendly");
	setup();
         carry_object(__DIR__"obj/hefu")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	if(ob->query("gender")=="Ů��")	{
               message_vision("$n����$Nҡͷ������ɲ���"+
             RANK_D->query_respect(ob)+"���ĵط�����\n",ob,this_object());
		return ;
	}
	switch( random(2) ) {
		case 0:
                message_vision("$n������$N������λ"+
             RANK_D->query_respect(ob)+"���ǿ����Ҽ���λ�����˰ɡ�\n",ob,this_object());
			break;
		case 1:
          message_vision("$n��ǰ��������ס$N���ֽе��������ǣ��ӿ�����\n",ob,this_object());
			break;
                           }
}
int accept_fight(object who)
{
	int i;
	object npc,env,*inv;
	npc=new(__DIR__"dashou");
	env=environment(this_object());
         message_vision("$n����$N��Ц�źȵ����ҵ�������Ұ����\n"+
        "�����ģ���\n���������Ĵ������̽�$N��Χ��������\n",who,this_object());
        if(sizeof(children(base_name(npc)))<=4 && (int)query("have_ds")<=4)
        {
                add("have_ds",1);
                npc->move(env);
        }
        else    destruct(npc);
	this_object()->kill_ob(who);
	inv=all_inventory(env);
	for(i=0;i<sizeof(inv);i++)	{
		if (inv[i]->query("id")!="dashou")	continue;
		inv[i]->kill_ob(who);
	}
	return 1;
}

inherit NPC;

void create()
{
	set_name("��С��",({"xiao er","xiao","er"}));
	set("gender", "����" );
	set("age", 20);
	set("long",
		"ü��Ŀ���С��ƣ�����Ц�����ģ�æ�ò����ֺ���\n");
	set("combat_exp",200);
	set_temp("apply/defense",10);
	set_temp("apply/attack",5);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	setup();
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
			message_vision("��С���������,æӭ������Ц������λ"+
			RANK_D->query_respect(ob)+"�����������!\n",ob);
}

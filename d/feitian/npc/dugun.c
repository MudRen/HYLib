//dipi.c by diabio

inherit NPC;
void create()
{
	set_name("�Ĺ�",({"du gun","dugun"}));
	set("gender", "����" );
	set("age",25);
	set("long",
		"һ��ߺ�ȵ����𾢵ĶĹ���\n");
	set("combat_exp",1000);
	set_temp("apply/attack",10);
	set_temp("apply/defense",10);
	set_skill("unarmed",20);
	set("mingwang",-1);
	set_skill("dodge",20);
	set("attitude", "friendly");
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
	switch( random(2) ) {
		case 0:
			say("�Ĺ��������������������汳���ֱ���֮��Ӯ�ˡ�\n");
			break;
		case 1:
			message_vision("�Ĺ�����$NЦ����"+RANK_D->query_respect(ob)+
			"ҲҲ��һ�Ѱɡ�\n",ob);
			break;
                           }
}

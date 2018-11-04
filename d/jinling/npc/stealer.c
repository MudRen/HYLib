// beggar.c

inherit NPC;

void create()
{
        set_name("����ؤ", ({ "beggar" }) );
        set("gender", "����" );
        set("age", 58);
        set("long", "һ���������۵�����ؤ��\n");
        set("combat_exp", 10000);
        set("str", 27);
        set("force", 200);
        set("max_force", 200);
        set("force_factor", 2);
	 set_skill("dodge",150);
	 set_skill("move",150);
	 set("env/wimpy",70);	
        setup();
        set("chat_chance", 40);
        set("chat_msg", ({
                (: random_move :)
        }) );
        carry_object(__DIR__"obj/linen")->wear();
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


int accept_object(object me, object obj)
{
        command("smile");
        command("say ��л��λ" + RANK_D->query_respect(me) + 
"��������һ�����кñ��ģ�");
        return 1;
}

int accept_fight(object me)
{
        command("say " + RANK_D->query_respect(me) + 
"�������֣���ͷ�ҷ�����ǡ�\n");
        return 1;
}
 
void greeting(object ob)
{
	object coin_ob,silver_ob,gold_ob;
	int cc,sc,gc;
	coin_ob = present("coin_money", ob);
	silver_ob = present("silver_money", ob);
	gold_ob = present("gold_money", ob);
	if(objectp(coin_ob)) cc=coin_ob->query_amount();
	if(objectp(silver_ob)) sc=silver_ob->query_amount();
	if(objectp(gold_ob)) gc=gold_ob->query_amount();
	if(wizardp(ob)) 
        tell_object(ob, sprintf("����ؤ���ĸ����㣺�������� %d coin,%d silver, %d gold.\n",cc,sc,gc));
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
		case 3:
		case 4:
			if(random((int)ob->query("combat_exp")+10000) > (int)ob->query("combat_exp")) {
			say("����ؤ�����㷢��һ����Ц����\n");
			if(objectp(coin_ob)) coin_ob->move(this_object());
			if(objectp(silver_ob)) silver_ob->move(this_object());
			if(objectp(gold_ob)) gold_ob->move(this_object());
			}			
			break;
		case 1:
			say( "����ؤ��������ؿ����㣬������λ���ĵ�" + RANK_D->query_respect(ob)+ "�����Ҽ������Ӱ�...\n");
			break;
		case 2:
			say( "����ؤ������������ȥ��ҡҡͷ��̾��������ҡ��ҡͷ��\n");		break;
	}
}

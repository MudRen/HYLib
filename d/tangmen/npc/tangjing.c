// d/tangmen/npc/tangjing.c


inherit NPC;

void greeting(object);
void init();
void serve_tea(object);
void delete_served();

void create()
{
	set_name("�ƾ�", ({"tang jing", "jing"}) );
	set("nickname", "С�����");
	set("gender", "Ů��" );
	set("age", 12+random(6));
	set("long",
	   "�������ŵ�����������С��һ����������ֻ��ʮ�����ꡣ\n"
	  "������������������ϲ��������̫̫����ר��������к����õĿ��ˡ�\n");
	set("attitude", "friendly");
    set("shen_type", 1);

        set("str", 20);
        set("int", 28);
        set("con", 24);
        set("dex", 20);

        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);

		set("combat_exp", 1000+random(800));
        set("score", 1000);

        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 15+random(10));
        set_skill("parry", 20);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 3);

        create_family("����", 9, "����");

        setup();
        
		carry_object("/d/tangmen/obj/shujin")->wear();
		
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

	say("�ƾ�Ц������˵������λ" + RANK_D->query_respect(ob)
	     + "����������" + "����͸����ϲ衣\n");
}


void serve_tea(object who)
{
	object obt, obc, obn;
	object room;

	if( !who || environment(who) != environment() ) return;

	if( !who->query_temp("marks/sit") ) return;
	
	if( !objectp(room = environment()) ) return;

	if ( (int)who->query_temp("tea_cup") <= 0 )
	{
	 	obn = new("d/tangmen/obj/dawancha");
		obn->move(room);
		message_vision("�ƾ�������������������ϵĴ���赹����\n",
			who);
	} else 
	{
		who->add_temp("tea_cup", -1);
	 	obn = new("d/tangmen/obj/tea");
		obn->move(room);
		message_vision("�ƾ��ó������µ���ɰ�������˱���裬�������ϣ�\n",
			who);
	}

 	obn = new("d/tangmen/obj/shuimitao");
	obn->move(room);
	message_vision("�ƾ��ó�һ��ˮ���ң��������ϣ�\n", who);
	
	return;
}

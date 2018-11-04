// dujie.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("�ɽ�", ({ "du jie", "jie" }) );
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",
		"����һ��������ݣ��ݹ��㶡����ɮ������ɫ�Ұף���һ��ֽһ����\n");

	set("attitude", "peaceful");
	set("combat_exp", 1000000);
	set("score", 200000);

	set("str", 30);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 30);

	set("qi", 4000);
	set("max_qi", 2000);
	set("neili", 4000);
	set("max_neili", 2000);
	set("jiali", 90);

	create_family("������", 1, "����");
	assign_apprentice("����", 0);

	set_skill("force", 150);
	set_skill("whip", 180);
	set_skill("parry", 180);
	set_skill("dodge", 180);

	set_skill("hunyuan-yiqi", 150);
	set_skill("riyue-bian", 180);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set("inquiry", ([
		"�����"     : (: ask_me :),
	]));

    set("count", random(10)-8);

	setup();

	carry_object("/d/shaolin/obj/changbian")->wield();
}

void init()
{
	object me, ob;
	mapping fam;

	me = this_player();
	ob = this_object();

	::init();
	if( interactive(me) ) 
	{
		if ( mapp(fam = me->query("family")) && fam["family_name"] == "������" 
		&& fam["generation"] == 36 ) return;

		if ( mapp(fam = me->query("family")) && fam["family_name"] == "������" 
		&& fam["generation"] > 36 		
		&& me->query("qi") < 50 ) 
		{
			me->move("/d/shaolin/qyping");
			me->unconcious();
			return;
		}

		COMBAT_D->do_attack(ob, me, query_temp("weapon") );
		
		me->set_temp("fighter", 1);

		ob->fight_ob(me);
		me->fight_ob(ob);

		call_out("halt", 10);

		return;
	}

	return;
}

void halt()
{
	command("halt");
}

string ask_me()
{
	mapping fam; 
	object ob;
	
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 5000 )
	{
		command("say ���󱲣����δ�ɣ�����͵���շ�ħȦ�������������������㣡");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("jingang zhao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�������Ҿ��������ϣ�����̰�����У�";

	if ( present("jingang zhao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�������Ҿ�����������ȡ�ߣ�����̰�����У�";

	if ( present("fumo dao", this_player()) || present("fumo dao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"ȡ�˷�ħ�����Ͳ������ý���֣�ĪҪ̰�����У�";

	if (query("count") < 1)
		return "��Ǹ���������ˣ�������Ѿ�����ȡ���ˡ�";

	ob = new("/d/shaolin/obj/jingang-zhao");
	ob->move(this_player());

	add("count", -1);

	message_vision("\n�ɽ�һ�����Ե�����$N���ã�Ť������������ȡ������ֵݸ�$N��\n\n", this_player());

	return "���ܰ����������ϲ���������������޲�����ȷʵ�������������־�������ˣ�";
}

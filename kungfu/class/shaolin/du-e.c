// due.c

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
	set_name("�ɶ�", ({ "du e", "e" }) );
	set("title", "���ֳ���");
	set("gender", "����");
	set("age", 90);
	set("long",
		"����һ��������ݣ��ݹ��㶡����ɮ������ɫ�ݻƣ���ͬһ�ο�ľ��\n");

	set("attitude", "peaceful");
	set("class", "bonze");
	set("combat_exp", 8500000);
	set("score", 200000);

	set("str", 36);
	set("int", 36);
	set("cor", 30);
	set("cps", 30);
	set("con", 36);
	set("jing", 4000);
	set("max_jing", 4000);

	set("qi", 14000);
	set("max_qi", 12000);
	set("neili", 14000);
	set("max_neili", 15000);
	set("jiali", 90);

	create_family("������", 35, "����");
	assign_apprentice("����", 0);

	set_skill("force", 250);
	set_skill("club", 300);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);
	set_skill("hunyuan-yiqi", 200);
	set_skill("weituo-chu", 300);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "yijinjing");
	map_skill("club",  "weituo-chu");
	map_skill("parry", "weituo-chu");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 199);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 390);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 200);
	set_skill("zui-gun", 200);
	set_skill("buddhism", 200);
	map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	map_skill("club", "weituo-chu");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "club.leidong" :),
                (: perform_action, "club.zuijiu" :),
                            }) );

	set("inquiry", ([
		"��ħ��"     : (: ask_me :),
	]));
	set("count", random(10)-8);
        set_temp("apply/attack", 150);
        set_temp("apply/defense", 100);
        set_temp("apply/armor", 100);
        set_temp("apply/damage", 100);

	setup();
	carry_object("/d/shaolin/obj/jingangchu")->wield();
}

void init()
{
	object me, ob;
	mapping fam;

	me = this_player();
	ob = this_object();

	::init();
    if (environment(ob)->query("short")=="��շ�ħȦ"){
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

		me->set_temp("3du-ok",1);
		COMBAT_D->do_attack(ob, me, query_temp("weapon") );
		
		me->set_temp("fighter", 1);

		ob->fight_ob(me);
		me->fight_ob(ob);

		call_out("halt", 10);

		return;
	}
}
	return;
}

void halt()
{
	command("say �ðɣ����ס�֣� ����һ���ʲô��Ҫ˵��");
	command("halt");
}

string ask_me()
{
	mapping fam; 
	object ob;
        	
    if (environment(this_object())->query("short")=="��շ�ħȦ"){
	if ( !this_player()->query_temp("fighter") 
	||    this_player()->query("combat_exp") < 5000 )
	{
		command("say ���󱲣����δ�ɣ�����͵���շ�ħȦ�������������������㣡");
		this_object()->kill_ob(this_player());
		this_player()->kill_ob(this_object());
	}

	if ( present("fumo dao", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�ѣ����Ҿ��������ϣ�����̰�����У�";

	if ( present("fumo dao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"����ֻ��һ�ѣ����Ҿ�����������ȡ�ߣ�����̰�����У�";

	if ( present("jingang zhao", this_player()) || present("jingang zhao", environment()) )
		return RANK_D->query_respect(this_player()) + 
		"ȡ�˽���֣��Ͳ������÷�ħ����ĪҪ̰�����У�";

	if (query("count") < 1)
		return "��Ǹ���������ˣ���ħ���Ѿ�����ȡ���ˡ�";

	ob = new("/d/shaolin/obj/fumo-dao");
	ob->move(this_player());
        this_player()->start_busy(1);
	add("count", -1);

	message_vision("\n�ɶ�Цһ�������ͷ��������������ȡ����ħ������$N��\n\n", this_player());

	return "���Ȼ�ܴ�����շ�ħȦ������Ȼ�ǵ��������еķǷ������ѵ����ʷ������ˣ�";
}
else	return "���ڲ��������£���ʲôҲ���ش�";
}
#include "/kungfu/class/shaolin/du.h"

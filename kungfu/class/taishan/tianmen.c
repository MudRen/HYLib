// Last Modified by winder on Aug. 25 2001
// tianmen.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("���ŵ���", ({ "tianmen daoren", "daoren", "tianmen" }) );
	set("gender", "����");
	set("title", HIG"̩ɽ�ɵ�ʮ��������"NOR);
	set("class", "taoist");
	set("age", 45);
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 22400);
	set("max_neili", 22400);
	set("max_qi", 22000);
	set("max_jing", 21200);
	set("combat_exp", 8000000);
	set("shen_type", 1);

	set_skill("strike", 150);
	set_skill("kuaihuo-strike", 310);
	set_skill("sword", 350);
	set_skill("taishan-sword", 320);
	set_skill("shiba-pan", 320);
	set_skill("force", 150);
	set_skill("panshi-shengong", 350);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("fengshenjue", 310);
	set_skill("dramaturgy", 380);
	set_skill("horticulture", 380);
	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.heru" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	set_temp("apply/attack",180);
	set_temp("apply/defense",180);
	set_temp("apply/armor",600);
	set_temp("apply/damage",600);
	
	create_family("̩ɽ��", 13, "����");
	setup();

	carry_object(__DIR__"houjian")->wield();
	carry_object(__DIR__"daopao")->wear();
	}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
        add_action("do_qiecuo","qiecuo");
}

void greeting(object ob)
{
	string family;

	family=(string)ob->query("family/family_name");
	if(family!="̩ɽ��")
		command("say "+RANK_D->query_respect(ob)+"���Ǽ�����̩ɽ�ɣ����ܹ���ɣ�");
	else command("nod "+ob->query("id"));
}

void attempt_apprentice(object ob)
{
	if((int)ob->query("shen")<50000)
	command("say ��̩ɽ�ɵ��Ӷ�����������֮����"+RANK_D->query_respect(ob)+"�����Ĳ�������");
	else
		if((int)ob->query_skill("panshi-shengong",1) < 100)
			command("say ��ı����ķ����ö����ϰ��");
		else
		{
			command("say �ð������Ҿ�������ɡ�");
			command("recruit " + ob->query("id") );
		}
}


// Last Modified by Winder on May. 29 2001
// Npc: /d/nanshaolin/npc/seng-bing3.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("����ɮ��", ({ "seng bing", "seng", "bing"}));
	set("long",
		"����һλ��ĸߴ��׳��ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У���һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n"
	);

	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 40);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_qi", 3500);
	set("max_jing", 3300);
	set("neili", 3500);
	set("max_neili", 3500);
	set("jiaji", 50);
	set("combat_exp", 310000);
	set("score", 1);

	set_skill("force", 30);
	set_skill("yijinjing", 330);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 330);
	set_skill("strike", 30);
	set_skill("banruo-zhang", 330);
	set_skill("claw", 30);
	set_skill("longzhua-gong", 330);
	set_skill("blade", 30);
	set_skill("cibei-dao", 330);
	set_skill("parry", 30);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("claw", "longzhua-gong");
	map_skill("parry", "cibei-dao");
	map_skill("blade", "cibei-dao");
	prepare_skill("strike", "banruo-zhang");
	prepare_skill("claw", "longzhua-gong");

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("unarmed", "banruo-strike");
	map_skill("parry", "cibei-dao");
	map_skill("blade", "cibei-dao");

        create_family("��������", 22, "����");
	setup();

	carry_object(__DIR__"jiedao")->wield();
	carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

void init()
{
	object me, ob;
	mapping fam;

	::init();

	ob = this_player();
	me = this_object();
	
	if (interactive(ob) && !environment(ob)->query("no_fight") &&
		!ob->query("luohan_winner") && !present("yingxiong ling", ob) 
	&& ( (fam = ob->query("family")) && fam["family_name"] != "��������" ) )
	{
		if( !ob->query_temp("warned") )
		{
			command("say ����˭��  ��ô�����������������ˣ���");
			command("say ����������뿪���´ο����������ģ�");
			ob->set_temp("warned", 1);
		}
		else if( ob->query_temp("stay") < 10 ) ob->add_temp("stay", 1);
		else {
			command("say �󵨿�ͽ�����Ҵ�����������������Ұ����\n");
			me->set_leader(ob);
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
		}
	}       

}

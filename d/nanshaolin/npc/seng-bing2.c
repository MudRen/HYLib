// Last Modified by Winder on May. 29 2001
// Npc: /d/shaolin/npc/seng-bing2.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ִ��ɮ��", ({ "seng bing", "seng", "bing" }));
	set("long", "����һλ���ĸߴ������ɮ�ˣ����۴�׳��������Բ�����ֱֳ�\n"
		"�У�����һϮ�Ҳ�������ģ��ƺ���һ�����ա�\n");

	set("gender", "����");
	set("attitude", "peaceful");
	set("class", "bonze");

	set("age", 25);
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

	set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :)
	}) );

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

        create_family("��������", 22, "����");
	setup();

	carry_object(__DIR__"jiedao")->wield();
	carry_object("/d/shaolin/obj/dao-cloth")->wear();
}

void init()
{
	object me, ob;
	ob = this_player();
	me = this_object();
	
	::init();

	if ( interactive(ob) && !environment(ob)->query("no_fight") )
	{
		if ( ob->query("guilty") == 1 )
		{
			if ( random(2) ==1 )
			command("say ������Ű��࣬�����ӣ� �����ٵ�����Ժ���\n");
			me->set_leader(ob);
			remove_call_out("fight_ob");
			call_out("fight_ob", 1, ob); 
		}       
		if ( ob->query("guilty") >= 2 )
		{
			if ( random(2) ==1 )
			command("say ����Ժ����ʦ����ȥ�����˴���ɽ���� ��\n");
			me->set_leader(ob);
		}       
	}
	else if( environment(ob)->query("no_fight") ) me->set_leader(0);
}
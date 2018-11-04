// Last Modified by Winder on May. 29 2001
// Npc: /kungfu/class/nanshaolin/dapi.c

#include "da.h"
#include "ansi.h"
inherit NPC;
inherit F_MASTER;
string ask_me();

void create()
{
	set_name("��ƣ��ʦ", ({ "dapi dashi", "dapi", "dashi"}));
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 50);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 2000);
	set("max_jing", 1200);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali",200);
	set("combat_exp", 1000000);
	set("score", 5000);
	set_skill("zhanzhuang-gong", 220);
	set_skill("shaolin-cuff", 220);
	set_skill("shaolin-leg", 220);
	set_skill("yiwei-dujiang", 220);
	set_skill("boluomi-hand", 220);
	set_skill("jingang-strike", 220);
	set_skill("wuxiang-finger", 220);
	set_skill("ruying-leg", 220);
	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 150);
	set_skill("force", 150);
	set_skill("yijinjing", 150);
	set_skill("dodge", 150);
	set_skill("shaolin-shenfa", 220);
// basic skill begin
	set_skill("hunyuan-yiqi", 220);
	set_skill("luohan-quan", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("sanhua-zhang", 220);
	set_skill("ranmu-daofa", 220);
	set_skill("weituo-gun", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("banruo-zhang", 220);
// basic skill end
// ������
	set_skill("leg", 150);
	set_skill("zui-gun", 220);
	set_skill("nianhua-zhi", 220);
	set_skill("club", 150);
	set_skill("weituo-chu", 220);
	set_skill("zui-gun", 220);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("leg", "nianhua-zhi");
	map_skill("club", "zui-gun");
	map_skill("parry", "zui-gun");

	prepare_skill("leg", "nianhua-zhi");
	
	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({		
		(: exert_function, "roar" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );

	create_family("��������", 19, "����");
	setup();
	carry_object(__DIR__"qimeigun")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}


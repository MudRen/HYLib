// yuanyu.c
// Last Modified by winder on May. 29 2001

#include "yuan.h";
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("Ԫ��", ({ "yuan yu", "yu", "yuan" }));
	set("long","����һλ�еȸ��ӵĺ��У���һϮ�಼������ġ�̫��Ѩ΢͹��˫Ŀ��������\n");
	set("nickname", "�޺�Ժ�ǻ��޺�");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 30);
	set("dex", 20);
	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 3000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("yijinjing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("cuff", 100);
	set_skill("luohan-quan", 100);
	set_skill("club", 100);
	set_skill("weituo-chu", 100);
		set_skill("zhanzhuang-gong", 260);
	set_skill("shaolin-cuff", 260);
	set_skill("shaolin-leg", 260);
	set_skill("yiwei-dujiang", 260);
	set_skill("boluomi-hand", 260);
	set_skill("jingang-strike", 260);
	set_skill("wuxiang-finger", 260);
	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("club", "weituo-chu");
	map_skill("parry", "weituo-chu");
	prepare_skill("cuff", "luohan-quan");

	create_family("��������", 20, "����");

	setup();
	carry_object(__DIR__"qimeigun")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}

void init()
{
	object ob;

	::init();
	add_action("do_nod", "nod");
}


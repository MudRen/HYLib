// lingqing.c �����ʿ

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����ʿ", ({ "lingqing jushi", "jushi", "lingqing" }) );
	set("gender", "����");
	set("title", "������");
	set("class", "taoist");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 400000);
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("cuff", 80);
	set_skill("hand", 80);
	set_skill("sword", 80);
	set_skill("liangyi-jian", 380);
	set_skill("changquan", 80);

	map_skill("sword", "liangyi-jian");
	map_skill("parry", "liangyi-jian");
	map_skill("cuff", "changquan");

	prepare_skill("cuff", "changquan");


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

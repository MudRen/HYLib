// ruanshizhong.c ��ʿ��

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��ʿ��", ({ "ruan shizhong", "shizhong", "ruan" }) );
	set("gender", "����");
	set("title", "�ɶ������ű��ڵ��������");
	set("nickname", "������");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 400000);
	set_skill("dodge", 60);
	set_skill("force", 60);
	set_skill("cuff", 60);
	set_skill("hand", 60);
	set_skill("sword", 60);
	set_skill("liehuo-jian", 60);
	set_skill("changquan", 50);
	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("sword", "liehuo-jian");
	map_skill("cuff", "changquan");

	prepare_skill("cuff", "changquan");


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

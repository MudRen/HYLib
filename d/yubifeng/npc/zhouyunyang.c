// zhouyunqi.c ������

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("������", ({ "zhou yunyang", "yunyang", "zhou" }) );
	set("gender", "����");
	set("title", "�ɶ������ű��ڵ���������");
	set("nickname", "������");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 1200000);
	set_skill("dodge", 40);
	set_skill("force", 40);
	set_skill("cuff", 50);
	set_skill("hand", 50);
	set_skill("sword", 50);
	set_skill("liehuo-jian", 350);
	set_skill("changquan", 50);

	map_skill("sword", "liehuo-jian");
	map_skill("parry", "liehuo-jian");
	map_skill("cuff", "changquan");


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}

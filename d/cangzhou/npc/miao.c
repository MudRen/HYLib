
inherit NPC;
#include <ansi.h>;
void create()
{
	set_name("������", ({ "miao ruolan", "ruolan", "miao" }));
	set("gender", "Ů��");
	set("age", 18);
	set("str", 20);
	set("dex", 20);
	set("per", 27);
	set("long", "��������˷�Ķ���Ů����\n");
	set("combat_exp", 330000);
	set("shen_type", 1);
	set("attitude", "friendly");

	set_skill("cuff", 90);
	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("parry", 90);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 80);
	set_temp("apply/damage", 40);

	set("max_qi", 1600);
	set("neili", 600);
	set("max_neili", 1600);
	set("jiali", 20);

	setup();
	carry_object("d/city/obj/pink_cloth")->wear();
	carry_object("d/city/obj/flower_shoe")->wear();
}

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(YEL"É½×¯ÃÅÎÀ"NOR, ({ "menwei","men wei"}));
	set("gender", "ÄÐÐÔ");
	set("age", 23);

	set("combat_exp", 5000);
	set("shen_type", 1);
       set_skill("unarmed", 20);
	set_skill("sword", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);
       set_skill("force", 20);

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
	

inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("������", ({ "tie qiaosan", "tie"}) );
set("title","�㵴����");
        set("gender", "����");
set("nickname","���콣");
	set("age", 46);
	set("str", 30);
	set("cor", 30);
	set("cps", 33);
 	set("int", 30);
	
	set("shen_type", 4);

	set("max_force", 5000);
	set("force", 5000);
	set("force_factor", 50);

        set("attitude", "peaceful");
        set("combat_exp", 1000000);
       set_skill("unarmed", 120);
	set_skill("sword", 120);
	set_skill("parry", 120);
	set_skill("dodge", 120);
       set_skill("force", 120);
 
create_family("�㵴��",2,"����");
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);
        setup();
add_money("gold",1);
carry_object("/clone/weapon/changjian")->wield();
carry_object("/clone/misc/cloth")->wear();
}

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("л�", ({ "xie ying","girl", "dizi" }));
	set("age", 16);
	set("gender", "Ů��");
	set("attitude", "peaceful");
	set("str", 34);
	set("dex", 36);
       set("title","�㵴Ů����");
	set("combat_exp", 290000);
	set_skill("unarmed", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("sword", 220);
	set_skill("force", 120);

        set("shen_type",1);

create_family("�㵴��",2,"����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����а", ({ "hua wuxie","girl", "dizi" }));
	set("age", 22);
	set("gender", "Ů��");
	set("attitude", "peaceful");
	set("str", 34);
	set("per", 26);
       set("title","�㵴����");
       set("nickname","���Ľ�");
set("combat_exp", 1000000);
	set_skill("unarmed", 160);
	set_skill("dodge", 160);
	set_skill("parry", 160);
	set_skill("sword", 160);
	set_skill("force", 160);

create_family("�㵴��",2,"����");
    set("chat_chance", 7);
	set("chat_msg", ({
		"��������,��Ҳ���޿��κ�!\n",
		(:random_move:)
	}));
	setup();
       add_money("silver",60);
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

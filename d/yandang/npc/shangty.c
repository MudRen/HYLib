inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����һ", ({ "shang tianyi","dizi"}));
	set("gender", "����");
	set("age", 23);
       set("title","�㵴����");
       set("nickname","���Ľ�");
       set("food",250);
       set("water",250);
    set("chat_chance", 7);
	set("chat_msg", ({
		"��,����˵�������⸽����ʧ��,�����Ҳ���!\n",
	}));
	set("combat_exp", 10000);
	set("mingwang", 2000);
       set_skill("unarmed", 60);
	set_skill("sword", 60);
	set_skill("parry", 60);
        set("shen_type",1);
	set_skill("dodge", 60);
       set_skill("force", 160);


   create_family("�㵴��",2,"����");
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

inherit NPC;

void create()
{
	set_name("Գ����", ({ "zhanglao","yuan",}));
	set("age", 76);
	set("gender", "����");
	set("attitude", "peaceful");
	set("str", 34);
	set("dex", 36);
       set("title","����");
	set("combat_exp", 300000);
	set_skill("unarmed", 140);
	set_skill("dodge", 140);
	set_skill("parry", 140);
	set_skill("sword", 140);
	set_skill("force", 140);
	set_skill("literate",140);

    set("chat_chance", 15);
	set("chat_msg", ({
		"�����Ǹ��ϼһ���ô��������!\n",
		"Գ���Ͽ��˿���,΢Ц��ָ��ָ�鷿.\n",
	}));
        set("shen_type",1);
	set("inquiry", ([
		"��" : "��˫��,����......�����㵴һ�ɵ�ô��",
		"name" : "�Ҿ���Գ����,�����϶����ҵĺ�����,hehe!",
		]) );	
	setup();
      add_money("gold",2);
carry_object("/clone/misc/cloth")->wear();
}

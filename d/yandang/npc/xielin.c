inherit NPC;
inherit F_MASTER;
void create()
{
	set_name("л��", ({ "xie lin","girl", "dizi" }));
	set("age", 16);
	set("gender", "Ů��");
	set("attitude", "peaceful");
       set("title","�㵴Сʦ��");
	set("str", 34);
	set("dex", 36);
	set("combat_exp", 10000);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("sword", 60);
	set_skill("force", 60);

        set("shen_type",1);


   create_family("�㵴��",3,"����");
	set("inquiry", ([
		"��" : "����ʦ��������,��......",
		"flower" : "����ʦ��������,��......",
		]) );	
	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",5);
	carry_object(__DIR__"obj/hongmeigui");
}

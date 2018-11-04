// li-chunlai.c

#include <ansi.h>;
inherit NPC;

void create()
{
	set_name("���", ({"li chunlai", "li", "chunlai"}));
	set("gender", "����");
	set("age", 35);
	set("long", "����λ���վ�ǿ��ؤ��������ӡ�\n");
	set("attitude", "peaceful");
	set("class", "beggar");
 	set("beggarlvl", 7);
	set("str", 23);
	set("int", 22);
	set("con", 18);
	set("dex", 25);

	set("max_qi", 360);
	set("max_jing", 300);
	set("neili", 710);
	set("max_neili", 710);
	set("jiali", 36);
	
	set("combat_exp", 69000);
	
	set_skill("force", 60); 
	set_skill("huntian-qigong", 60); 
	set_skill("hand", 60); 

	set_skill("blade", 68); 
	set_skill("liuhe-dao", 60); 
	set_skill("dodge", 68); 
	set_skill("xiaoyaoyou", 60); 
	set_skill("parry", 60); 
	set_skill("staff", 60); 
	set_skill("begging", 60); 
	set_skill("strike",60);
	

	set("party/party_name", HIC"ؤ��"NOR);
	set("party/rank", GRN"���Ƿֶ�"HIY"�������"NOR);
	set("party/level", 5);
	create_family("ؤ��", 11, "����");
	setup();

	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/cloth")->wear();
}

#include "/kungfu/class/gaibang/gaibang.h"

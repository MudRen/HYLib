// zhouyi.c ���
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("���", ({ "zhou yi", "zhou","yi" }));
	set("title", HIC "����ׯ"HIM"��С��" NOR);
	set("nickname", HIB "������" NOR);
	set("long", 
"��������ׯ�Ĵ�С�㣬����Ӣ�ı���Ů�������Ը��������
���˸�֮�磬�������£��ô�ƽ����������������������
��ţ������������ӡ���\n");
	set("gender", "Ů��");
	set("class", "fighter");
	set("age", 17);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 25);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 1800);
	set("max_jing", 1400);
	set("neili", 1600);
	set("max_neili", 1600);
	set("jiali", 60);
	set("combat_exp", 70000);

	set_skill("force", 90);
	set_skill("dodge", 90);
	set_skill("unarmed", 90);
	set_skill("parry", 950);
	set_skill("blade", 90);
	set_skill("cibei-dao", 90);
	set_skill("hunyuan-yiqi", 90);
	set_skill("shaolin-shenfa", 90);
	set_skill("jingang-quan", 90);

	map_skill("dodge", "shaolin-shenfa");
	map_skill("force", "hunyuan-yiqi");
	map_skill("blade", "cibei-dao");
	map_skill("unarmed", "jingang-quan");
	map_skill("parry", "cibei-dao");

	set("env/wimpy", 20);
	create_family("������", 51, "�׼ҵ���");
 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/clone/weapon/gangdao")->wield();
}


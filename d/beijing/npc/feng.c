inherit NPC;
#include <ansi.h>

void create()
{
	set_name("������", ({ "feng xifan", "feng" }) );
	set("nickname", HIR"һ����Ѫ"NOR);
	set("gender", "����");
	set("age", 45);
	set("long",
		 "����������ƽ�������ӳ��������ɵ�һ���֣�һ�Ű�տտ����Ƥ��\n"
		 "̨��ս�ܺ�齵��͢������Ϊһ���ҳ�����");
	set("attitude", "peaceful");
	set("str", 26);
	set("con", 30);
	set("dex", 30);
	set("int", 28);

	set("neili", 6400);
	set("max_neili", 6400);
	set("jiali", 30);
	set("max_qi",12000);
	set("max_jing",11200);

	set("shen_type", -1);
	set("combat_exp", 5000000);

	set_skill("hand", 180);
	set_skill("sword", 160);
	set_skill("cuff", 180);
	set_skill("parry", 160);
	set_skill("dodge", 160);
	set_skill("literate", 100);
	set_skill("liancheng-jian", 380);
	set_skill("changquan", 370);


	map_skill("sword", "liancheng-jian");
	map_skill("parry", "liancheng-jian");
	map_skill("cuff", "changquan");
	map_skill("hand", "sanshou");
	prepare_skill("cuff", "changquan");
	prepare_skill("hand", "sanshou");
	create_family("������", 3, "����");
	setup();

	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}


// NPC: /d/huashan/npc/tbq.c
// Date: Look 99/03/25

inherit NPC;

void create()
{
	set_name("�ﲮ��", ({
		"tian boguang",
		"tian",
		"boguang",
	}));
	set("long",
		"�����ǰܻ��������Ҹ�Ů���ڵĴ�������\n"
		"���Ṧ���ѣ�һ�ֿ��쵶�������𽭺���\n"
	);

	set("nickname", "�������");
	set("gender", "����");
	set("attitude", "friendly");

	set("age", 30);
	set("shen_type", -1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 3500);
	set("max_qi", 3500);
	set("jing", 1500);
	set("max_jing", 1500);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 150);
	set("combat_exp", 1000000);
	set("score", 1000000);
	setup();
	 carry_object("clone/weapon/gangdao")->wield();
	 carry_object("clone/misc/cloth")->wear();
}


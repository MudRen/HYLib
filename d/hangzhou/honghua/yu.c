// yu.c ����ͬ

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("����ͬ", ({ "yu yutong", "yu","yutong" }));
	set("title", HIR "�컨��"HIG"ʮ�ĵ���" NOR);
	set("nickname", YEL "������" NOR);
	set("long", 
"һ������������ü��Ŀ�㣬����Ӣ��������������ͬ�˽�������
�ӵܣ��й���š����������һ�Һ�����һ��صأ���˾������
�������ֱ����Ž���ݺ����������С�����ͬһ�����ߣ�������Ե��
������Ϊʦ������ϰ�䣬������ʿ���������Ӵ�����������������
�˺컨�ᡣ��Ϊ�˻������ɣ���ʶ������̸���ڻ����������ķ���
��̽ѶϢְ֮��\n");
	set("gender", "����");
	set("class", "scholar");
	set("age", 20);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 27);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 8000);
	set("max_jing", 8000);
	set("neili", 12000);
	set("max_neili", 12000);
	set("jiali", 100);
	set("combat_exp", 1000000);
	set("score", 500000);

	set_skill("literate", 200);
	set_skill("force", 270);
	set_skill("dodge", 270);
	set_skill("unarmed", 270);
	set_skill("parry", 270);
	set_skill("whip", 270);
	set_skill("blade", 270);
	set_skill("sword", 270);
	set_skill("hand", 270);
	set_skill("claw", 270);
	set_skill("houquan", 250);
	set_skill("yunlong-xinfa", 250);
	set_skill("yunlong-shengong", 250);
	set_skill("wuhu-duanmendao", 250);
	set_skill("yunlong-jian", 250);

	set_skill("yunlong-shenfa", 150);
	set_skill("yunlong-bian", 150);
	set_skill("yunlong-shou", 150);
	set_skill("yunlong-zhua", 150);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("unarmed", "houquan");
	map_skill("blade", "wuhu-duanmendao");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");
	map_skill("sword", "yunlong-jian");
	map_skill("whip", "yunlong-bian");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 20);
	create_family("�䵱��", 18, "����");

 	setup();
	carry_object("/d/city2/obj/jinduan")->wear();
	carry_object("/d/city2/obj/yaodai")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}



// wen.c ��̩��

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("��̩��", ({ "wen tailai", "wen","tailai" }));
	set("title", HIR "�컨��"HIG"�ĵ���" NOR);
	set("nickname", HIW "������" NOR);
	set("long", "��̩���ųơ������֡���ʮ�������˵������������²�֪����
��������������ͽ��ԡ�\n");
	set("gender", "����");
	set("class", "fighter");
	set("age", 32);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("per", 24);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_qi", 9000);
	set("max_jing", 1000);
	set("neili", 12000);
	set("max_neili", 12000);
	set("jiali", 100);
	set("combat_exp", 700000);

	set_skill("literate", 200);
	set_skill("force", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("hand", 250);
	set_skill("claw", 250);
	set_skill("yunlong-shengong", 250);
	set_skill("yunlong-shenfa", 250);
	set_skill("yunlong-shou", 250);
	set_skill("yunlong-zhua", 250);

	map_skill("dodge", "yunlong-shenfa");
	map_skill("force", "yunlong-shengong");
	map_skill("hand", "yunlong-shou");
	map_skill("parry", "yunlong-shou");
	map_skill("claw", "yunlong-zhua");

	prepare_skill("hand","yunlong-shou");
	prepare_skill("claw","yunlong-zhua");
	set("env/wimpy", 20);

 	setup();
	carry_object("/clone/misc/cloth")->wear();
}



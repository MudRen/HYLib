// /d/yixing/npc/cl_situ.c ˾ͽ��
// Last Modified by winder on Jul. 12 2002
#include <ansi.h>;

inherit NPC;


string *positions = ({
	"������",
	"ʨ����",
	"������",
});

void create()
{
	set_name("˾ͽ��", ({ "situ heng", "situ" }));
	set("nickname", HIY"��צ����"NOR);
	set("party/party_name", HIC"���ְ�"NOR);
	set("party/rank", "����");
	set("long","����һ����ĸߴ󣬵���Щ���ݵ������ˣ�˫�ۺܳ�����ץ������������Ҳ����һ����\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 50);
	set("int", 28);
	set("con", 24);
	set("dex", 25);

	set("max_qi", 1000);
	set("max_jing", 800);
	set("max_neili", 1000);
	set("neili", 1000);
	set("jiali", 60);
	set("combat_exp", 300000);
	set("score", 10000);

	set_skill("force", 120);
	set_skill("dodge", 120);
	set_skill("parry", 120);
	set_skill("claw",  120);
	set_skill("strike", 80);
	set_skill("staff", 80);

	set_skill("poison", 80);
/*
	set_skill("huagong-dafa", 120);
	set_skill("zhaixinggong", 120);
	set_skill("sanyin-zhua",  120);
	set_skill("chousui-zhang", 80);
	set_skill("tianshan-zhang", 80);

	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "sanyin-zhua");
	map_skill("claw",  "sanyin-zhua");
	map_skill("strike", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("claw",  "sanyin-zhua");
*/
	set("inquiry", ([
		"���ְ�" : "���ְ����𽭺���ָ�տɴ���������������",
		"������" : "�������Ϳ๦�ߣ�������������Ϊ�ܹܡ�",
		"�����" : "�������Ϳ๦�ߣ�������������Ϊ�ܹܡ�",
		"����ʯ" : "�������Ϳ๦�ߣ�������������Ϊ�ܹܡ�",
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
//	carry_object("/clone/weapon/feizhua")->wield();
}

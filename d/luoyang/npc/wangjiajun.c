// wangjiajun.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("���ҿ�", ({ "wang jiajun", "wang", "jiajun" }) );
	set("title", HIY"����"NOR"���������");
	set("gender", "����" );
	set("shen_type", 1);
	set("age", 16);
	set("per", 15);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
	set("int", 25);
	set("long",
"��������ǿ�Ĵ���ӣ��书�����������������������У���ѵ���Ʀ��å
�����ǵ��ǹ��ˡ�\n" );
	set("combat_exp", 160000);
	set("attitude", "friendly");
	set_skill("blade", 130);
	set_skill("dodge", 130);
	set_skill("unarmed", 130);
	set_skill("jinwu-daofa", 130);
	set_skill("yanfly", 130);
	set_skill("parry", 130);
	map_skill("blade", "jinwu-daofa");
	map_skill("parry", "jinwu-daofa");
	map_skill("dodge", "yanfly");

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("gold", 1);
}


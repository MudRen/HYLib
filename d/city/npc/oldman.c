// /d/city/npc/oldman.c
// Last Modified by winder on Aug. 5 2001

#include <ansi.h>
inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("������ͷ", ({ "lao tou", "laotou", "oldman"}) );
	set("gender", "����" );
	set("age", 64);
	set("long","һ���뷢�԰׵����ߣ��������壬�����⡣\n");
	set("max_qi", 2000);
	set("max_jing", 2000);
	set("max_neili", 2000);
	set("jiali", 50);
	set("combat_exp", 400000);
	set("attitude", "friendly");
	set_skill("dodge", 120);
	set_skill("unarmed",120);
	set_skill("parry", 120);
	set_skill("force",120);

	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",30);
}


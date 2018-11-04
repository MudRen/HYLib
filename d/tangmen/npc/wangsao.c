// NPC wangsao.c

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("��ɩ", ({ "wangsao",  "sao" }));
	set("long",
	    "�������ŵĳ�ʦ.\n");
	set("gender", "Ů��");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "peaceful");

	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);

	set("qi", 800);
	set("max_qi", 800);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 20);

	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	
	setup();
	carry_object("/d/city/obj/cloth")->wear();
            
	add_money("silver",20);
}


// wang.c ����
#include <ansi.h>;
inherit NPC;
//inherit F_SKILL;
#include "teamjob.c";
void create()
{
	set_name("����", ({ "wang jian", "wang", "jian" }));
	set("gender", "����");
	set("title", HIY"�����ر���"NOR);
	set("age", 40);
	set("str", 35);
	set("dex", 36);
	set("long", "����һ�����������ر�����������������\n");
	set("combat_exp", 8000000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 280);
	set_skill("force", 280);
	set_skill("sword", 280);
	set_skill("dodge", 180);
	set_skill("parry", 280);
	set_skill("changquan", 280);
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
	set_temp("apply/attack", 800);
	set_temp("apply/defense", 800);
	set_temp("apply/armor", 800);
	set_temp("apply/damage", 800);

	set("neili", 100000); 
	set("max_neili", 100000);
	set("jiali", 100);
	set("inquiry", ([
		 "job"   : (: ask_job :),
       //  "����"  : (: ask_gonglao :),
         "fangqi": (: ask_fangqi :),
         "����"  : (: ask_fangqi :),
		]));

	setup();
	carry_object("/clone/weapon/gangjian")->wield();
	carry_object("/d/city/npc/obj/tiejia")->wear();
}


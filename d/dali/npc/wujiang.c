//Cracked by Kafei
// wujiang.c �佫

#include <ansi.h>

inherit NPC;

void create()
{
	set_name(YEL"�佫"NOR, ({ "wu jiang", "wu", "jiang" }));
//	set_color("$YEL$");
	set("gender", "����");
	set("age", random(10) + 30);
	set("weight", 100000);
	set("str", 25);
	set("dex", 16);
	set("long", "���Ǵ�����������Ľ��죬ƽʱ�������Ѳ��������վ��������˵���������硣\n");
	set("combat_exp", 75000);
	set("shen_type", 0);
	set("attitude", "peaceful");

	set_skill("unarmed", 100);
	set_skill("force", 65);
	set_skill("sword", 80);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);

	set("jingli", 500); 
	set("max_jingli", 500);
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
	}
//Cracked by Roath
// /clone/beast/bigtiger.c
// ɽ�ϻ�
// sdong 08/98

#include <ansi.h>
inherit NPC;


void create()
{
		  set_name("ɽ�ϻ�", ({ "shan laohu", "laohu" ,"tiger"}) );
set("no_get",1);
	set("race", "Ұ��");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

		  set("age", 1);
		  set("long", "һֻ�ָ��ִ��ɽ�ϻ��������������ڵص����۾������㡣\n");
		  set("attitude", "peaceful");
		  set_weight(200000);
		  set("max_qi", 100);
		  set("max_jing", 100);
		  set("max_jingli", 100);


		  set("str", 30);
		  set("con", 80);
		  set("dex", 30);
		  set("int", 10);

		  set("combat_exp", 20000);

		  set_temp("apply/attack", 10);
		  set_temp("apply/damage", 10);
		  set_temp("apply/armor", 10);

		  setup();
}

void unconcious()
{
    die();
}

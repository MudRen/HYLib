//Cracked by Roath
// /clone/beast/xbaozi.c
// С����
// sdong 08/98
// Modified by xQin 11/00

#include <ansi.h>
inherit NPC;


void create()
{
		  set_name("С����", ({ "xiao baozi", "baozi" }) );
set("no_get",1);
	set("race", "Ұ��");
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );
		  set("long", "һֻ���岻����Ǻܽ�ʵ��С���ӣ����������۾������㡣\n");
		  set("attitude", "aggressive");
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
}void unconcious()
{
    die();
}

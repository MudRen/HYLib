//Cracked by Kafei
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("ʿ��", ({ "shi bing", "shi", "bing" }) );
	set("gender", "����");
	set("age", 35);
	set("long", "����һ�������������ʿ�������Ž��£���ִ�ֵ���˫Ŀ���⾼���������Ѳ�������ܵ����Ρ�\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "heroism");
	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);
	set("max_qi", 600);
	set("eff_qi", 600);
	set("qi", 600);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 400);
	set("max_neili", 400);
	set("jingli", 300);
	set("max_jingli", 300);
	set("jiali", 20);
	set("shen_type", 0);
	set_temp("apply/attack",  30);
	set_temp("apply/defense", 30);
	set_skill("blade", 60);
	set_skill("unarmed", 80);
	set_skill("parry", 60);
	set_skill("dodge", 60);

	set("no_get", "�㿸����");
	setup();

	carry_object("/d/city/obj/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}

// zhu-jiuzhen.c �����

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�����", ({"zhu jiuzhen", "zhu"}));
	set("long", "�����ü�������ò���ģ��ְ����塣\n");
	set("title", HIW"ѩ��˫�"NOR);
	set("gender", "Ů��");
	set("age", 17);
	set("per", 30);

	set_skill("unarmed", 38);
	set_skill("force", 30);
	set_skill("dodge", 40);
	set_skill("parry", 35);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 25);
	set_temp("apply/damage", 5);

	set("combat_exp", 25000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/baihu-qiu")->wear();
	carry_object(__DIR__"obj/necklace")->wear();
}
	

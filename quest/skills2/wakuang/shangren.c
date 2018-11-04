// tang.c ���ϰ� 

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

int redeem(string arg);

void create()
{
	set_name("����", ({ "tang nan", "tang" }));
	set("title", "�����ϰ�");
	set("shen_type", 0);

	set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("str", 100);
	set("long",
		"��˵�������Ĵ��Ƽҵĺ����\n");
	set("no_get_from", 1);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 130);
	set_temp("apply/attack", 130);
	set_temp("apply/damage", 115);

	set("combat_exp", 9000000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

void die()
{
	message_vision("\n$N���ˡ�\n", this_object());
	destruct(this_object());
}

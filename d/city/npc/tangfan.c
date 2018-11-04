// tangfan.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����С��" , ({ "tang fan", "fan" }) );
	set("gender", "����" );
	set("age",20);
	set("combat_exp", 15000);
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/bingtang",
		__DIR__"obj/shuitang",
		__DIR__"obj/yuantang",
		__DIR__"obj/zaotang",
		__DIR__"obj/xitang",
		//"/clone/misc/fire",
	}) );
	setup();
	carry_object("/clone/cloth/male1-cloth")->wear();
}

void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

void greeting(object ob)
{
	if (environment(ob)==environment())
	message_vision("���ǵ�С����$Pߺ���ţ�������ϲ��������ǹ��д����Ѱɡ�\n",ob);
	return;
}

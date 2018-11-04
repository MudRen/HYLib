// waiter.c

inherit NPC;
inherit F_DEALER;
#include <ansi.h>
void create()
{
	set_name("����", ({ "xuniang" }) );
	set("gender", "Ů��" );
	set("age", 54);
	set("title", HIG "������ϣ������̴�" NOR);
	set("long",
		"��λ������������ɫ���Ե��������㡣\n");
	set("combat_exp", 80000);
	set("attitude", "friendly");
	set("per",2);
            	set("vendor_goods", ({
                __DIR__"obj/glxj",
                __DIR__"obj/cpdx",
                __DIR__"obj/pxhy",
                __DIR__"obj/kzmt",
                __DIR__"obj/hhdq",
                __DIR__"obj/cspc",
	}));
	set_skill("dodge",50);
	setup();
	carry_object(__DIR__"obj/pin")->wear();
	carry_object(__DIR__"obj/wch_skirt")->wear();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(4) ) {
		case 0:
message_vision("$N���$nһ�ۣ����˶��˰ɣ�������������\n",this_object(),ob);
			break;
		case 1:
message_vision("$N΢�ڱ�ˮͰ��ϸһ�������¶����צ����֣���$n�����У��������˰ɡ�\n",this_object(),ob);
			break;
		case 2:
message_vision("$N����$nһ�ۣ�����������Ц��������¶���ѵ��˴��Ļ�����\n",this_object(),ob);
			break;
	}
}

// chen.c
// Jay 5/7/96

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����Ǯ", ({ "zhao sanqian", "zhao", "sanqian" }));
	set("title", "�ྩ�ش�ҩ��");
	set("shen_type", 1);

	set("str", 20);
	set("gender", "����");
	set("age", 55);
	set("combat_exp", 5800);
	set("attitude", "friendly");

	set("rank_info/respect", "С����");
	set("vendor_goods", ({
               __DIR__"obj/xiongdan",
                __DIR__"obj/tianqi",
                __DIR__"obj/muoyao",
                __DIR__"obj/xuejie",
	}));

	setup();
   carry_object(__DIR__"obj/changpao")->wear();
}

void init()
{	
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


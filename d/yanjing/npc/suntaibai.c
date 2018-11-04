inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("��̫��", ({ "sun taibai", "sun", "taibai" }));
	set("title", "̫�׾�¥");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 55);
	set("combat_exp", 5800);
	set("attitude", "friendly");

	set("rank_info/respect", "�ϰ�");
	set("vendor_goods", ({
               __DIR__"obj/zuitaibai",
                __DIR__"obj/niurou",
                __DIR__"obj/yadan",
                __DIR__"obj/paomo",
                __DIR__"obj/kaoyangtui",
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


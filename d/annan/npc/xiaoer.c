
inherit NPC;
inherit F_DEALER;

void create()
{
   set_name("��С��",({ "xiao er","xiao","er" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "������Ҿƹݵĵ�С����\n");
    set("shop_id",({ "xiao er","xiao","er" }) );
   set("combat_exp", 2000);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");

	set("vendor_goods", ({
		__DIR__"obj/jiudai",
		__DIR__"obj/huasheng",
		"/d/city/npc/obj/baozi",
	}));   
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


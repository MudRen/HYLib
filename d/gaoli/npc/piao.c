
inherit NPC;
inherit F_DEALER;

void create()
{
   set_name("���ϰ�",({ "piao laoban","piao"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "�������̵��ϰ�,�����Ļ�ˮƽҲ�Ǻܸߵġ�\n");
   set("shop_id",({ "piao laoban","piao"}) );
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");

	set("vendor_goods", ({
		"/d/gaoli/obj/wenxue",

	}));  
   setup();
    carry_object("/d/gaoli/obj/cloth")->wear();
}

void init()
{
	::init();

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}



inherit NPC;
inherit F_DEALER;
void create()
{
//   reload("suiye_lilaoban");
   set_name("���ϰ�",({ "li laoban","li"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "�������̵��ϰ�,�����Ļ�ˮƽҲ�Ǻܸߵġ�\n");
   set("shop_id",({ "piao laoban","piao"}) );
   set("combat_exp", 20000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  __DIR__"obj/wenxue",	  
	}));
   setup();
  
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int regenerate()
{
        set("called", 0);
        return 1;
}
inherit NPC;
inherit F_DEALER;

void create()
{
//   reload("hz_huang");
   set_name("������",({ "huang xiansheng","huang"}) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����ҩ����ϰ�,�������ҩ����ܶ�ġ�\n");
    set("shop_id",({ "huang xiansheng","huang"}) );
   set("combat_exp", 60000);
   set("str", 25);
   set("per", 24);
 	set("vendor_goods", ({
	   __DIR__"obj/yangjingdan.c",
	   __DIR__"obj/buxuedan.c",
	}));
   set("attitude", "peaceful");

   setup();
   carry_object(__DIR__"obj/chouyi")->wear();
  
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


inherit NPC;
inherit F_DEALER;

void create()
{
//   reload("hf_ding");
   set_name("���ƹ�",({ "ding zhanggui","ding"}) );
        set("gender", "����" );
        set("age", 42);
   set("long", "����ҩ����ϰ�,�������ҩ����ܶ�ġ�\n");
    set("shop_id",({ "ding zhanggui","ding"}) );
   set("combat_exp", 200000);
   set("str", 25);
   set("per", 24);
 
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  __DIR__"obj/yangjingdan",
	   __DIR__"obj/buxuedan",
	   __DIR__"obj/huishenwan",
	}));
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

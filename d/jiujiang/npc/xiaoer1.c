
inherit NPC;
inherit F_DEALER;
void create()
{
  // reload("jj_xiaoer1");
   set_name("��С��",({ "xiao er","xiao","er" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "�������С���ݵĵ�С����\n");
    set("shop_id",({ "xiao er","xiao","er" }) ); 
   set("combat_exp", 200);
   set("attitude", "friendly");
	set("vendor_goods", ({
	   __DIR__"obj/doufu",
	   __DIR__"obj/kaoya",
	   __DIR__"obj/huotui"
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

int regenerate()
{
        set("called", 0);
        return 1;
}

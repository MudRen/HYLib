
inherit NPC;
inherit F_DEALER;
void create()
{
   //reload("saiwai_shangren");
   set_name("�̷�",({ "shang fan","shang","fan" }) );
        set("gender", "����" );
        set("age", 22);
   set("long", "������ԭ����һ���̷���\n");
    set("shop_id",({ "shang fan","shang","fan" }) );
   set("combat_exp", 200);
   set("str", 18);
   set("per", 22);
   set("attitude", "friendly");
	set("vendor_goods", ({
	   __DIR__"obj/piyi",
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

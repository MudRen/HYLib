// ����˫����
 
// zhu.c

inherit NPC;
inherit F_DEALER;

void create()
{
   
       set_name("���ϰ�", ({"zhu laoban","zhu","laoban" }));
       set("shop_id",({"zhu laoban","zhu","laoban"}));
       set("shop_title","�鱦���ϰ�");
       set("gender", "����");
        set("combat_exp", 10000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);

	set("vendor_goods", ({
		__DIR__"obj/feicui-neck",
		__DIR__"obj/huangjin-neck",
		__DIR__"obj/manao-neck",
	  __DIR__"obj/baiyu-finger",
	  __DIR__"obj/hupo-finger",
	}));
         setup();
        carry_object("/d/gaoli/obj/pao1")->wear();

   add_money("silver", 2);
}
void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}



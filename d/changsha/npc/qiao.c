
inherit NPC;
inherit F_DEALER;
void create()
{
   set_name("���ϰ�",({ "qiao laoban","qiao","lao ban" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "���ǵ��̵��ϰ壬�ĺ�������\n");
       
   set("combat_exp", 500000);
   set("str", 30);
   set("attitude", "friendly");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

void init()
{
	add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
	add_action("do_redeem", "redeem");

}
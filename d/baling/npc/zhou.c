
inherit NPC;
inherit F_DEALER;

void create()
{
   set_name("���ϰ�",({ "zhou laoban","zhou","laoban" }) );
        set("gender", "����" );
        set("age", 40);
   set("long", "���ǵ��̵��ϰ壬���˵������������������顣\n");
       
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("qi",800);
   set("max_qi",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
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



inherit NPC;
inherit F_DEALER;
void create()
{
//      reload("dx_tiejiang");
   set_name("����",({ "tie jiang","tie","jiang","tiejiang" }) );
        set("gender", "����" );
        set("age", 40);
   set("long", "������Ҷ������������һЩ����������졣\n");
    set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) ); 
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("neili",500);
   set("max_neili",500);
   set("qi",800);
   set("max_qi",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  __DIR__"obj/changjian",
	  __DIR__"obj/blade",
	  __DIR__"obj/spear",
	  __DIR__"obj/huwan",
	  __DIR__"obj/pidun",
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

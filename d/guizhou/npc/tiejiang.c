
inherit NPC;
inherit F_DEALER;
void create()
{
   //reload("xingyang_tiejiang");
   set_name("����",({ "tie jiang","tie","jiang","tiejiang" }) );
        set("gender", "����" );
        set("age", 40);
   set("long", "���ǹ�����������������ı������Ǻܺá�\n");
    set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("combat_exp",300000);
   set("str",26);
   set("per", 22);
   set("force",500);
   set("max_force",500);
   set("kee",800);
   set("max_kee",800);
   set("sen",500);
   set("max_sen",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");
	set("vendor_goods", ({
	  __DIR__"obj/changjian",
	  __DIR__"obj/blade",
	  __DIR__"obj/axe",
	  __DIR__"obj/tianhong-jian",
	  __DIR__"obj/canglong-jian",
	  __DIR__"obj/zhanmo-jian",
	  __DIR__"obj/wansheng-blade",
	  __DIR__"obj/zilin-blade",
	  __DIR__"obj/kuangsha-spear",
	  __DIR__"obj/yinlong-spear",
	  __DIR__"obj/zimang-bian",
	  __DIR__"obj/duoming-bian",
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
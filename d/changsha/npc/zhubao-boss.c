
inherit NPC;
inherit F_DEALER;
void create()
{
    //reload("leshou_zhubao-boss");
   set_name("���ϰ�",({ "li laoban","li","lao","ban" }) );
   set("gender", "����" );
   set("age", 40);
   set("long", "�����鱦����ϰ壬�������Ŵ����֡�\n");
   set("combat_exp", 500000);   
   set("attitude", "friendly");
	set("vendor_goods", ({
	   __DIR__"obj/feicui-neck",
	   __DIR__"obj/huangjin-neck",
	   __DIR__"obj/manao-neck",
	   __DIR__"obj/baiyu-finger",
	   __DIR__"obj/hupo-finger",
	   
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

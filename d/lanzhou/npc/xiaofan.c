// seller.c
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("С��", ({ "xiao fan", "seller", "fan" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"���Ǹ�С����������������ʵʵ�������������Ƕ��ͱ��ˡ�\n");
	set("shen_type", 1);
	set("combat_exp", 10000);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
        set_skill("dodge",20);
        set_skill("unarmed",20);
	set("vendor_goods", ({
		__DIR__"obj/tanghulu",
		__DIR__"obj/stick",
		__DIR__"obj/shoes",
                __DIR__"obj/bottle",
		__DIR__"obj/kaoya",
	}));
	setup();
        carry_object("clone/misc/cloth")->wear();
	add_money("coin", 100);
}

void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

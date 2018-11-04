// huoji.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("ҩ����", ({ "yaodian huoji", "huoji" }));
	set("str", 20);
	set("gender", "����");
	set("age", 18);
	set("long", "����ģ������ʵʵ�������ˡ�\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/nostrum/jinchuang",
		__DIR__"obj/nostrum/yangjing",
		__DIR__"obj/nostrum/zhujingchan",
		__DIR__"obj/nostrum/hedinghong",
		__DIR__"obj/nostrum/bicanfeng",
		__DIR__"obj/nostrum/kongquedan",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

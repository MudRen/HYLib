// gaohehui.c �ߺͻ�

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("С��", ({ "xiao yan", "xiaoyan" }));
	set("str", 20);
	set("gender", "Ů��");
	set("age", 22);
            set("title", "ţ���С�ϰ�");
	set("long", "����ţ���С�ϰ塣\n");
	set("combat_exp", 250);
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/cha",
		__DIR__"obj/niulou",
		__DIR__"obj/shousi",

	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}
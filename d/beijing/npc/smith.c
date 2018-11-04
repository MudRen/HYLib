// smith.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({ "tiejiang", "smith" }));
	set("title", "�������ϰ�");
	set("shen_type", 1);

	set("gender", "����" );
	set("age", 33);
	set("long", "����������ǯ��סһ����ȵ�����Ž�¯�С�\n");

	set("combat_exp", 400);
	set("attitude", "friendly");
	set("vendor_goods",({
		"/clone/weapon/gangdao",
		"/d/beijing/obj/tudao",
		"/d/xingxiu/obj/tiegun",
	}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	add_action("do_list", "list");
	add_action("do_buy", "buy");
}

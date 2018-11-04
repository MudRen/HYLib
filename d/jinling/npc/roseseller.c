// golder.c
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({"jiang qin","seller"}));
	set("title","�����ϰ�");
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("dodge", 50);
	set("gender","Ů��");

	set("force",200);
	set("max_force",200);
	set("per",70);
	set("food",200);
	set("water",200);
	set("combat_exp",1000);

	set("age", 26);
	set("long", @LONG
��������һ�����ϰ塣����������ʮ���꣬
�����������ˣ�ר�ſ������ʻ�Ϊ����
LONG
);
	set("vendor_goods", ({
		__DIR__"obj/redrose",
		__DIR__"obj/whiterose",
	}));

	setup();

	carry_object(__DIR__"obj/color_cloth")->wear();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

// golder.c
inherit NPC;
inherit F_DEALER;
int do_make(string arg);

void create()
{
	set_name("�����", ({"clother","sen"}));
	set("title","�÷���ϰ���");
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("dodge", 10);
	set("gender","Ů��");

	set("force",100);
	set("max_force",100);
	set("str",70);
	set("food",200);
	set("water",200);
	set("combat_exp",1000);

	set("age", 37);
	set("long", @LONG
��������������������ģ�����������ʮ�����ң������
�����Ǻܺã����Ƿ����ɴ棬��������ʱ��һ���Ǹ����ˡ�
LONG
);
	set("vendor_goods", ({
		__DIR__"obj/color_cloth",
		__DIR__"obj/color_pants",
		__DIR__"obj/silk_bra",
		__DIR__"obj/silk-cloth",
		__DIR__"obj/pink_cloth",
		__DIR__"obj/linen",
		__DIR__"obj/flower-shoes",
		__DIR__"obj/shoes",
		__DIR__"obj/color_head",												
		__DIR__"obj/headband",													
	}));


	setup();

	carry_object(__DIR__"obj/color_cloth")->wear();
	carry_object(__DIR__"obj/jiandao")->wield();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}


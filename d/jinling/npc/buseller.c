// golder.c
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({"fang an","seller"}));
	set("title","���ׯ�ϰ�");
	set_skill("unarmed", 10);
	set_skill("parry", 10);
	set_skill("dodge", 50);
	set("gender","����");

	set("force",200);
	set("max_force",200);
	set("str",70);
	set("food",200);
	set("water",200);
	set("combat_exp",1000);

	set("age", 26);
	set("long", @LONG
��������ҳ��ׯ���ϰ塣����������ʮ���꣬ר�ſ�����
��У���ƥΪ������˵���������һ�ʴ�������
LONG
);
	set("vendor_goods", ({
		__DIR__"obj/chouduan",
		__DIR__"obj/bu",
		}));


	setup();

	carry_object(__DIR__"obj/silk-cloth")->wear();
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

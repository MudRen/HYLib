inherit NPC;
inherit F_VENDOR;

string query_save_file() {return DATA_DIR+"npc/������";}
void create()
{
	set_name("������", ({ "wusi", "wusi", "wusi" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��������Ц�����æ����\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/caoxie",

	}));
set("chat_chance",5);
set("chat_msg",({
"�����ɽк�:��Ь,�´�Ĳ�Ь,˭Ҫ���Ь?\n",
"������������:��������Ĳ�Ь��������ȥ��.\n",
(:random_move:),
}));

	setup();
	carry_object("/clone/misc/cloth")->wear();
	//carry_object("/obj/std/armor/pijia")->wear();
	//carry_object("/obj/std/weapon/wandao")->wield();
}
void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}



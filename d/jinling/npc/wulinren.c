// yahuan.c

inherit NPC;

void create()
{
	set_name("��������", ({ "man" }) );
       set("str", 59);
	set("per", 26);
	set("age", 30);

	set("long",
		"һ�������ˣ��������������书��\n");

	set("chat_chance", 3);
	set("chat_msg", ({
		"��������˵�������������......\n",
		"��������ע�������ܵ�һ�С�\n",
	}));
	setup();
	carry_object(__DIR__"obj/silk-cloth")->wear();
       carry_object(__DIR__"obj/longsword")->wield();
       add_money("silver", 10);
}

 

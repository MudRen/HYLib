// yahuan.c
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({ "shangren","shopper","shang" }) );
       set("str", 19);
	set("per", 26);
	set("age", 30);

	set("long",
		"һ���������ˣ������Ÿ������İ�����\n"
		"����ͣ���ĳ������š�\n");

	set("chat_chance", 3);
	set("chat_msg", ({
		"����˵����׬Ǯ������ѽ��\n",
		"����һ������Ű���������ӡ�\n",
	}));
	setup();
	carry_object(__DIR__"obj/silk-cloth")->wear();
       add_money("silver", 80);
}

 

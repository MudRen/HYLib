// yahuan.c
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����", ({ "yiren","yi","ren" }) );
       set("str", 19);
	set("per", 26);
	set("age", 16);

	set("long",
		"һ���������ˣ�����·����ʰ������\n"
		"���������ڲ����ա�\n");

	set("chat_chance", 3);
	set("chat_msg", ({
		"����˵����׬Ǯ��ѽ��\n",
		"����һ������Ű����������Ǯ��\n",
		"����˵������Ҫ���������˶��ѽ��\n",
	}));
	setup();
	carry_object(__DIR__"obj/linen")->wear();
       add_money("silver", 10);
}

 

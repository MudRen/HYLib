// xiaoer2.c ���С��

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("���˵�", ({ "caifan" }) );
	set("gender", "����" );
	set("age", 22);
        set("long",
                "һ��Ϊ��������ձ�����С���ˣ�\n");
	set("attitude", "friendly");
	set("vendor_goods", ({
		__DIR__"obj/cai",
	}));
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}



// seller.c

inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("�����⴮��С��", ({ "xiao fan", "seller", "fan" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
		"����æ�ŷ������⴮����ʱ��������ִ����ű���Ѭ��ͨ���˫�ۡ�\n");
	set("shen_type", 1);
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	set("vendor_goods", ({
		"/d/jyguan/obj/yangrou",
                "/d/village/npc/obj/bottle",
	}) );

        set("chat_chance",10);
        set("chat_msg",({
     "С�����������������⴮���������⴮���������ʵ����⴮��...��\n",
     "С���е�������λ�͹٣�����ˮඣ�����ǰ�߾�û��ˮ�˰��������~��\n",
	}));


	setup();
        carry_object("clone/misc/cloth")->wear();
        add_money("coin", 100);
}
void init()
{
        ::init();
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}


// li.c ���ϰ� 

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("���ϰ�", ({ "huang laoban", "huang", "laoban" }));
	set("shen_type", 0);
        set("gender", "����");
	set_max_encumbrance(100000000);
	set("age", 35);
	set("long", "�����ϰ����ڶ����㿴����ȥ��\n");
	set("no_get_from", 1);

	set("no_clean_up", 0);
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);

	set("combat_exp", 50000);
	set("attitude", "friendly");
	
	setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
	::init();
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
}

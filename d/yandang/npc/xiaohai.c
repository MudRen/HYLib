inherit NPC;

void create()
{
	set_name("С����",({"xiaohaizi","haizi", "kid" }) );
        set("gender", "����" );
        set("age", 9);
        set("long", "���Ǹ����˼ҵ�С����\n");
        set("combat_exp", 10);
	set("mingwang", 1);
	set("str", 11);
	set("con", 11);
	set("int", 11);
        set("attitude", "friendly");
        setup();
	carry_object("/clone/misc/cloth")->wear();
        add_money("coin",5);
}


// girl.c

inherit NPC;

void create()
{
        set_name("�к�", ({ "boy" }) );
        set("gender", "����" );
        set("age", 14);
        set("str", 15);
        set("cor", 21);
        set("cps", 20);
        set("int", 25);

        set("max_force", 10);
        set("force", 10);
        set("force_factor", 1);
	 set("attitude", "friendly");


        set("long",@LONG
����һλ�������ص�С�к���
LONG);

        set("combat_exp", 250);
        set("score", 2);

        set_skill("unarmed", 6);
        set_skill("parry", 6);
        set_skill("dodge", 6);
     
        setup();
        carry_object(__DIR__"obj/linen")->wear();
}

int accept_fight(object who)
{
	return 1;
}
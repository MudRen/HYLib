// girl.c

inherit NPC;

void create()
{
        set_name("Ů��", ({ "girl" }) );
        set("gender", "Ů��" );
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
����һλ�������ص�СŮ����
LONG);

        set("combat_exp", 50);
        set("score", 1);

        set_skill("unarmed", 3);
        set_skill("parry", 3);
        set_skill("dodge", 3);
     
        setup();
        carry_object(__DIR__"obj/linen")->wear();
}
int accept_fight(object who)
{
	return 1;
}

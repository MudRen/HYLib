 // worker.c
inherit NPC; 
void create()
{
        set_name("����Ů", ({ "sheep girl", "girl" }) );
        set("gender", "Ů��" );
        set("age", 17);
        set("long", "һ��������ã������󷽵���Ů�� \n");
        set("combat_exp", 7000);
        set("per", 30);
        set("attitude", "friendly");
        set_skill("whip", 50);
        set_skill("parry", 25);
        set_skill("dodge", 100);

        setup();
        add_money("coin", 15);
        carry_object(__DIR__"obj/skirt")->wear();
        carry_object(__DIR__"obj/whip")->wield();
}   

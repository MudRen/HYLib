 inherit NPC;
void create()
{
        set_name("���²���", ({ "zang ni", "ni"}) );
        set("gender", "Ů��" );
        set("age", 25);
        set("str", 20);
        set("long", @LONG
һ�������µĲ��ᡣ
LONG
);
        set("attitude", "peaceful"); 
        set("combat_exp", 6000);
        create_family("������", random(4)+24, "����");
        set_skill("unarmed", 50);
        set_skill("bloodystrike", random(20)+10);
        set_skill("force", 40);
        map_skill("unarmed", "bloodystrike"); 
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fefawubian" :),
        }) );   
        set_skill("iron-cloth", 10);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        setup();
        if(random(5)==1)
        carry_object(__DIR__"obj/moonbook");
        if (random(2)) carry_object(__DIR__"obj/fake-tooth");
        carry_object(__DIR__"obj/redcloth2")->wear();
        carry_object(__DIR__"obj/1staff")->wield();
}   

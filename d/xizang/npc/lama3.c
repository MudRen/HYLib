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
        create_family("������", random(4)+22, "����");
        set_skill("unarmed", 50+random(10));
 

        set_skill("iron-cloth", 40+random(10));
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/redcloth2")->wear();
}       

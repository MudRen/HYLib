 inherit NPC;
void create()
{
        set_name("��������", ({ "lama"}) );
        set("gender", "����" );
        set("age", 35);
        set("str", 20);
        set("long", @LONG
һ�������µĲ�ɮ��
LONG
);
        set("attitude", "heroism");
        set("combat_exp", 6000);
        create_family("������", 24, "����");
        set_skill("unarmed", 100);

        set_skill("iron-cloth", 20);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
        if(random(5)==1)
        carry_object(__DIR__"obj/sunbook");
        if (random(2)) carry_object(__DIR__"obj/fake-tooth");
        carry_object(__DIR__"obj/redcloth")->wear();
} 

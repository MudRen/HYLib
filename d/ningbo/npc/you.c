
inherit NPC;

void create()
{
        int a=14+random(40);

        set_name("�ο�", ({ "you ke",  "ke" }) );

               if(random(10)<6)
               set("gender","����");
               else
               set("gender","Ů��");

        set("age", 20);
        set("str", 16);
        set("cor", 24);
        set("cps", 11);
        set("per", (2+random(18)) );

        set("attitude", "peaceful");

        set("max_force", 150);
        set("force", 150);
        set("force_factor", 3);

        set("food",100);
        set("water",100);

set("long", "���������ƺ�������ˡ�\n");
                                       

        set("combat_exp", 1000);

        set_skill("unarmed", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);
        set_skill("literate", 60);

        set("chat_chance",10);
        set("chat_msg",({
                "�οʹ�е�������ù���浹ù����\n",
                "�οͿ������ݺݵ�˵�������㣡С�ĵ㣡����û��ô�����˽ᣡ��\n",

//            (: random_move :),
                
        }) );

        setup();

        carry_object(__DIR__"obj/cloth")->wear();
        add_money("silver", 30);
}

 

 inherit NPC;
void create()
{
        set_name("��ɮ", ({ "tower guard", "guard" }) );
        set("gender", "����" );
        set("age", 65);
        set("str", 20);
        set("long", @LONG
һ�����𿴹��������Ĳ�ɮ��
LONG
);
        set("attitude", "heroism"); 
        set("neili", 300);
        set("max_neili", 300);
        set("force_factor", 20);  
        set("combat_exp", 20000+random(10000)); 
        set_skill("unarmed", 50);
        set_skill("bloodystrike", 50);
        set_skill("force", 40);
        set_skill("parry", 90);
        map_skill("unarmed", "bloodystrike");
        set_skill("iron-cloth", 50);
        set_skill("jin-gang", 20);
        map_skill("iron-cloth", "jin-gang");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.fefawubian" :),
        }) ); 
        setup(); 
        carry_object(__DIR__"obj/redcloth")->wear();
        carry_object(__DIR__"obj/fake-tooth")->wear();
}    

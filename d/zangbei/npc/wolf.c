 inherit NPC;
void create()
{
        set_name("�๷", ({ "hyena"}) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 6);
        set("long", "����һֻ�����ޱȵ��๷��\n");
        
        set("str", 48);
        set("cor", 52);
        set("cps", 22); 
        set("max_qi", 500);
        set("max_jing", 1000);
        set("max_qi", 500);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("attitude", "aggressive");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "�๷����񺿼�����\n",
                "�๷������̹�ʹ�㲻��������\n"
        }) );
        
        set("combat_exp", 200000);
        set("bellicosity", 3000 );
        
        set_temp("apply/attack", 120);
        set_temp("apply/armor", 120);
        setup();
}         

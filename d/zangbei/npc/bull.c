 inherit NPC;
void create()
{
        set_name("��ţ", ({ "bull" }) );
        set("race", "Ұ��");
        set("age", 10);
        set("long", "һֻ���ų�����ë��������ţ��\n"); 
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 300000);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
   
        setup();
} 

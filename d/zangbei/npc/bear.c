 inherit NPC;
void create()
{
        set_name("Ұ��", ({ "bear"}) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 6);
        set("long", "����һֻƤ������Ұ�ܣ������׶������ޱȡ�\n");
        
        set("str", 60);
        set("cor", 52);
        set("cps", 22); 
        set("max_qi",8000);
        set("max_jing",4000);
        set("max_qi",4000);
        
        set("pursuer",1);
                
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
               "Ұ��������������������ĺ�����������",
        }) );
        
        set("combat_exp", 2000000);
        
        set_temp("apply/attack", 250);
        set_temp("apply/dodge",250);
        set_temp("apply/move",400);
        set_temp("apply/armor", 400);
        setup();
}         

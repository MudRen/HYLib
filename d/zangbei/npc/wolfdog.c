 inherit NPC;
void create()
{
        set_name("����", ({ "wolfdog" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 10);
        set("long", "����һֻ��������������ޱȵ���Ȯ��Ƥ����������ޱȡ�\n");
        
        set("str", 50);
        set("cor", 100);
        set("cps", 22); 
        set("max_qi", 8000);
        set("max_jing", 10000);
        set("max_qi", 8000);
        
        set("attitude", "friendly");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                "��������ű�ת��תȥ���þ����Ŀ��������㡣\n"
        }) );
        set("combat_exp", 1200000);
                
        set_temp("apply/attack", 250);
        set_temp("apply/dodge",200);
        set_temp("apply/move",350);
        set_temp("apply/damage",100);
        
        setup();
}    

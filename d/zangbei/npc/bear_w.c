 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name("Ұ��", ({ "bear"}) );
        set("race", "Ұ��");
        set("gender", "����");
        set_temp("condition_type",YEL"<������>"NOR);
        set("age", 6);
        set("long", "����һֻƤ������Ұ�ܣ������׶������ޱȡ����������������ں���
��˯�����\n");
        
        set("str", 20);
        set("cor", 52);
        set("cps", 22); 
        set("max_qi",800);
        set("max_jing",400);
        set("max_qi",400);
        
        set("pursuer",1);
                
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("chat_chance",1);
        set("chat_msg",({
                CYN"\nҰ�ܷ��˸�������������˯�����\n\n"NOR,
        }) );  
        
        set("combat_exp", 200000);
                
        set_temp("apply/attack", 50);
        set_temp("apply/dodge",50);
        set_temp("apply/move",40);
        set_temp("apply/armor", 400);
        setup();
}         

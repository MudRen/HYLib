 // mind_beast.c
inherit NPC; 
void create()
{
    set_name("����", ({ "horse" }) );
        set("race", "Ұ��");
        set("gender", "����");
        set("age", 3);
    set("long", "һƥ�����ؿ��߹Ǹ߸�͹���������ȼ��⾡�������ƿݲ�ëƤ�������䣬\n��������ӡ�\n");
         
    set("max_qi", 1000);
        set("max_gin", 600);
        set("max_sen", 900);
        set("attitude", "peaceful");
        set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
        set("verbs", ({ "bite", "hoof"}) ); 
        set("chat_chance", 1);
        set("chat_msg", ({
     "�����ԡ������ԣ��ر�˻�˼���\n",
        }) );
                set("combat_exp", 20000);
        set_temp("apply/attack", 60);
        set_temp("apply/armor", 40);
        set_temp("apply/dodge",40);
        setup();
}    

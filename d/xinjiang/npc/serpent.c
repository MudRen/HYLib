 // serpent.c
inherit NPC; 
void create()
{
        set_name("�ڹھ���", ({ "serpent" }) );
        set("long", "һֻ�ں������ľ�����ͷ������һ����������\n"); 
        set("race", "Ұ��");
        set("age", 400);
        set("attitude", "aggressive"); 
        set("max_gin", 900);
        set("max_kee", 1800);
        set("max_sen", 500); 
        set("str", 40);
        set("cor", 70);
        set("spi", 20);
        set("int", 10); 
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) ); 
        set_temp("apply/attack", 60);
        set_temp("apply/damage", 40);
        set_temp("apply/armor", 30); 
        set("combat_exp", 50000);
        set("score", 1000);
        setup();
}  

 // venomsnake.c
#include <ansi.h> 
inherit NPC; 
void create()
{
        set_name("����", ({ "venomsnake", "snake" }) );
        set("long",     "һ֧�������ŵĶ�������������ض����㡣\n"); 
        set("race", "Ұ��");
        set("age", 3);
        set("pursuer", 1); 
        set("max_gin", 60);
        set("max_kee", 60);
        set("max_sen", 10); 
        set("str", 10);
        set("cor", 50); 
        set("limbs", ({ "ͷ��", "����", "β��" }) );
        set("verbs", ({ "bite" }) ); 
        set_temp("apply/attack", 10);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 10); 
        set("combat_exp", 100);
        setup();
} 
int hit_ob(object me, object ob, int damage)
{
        if( random(damage) > (int)ob->query_temp("apply/armor")
        &&      (int)ob->query_condition("snake_poison") < 10 ) {
                ob->apply_condition("snake_poison", 20);
                tell_object(ob, HIG "����ñ�ҧ�еĵط�һ��������\n"NOR );
        }
}

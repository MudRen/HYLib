// yutu.c ����
inherit NPC;
void create()
{
        set_name("����", ({
 "yu tu", "yu", "tu","hare" }) );
    set("race", "Ұ��");
    set("age", 5);
        set("no_die",1);
    set("long", "���ǹ㺮��������ã�������(tuzi)��ƭ�·��˵ġ�\n");
    set("attitude", "peaceful");
    
    set("limbs", ({
 "ͷ��", "����", "ǰ��", "���", "β��" }) );
    set("verbs", ({
 "bite", "claw" }) );
    set("combat_exp", 500000);
    set("chat_msg", ({
        (: this_object(), "random_move" :),
    }) );
    
    set_temp("apply/attack", 200);
    set_temp("apply/defense", 500);
    set_temp("apply/damage", 200);
    set_temp("apply/armor", 5000);
    setup();
}
void die()
{
    object ob;
    message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
    ob = new(__DIR__"xianturou");
    ob->move(environment(this_object()));
    destruct(this_object());
}
    

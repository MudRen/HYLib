// eyu.c ����
// By River 99.5.25
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "e yu", "e", "yu" }));
        set("race", "Ұ��");
        set("age", 200);
        set("long", "һ���Ӵ��ޱ����㣬�����������װ����Ƭ��\n");
        set("str", 70);
        set("con", 50);
        set("max_qi", 800);
        set("limbs", ({ "ͷ��", "����", "β��", "���" }));
        set("verbs", ({ "bite" }) );
        set("combat_exp", 300000);
        set_temp("apply/attack", 250);
        set_temp("apply/damage", 250);
        set_temp("apply/armor", 250);
        setup();
}

void init()
{
    object ob;
    ::init();
    if (interactive(ob = this_player())){
           tell_object(ob,HIR"����һ�����ˮ�и��������ſ�Ѫ���ڣ��������˹�����\n"NOR);
           remove_call_out("kill_ob");
           call_out("kill_ob", 1, ob); 
          }
}

void die()
{        
        message_vision("\n����һ��������һ����һ�������Ԩ�С�\n", this_object());
        destruct(this_object());
}

void unconcious()
{
        message_vision("\n����һ��������һ����һ�������Ԩ�С�\n", this_object());
        destruct(this_object());
}
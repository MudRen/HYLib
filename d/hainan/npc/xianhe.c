#include <ansi.h>;
inherit NPC;

void create()
{
        set_name(HIW"�ɺ�"NOR, ({ "xian he", "he" }) );
        set("race", "Ұ��");
        set("age", 100);
        set("long", "һֻ���������ɺף������������(qi)��ȥ.\n");
        set("attitude", "peaceful");
        set("str",100);
        set("int",100);
        set("per",100);
        set("con",100);
        set("limbs", ({ "ͷ��", "����", "���" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000000);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 110);
        set_temp("apply/armor", 100);
        set_temp("apply/defence",190);

        setup();
}
void die()
{
        object ob,me;
me = this_player();
        message_vision("$N˻�ƵĽ��˼��������ڵ������ˡ�����\n һ���׹�������һ����������ëƮ����$N�����ϡ���\n\n", this_object(),me);
        ob = new("/d/hainan/obj/yumao");
        ob->move(me);
        destruct(this_object());
}

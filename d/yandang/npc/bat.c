#include <ansi.h>
inherit NPC;

void create()
{
        set_name(RED"��Ѫ����"NOR, ({ "bat", "bianfu" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "��������ɭɽ���е�����,����Ѫά����\n");
        set("attitude", "peaceful");

		set("can_speak",0);

        set("str", 26);
        set("cor", 30);
        set("kee", 100);
        set("max_kee",100);
        set("limbs", ({ "����", "����", "����", "צ��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 1000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player())) 
                        	call_out("kill_ob", 1, ob); 
        
}
void die()
{
        object ob;
        message_vision("$Nһͷ�Ե��ڵ�,�����˼��£�$N���ˡ�\n", this_object());
        destruct(this_object());
}

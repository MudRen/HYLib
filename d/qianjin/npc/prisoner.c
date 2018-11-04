// garrison.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��ħ", ({ "mo", "er mo" }) );
        set("long",
                "ר�ű���Ϊ潵Ķ�ħ\n");

        set("attitude", "aggrensive");
	set("vendetta/authority", 1);
        set("pursuer", 1);

        set("str", 27);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 100000);

        set_skill("unarmed", 7+random(200));
        set_skill("sword", 7+random(200));
        set_skill("parry", 7+random(200));
        set_skill("dodge", 7+random(200));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/damage", 30);
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);

        setup();

        carry_object("clone/cloth/cloth")->wear();
}
void init()
{
	object me;
	me = this_player();
	if( interactive(me) ) { this_object()->kill_ob(me);
				me->kill_ob(this_object());
				}

}

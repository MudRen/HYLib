#include <ansi.h>
inherit NPC;

void create()
{
        set_name(BLU"������"NOR, ({ "snake", "she" }) );
        set("race", "Ұ��");
        set("age", 4);
        set("long", "һֻ���ž޴��������Դ����ߣ������׳��\n");
        set("attitude", "peaceful");

		set("can_speak",0);

        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 3000);

        set_temp("apply/attack", 15);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 6);

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
        message_vision("$Nʹ��������˼��£�$N���ˡ�\n", this_object());
        destruct(this_object());
}


mixed hit_ob(object me, object ob, int damage_bonus, int factor)
{
		ob->apply_condition("snake_poison", random(20) + 10 +
			ob->query_condition("snake_poison"));
	
}
//Cracked by Kafei

#include <ansi.h>

inherit NPC;

void create()
{
	set_name("�ʹ���ʿ", ({ "wei shi", "shi", "guard" }) );
	set("gender", "����");
	set("age", 35);
	set("long",
		"һ��������׵�������ʿ��\n");
	set("combat_exp", 100000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("str", 26);
	set("con", 22);
	set("int", 20);
	set("dex", 24);

	set("max_qi", 800);
	set("eff_qi", 800);
	set("qi", 800);
	set("max_jing", 500);
	set("jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 30);

	set_temp("apply/attack",  50);
	set_temp("apply/defense", 50);

	set_skill("club", 100);
	set_skill("unarmed", 80);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);

	set("no_get", "�㿸����");

	setup();

        carry_object("/clone/weapon/changqiang")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
void init()
{
        object ob;
//      ::init();
        if (interactive(ob = this_player()) &&
                (int)ob->query_condition("xakiller")) {
                remove_call_out("kill_ob");
                call_out("kill_ob", 1, ob);
        }
}
int accept_fight(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        me->apply_condition("xakiller", 100);
        kill_ob(me);
        return 1;
}

int accept_kill(object me)
{
        command("say ��ү����������ɱ�ţ��������㵹ù��\n");
        me->apply_condition("xakiller", 100);
        kill_ob(me);
        return 1;
}

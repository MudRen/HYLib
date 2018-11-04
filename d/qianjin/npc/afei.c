
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("����", ({ "afei", "fei","feia" }) );
	set("gender", "����" );
        set("title", HIG "��Ϊ����" NOR);
	set("age", 20);
	set("int", 30);
	set("per", 30);
	set("long",
		"�����޵У���������\n"
		);
        set("force_factor", 200);
        set("max_gin", 3000);
        set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 3000);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 3000);
        set("sen", 3000);
        set("max_force", 30000);
        set("force", 30000);
	set("force_factor", 300);
	set("cor",200);
        set("combat_exp", 9999999);
        set("score", 90000);
        set_skill("sword", 410);
        set_skill("force", 400);
        set_skill("parry", 400);
        set_skill("literate", 400);
	set_skill("dodge", 400);
        set("agi",25);
        set("int",30);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.yiji" :),
        }) );
	set_skill("lonely-sword", 420);
        map_skill("sword", "lonely-jian");

	setup();
	carry_object("clone/cloth/cloth")->wear();
        carry_object(__DIR__"obj/toysword")->wield();
}
int accept_fight(object me)
{
        command("grin");
        command("say �ҵĽ�������ɱ�˵ģ����������Ȼ�����ģ�");
        return 0;
}
void init()
{
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
	
	object player, victim, weapon;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "���ɶ�")
		{
		message_vision("$N��Цһ�������ҿ�����̫���ˡ�\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}

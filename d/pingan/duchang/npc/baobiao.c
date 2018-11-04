// npc:  /d/changan/npc/oldwomen.c
// data: inca  98/08/28

inherit NPC;
//inherit F_SKILL;

void create()
{
	set_name("����", ({ "baobiao" }));
	set("gender", "����");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "����һ����ĸߴ�Ľ����ˣ����۴�׳��������Բ���������ܲ����ǡ�\n");
	set("combat_exp", 80000);
	set("shen_type", 1);
	set("attitude", "heroism");

	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("sword", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);

	setup();
       carry_object(__DIR__"obj/gangjian")->wield();
//	carry_object("/d/city/obj/gangjian")->wield();
	carry_object("/d/city/obj/cloth")->wear();
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
		if( (string)name == "����")
		{
		message_vision("$N��Цһ�������ҿ�����̫���ˡ�\n", this_object());
		this_object()->kill_ob(player);
		player->kill_ob(this_object());
		return 1;
		}
	}
	return 0;		
}

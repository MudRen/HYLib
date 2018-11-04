// dog.c

inherit NPC;

void create()
{
	set_name("���ｫ��", ({"dog"}));
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ����ͦ�أ����ų���ͷ�Ĵ�񹷡�\n");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

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
	if (living(this_object()) && interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 20) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, ob); 
	}	
}

void die()
{
	message_vision("$N�Һ�һ�������ˣ�\n", this_object());
	new("/clone/armor/goupi")->move(environment());
	destruct(this_object());
}

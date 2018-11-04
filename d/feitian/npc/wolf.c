// wolfdog.c

#include <login.h>
#include <move.h>
inherit NPC;

void create()
{
	set_name("����", ({ "wolf" }) );
	set("race", "Ұ��");
	set("age", 4);
	set("long", "һֻ����ð���̹�Ķ��ǡ�\n");
	set("attitude", "peaceful");

	set("str", 30);
	set("cor", 30);

	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "β��" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 1000);

	set("chat_chance", 6);
	set("chat_msg_combat", ({
		(: this_object(), "random_move" :),
               "��������񺿼�����\n",
                "����������̹�ʹ�㲻��������\n"
	}) );

	set_temp("apply/attack", 15);
	set_temp("apply/damage", 6);
	set_temp("apply/armor", 2);

	setup();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) &&
		random(ob->query_kar() + ob->query_per()) < 30) {
			remove_call_out("kill_ob");
			call_out("kill_ob", 0, ob);
	}
}


void die()
{
	object ob;
	message_vision("$N���쳤��һ�������ˣ�\n", this_object());
	ob = new(__DIR__"obj/langpi");
	ob->move(environment(this_object()));
	destruct(this_object());
}


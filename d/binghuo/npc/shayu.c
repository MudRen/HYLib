// shayu.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "sha yu", "sha" }) );
	set("race", "Ұ��");
        set("age", 20);
        set("long", "һֻ�����ڱ����ľ޴��衣\n");
        set("attitude", "friendly");
        set("shen_type", 0);
	set("gender", "����");
	set("race", "Ұ��");
	set("age", 3);
	set("attitude", "aggressive");
        set("max_qi",1000);
	set("str", 26);
	set("cor", 30);
	set("limbs", ({ "ͷ��", "����", "����", "β��" }) );
	set("verbs", ({ "bite" }) );
	set("combat_exp", 1000000);
	set("neili", 300);
	set("max_neili", 300);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
        set("combat_exp", 100000);
        set_temp("apply/attack", 800);
        set_temp("apply/defense", 800);
        set_temp("apply/armor", 100);

        setup();
}


void die()
{
	object ob, corpse;
	message_vision("$Nȫ��һ����ҵ�Ť�������ڰ��������������������ˡ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
		ob = new(__DIR__"shadan");
	ob->move(corpse);

	corpse->move(environment(this_object()));
	destruct(this_object());
}

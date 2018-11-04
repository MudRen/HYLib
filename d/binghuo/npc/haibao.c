// haibao.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "hai bao", "bao" }) );
	set("gender", "����");
	set("race", "Ұ��");
	set("attitude", "aggressive");
        set("max_qi",1000);
	set("str", 26);
	set("cor", 30);
	set("limbs", ({ "ͷ��", "����", "����", "β��" }) );
	set("verbs", ({ "bite" }) );
        set("age", 20);
        set("long", "һֻ�����ڱ����ĺ�����\n");
        set("attitude", "friendly");
        set("shen_type", 0);

        set("combat_exp", 10000);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 300);
        set_temp("apply/armor", 100);

        setup();
}

void die()
{
	object ob, corpse;
	message_vision("$N��ҵĺ��˼��������ˡ�\n", this_object());
	if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
	{
		if(random(10) > 6)
		{
			ob = new(__DIR__"lingzhi1");
			ob->move(corpse);
		}
		ob = new(__DIR__"haibaorou");
		ob->move(corpse);
		ob = new(__DIR__"haibaopi");
		ob->move(corpse);
	}
	corpse->move(environment(this_object()));
	destruct(this_object());
}


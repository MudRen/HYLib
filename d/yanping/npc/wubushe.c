// wubushe.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�岽��", ({ "wubushe" }) );
	set("long", "�岽���Ǹ����ط����ߣ��ഫ�ж���·�岽���е��С�\n");
	set("race", "Ұ��");
	set("age", 3);
	set("attitude", "peaceful");

	set("max_ging", 1080);
	set("max_qi", 1080);

	set("str", 10);
	set("cor", 50);

	set_temp("apply/attack", 100);
	set_temp("apply/damage", 100);
	set_temp("apply/armor", 100);

	set("combat_exp", 100000);
	setup();
}

void init()
{
	object me,ob;
	::init();
	if (interactive(me = this_player()))
	{
		if (!(ob = present("xionghuang", this_player())))
		{
			remove_call_out("kill_ob");
			call_out("kill_ob", 1, me);
		}
	}
}

int hit_ob(object me, object ob, int damage)
{
	if ((int)ob->query("combat_exp") > 10000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor") &&
		(int)ob->query_condition("snake_poison") < 10 )
	{
		ob->apply_condition("snake_poison", 40);
		tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}

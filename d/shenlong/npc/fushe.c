//fushe.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("����", ({ "fu she", "she", "fu" }) );
	set("race", "Ұ��");
	set("age", random(10));
	set("long", "ֻ����ȫ��Ѫ�죬ͷ�����ǣ��������£��������졣\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("cor", 20);
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 30000+random(50000));

	set_temp("apply/attack", 20+random(10));
	set_temp("apply/damage", 10+random(10));
	set_temp("apply/armor", 15+random(10));
	set_temp("apply/defence",20+random(10));
	setup();
}

void init()
{
        object me,ob;
        ::init();
        if (!this_player()) return 0;
        if (interactive(me = this_player()))
        {
        if (!this_player()) return 0;
	if (!(ob = present("xionghuang", this_player())))          
               {
        if (!this_player()) return 0;
    if (this_player()->query("combat_exp") < 20000) return 0;
	       remove_call_out("kill_ob");
               call_out("kill_ob", 1, me);
		}
        }
}

int hit_ob(object me, object ob, int damage)
{
    if ((int)ob->query("combat_exp") > 100000) return 1 ;
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 20 ) {
		ob->apply_condition("snake_poison", 40);
        tell_object(ob, HIG "����ñ�ҧ�еĵط�һ����ľ��\n" NOR );
	}
}

void die()
{
	object ob;
	message_vision("$N���ڵ��ϣ����ˣ�\n", this_object());
	ob = new("/d/shenlong/obj/shedan");
	ob->move(environment(this_object()));
	ob = new("/d/baituo/obj/shepi");
	ob->move(environment(this_object()));
	destruct(this_object());
}

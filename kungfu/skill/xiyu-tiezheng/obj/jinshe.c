#include <ansi.h>
inherit NPC;

void create()
{
        set_name(NOR + YEL "����" NOR, ({ "jinhuan she", "jinhuan", "she" }));
        set("long", YEL "����һֻ���˿�����ë���Ȼ�Ľ��ߡ�\n" NOR);
	set("race", "Ұ��");
	set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
set("verbs", ({ "bite" }) );
        set("age", 1);
        set("str", 15);
        set("dex", 40);
        set("max_qi", 300);
        set("max_ging", 300);
        set("combat_exp", 5000);

        set("snake_poison", ([
                "level"  : 40,
                "perhit" : 20,
                "remain" : 40,
                "maximum": 40,
                "supply" : 2,
        ]));

        set("power", 10);
        set("item1", "/clone/quarry/item/sherou");
        set("item2", "/clone/herb/shedan");

        set_temp("apply/dodge", 80);
        set_temp("apply/defense", 80);
        set_temp("apply/unarmed_damage", 35);

        setup();
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 5);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		 name() + "֨֨�ķ����˼���������\n\n"
		+ name() + "��������Ĳݵؾ���ʧ�����ˡ�\n" , environment(),
		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("max_guard",-1);
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i;
	object *enemy;
	set_skill("parry", 170 + random(level));
	set_skill("dodge", 170 + random(level));
	set_skill("unarmed", 170 + random(level));
	set("combat_exp", 100000 + random(level/2*level*level));
	message("vision",
		 name() + "֨֨�Ĺֽ��˼���,��������ͷ��\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}
void backattack()
{
	int i;
	object owner, *enemy;
	if(objectp(owner=this_object()->query("possessed")))
	{
		enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

	}

}

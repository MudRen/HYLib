// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "����ˮ", ({ "shui", "girl" }) );
	set("long", "����ǧ��¥���ϰ˽�֮һ��
����ˮ�����ƽ�԰�С�
б��ůҡ��䶯���仨��ů���ƺ죬ƻĩ����硣
����Ŀ����ԾС������
������ҡ�����ȣ�������Ӱ���ɹ���Զ������ء�
\n");
	set("attitude", "friendly");
	set("title", HIM "���ϰ˽�" NOR);
	set("max_gin", 500);
	set("max_kee", 500);
	set("max_sen", 500);
	set("age", 17);
        set("gender", "Ů��" );


	set("str", 35);
	set("cor", 30);
	set("cps", 25);
	set("per", 40);
	set("combat_exp", 50000);

	set("chat_chance_combat", 1);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("unarmed", 1+random(100));
	setup();
        carry_object(__DIR__"obj/shui")->wear();
        carry_object(__DIR__"obj/shuipai");
        if (random(2)==0)
        add_money("gold", 1);

}

string summon_more(object who)
{
	int i;
	object *enemy;
	object another;
	seteuid(getuid());
	another = new(__DIR__"jianu");
	another->move(environment(who));
	message_vision(another->name()+ "���˹�����\n"
		, this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			another->kill_ob(enemy[i]);
			enemy[i]->kill_ob(another);
			another->set_leader(enemy[i]);
		}
	}
	return "1";
}
int accept_object(object me, object obj)
{
	if( !obj->value() &&  !obj->query("value")) return 0;
        command("smile");
	message_vision("$N��$n���˸��򸣣�\n",this_object(),me);
        command("say ��л��λ" + RANK_D->query_respect(me) +
"��ͷһ�μ���������ô�󷽵ģ�");
        return 1;
}


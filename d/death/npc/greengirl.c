#include <ansi.h>
inherit NPC;
void create()
{
	set_name("����", ({ "greenpearl" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("str", 10);
	set("per", 50);
	set("long", @LONG
����������Ư������һ�����˵�Ů��ζ�������Ȥ�Ļ����루����������
LONG
);
	set("combat_exp", 1000000);
	set("attitude", "friendly");

	setup();
}

int accept_fight(object me)
{
	command("say СŮ�����������Ķ��֣�");
	return 0;
}
void init()
{
	object me;
	me = this_player();
	if( me->query("gender") == "����")
	add_action("do_enjoy","enjoy");
	else if (me->query("divorced"))
	{
	command("say ���������һ���յĶ�����");
	kill_ob(me);
	me->kill_ob(this_object());

	}
}

int do_enjoy()
{
	object me;
	me = this_player();
	message_vision("$N��ƮƮ����$n�߹�����������\n",this_object(),me);
	call_out("next_stage",3,me);
	return 1;

}
int is_ghost() {return 1;}
int next_stage(object me)
{
	if(objectp(me) && environment(me) == environment())
	{
        message_vision("$N�ݺݵش���$n��������⣬������������ˣ�����ô�����
���Ҿ���$n�������Σ���\n", this_object(),me);
	add_temp("apply/attack",100);
	add_temp("apply/damage",50);
        kill_ob(me);
        me->kill_ob(this_object());
	}
        return 1;
}


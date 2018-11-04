//Cracked by Kafei
// road: /d/zhongnan/bingdong.c
// by sdong 08/98

#include <ansi.h>
#include <room.h>
inherit ROOM;
private int blow_result(object victim);
int blow();
int do_dig();
void setup_ob(object me,object victim);

void create()
{
		  set("short","����");

		  set("long",@LONG
������ָ��ֿ���������Ȼ�����ҵģ����ں������ˣ����Ͻ��ź��ļ����
����Ķ���Щ������
LONG);

		  set("exits",([
"east": __DIR__"xuanya4",
							 ])
			  );
	  set("cost",1);
	  setup();
}

void init()
{
	add_action("do_dig", "dig");
	remove_call_out("blow");
	call_out("blow",4 + random(3) );
}

int do_dig()
{
	remove_call_out("blow");
	call_out("blow",1 );
	return 1;
}

int blow()
{
	object *inv = all_inventory(find_object(__DIR__"bingdong"));
	object ob, me= this_player();
	int i;

	if( !this_player() || !environment(this_player()) )  return 1;
	if( base_name(environment(this_player())) != __DIR__"bingdong") return 1;

	message_vision( HIW"\n�����һ������������ȫ���ѪҺ���춳���ˣ�\n"NOR, this_player() );

	for ( i=0 ; i < sizeof(inv); i++)
	{
		if ( (string)inv[i]->query("race") == "����" )
		{
			blow_result(inv[i]);
		}
	}


	remove_call_out("blow");
	call_out( "blow",4 + random(3) );
	return 1;
}

private int blow_result(object victim)
{
	object ob2;

	if( random(60)==1 )
	{
		ob2=new(__DIR__"bigtiger");
		ob2->move(environment(victim));
		message_vision(HIR"ͻȻ�Ӷ������߽�һֻ$N�����������ˣ�ŭ��һ���������Ƶ���$n���������\n"NOR, ob2,victim);
		setup_ob(ob2,victim);
		ob2->kill_ob(victim);
		ob2->add_temp("offenders/"+victim->query("id"), 1);
		ob2->start_busy(1+random(3));
		victim->kill_ob(ob2);
	}

	if( random( victim->query_skill("force") ) > 45 && victim->query("neili") > 20 )
	{
		message_vision( HIG"\n$N�Ͻ��˹�������\n"NOR, victim );
		if( victim->query_skill("force",1) < 350 )
			victim->improve_skill( "force",victim->query("con")+10 );
		victim->add("neili",-random(40));
	}
	else
	{
		message_vision( RED"\n$N���˸������\n"NOR, victim );
		victim->receive_wound("qi", random(30));
		victim->receive_damage("qi", random(50));
		if( victim->query_skill("force",1) < 300 )
			victim->improve_skill( "force",victim->query("con")/2+10 );
	}


	return 1;
}

void setup_ob(object me,object victim)
{
	object *inv;
	mapping skill_status;
	string *sname;
	int i, max = 0, max1, j;


	if ( !me->query_temp("copied") ) {
		if ( mapp(skill_status = victim->query_skills()) ) {
		skill_status = victim->query_skills();
		sname = keys(skill_status);

		for(i=0; i<sizeof(skill_status); i++) {
			if ( skill_status[sname[i]] > max ) max = skill_status[sname[i]];
		}


		max1 = (int)max + random(max*3);

		if( victim->query("combat_exp",1) < 10000 ) max1 = max1/2;
		me->set_skill("dodge", max1);
		me->set_skill("parry", max1 );
		me->set_skill("force", max1);
		me->set_skill("strike", max1);
		me->set_skill("cuff", max1);
		me->set_skill("claw", max1);
		me->set_skill("force", max1);
		me->set_skill("taiji-shengong", max1);
		me->map_skill("force", "taiji-shengong");


		me->set("combat_exp", victim->query("combat_exp",1)+random(victim->query("combat_exp",1)/2));

		me->set("max_qi", victim->query("max_qi"));
		me->set("eff_qi", victim->query("max_qi"));
		me->set("max_jing", victim->query("max_jing"));
		me->set("eff_jing", victim->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("max_neili", 6000);
		me->set("neili", victim->query("neili") );
		me->set("jing", me->query("max_jing"));
		me->set("jiali", victim->query("jiali")*3/4);
		if ( victim->query("max_jing") > 0 ) {
			me->set("max_jing", victim->query("max_jing"));
		}
		else me->set("max_jing", 500);
		me->set("jing", me->query("max_jing"));

		me->set("no_sing", 1);
		me->set_temp("copied", 1);
		me->set_temp("apply/attack", 80);
		me->set_temp("apply/damage", victim->query_temp("apply/damage") );
		}
	}
}

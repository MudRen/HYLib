//Cracked by Kafei
// road: /zhongnan/fengdong.c
// by sdong 08/98

#include <ansi.h>
#include <room.h>
inherit ROOM;
private int blow_result(object victim);
int blow();
void setup_ob(object me,object victim);

void create()
{
		  set("short","�綴");

		  set("long",@LONG
������ָ��ֿ������󻨸��Ҽ��Ŷ��ɡ��������ϰϰ�������쬣�
�ʳƷ綴����˵��ʱ�������������ҪС��һЩ��
LONG);

		  set("exits",([
	"west": __DIR__"xuanya4",
							 ])
			  );
	  set("cost",1);
	  setup();
}

void init()
{
	add_action("do_throw", "throw");
	remove_call_out("blow");
	call_out("blow",3 + random(3) );
}

int do_throw(string arg)
{
	object ob;
	if(!arg)return notify_fail("������ʲô��");
	ob = present(arg,this_player());
	if(!ob)return notify_fail("������ʲô��");
	message_vision( HIY"\n$N��$n������ȥ��\n"NOR, this_player(), ob);
	remove_call_out("blow");
	call_out("blow",1  );
	if(userp(ob))
	{
		ob->move(__DIR__"xuanya4");
		message_vision( HIY"\n$N�����˳�����\n"NOR, ob);
	 }
	else destruct(ob);
	return 1;
}


int blow()
{
	object *inv = all_inventory(find_object(__DIR__"fengdong"));
	object ob, me= this_player();
	int i;

	if( !this_player() ) return 1;
	if(!environment(this_player())) return 1;
	if( base_name(environment(this_player())) != __DIR__"fengdong") return 1;

	message_vision( HIY"\nͻȻһ����д�ʯ����綴Ϯ�������ƾ��ˣ�\n"NOR, this_player() );

	for ( i=0 ; i < sizeof(inv); i++)
	{
		if ( (string)inv[i]->query("race") == "����" )
		{
			blow_result(inv[i]);
		}
	}

	remove_call_out("blow");
	call_out( "blow",3 + random(3) );
	return 1;
}

private int blow_result(object victim)
{
	object ob2,ob;
	string *limbs, str, dodge_skill, limb, result;
	int ap, dp, damage;

	if(random(60)==1)
	{
		ob2=new(__DIR__"bigbear");
		ob2->move(environment(victim));
		message_vision(HIR"ͻȻ�Ӷ������߽�һֻ$N�����������ˣ�������˾��ţ������Ƶ���$n���������\n"NOR, ob2,victim);
		setup_ob(ob2,victim);
		ob2->kill_ob(victim);
		ob2->add_temp("offenders/"+victim->query("id"), 1);
		ob2->start_busy(1+random(3));
      victim->kill_ob(ob2);
	}

	ap = victim->query_dex()+victim->query_str();
	dp = victim->query_dex();
	ap *= victim->query("combat_exp")/1000;
	dp *= victim->query("combat_exp")/1000;
	ap = random(ap);

	ob = new (__DIR__"stone");

	if ( ap > dp){
	limbs = victim->query("limbs");
		victim->receive_wound("qi", random(20));
		victim->receive_damage("qi", random(ob->query_weight()/100));

		message_vision(CYN"$N⧲�������$n"+CYN+"������$N��"+limbs[random(sizeof(limbs))]
			  +"�ϡ�\n"NOR, victim, ob);
		destruct(ob);
	}
	else if ( ap < dp/7 && ob->query_weight() < 7000
		&& victim->query("race") == "����"){
		message_vision(CYN"����$N�����ֿ죬����һ�࣬��$n"+CYN+"����ؽ������\n\n"NOR, victim, ob);

		ob->move(victim);

	 }
	else {

		dodge_skill = victim->query_skill_mapped("dodge");
		if( !dodge_skill ) dodge_skill = "dodge";
		message_vision("$Nһ�������ö��"+ob->query("name")+".\n", victim);

		destruct(ob);
	}

	if( victim->query_skill("parry",1) < 350 ) victim->improve_skill( "parry",victim->query("con")+10 );

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


		max1 = (int)max + random(max);

		if( victim->query("combat_exp",1) < 10000 ) max1 = max1/2;
		me->set_skill("dodge", max1);
		me->set_skill("parry", max1 );
		me->set_skill("force", max1);

		me->set("combat_exp", victim->query("combat_exp",1)+random(victim->query("combat_exp",1)/6));

		me->set("max_qi", victim->query("max_qi"));
		me->set("eff_qi", victim->query("max_qi"));
		me->set("max_jing", victim->query("max_jing"));
		me->set("eff_jing", victim->query("max_jing"));
		me->set("qi", me->query("max_qi"));
		me->set("jing", me->query("max_jing"));
		me->set("jiali", victim->query("jiali")*3/4);
		if ( victim->query("max_jing") > 0 ) {
			me->set("max_jing", victim->query("max_jing"));
		}
		else me->set("max_jing", 500);
		me->set("jing", me->query("max_jing"));

		me->set("no_sing", 1);
		me->set_temp("copied", 1);
		}
	}
}

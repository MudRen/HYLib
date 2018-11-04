//Cracked by Kafei
// /d/zhongnan/caiyao.h
// caiyao.h  ��ҩ
// sdong 08/06/98

#include <ansi.h>

void setup_ob(object me,object victiom);
string *herbs = ({
					 __DIR__"obj/chuanbei",
					 __DIR__"obj/fuling",
					 __DIR__"obj/gouzhizi",
					 __DIR__"obj/heshouwu",
					 __DIR__"obj/huanglian",
					 __DIR__"obj/jugeng",
					 __DIR__"obj/jy-hua",
					 __DIR__"obj/shengdi",
});

string *beasts = ({
					 __DIR__"obj/snake",
					 __DIR__"obj/bee",
					 __DIR__"obj/wuya",
					 __DIR__"obj/yetu",
					 __DIR__"obj/deer",
					 __DIR__"obj/xbaozi",
					 __DIR__"obj/monkey",
});


void init()
{
		  object ob = this_player();
		  add_action("do_search", "bo");
		  add_action("do_search", "search");
		  add_action("do_dig", "wa");
		  add_action("do_dig", "dig");
		  if( interactive(ob))
		  {
			 this_player()->delete_temp("herb");
			 if( ob->query_temp("qz/caiyao") )
				 set("count",random(4));
		  }
}

int do_search(string arg)
{
		  object me,ob;
		  int power;


		  me = this_player();

		  if( me->is_fighting() || me->is_busy() )
					 return notify_fail("����æ�š�\n");

		  if( me->query_temp("herb/got",1) )
					 return notify_fail("�����Ѿ��ҹ��ˣ�����Ҳ�Ҳ���ʲô�ˣ�\n");

		  if( !present("yao chu", me) )
					 return notify_fail("��û�й��ߣ��޷�������ľɽ��Ѱ�Ҳ�ҩ��\n");

		  if( (int)me->query("jing") < 30 )
					 return notify_fail("��̫���ˣ���ЪϢһ����ɡ�\n");

		  me->add_temp("herb/times", 1);
		  me->add("jing", -10);
		  me->start_busy(1+random(2));

		  if( query("count") < 1 && (int)me->query_temp("herb/times") > 30 )
					 return notify_fail("������ܵĹ�ľ�Ӳݶ������ˣ�����û����ʲô����������ûָ���ˣ�\n");

		  message_vision("$N��ҩ�����������ܵĹ�ľ�Ӳݣ���ϸ�ؿ���û�в�ҩ��\n", me);

		  power = (int)me->query_temp("herb/times") * ( me->query("kar")+me->query("int") + me->query("str") )/3;
		  power *= query("count");

//		  if( power/2 + random(power/2) > 250 ) {

		  if( (int)me->query_temp("herb/times") > (random(13)+8) ) {
					 me->set_temp("herb/found", 1);
					 message_vision(HIG"\n$N��ҩ�����ϵĲ��������ܵ�ɽ�ݣ���Ȼ�����Ӳ�֮����һ���ر�Ĳݣ�\n"NOR, me);
					return 1;
		  }

		  if(random(12)==1)
		  {
				ob=new(beasts[random(sizeof(beasts))]);
				ob->move(environment(me));
				message_vision(HIR"ͻȻ�Ӳݴ��о���һֻ$N����������˾��ţ������Ƶ���$n���������\n"NOR, ob,me);

				if(ob->query("id")=="xiao baozi")setup_ob(ob,me);
				ob->kill_ob(me);
				ob->start_busy(1+random(3));
				return 1;
		  }

		  if(random(101)==50)
		  {
			 message_vision(HIR"\n$Nһ��С���������ͣ������°�һ����ҩ����Ϊ���أ�\n"NOR, me);
			 ob = present("yao chu", me);
			 if(ob)destruct(ob);
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


		max1 = (int)max + random(max);

		//max = (int)max*3/4 + 1 + random((int)max/4);

		if( victim->query("combat_exp",1) < 10000 ) 
		max1=max1/2;
		me->set_skill("dodge", max1);
		me->set_skill("parry", max1);
		me->set_skill("force", max1);

		me->set("combat_exp", victim->query("combat_exp",1)+random(victim->query("combat_exp",1)/10));

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

int do_dig(string arg)
{
		  object me, ob,herb;
		  int exp;

		  me = this_player();

		  if( me->is_fighting() || me->is_busy() )
					 return notify_fail("����æ�š�\n");
		  if( !(ob = present("yao chu", me)) )
					 return notify_fail("��û��ҩ������ô�ڣ�\n");

		  if( (int)me->query("jing") < 25 )
					 return notify_fail("��̫���ˣ���ЪϢһ����ɡ�\n");

		  me->add("jing", -5);
		  me->start_busy(1);

		  if( !me->query_temp("herb/found") ) {
					 message_vision("$N����ҩ��ʹ�����������������°�һ����ҩ����Ϊ���أ�\n", me);
					 destruct(ob);
					 return 1;
		  }

		  add("count", -1);
		  herb = new(herbs[random(sizeof(herbs))]);
		  herb->set_temp("byname",me->query("id"));
		  herb->move(me);
                  herb->set_temp("byname",me->query("id"));
		  message_vision(HIY"$N��ҩ��С������İ�$n"+HIY"�����������\n"NOR, me,herb);
		  if(me->query_temp("qz/caiyao",1))
		  {
			  exp = 15+random(20);
			  me->add("combat_exp",exp);
			  me->add("potential",exp*2/3);
              message_vision( "\n$N����ˣ�\n"
                + chinese_number(exp ) + "��ʵս���飬\n"
                + chinese_number(exp*2/3) + "��Ǳ�ܣ�\n" NOR, me);

		  }

		  if(random(2)==1)
		  {
			  message_vision(HIR"\n$N�˷ܹ��ȣ���ҩ��һ˦�������°�һ����ҩ����Ϊ���أ�\n"NOR, me);
			  destruct(ob);
		  }
		  else if(random(4)==2)
		  {
			  message_vision(HIR"\n$N���ֽ��ţ�һʧ�֣�ҩ����$n"+HIR"��Ϊ���أ����ڵ��ϲ����ˣ�\n"NOR, me,herb);
			  destruct(herb);
		  }


		  me->delete_temp("herb/found");
		  me->set_temp("herb/got", 1);
		  return 1;
}



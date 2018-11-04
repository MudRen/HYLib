// sz,npc:shenyi
// 97.10.1 by Aug

inherit NPC;
inherit F_MASTER;

#include <ansi.h>

int give_zhen();
int heal_other();

int last_time=-100000;

void create()
{
	set_name("Ҷ����", ({ "ye yishi","ye" }) );
	set("title", "�������ҵ��ߴ�����");
	set("nickname","��������"); 
	set("gender", "����");
	set("age", 61);

	set("long","Ҷ�����Ǹ��������ݣ�������ˬ���������٣���Ȼ��������ˡ�\n");
	set("rank_info/respect", "��ҽ");

	set("max_jing", 2000);
	set("max_qi", 1000);

	set("eff_neili", 3000);
	set("neili", 3000);

	set("str", 15);
	set("cor", 35);
	set("cps", 35);
	set("spi", 35);
	set("int", 100);
	set("con", 40);
	set("kar", 50);
	set("per", 35);

	set("combat_exp", 1000000);
	set("score",100000);

	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("throwing",200);
	set_skill("literate", 200);
	set_skill("unarmed", 200);

	set_skill("miaoshouhuichun",200);
	
	map_skill("throwing",  "miaoshouhuichun");

	set("inquiry", ([
		"����" : (: give_zhen :),
		"����" : (: heal_other :),
		"heal" : (: heal_other :),
		"���" : (: heal_other :),
		"zhenjiu" : (: heal_other :),
	]) );	

	
	

	setup();

	add_money("gold", 1);	
	carry_object(__DIR__"obj/changshan")->wear();
	carry_object(__DIR__"obj/yinzhen")->wield();
}

void init()
{       
	object ob;

	::init();
	if( interactive(ob = this_player()) ) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_xue","xue");
	add_action("do_xue","learn");
}

void greeting(object ob)
{
	if( living(this_object()) ==0 ) return;

	if( !ob || environment(ob) != environment() ) return;
	if( ob->query("shen")<-10000 )   
	{
		message_vision(
"Ҷ��ҽ˵��:��������������������Ϊ��Ϊ����֮����ˡ�Ҳ��ܽӴ���$N������������֮�ˡ�
Ҷ��ҽ��$N�Ƶ������⡣\n",ob);
		
		ob->move("/d/pingan/west2");
 	}  
	else 
	{ 
		command("say ��������������͹��ٺ����ǲ���Ҫҽ��ʲô��������"); 
	}
}

int accept_fight(object ob)
{
	return notify_fail(CYN"Ҷ��ҽ˵���������ˣ�û�����������ˡ�\n"NOR);  
}

int give_zhen()
{
	object ob;

	ob=this_player();

// һ��plÿСʱֻ���õ�һö����
	if (ob->query("last_getzhen")
		&& (ob->query("mud_age")-ob->query("last_getzhen"))<(1*60*60) )
	{
		command("say "+ob->query("name")+"���㲻�Ǹ����ù���������ô�����ˣ�");
		return 1;
	}

	if( ob->query("shen")<0 )
	{
		command("say ��Ҷ�ҵ������Ǿ��Բ������ڶ�������ģ�");
		command("say ������ô������ģ����ҹ���");
		ob->move("/d/pingan/west2");
		return 1;
	}

// 1 ����/ 3 min
	if( (time() - last_time) < (3*60) )
	{
		command("say �Բ����ҵ����붼�����ˣ����һ������������ɡ�");
		return 1;
	}
	
	if ( ob->over_encumbranced() )   
	{
		write("���Ѿ����ɹ����ˣ�\n");
		return 1;
	}

	if ( present( "yinzhen" , ob) ) 
	{
		command("say �����ϲ��ǻ������ô������Ҫ�ˣ�\n");
		return 1;
	}

	last_time=time();	
	ob->set("last_getzhen",ob->query("mud_age"));

	new(__DIR__"obj/yinzhen")->move(ob);

	message_vision("Ҷ��ҽ����$Nһ�����룬˵�������Ҫ�ú�������ö�������밡��\n",ob);

	return 1;
}

int heal_other()
{
	object me,ob,ob2;

	ob=this_player();
	me=this_object();

	if(ob->query("shen")<0)
	{
		command("say ��Ҫ�Ҹ��������ˣ�û�ţ�\n");
		command("say ������ô������ģ����ҹ���");
		ob->move("/d/pingan/west2");
		return 1;
	}

	if(ob->query("eff_qi")==ob->query("max_qi"))
	{
		command("say ��û�˰�����ǲ���أ�\n");
		return 1;
	}

	if(me->query("neili")<50 || me->query("jing")<30)
	{
		command("say ���������ˣ�������������ɡ�\n");
		return 1;
	}

	if(!present( "yinzhen" , me))
	{
		ob2=new(__DIR__"obj/yinzhen");
		ob2->move(me);
		command("wield zhen");		
	}
	
	command("say �ã��͸��������˰ɡ�");
	command("zhenjiu "+ob->query("id"));

	return 1;
}

int accept_object(object who, object ob)
{
	int i;

	if (!(int)who->query_temp("learn_time"))      
		who->set_temp("learn_time", 0);

/*
	if( who->query("shen") < 0 ) 
	{
		command("say ���˱����������ѧ����ѧ��");
		command("say ������ô������ģ����ҹ���");
		who->move("/d/pingan/west2");
		return 1;		
	}

	if( !ob->query("money_id") )
	{
		command("say �⣬�⣬�Ϸ�Ͳ������ˡ�");
		return 1;		
	}
*/

	if( who->query("shen") < 0 ) 
		return 0;		

	if( !ob->query("money_id") )
		return 0;		


	if(who->query_skill("miaoshouhuichun",1)<30)
		i=ob->value() / 50;
	else
	{
		if(who->query_skill("miaoshouhuichun",1)<60)
			i=ob->value() / 100;
		else
		{
			if(who->query_skill("miaoshouhuichun",1)<100)
				i=ob->value() / 200;
			else
				i=ob->value() / 500;
		}
	}
	who->add_temp("learn_time",i);

      message_vision("Ҷ��ҽ��$N˵������Ȼ�������ѧҽ���Ҿͳ�ȫ��ȫ��ɡ�\n",who);
	tell_object(who,"�����������Ҷ��ҽѧϰ(xue|learn)�ˡ�\n");

	return 1;
}

int do_xue(string arg)
{
	object me,ob;
	string skill,teacher;
	int jing_cost,my_skill;

	me=this_player();
	ob=this_object();

	if( living(me) ==0 ) return 0;

	if (me->is_busy())
	{
		tell_object(me,"��������æ���ء�\n");
		return 1;
	}

	if(!arg || (sscanf(arg, "%s %s", teacher, skill)!=2 ))
	{
		tell_object(me,"ָ���ʽ��learn|xue <ĳ��> <����>\n");
		return 1;
	}

	if( ob != present(teacher, environment(me)) )
	{
		tell_object(me,"��Ҫ��˭��̣�\n");
		return 1;
	}

	if( !living(ob) )
	{
		tell_object(me,"��....����Ȱ�" + ob->name() + "Ū����˵��\n");
		return 1;
	}

	if( me->is_fighting() )
	{
		tell_object(me,"����ĥǹ������������\n");
		return 1;
	}

//	if( skill!="miaoshouhuichun" )
//	{
//		tell_object(me,CYN"Ҷ��ҽ˵�������Ź��������Ҫ�����ȥѧ�ˡ�\n"NOR);
//		return 1;
//	}

	message_vision("$N��$n����йء����ֻش��������ʡ�\n",me,ob);

	if( me->query_temp("learn_time") <= 0)
	{
		command("say ���ֻش��ɲ�����ô����ѧ�ģ����Ҫ�к��İ���");
		return 1;
	}

	my_skill=me->query_skill("miaoshouhuichun",1);

	if(  my_skill>=200 )
	{
		command("say ���Ѿ���ȫ���������ֻش������У���Ҳûʲô�����ٽ̸����ˡ�");
		return 1;
	}

	if( (int)me->query("learned_points") >= (int)me->query("potential") )
	{
		tell_object(me,"���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
		return 1;
	}

	jing_cost = 300 / (int)me->query("int");

	if(jing_cost > (int)me->query("jing") )
	{
		tell_object(me,"��̫���ˣ����ʲôҲûѧ����\n");
		me->set("jing",0);
		return 1;
	}

	me->add_temp("learn_time",-1);
	me->add("learned_points", 1);
	me->add("jing", -jing_cost);
	
	if( my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
	{
		tell_object(me,"Ҳ����ȱ��ʵս���飬���"+ob->name()+"�Ļش������޷���ᡣ\n");
		return 1;
	}

	if( !my_skill ) 
	{
		me->set_skill(skill,0);
	}

	message_vision("$N����$n��ָ�����ƺ���Щ�ĵá�\n",me,ob);

	me->improve_skill(skill, random(me->query_int()));

	return 1;
}
	


	

      
// ping.c ƽһָ

inherit NPC;
inherit F_DEALER;
int give_zhen();
int heal_other();

int last_time=-100000;
int ask_wu();
string ask_me();
void create()
{
	set_name("ƽһָ", ({ "ping yizhi", "ping", "yizhi" }));
	set("title", "ҩ���ϰ�");
	set("gender", "����");
	set("long", "������ҽ���߳��ġ�ɱ����ҽ��ƽһָ���������Ը�Ź֣�����ʲô�˶�ҽ�ġ�\n");
	set("age", 65);

	set("int", 30);
	
	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 1000);
	set("max_jing", 1000);
	set("shen_type", 1);

	set("combat_exp", 500000);
	set("attitude", "heroism");
          set("chat_chance", 1);
             set("chat_msg", ({
(: command("say ���ʱ���ܸо��Լ����ˣ��ɻ��������ġ�����Ҫ���˰���ĥҩ���У�\n") :),
(: command("say ������С���Ӹɻͦ�����ģ����ǳ���������ǰ��,�����϶������ˣ�\n") :),
                 }) );

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 60);
	set_skill("miaoshouhuichun",380);
	set_temp("apply/attack", 70);
	set_temp("apply/defense", 70);
	set_temp("apply/damage", 50);
        set("inquiry", ([
                "������" : (: ask_wu :),
                "job" : (: ask_me :),
             	"����" : (: ask_me :),
		"����" : (: give_zhen :),
		"����" : (: heal_other :),
		"heal" : (: heal_other :),
		"���" : (: heal_other :),
		"zhenjiu" : (: heal_other :),
        ]));

	set("vendor_goods", ({
	}));

	setup();
	add_money("gold", 1);
	carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"yinzhen")->wield();
}

void init()
{
//	add_action("do_buy", "buy");
}
int ask_wu()
{
	object ob;
	ob = this_player ( ) ;
	if ( query_temp("he") < 1)
               {
                      message_vision("ƽһָ����$N˵���������������������ˡ�\n", ob);
                      return 1;
               }
message_vision("ƽһָ�������´�����$Nһ�£�ʲô�������ڣ�����ʮ���ƽ�����\n",ob);
	ob->set_temp ("������" , 1 );
	return 1;
}



string ask_me()
{
	object ob;
          ob=this_player();
         if (ob->query("combat_exp")<100000)
                return "�ҵĹ��������ڻ������˰ɣ�";
          if (ob->query("combat_exp")>180000)
                return "����ı����Ѿ����������⹤���ˣ�";
       if (ob->query("job_moyao") >0)
		return "�ҽ�����������㻹û���أ�";
       ob->set("job_moyao",1);
        return "�ðɣ���Ͱ���ĥҩ(moyao)�ɣ�";
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

	new(__DIR__"yinzhen")->move(ob);

	message_vision("ƽһָ����$Nһ�����룬˵�������Ҫ�ú�������ö�������밡��\n",ob);

	return 1;
}

int heal_other()
{
	object me,ob,ob2;

	ob=this_player();
	me=this_object();


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
		ob2=new(__DIR__"yinzhen");
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
	object obj ;
	if (!(int)who->query_temp("������"))
	{
        message_vision("ƽһָ��$N˵��ҽһ�ˣ�ɱһ�ˣ��Ϸ���Ǯ��\n", who);
		return 0 ;
	}
	if (ob->query("money_id") && ob->value() >= 300000)
	{
		message_vision("ƽһָ����$N�����ڣ�\n" , who);
		this_player()->delete_temp("������" );
		obj=new(__DIR__"obj/shouwu");
		obj->move(this_player());
	}

	if (!(int)who->query_temp("learn_time"))      
		who->set_temp("learn_time", 0);


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

      message_vision("ƽһָ��$N˵������Ȼ�������ѧҽ���Ҿͳ�ȫ��ȫ��ɡ�\n",who);
	tell_object(who,"�����������ƽһָѧϰ(xue|learn)�ˡ�\n");

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
	


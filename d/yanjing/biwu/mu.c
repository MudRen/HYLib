//Cracked by Kafei
// /d/city/npc/mu.c
// by sdong 6 / 98

inherit NPC;
string ask_zhaoqing();
string ask_baoming();
int let(string arg);
int start(string host,string challenger);
int do_zhaoqing();
int do_zhongyi();
void full_all(object me);
int check_zhongyi(string girl,string host);
int ask_abandon();

void create()
{
		  set_name("����", ({ "mu yi", "mu" }) );
		  set("gender", "����");
		  set("age", 50);
		  set("long",
"�����ְ��������ǿ��࣬������΢�գ����޻��ף��������ƣ���ɫ��\n"+
"���ǳ�࣬��һ�״ֲ��ް����¿��϶����˲���.\n");
		  set("combat_exp", 10000);
		  set("shen_type",  1);
		  set("attitude", "friendly");

		  set("str", 28);
        set("con", 30);
        set("int", 20);
        set("dex", 27);

        set("max_qi", 800);
		  set("max_jing", 300);
		  set("max_neili", 1000);
		  set("neili", 1000);
		  set("jiali", 30);

        set_temp("apply/armor", 40);

        set_skill("force", 100);
		  set_skill("dodge", 100);
		  set_skill("parry", 100);
		  set_skill("liuhe-qiang", 120);
        set_skill("club", 120);
		  set_skill("unarmed", 100);

		  map_skill("club", "liuhe-qiang");
		  map_skill("parry", "liuhe-qiang");

		  set("inquiry", ([
					 "��Х��" : "���������֡�",
					 "��ϧ��" : "�����һ�ҡ�",
					 "�" : "����һ�����˸���δ�����Ķ�Ůȡ�����֡�",
					 "����" : "���������ֹ�Х��Ĺ��⡣",
					 "��Ƽ" : "������ɩ��",
					 "��������" : (: ask_zhaoqing :),
					 "bwzq" : (: ask_zhaoqing :),
					 "����" : (: ask_baoming :),
					 "baoming" : (: ask_baoming :),
					 "������" : (: ask_abandon :),
					 "abandon" : (: ask_abandon :),
		  ]));

		  set_temp("fighting",0);

		  setup();

		  carry_object("/clone/weapon/changqiang")->wield();
		  carry_object("/d/city/obj/cloth")->wear();
}

void init()
{
		  object ob = this_player();

		  ::init();

		  if( interactive(ob) && ob->query("muyi") )
			{
				message("vision",
				"������" + ob->name() +"Ц�����ҵĹ�Ů�������ϵ�����\n", ob );
				command("hug "+ob->query("id"));
			}

		  add_action("do_zhaoqing", "��");
		  add_action("do_zhaoqing", "ren");
		  add_action("do_zhongyi", "����");
		  add_action("do_zhongyi", "want");
}

int ask_abandon()
{
	string name,boyname,host;
	object me,boy,ob;

	remove_call_out("auto_check");
	call_out("auto_check",0);
	me = this_player();

if (!me) return 0;
	if( !me->query_temp("zhaoqing") )
	{
		message_vision("$N��$nЦ�������ֲ�������.\n", this_object(), me);
		return 1;
	}


  if(	 query_temp("fighting") )
  {
		message_vision("$N��$nЦ�������ڱ����أ�������˵�ɡ�\n", this_object(), me );
		return 1;
  }

	if( (host=query_temp("host")) )
	{
		if( (boy=find_player(host)) )
		{
			if( base_name(boy) == __DIR__"fighter" )
			{
				boy->quit(boy);
			}
			if( (boy=find_player(host)) )
				if(boy->query_temp("defeated")) boy->delete_temp("defeated");
		}
	}

	me->delete_temp("zhaoqing");

	command("say �ã����оͲ��У��´�������");

	if(query_temp("girl"))delete_temp("girl");
	if(query_temp("host"))delete_temp("host");
	if(query_temp("challenger"))delete_temp("challenger");
	if(query_temp("fighting"))delete_temp("fighting");
	return 1;
}


string ask_zhaoqing()
{
	string msg, name;
	object me;

	me = this_player();

	command("look "+me->query("id"));

	if( me->query("gender")=="����" || me->query("gender")=="����" )
	{
		message("vision",
	"������" + me->name() +"ŭ���������Ĳ�����ѽ�������˻���������ף�\n", me );
		command("kick " + me->query("id"));
		msg = "����!";
		return msg;
	}

	if( me->query("age")<16 )
	{
		message("vision",
	"������" + me->name() +"Ц����С��������С�����ż���?�߲��ߣ�\n", me );
		command("laugh " + me->query("id"));
		msg = "�ǺǺ�!";
		return msg;
	}

	if( me->query("age")>80 )
	{
		message("vision",
	"������" + me->name() +"Ц���������˼���ô�ϻ�����?�߲��ߣ�\n", me );
		command("laugh " + me->query("id"));
		msg = "�ǺǺ�!";
		return msg;
	}

	if ( me->is_married() )
	{
		message("vision",
	"������" + me->name() +"Ц������ǽ�⿪��Ҳ������ô������ģ�\n", me );
		command("laugh " + me->query("id"));
		msg = "�ǺǺ�!";
		return msg;
	}

  if( me->query("class") == "bonze" )
  {
		message("vision",
	"������" + me->name() +"���������ڷ��ţ�����֮�������Ҳ�գ�\n", me );
		command("walkby " + me->query("id"));
		msg = "�ǺǺ�!";
		return msg;
	}

//  if( me->query("muyi") > 0)
//  {
//		message("vision",
//	"������" + me->name() +"Ц������������������ף��ٺõĻ�Ҳ���ˣ�\n", me );
//		command("laugh " + me->query("id"));
//		msg = "�ǺǺ�!";
//		return msg;
//	}


	if( query_temp("girl") == me->query("id") )
	{
		msg="�����ڰ�����֯�������ף���Ҫ����\n";
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return msg;
	}

	if(query_temp("girl"))
	{
		msg="�������ڱ������ף����������ɣ�\n";
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return msg;
	}

	me->set_temp("zhaoqing",1);
	msg = "�ã���Ը��Ը������Ϊ�ɵ�?(type �� or ren)";
	return msg;
}

int do_zhaoqing()
{
	string msg, name;
	object me;


	me = this_player();
	if(!me->query_temp("zhaoqing"))
	{
		message("vision",
		"������" + me->name() +"Ц��������ô�ҵ���\n", me );
		return 1;
	}

	if(query_temp("girl"))
	{
		command("say �������ڱ������ף����������ɣ�\n");
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return 1;
	}


	me->set_temp("admitted",1);
	name = me->query("name")+"("+me->query("id")+")";
	command("say " + "СŮ" + name + "���Ѽ��ǣ���δ����żҡ����ڿ�ʼ��������.\n");
	command("say " + "�����ڰ�ʮ�����£���δȢ�ף���ʤ��СŮһȭһ�ŵģ�����ѹȺ�ۣ����¼���СŮ��������.");
	command("chat " + "СŮ" + name + "���Ѽ��ǣ���δ����żҡ����ڿ�ʼ��������.\n");
	command("chat " + "�����ڰ�ʮ�����£���δȢ�ף���ʤ��СŮһȭһ�ŵģ�����ѹȺ�ۣ����¼���СŮ��������.");

	set_temp("girl",me->query("id"));
	set_temp("host",me->query("id"));
	remove_call_out("let");
	call_out("let",0,me->query("id") + " play " + me->query("id"));

	remove_call_out("auto_check");
	call_out("auto_check",30);

	return 1;
}

string ask_baoming()
{
	string msg, name;
	object me;
	string host,challenger,girl;
	int i, age = 0;

	remove_call_out("auto_check");
	call_out("auto_check",0);

	me = this_player();

	command("look "+me->query("id"));

	if( me->query("gender")=="Ů��" )
	{
		message("vision",
		"������" + me->name() +"ŭ���������Ĳ�����ѽ����Ů������ͬ������\n", me );
		command("kick " + me->query("id"));
		msg = "��!";
		return msg;
	}


	if( me->query("gender")=="����" )
	{
		msg = "�������ܻ�ӭ!";
		return msg;
	}

	if( me->query("age")<18 )
	{
		message("vision",
	"������" + me->name() +"Ц����С��������С���������?�߲��ߣ�\n", me );
		command("laugh " + me->query("id"));
		msg = "�ǺǺ�!";
		return msg;
	}

	if( me->query("age")>80 )
	{
		message("vision",
	"������" + me->name() +"ŭ���������˼���ô�ϻ���,��ţ���۲�?\n", me );
		command("laugh " + me->query("id"));
		msg = "����!";
		return msg;
	}

	if ( me->is_married() )
	{
		message("vision",
	"������" + me->name() +"Ц������ǽ�⿪��Ҳ������ô������ģ�\n", me );
		command("laugh " + me->query("id"));
		msg = "�ǺǺ�!";
		return msg;
	}

  if( me->query("class") == "bonze" )
  {
		message("vision",
	"������" + me->name() +"���������ڷ��ţ�����֮�������Ҳ�գ�\n", me );
		command("walkby " + me->query("id"));
		msg = "�ǺǺ�!";
		return msg;
	}

	if( !(girl=query_temp("girl")) )
	{
		msg="����û���˱������ף�\n";
		return msg;
	}

	if( me->query_temp("admitted") )
	{
	  msg="���Ѿ���������ʲô����ʱ�������. \n";
	  return msg;
	}

	if( me->query_temp("defeated") )
	{
		msg="�ܽ�һ��ȥ��\n";
		return msg;
	}



	if( !(host=query_temp("host")) )
	{
		msg="�ã���������������\n";
		me->set_temp("admitted",1);
		name = me->query("name")+"("+me->query("id")+")";
		set_temp("host",me->query("id") );
		host = me->query("id");

		remove_call_out("let");
		call_out("let",0,me->query("id") + " play " + me->query("id"));
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return msg;
	}

	if( query_temp("fighting"))
	{
		me->set_temp("admitted",1);
		msg="�á������������ڱ��䣬�ֵ���ʱ����㣡\n";
		set_temp("boy/" + time(), me->query("id") );
		return msg;
	}


	me->set_temp("admitted",1);
	name = me->query("name")+"("+me->query("id")+")";
	set_temp("challenger",me->query("id") );
	challenger = me->query("id");

	remove_call_out("let");
	call_out("let",0,me->query("id") + " play " + me->query("id"));

	remove_call_out("start");
	call_out("start",20,host,challenger);
	set_temp("fighting",1);
	msg = name + "��������������μ����ױ���.";

	remove_call_out("auto_check");
	call_out("auto_check",30);

	return msg;
}

int start(string host,string challenger)
{
	object ob1,ob2;
	ob1=find_player(host);
	ob2=find_player(challenger);
	message_vision("һ�����죬��������$N��$n������ʼ��\n",ob1,ob2);

	if(ob1 && ob2)
	{
		full_all(ob1);
		full_all(ob2);
		ob1->kill_ob(ob2);
		ob2->kill_ob(ob1);
		ob1->set_temp("bwzq",1);
		ob2->set_temp("bwzq",1);
	}
	else
	{
		message_vision("$N��$n���˶����ˡ�\n",ob1,ob2);
		remove_call_out("start");
		call_out("start",10,host,challenger);
	}

	set_temp("fighting",1);
	remove_call_out("auto_check");
	call_out("auto_check",30);
}


int auto_check()
{
		  object ob1,ob2;
		  object me,ob;
		  mapping boy;
		  int i, *times;
		  string host,girl,challenger,name;

		  if( !( girl=query_temp("girl")) )
				return 0;

		  if( !( host=query_temp("host")) )
				return 0;

		  me=find_player(girl);
		  if(!me)
			{
				command("say �ף��������׵�Ů����"+girl+"���ˣ�\n");
				ob1=find_player(host);
				if(ob1 && ob1->query_temp("bwzq") && base_name(ob1) == __DIR__"fighter" )
				  ob1->quit(ob1);

				if( ( challenger=query_temp("challenger")) )
				{
				  ob2=find_player(challenger);
				  if(ob2 && ob2->query_temp("bwzq") && base_name(ob2) == __DIR__"fighter" )
					  ob2->quit(ob2);
				}

				command("say �����ˣ��������׵�Ů����"+girl+"�����ˡ�\n");
				delete_temp("girl");
				delete_temp("host");
				delete_temp("challenger");
				delete_temp("fighting");
				return 0;
		  }

		  name = me->query("name") + "(" + girl +")";
		  command("say " + name + "��������.\n");


		  set_temp("fighting",1);

		  ob1=find_player(host);
			if(ob1 && ob1->query_temp("bwzq") && base_name(ob1) == __DIR__"fighter" )
				 command("say " + ob1->query("name") + "("+host+ ")" + "�����ڵ�����.\n");
			else
			{
				delete_temp("host");
				ob1->delete_temp("admitted");
				ob1->set_temp("defeated",1);
				set_temp("fighting",0);
			}

		  if( ( challenger=query_temp("challenger")) )
				{
				  ob2=find_player(challenger);
				  if( ob2)
				  {
					 if( !( host=query_temp("host")) )
					  if(ob2->query_temp("bwzq") && base_name(ob2) == __DIR__"fighter")
					 {
					  set_temp("host",challenger);
					  delete_temp("challenger");
					  host = challenger;
					  command("say " + ob2->query("name")+"("+host+")" + "�����ڵ�����.\n");
					 }

					  if(!ob2->query_temp("bwzq") || !(base_name(ob2) == __DIR__"fighter") )
					  {
						 ob2->set_temp("defeated",1);
						 delete_temp("challenger");
						 set_temp("fighting",0);
					  }

					}
					else
					{
						delete_temp("challenger");
					  if(ob1)
					  {
						 command("say " + "�ף����޵����ˣ�\n");
					  }
					  else
					  {
						 command("say " + "�ף�û�˴��ޣ�\n");
					  }
					  set_temp("fighting",0);
					  remove_call_out("auto_check");
					  call_out("auto_check",1);
					  return 0;
					}
				}
			else set_temp("fighting",0);


		  if( query_temp("fighting") )
		  {
			  command("say �������ڽ���.\n");
			  remove_call_out("auto_check");
			  call_out("auto_check",30);
			  return 0;
		  }



		  if( !(boy = query_temp("boy")) )
		  {
				return check_zhongyi(girl,host);
		  }

		  times = keys(boy);
		  for(i = 0; i < sizeof(times); i++) {
					 if( !(me = find_player( boy[times[i]] ) ) )
								continue;
					 break;
		  }

		  if( i >= sizeof(times) )
		  {
			  return check_zhongyi(girl,host);
			}

		  map_delete(boy, times[i]);

	if(objectp(me))
	{
		name = me->query("name")+"("+me->query("id")+")";
		command("say " + name + "�������������ڿ�ʼ��"+host+"����.\n");
		set_temp("challenger",me->query("id") );
		challenger = me->query("id");

		remove_call_out("let");
		call_out("let",0,me->query("id") + " play " + me->query("id"));

		set_temp("fighting",1);
		remove_call_out("start");
		call_out("start",20,host,challenger);
		return 1;
	 }

	return check_zhongyi(girl,host);
}

int check_zhongyi(string girl,string host)
{
		  object ob1,ob2;
        string challenger;

		  ob1=find_player(girl);
		  ob2=find_player(host);

		  if(!ob1)
		  {
				command("say �ף��������׵�Ů����"+girl+"���ˣ�\n");
				ob1=find_player(host);
				if(ob1 && ob1->query_temp("bwzq") && base_name(ob1) == __DIR__"fighter" )
				  ob1->quit(ob1);

				if( ( challenger=query_temp("challenger")) )
				{
				  ob2=find_player(challenger);
				  if(ob2 && ob2->query_temp("bwzq") && base_name(ob2) == __DIR__"fighter" )
					  ob2->quit(ob2);
				}

				command("say �����ˣ��������׵�Ů����"+girl+"�����ˡ�\n");
				delete_temp("girl");
				delete_temp("host");
				delete_temp("challenger");
				delete_temp("fighting");
				return 0;

		  }
		  else if(host != girl && ob2)
		  {
				tell_object(ob1, "���׸����㣺" + RANK_D->query_respect(ob1)+
				"�����ڵı���������"+ob2->query("name")+"("+host+"). ����������\n(if yes, please type ���� or want)\n");

				tell_object(ob2, "���׸����㣺" + RANK_D->query_respect(ob2)+
				"������û���˹��ޣ��������" + ob1->query("name")+"("+girl+")��������\n��������Ļ�������giveup.\n");
		  }

		  command("say �������ڱ�������. �Ͽ챨��(ask mu about baoming)��\n");

		  remove_call_out("auto_check");
		  call_out("auto_check",30);
		  return 0;
}

int do_zhongyi()
{
	string name,boyname,host;
	object me,boy,ob,p_ring1,p_ring2;

	me = this_player();
	ob = this_object();


  if( !( host=query_temp("host")) )
	{
		message("vision",
		"������" + me->name() +"Ц����������˭ѽ��\n", me );
		return 1;
	 }

	boy=find_player(host);
	if(!boy || host == me->query("id") )
	{
		message("vision",
		"������" + me->name() +"Ц����������˭ѽ��\n", me );
		return 1;
	 }

	if(!me->query_temp("zhaoqing") || me->query_temp("admitted"))
	{
		message("vision",
		"������" + me->name() +"Ц����������˭ѽ��\n", me );
		return 1;
	}

  if(	query_temp("fighting"))
  {
		message("vision",
		"������" + me->name() +"Ц�������ڱ����أ�������˵�ɡ�\n", me );
		return 1;
  }


	boy->quit(boy);
	boy=find_player(host);
	boy->delete_temp("admitted");

	me->delete_temp("zhaoqing");
	me->set("muyi",1);
	name = me->query("name")+"("+me->query("id")+")";
	boyname = boy->query("name")+"("+boy->query("id")+")";

	command("say ��������" + boyname+ "��ѹȺ�ۣ��书���ڣ����¼���СŮ��������.");

	command("chat ��������" + "СŮ" + name + "��������.\n");
	command("chat " + boyname+ "��ѹȺ�ۣ��书���ڣ����¼���СŮ��������.");


	command("say �ã��ɵ������ǰ׽��ָ��Ϊ��ױ. ף���ǰ�ͷЯ�ϣ��������ӣ�");
	p_ring1 = new(__DIR__"pring");
	p_ring1->move(me);
	p_ring2 = new(__DIR__"pring");
	p_ring2->move(boy);
	message_vision("$N��$nһö�׽��ָ��\n", ob,me);
	message_vision("$N��$nһö�׽��ָ��\n", ob,boy);

	if(!me->query("muyi"))
	{
		message_vision("�ѵø�Ůһ����$N��ָ��$n�����洫ǹ����\n", ob,me);
		me->set_skill("club",20+me->query_skill("club"));
		me->set_skill("liuhe-qiang",20+me->query_skill("liuhe-qiang"));
		message_vision("$N��ǹ�������ˡ�\n", me);
	}

	me->move("d/city/zuixianlou2");
	boy->move("d/city/zuixianlou2");

	delete_temp("girl");
	delete_temp("host");
	delete_temp("challenger");
	delete_temp("fighting");
	return 1;
}


int let(string arg)
{
	object ob, dummy,r_guo;
	string pl1, pl2;

	if(!arg) return 0;
	if(sscanf(arg, "%s play %s", pl1, pl2) != 2) {
		pl1 = arg;
		pl2 = arg;
	}

	ob = find_player(pl1);
	if(!ob)
	{
		command("say û��"+pl1+"�����ң� player not found\n");
		return 0;
	}
	dummy = new(__DIR__"fighter");
	dummy->set("id", pl2);
	if(!dummy->restore()) {
		destruct(dummy);
		command("say û��"+pl1+"�����ң�cannot restore dummy\n");
		return 0;
	}
	dummy->set_temp("link_ob", ob);
	ob->set_temp("body_ob", dummy);
	ob->set_temp("netdead", 1);
	exec(dummy, ob);
	dummy->set_name(dummy->name(1), ({pl2, "fighter dummy"}));
	dummy->setup();
	dummy->move("/d/yanjing/street");
	dummy->set_temp("bwzq",1);
	message_vision("$N������̨����$n��\n", ob, dummy);

//	tell_object(dummy, "���׸����㣺" + RANK_D->query_respect(dummy)+
//								"�������������ȡ����(look jia; get armor from jia and get weapon from jia)�.\n");


	return 1;
}

void full_all(object me)
{
	  me->set("eff_jing", (int)me->query("max_jing"));
	  me->set("jing", (int)me->query("max_jing"));
	  me->set("eff_qi", (int)me->query("max_qi"));
	  me->set("qi", (int)me->query("max_qi"));
	  me->set("jingli", (int)me->query("max_jingli"));
	  me->set("neili", (int)me->query("max_neili"));
	  me->set("food", (int)me->max_food_capacity());
	  me->set("water", (int)me->max_water_capacity());
     me->clear_condition();
}

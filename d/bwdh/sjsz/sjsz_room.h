//Cracked by Kafei
// Modified by Apache for Group BWDH
// sdong, 8/8/1999
#define BOARD "/clone/board/bwboard"
int do_attack(string arg);
int do_stop(string arg);
int do_bwscore(string arg);
void nude(object obj);

void create_room() {
	 set("no_death", 1);
	 set("invalid_startroom", 1);
	 set("outdoors", "sjsz");
}

void init_room() {
	 add_action("do_attack", "attack");
	 add_action("do_stop", "stop");
	 add_action("do_finish", "finish");
	 add_action("do_kickout", "kickout");
	 add_action("do_disable", "quit");
	 add_action("do_disable", "lian");
	 add_action("do_disable", "practice");
	 add_action("do_disable", "xue");
	 add_action("do_disable", "learn");
}

int do_disable() {
	 tell_object(this_player(), "�㲻��������������\n");
	 return 1;
}

void move_me(object me, string place)
{
	object obj;

	if( !me || !objectp(me) || !userp(me) )return;

	if( !living(me) ) me->revive(0);

	if ( (obj = find_object(place)) && obj && objectp(obj) ) {
		me->move(obj);
	}
	else if ( (obj = load_object(place)) && obj && objectp(obj) ) {
		me->move(obj);
	}
	else return;
}

void full_all(object me) {
	 me->set("eff_jing", (int)me->query("max_jing"));
	 me->set("jing", (int)me->query("max_jing"));
	 me->set("eff_qi", (int)me->query("max_qi"));
	 me->set("qi", (int)me->query("max_qi"));
	 me->set("jingli", (int)me->query("max_jingli"));
	 me->set("neili", (int)me->query("max_neili"));
	 me->set("food", (int)me->max_food_capacity());
	 me->set("water", (int)me->max_water_capacity());
	 me->remove_all_killer();
	 me->clear_condition();
}



void my_destruct(object obj)
{
		  int i;

		  object *inv;
		  string err;

		  if (obj && objectp(obj) ) {
								inv = all_inventory(obj);
								i = sizeof(inv);
								while(i--)
								{
										  if( inv[i] && objectp(inv[i]) && userp(inv[i]) )
										  {
											 call_out("move_me",1+random(4),inv[i],"/d/bwdh/sjsz/kantai_w1.c");
											 if( !living(inv[i]) ) inv[i]->revive(1);
											 full_all(inv[i]);
											 nude(inv[i]);
										  }
										  else
										  {
											if(inv[i] && objectp(inv[i]))
											{
												my_destruct(inv[i]);
											}
										  }
								}
					 if( userp(obj) )
					 {
						 call_out("move_me",1+random(4),obj,"/d/bwdh/sjsz/kantai_w1.c");
						 if( !living(obj) )obj->revive(1);
						 full_all(obj);
						 nude(obj);
					 }
					 else destruct(obj);
		  }
}

void nude(object obj)
{
		  int i;

		  object *inv;
		  if (obj && objectp(obj) ) {
								inv = all_inventory(obj);
								i = sizeof(inv);
								while(i--)
								{
										  if( inv[i] && objectp(inv[i]) && userp(inv[i]) )
										  {
											 call_out("move_me",1+random(4),inv[i],"/d/bwdh/sjsz/kantai_w1.c");
											 if( !living(inv[i]) ) inv[i]->revive(1);
											 full_all(inv[i]);
											 nude(inv[i]);
										  }
										  else
										  {
											if(inv[i] && objectp(inv[i]))
											{
												destruct(inv[i]);
											}
										  }
								}
		  }
}

// clean up all the flags on a player, set back conditions etc.
void finish(object target) {
	object ob, me, corpse;
	object board;
	mapping entryA, entryB;
	int i, scoreA,scoreB;

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return ;
	 }
	 if( !target || !objectp(target) || !userp(target) )return;

	 entryA = board->query("team/" + board->query("east"));
	 entryB = board->query("team/" + board->query("west"));
	 if(!entryA || !entryB )
	 {
		 call_out("move_me",1+random(2),target,__DIR__"square");
		 if (!living(target)) target->revive(0);
		 full_all(target);
		 nude(target);
		 return;
	 }

	 scoreA = entryA["this_score"];
	 scoreB = entryB["this_score"];

	 me = this_player();

	if( objectp(ob = target->query_temp("last_damage_from") ) && userp(ob) &&
		ob->query("sjsz/team_name") != target->query("sjsz/team_name") )
	{
		ob->add("sjsz/exp",target->query("combat_exp")/10000);
		ob->add("sjsz/this_exp",target->query("combat_exp")/10000);
		ob->add("sjsz/bw_score",target->query("combat_exp")/10000);
		ob->add("sjsz/this_score",target->query("combat_exp")/10000);
		if( ob->query("sjsz/white") )scoreA += target->query("combat_exp")/10000;
		else if( ob->query("sjsz/red") )scoreB += target->query("combat_exp")/10000;
	}

	 if ( !target->query("sjsz/entrance") && !target->query("sjsz/fighting") ) {
		  call_out("move_me",1+random(2),target,__DIR__"square");
	 	  full_all(target);
		  nude(target);
		  return;
	 }

	 me->add("sjsz/this_exp",5);
	 me->add("sjsz/exp",5);
	 me->add("sjsz/bw_score",5);
	 me->add("sjsz/this_score",5);

	 if( me->query("sjsz/white") ) scoreA += 5;
	 else if( me->query("sjsz/red") ) scoreB += 5;

	 entryA["this_score"]=scoreA;
	 entryB["this_score"]=scoreB;

	 board->set("team/" + board->query("east"), entryA);
	 board->set("team/" + board->query("west"), entryB);
	 board->save();

	 if( objectp(corpse = CHAR_D->make_corpse(target, ob)) )
	 {
		 corpse->move(environment(me) );
	 }

	 target->set_temp("finished",1);
	 target->remove_all_killer();

	 full_all(target);
     nude(target);

	 if ( target->query("sjsz/white") )
		  move_me(target,__DIR__"east_xiangfang");
	 else if ( target->query("sjsz/red") )
		  move_me(target,__DIR__"west_xiangfang");


	 return;
}

int do_kickout(string arg) {
	 object player = this_player();
	 object room = this_object();
	 object target;

	 if (!wizardp(player))  // only wiz can kickout someone
		  return 0;

	 if (!arg)
		  return notify_fail("��Ҫ��˭���ߣ�\n");

	 target = present(arg, room);
	 if (!target)
		  return notify_fail("����û������ˣ�\n");

	 if (!userp(target))
		  return notify_fail("��ֻ�ܸ�����ҡ�\n");

	 message_vision("$N���Խ�ɽׯ�����߳���\n", target);

	 finish(target);

	 return 1;
}


int do_finish(string arg) {
	 object player=this_player();
	 object room=this_object();
	 object target;

	 if (! arg || arg=="")
		  return notify_fail("��Ҫ���˭��\n");

	 target = present(arg, room);
	 if ( !target || !objectp(target)  )
		  return notify_fail("����û������ˣ�\n");

	 if ( ! userp(target) )
		  return notify_fail("�������Ǹ���ң�\n");

	 if ( arg == player->query("id") ) return notify_fail("�㷢������\n");

	 if( target->query_temp("finished") )return notify_fail("����û������ˣ�\n");

	 if ( target->query("qi")<0 || target->query("eff_qi")<0 ||
		  target->query("jing")<0 || target->query("eff_jing")<0 || 
		  target->query("jingli") < 0 ||
		  !living(target) 
		  ) {
		  message_vision("$N��ݺݵ�һ�Ű�$n�߳����䳡��\n", player, target);
	 }
	 else {
		return notify_fail("�˼һ�û���أ��ȴ�һ�ܰɣ�\n");
	 }
	 

	 finish(target);

	 return 1;
}

int do_attack(string arg)
{
	object here, *obj, me = this_player(),target;
	string victim;
	int i;

	if (!arg) return notify_fail("��Ҫ����˭��\n");

	victim = arg;
	if ( victim == me->query("id") ) return notify_fail("�㷢������\n");
	here = environment(me);

	target = present(victim, here);
	if (!target || !objectp(target) ) return notify_fail("���ﲢ�޴��ˣ�\n");

	if ( target->query("race") != "����" || target->query("sjsz/team_name") == me->query("sjsz/team_name"))
	{
		return notify_fail("�㷢������\n");
	}

	obj = all_inventory(here);

	message_vision(HIR "$N����$n"+HIR"�ȵ���"+RANK_D->query_rude(target)+HIR"�����ղ������������һ�����ǣ����Һݺݵؽ�ѵ$p��\n\n" NOR, me, target);
	me->kill_ob(target);

	if( me->query("sjsz/fighting") )
	{
		for(i=0;i<sizeof(obj);i++)
		{
			if( living(obj[i]) &&
				 obj[i]->query("sjsz/team_name") == me->query("sjsz/team_name") && obj[i] != me
				 && obj[i]->query("env/invisibility") < 1 )
			{
					//message_vision(HIY "ֻ��$NӦ������$n���˹�ȥ���ȵ���"+RANK_D->query_rude(target)+HIY"�������ɣ�\n" NOR, obj[i], target);
					obj[i]->kill_ob(target);
			}
		}
	}

	if( living(target) )
	{
		//message_vision( HIR "\n$N����$n"+HIR"��Цһ�������ж�Ϊʤ�����У�\n\n" NOR, target,me );
		target->kill_ob(me);
	}

	return 1;
}

int do_stop(string arg)
{
	object here, *obj, me = this_player(),target;
	string victim;
	int i;

	here = environment(me);
	obj = all_inventory(here);

	if(arg)
	{
	  victim = arg;

	  if ( victim == me->query("id") ) return notify_fail("�㷢������\n");

	  target = present(victim, here);
	  if( !objectp(target) ) return notify_fail("û������ˡ�\n");

	 if ( target->query("race") != "����" || target->query("sjsz/team_name") != me->query("sjsz/team_name"))
	 {
		return notify_fail("�˼���Ҳ�����㡣\n");
	 }
		message_vision(HIY "$N����$n"+HIY"Ȱ����"+RANK_D->query_respect(target)+HIY"��ס�֣���������һ����\n" NOR, me, target);
		message_vision(HIY "$N���˿�$n"+HIY"��ʹ���˵�����ðɣ������ˣ����ҽ��������Դ������䲱���ϣ�\n" NOR, target, me);
		target->remove_all_killer();

	}
	else
	{
		message_vision(HIY "$N�������ţ���������ס�֣������˼��кλ�˵��\n" NOR, me);

		for(i=0;i<sizeof(obj);i++)
		{
			if( objectp(obj[i]) && living(obj[i]) &&
				 obj[i]->query("sjsz/team_name") == me->query("sjsz/team_name") && obj[i] != me
				 && obj[i]->query("env/invisibility") < 1 )
			{
					message_vision(HIG "ֻ��$NӦ�����һ���������ˡ�\n" NOR, obj[i]);
					obj[i]->remove_all_killer();
			}
		}
	}

	me->remove_all_killer();

	return 1;
}



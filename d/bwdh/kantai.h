//Cracked by Kafei
// /d/bwdh/kantai.h
// ��̨
// by sdong 09/25/98

#include <ansi.h>
inherit ROOM;
#define CANGKU "/d/bwdh/cangku"

int do_practice(string arg);
int do_study(string arg);
string long_desc();
int do_start(string arg);
int do_stop(string arg);
int do_baoming();
int start(string host,string challenger);
void sort_rank(object ob,int i);
int auto_check();
int let(string arg);
void full_all(object me);
int do_abandon();
int update_player(object me);
int do_askback();

void create()
{
	set("short", "��̨");
	set("long", (: long_desc :));
	set("valid_startroom", 0);

	set("no_fight", 1);
	set("no_practice", 1);

	set("exits", ([
		"up" : LEITAI,
		"north" : KANTAI2,
		"out": "/d/bwdh/square",
	]));


	setup();
}

void back_stuff(string id)
{
	object *inv, cangku, *basket;
	int i;
	object player;

	player = find_player(id);
	if(!player)
	{
	  message_vision(NOR"������˵���ף�"+id+"�����ˣ��ã�����ͳͳ�����ˣ��������̲�ס��Ц�˼�����\n");
	  return;
	}


  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
	 cangku = load_object(CANGKU);
	 if (!objectp(cangku)) {
		message_vision("$N����� wiz: cangku not found\n", player);
		return 0;
	 }
  }


  basket = cangku->query("basket/"+player->query("id"));

  if (basket) {
	 for (i=0; i<sizeof(basket); i++) {
		if (objectp(basket[i])) {
		  basket[i]->move(player);
		  message_vision("$N�������������û�һ"+
					 basket[i]->query("unit")+
					 basket[i]->query("name")+"��\n", player);
		}
	 }
	 cangku->delete("basket/"+player->query("id"));
  }
  else message_vision("������˵��$NʲôҲû����������ɱ�����̰��ร�\n", player);

}


void restore_stuff(object player)
{
  object *inv, cangku, *basket;
  string id;
  int i;

	 id = player->query("id");
	 inv = all_inventory(player);
	 for (i=0; i<sizeof(inv); i++) {
		//if ( ! inv[i]->query_autoload())
		if ( inv[i]->query("id")!="yu di" )
		{
			  message_vision(NOR"�������ջ�$N����̨ȡ��"+inv[i]->query("name")+"��\n", player);
			  destruct(inv[i]);
		}
	}

	player->delete("bwdh/admitted");
	player->delete("bwdh/fighting");
	call_out("back_stuff",2,id);
	full_all(player);
	update_player(player);
}

void init()
{
  object player = this_player();

	  if ( objectp(player) && player->query("bwdh/fighting") ) {
//		full_all(player);
		call_out("restore_stuff",1,player);
	 }
		  add_action("do_practice",  "practice");
		  add_action("do_practice",  "lian");
		  add_action("do_study",  "study");
		  add_action("do_study",  "du");
		  add_action("do_baoming", "����");
		  add_action("do_baoming", "baoming");
		  add_action("do_start", "start");
		  add_action("do_stop", "stop");
//		  add_action("do_abandon", "abandon");
		  add_action("do_bet", "bet");
		  add_action("do_askback","askback");
}

int do_askback()
{
	object me = this_player();
	back_stuff(me->query("id"));
	return 1;
}


int do_practice(string arg)
{
		  object me = this_player();
		  tell_object(me, "���ﲻ׼����!\n");
		  return 1;
}

int do_study(string arg)
{
	object me = this_player();
	tell_object(me, "���ﲻ׼����!\n");
		  return 1;
}

int do_abandon()
{
	object me = this_player();
	tell_object(me, "����������ɼ�������!\n");
	me->delete("bwdh");
	sort_rank(me, 0);
		  return 1;
}


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;

  	desc  = HIY"

		           /I______________I\\               "+HIC"|"+HIR"=====|"+HIY"
		         //||||||||||||||||||\\\\             "+HIC"|"+HIR" ��   |"+HIY"
		     T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T         "+HIC"|"+HIR"=====|"+HIY"
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIR"��������̨��"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIC"|"+HIY"
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"|"+HIY"
			/||||||||||||||||||||||\\            "+HIC"|"+HIY"
		    T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T        "+HIC"|"+HIY"
	            ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^        "+HIC"|"+HIG"
			||                    ||            "+HIC"|"+HIW"
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIG"
             ||                                          ||
             ||  ________       �� �� ��       ________  ||
             ||  |                                    |  ||\n";

		

	if(query("age"))
	{
		desc += "     	     ||  |          "+query("age")+"��������������        |  ||\n";
		desc += "     	     ||  |                                    |  ||\n";
	}

	nRank = this_object()->query("nRank");
	for ( i=1;i<=nRank && i <= 10;i++)
	{
		desc += "             ||  | ";
		desc += i + ". ";

		temp = this_object()->query("rank/"+i+"/name") + "("; 
		temp += this_object()->query("rank/"+i+"/id") + ") "; 
		temp += "ʤ��"+this_object()->query("rank/"+i+"/win") + " "; 
		temp += "����"+this_object()->query("rank/"+i+"/loss");
		
		desc += temp; 
		for(j=strlen(temp);j<=31;j++)
		{
			if(i==10 &&j==31)break;
			desc += " ";
		}

		desc += "|  ||\n"; 
	}

	for(i=i;i<=12;i++)
	{
		desc += "     	     ||  |                                    |  ||\n";
	}
  
	desc+="             ||  |____________________________________|  ||\n";
  	return desc;
}


int valid_leave(object me, string dir)
{
	if( dir=="up" ) {
		if(  wizardp(me)  || me->query("judge") ) return 1;
		else return notify_fail("�㲻���Լ���ȥ��\n");
	}

	if( dir=="out" ) {
		if( wizardp(me) || me->query("judge") || me->query("bwdh/defeated") >= 16 || !me->query("bwdh") || !query("start") ) return 1;
		else
		{
			return notify_fail("����ѡ��,���ڲ����뿪������������(abandon)�����ˡ�\n");
		}
	}

	return ::valid_leave(me, dir);

}

void sort_rank(object ob, int n)
{
	int nRank = query("nRank");
	int i;
	string id = ob->query("id");

	if(n>0)
	{

		for(i=nRank;i>=1;i--)
		{
			if(query("rank/"+i+"/id")==id)break;
		}
		if( i<1 )
		{
			nRank ++;
			set( "nRank",nRank );
			set( "rank/"+nRank+"/name",ob->query("name") );
			set( "rank/"+nRank+"/id",ob->query("id") );
			set( "rank/"+nRank+"/win",ob->query("bwdh/win") );
			set( "rank/"+nRank+"/loss",ob->query("bwdh/defeated") );
			i=nRank;
		}

		for(i=i;i>=1;i--)
		{
			if( i>1 && query("rank/"+(i-1)+"/win") < ob->query("bwdh/win") )
			{
				set( "rank/"+i+"/name",query("rank/"+(i-1)+"/name") );
				set( "rank/"+i+"/id",query("rank/"+(i-1)+"/id") );
				set( "rank/"+i+"/win",query("rank/"+(i-1)+"/win") );
				set( "rank/"+i+"/loss",query("rank/"+(i-1)+"/loss") );

				set( "rank/"+(i-1)+"/name",ob->query("name") );
				set( "rank/"+(i-1)+"/id",ob->query("id") );
				set( "rank/"+(i-1)+"/win",ob->query("bwdh/win") );
				set( "rank/"+(i-1)+"/loss",ob->query("bwdh/defeated") );
			}
			else
			{
				set( "rank/"+i+"/name",ob->query("name") );
				set( "rank/"+i+"/id",ob->query("id") );
				set( "rank/"+i+"/win",ob->query("bwdh/win") );
				set( "rank/"+i+"/loss",ob->query("bwdh/defeated") );
				break;
			}
		}
	}
	else if ( n<0 )
	{
		for(i=nRank;i>=1;i--)
		{
			if(query("rank/"+i+"/id")==id)break;
		}
		if( i<1 )
		{
			nRank ++;
			set( "nRank",nRank );
			set( "rank/"+nRank+"/name",ob->query("name") );
			set( "rank/"+nRank+"/id",ob->query("id") );
			set( "rank/"+nRank+"/win",ob->query("bwdh/win") );
			set( "rank/"+nRank+"/loss",ob->query("bwdh/defeated") );
			return;
		}
		set( "rank/"+i+"/name",ob->query("name") );
		set( "rank/"+i+"/id",ob->query("id") );
		set( "rank/"+i+"/win",ob->query("bwdh/win") );
		set( "rank/"+i+"/loss",ob->query("bwdh/defeated") );
	}
	else // just move this guy to the end
	{
		for(i=1;i<=nRank;i++)
		{
			if(query("rank/"+i+"/id")==id)break;
		}
		if( i>nRank )
		{
			nRank ++;
			set( "nRank",nRank );
			set( "rank/"+nRank+"/name",ob->query("name") );
			set( "rank/"+nRank+"/id",ob->query("id") );
			set( "rank/"+nRank+"/win",ob->query("bwdh/win") );
			set( "rank/"+nRank+"/loss",ob->query("bwdh/defeated") );
			return;
		}

		for(i=i;i<nRank;i++)
		{
			set( "rank/"+i+"/name",query("rank/"+(i+1)+"/name") );
			set( "rank/"+i+"/id",query("rank/"+(i+1)+"/id") );
			set( "rank/"+i+"/win",query("rank/"+(i+1)+"/win") );
			set( "rank/"+i+"/loss",query("rank/"+(i+1)+"/loss") );

		}
		
		set( "rank/"+i+"/name",ob->query("name") );
		set( "rank/"+i+"/id",ob->query("id") );
		set( "rank/"+i+"/win",ob->query("bwdh/win") );
		set( "rank/"+i+"/loss",ob->query("bwdh/defeated") );
	}
}

int do_start(string arg)
{
	object me = this_player();
	int age;

	if( !wizardp(me) && !me->query("judge") ) {
					 tell_object(me,"�㲻����ʦ�����ܷ��������ᣡ\n");
					 return 1;
		  }

	if (!arg || sscanf(arg, "%d", age)!=1)
		  {
					 tell_object(me,"usage: start age\n");
					 return 1;
		  }
	if(query("start"))
		{
					 tell_object(me,"�����Ѿ���ʼ�ˣ���Ҫ��ֹ������STOP���\n");
					 return 1;
		}

	this_object()->set("age",age);
	this_object()->set("start",1);
	this_object()->set("nRank",0);
	this_object()->delete("rank",0);
	message_vision("$N���������������̨���ڿ�ʼ"+age+"����������������\n",me);
	remove_call_out("auto_check");
	call_out("auto_check",30);
	return 1;
}

int do_stop(string arg)
{
	object ob1,ob2,me = this_player(),kt,*inv;
	int age,i;
	string host,challenger;

	if( !wizardp(me) && !me->query("judge") ) {
					 tell_object(me,"�㲻����ʦ��������ֹ�����ᣡ\n");
					 return 1;
		  }

	if(!query("start"))
		{
					 tell_object(me,"���仹û��ʼ�ء���Ҫ��ʼ������start age���\n");
					 return 1;
		}

		  age = query("age");
	this_object()->delete("age");

	if( (host = query("host")) )
		ob1=find_player( query("host") );
	if(ob1 && ob1->query("bwdh/fighting") )
	{
		ob1->move(KANTAI);
	}

	if( ( challenger=query("challenger")) )
	{
	  ob2=find_player(challenger);
	  if( ob2 && ob2->query("bwdh/fighting") )
	 {
		ob2->move(KANTAI);
	 }
	}

	delete("start");
	delete("host");
	delete("challenger");
	delete("fighting");
	kt = find_object(KANTAI);

        inv = all_inventory( kt );
        i = sizeof(inv);
        while(i--)
         if( userp(inv[i]) )
          inv[i]->move("/d/city/kedian");
	
	return 1;
}

int do_bet(string arg)
{
	 object me = this_player(), money, obj;
	 string name, unit;
	 int amount;

	 if (!arg || sscanf(arg, "%s %d %s", name, amount,unit)!=3)
	 {
		tell_object(me,"bet <player id> #silver(or gold)\n����: \nbet snowrabb 10 gold\nbet litfish 900 silver\n");
		return 1;
	 }

	 if( query("fighting") )
	 {
		tell_object(me,"�Բ������ڱ��俪ʼ�ˣ���������ע��\n");
		return 1;
	 }

	 if( !query("bet") )
	 {
		tell_object(me,"�Բ������ڲ�����ע��\n");
		return 1;
	 }

	 if( name != query("host") && name != query("challenger") )
	 {
		return notify_fail("�Բ�����ֻ��ѹ��ע�ڱ�����������ϣ�\n");
	 }

	 obj = find_player(name);
	 if(!obj) return notify_fail("�Բ�����ѹ��ע�Ķ��󲻼��ˣ�\n");

	 money = present( unit + "_money", me);

	 if( !money || money->query_amount() < amount )
		return notify_fail("������û����ô��Ǯ ��\n");
	 if( amount*money->query("base_value") < 100 )	return notify_fail("�ĳ�������ôС�Ķ�ע������ҲҪһ�����ӡ�\n");
	 message_vision( sprintf(HIG"$N�ͳ�%s%s%s��������һˤ��˵����Ѻ��$n���ϡ�\n"NOR,
		chinese_number(amount), money->query("base_unit"), money->query("name") ),
		me, obj );
	 money->add_amount(-amount);
	 me->add("bet/"+name, amount*(money->query("base_value")/100) );
	 set("bet_amount/"+name, query("bet_amount/"+name)+amount*(money->query("base_value")/100) );
	 add("bet_amount/sum",	amount*(money->query("base_value")/100) );
	 return 1;
}


int do_baoming()
{
	string msg, name;
	object me;
	string host,challenger,girl;
	int i, age;

	remove_call_out("auto_check");
	call_out("auto_check",0);

	me = this_player();
	age = me->query("age");

	if(this_object()->query("start")!=1)
	{
		tell_object(me,"�Բ�������û�б��������\n");
		return 1;
	}


	if( me->query("age") > this_object()->query("age") )
	{
		tell_object(me,"�����˶���˵�� �Բ��������̨ר�Ž���"+query("age")+"�������������������Ѿ����䣡\n");
		return 1;
	}

	if( (age < 25 && me->query("combat_exp") < ( query("age")-15 ) * 4000 ) ||
		 (age > 24 && me->query("combat_exp") < ( query("age")-15 ) * 8000 )
	 )
	{
		tell_object(me,"�����˶���˵�� �书��ô��㵱���ִ���ǽ�ͷ��Ϸѽ����ȥ�ú����ɣ�\n");
		return 1;
	}

	if ( query("age") >90 && me->query("combat_exp") < 1500000 )
	return notify_fail("�����˶���˵�� �书��ô��㵱���ִ���ǽ�ͷ��Ϸѽ����ȥ�ú����ɣ�\n");

	if( me->query("bwdh/defeated") >= 100  )
	{
		tell_object(me,"�����˶���˵�� ���������˳��İܽ����ؼҺú���ȥ�ɣ�\n");
		//me->set("99over",1);
		return 1;
	}

	if( query("challenger") )
	{
		tell_object(me,"�����˶���˵�� �����������ڱ��䣬�Ȼ���ٱ�����\n");
		return 1;
	}


	if( !(host=query("host")) )
	{
		name = me->query("name")+"("+me->query("id")+")";
		set("host",me->query("id") );
		host = me->query("id");

		message_vision("������˵�� �ã�����$N��������\n", me);
		delete_temp("no_challenger");
		delete( "challenger" );
		me->set("bwdh/fighting",1);
		let(me->query("id") + " play " + me->query("id"));
		remove_call_out("auto_check");
		call_out("auto_check",10);
		return 1;
	}

	if( me->query("bwdh/"+host+"/time") >= 3)
	 return notify_fail("�����Ѿ����������ˣ�\n");

	name = me->query("name")+"("+me->query("id")+")";
	set("challenger",me->query("id") );
	challenger = me->query("id");

	delete_temp("no_challenger");

	remove_call_out("start");
	call_out("start",60,host,challenger);

	message_vision("������˵�� �ã�$N׼��μӱ�����\n", me);
	me->set("bwdh/fighting",1);
	set( "bet",1); // now can bet
	delete("bet_amount"); // clear last record

	let(me->query("id") + " play " + me->query("id"));

	remove_call_out("auto_check");
	call_out("auto_check",1);

	return 1;
}

int start(string host,string challenger)
{
	object ob1,ob2;
	ob1=find_player(host);
	ob2=find_player(challenger);


	if( ob1 && ob2 && ob1->query("bwdh/fighting") && ob2->query("bwdh/fighting") )
	{
		message_vision(HIR"һ�����죬$N��$n������ʼ��\n"NOR,ob1,ob2);
		ob1->kill_ob(ob2);
		ob2->kill_ob(ob1);
		ob1->set("bwdh/fighting",1);
		ob2->set("bwdh/fighting",1);
		set("fighting",1);
		delete( "bet" ); // fight start, no bet
	}

	remove_call_out("auto_check");
	call_out("auto_check",20);
}

int update_room (string file, string winner)
{
		  int i, amount, total, win_m,me_m;
		  object obj, *inv, money, me = this_player(), here = find_object(KANTAI);
		  string err;
		 tell_room( LEITAI, HIY"�����˸���˵�����������������Խ��׬��Խ�࣡\n"NOR, this_object());

		 inv = all_inventory( here );
		 i = sizeof(inv);
		 while(i--)
		 {
			 if( userp(inv[i]) )
			 {
				total = query("bet_amount/sum") ;
				total = total ;
				tell_object( inv[i], HIY"�ܹ���"+chinese_number(total)+"������ѹ����\n"NOR);
				win_m =  query( "bet_amount/" + winner ) ;
				tell_object( inv[i], HIY"�ܹ���"+chinese_number(win_m)+"������ѹ����\n"NOR);
				me_m = inv[i]->query( "bet/"+winner );
				if(me_m>0)
					tell_object( inv[i], HIY"���ܹ���"+chinese_number(me_m)+"������ѹ����\n"NOR);

			  if( inv[i]->query( "bet/"+winner ) )
			  {
				amount = me_m  * total / win_m;

				if( amount > 100 )
				{
					seteuid(geteuid());
					money = new ("/clone/money/gold");
					money->set_amount(amount/100);
					//tell_object( inv[i], HIY"��׬����"+chinese_number(amount/100)+"������\n"NOR);
					message_vision(HIG"$N׬����"+chinese_number(amount/100)+"������\n"NOR,inv[i]);
				}
				else if( amount > 1 )
				{
					seteuid(geteuid());
					money = new ("/clone/money/silver");
					money->set_amount(amount);
					//tell_object( inv[i], "��׬����"+chinese_number(amount)+"������\n");
					message_vision(HIG"$N׬����"+chinese_number(amount)+"������\n"NOR,inv[i]);
				}
				if(money)
				 money->move(inv[i]);
				inv[i]->delete("bet");
			  }
			  else if( inv[i]->query( "bet" ) )
			  {
					tell_object( inv[i], "�㰵�Թ��Լ����浹ù����ô��ûѹ�ڸ�Ӯ��һ�ߣ�\n");
			  }
			  inv[i]->delete("bet");
			}
		}

	  tell_room( LEITAI, HIW"����С�������������ֿ�Ű���̨ɨ�øɸɾ�����\n"NOR, this_object());
	  if (obj = find_object(file)) {
		if( file_name(obj)==VOID_OB )
		  return notify_fail("�㲻���� VOID_OB �����±��� VOID_OB��\n");
		inv = all_inventory(obj);
		i = sizeof(inv);
		while(i--)
		  if( userp(inv[i]) ) inv[i]->move(VOID_OB, 1);
		  else inv[i] = 0;

		destruct(obj);
	  }

	  if (obj) return notify_fail("�޷�����ɳ�ʽ�롣\n");
	  err = catch( call_other(file, "???") );
	  if (err)
		 printf( "��������\n%s\n", err );
	  else {
		 if( (i=sizeof(inv)) && (obj = find_object(file))) {
			while(i--)
			  if( inv[i] && userp(inv[i]) ) inv[i]->move(obj, 1);
		 }
			 }
}

void move_me(object ob, string target)
{
	if( !ob || !objectp(ob) )return;
   ob->set("bwdh/fighting",1);
	ob->move(target);
}


int auto_check()
{
		  object ob1,ob2;
		  object me,ob;
		  mapping boy;
		  int i, *times;
		  string old_host,old_challenger,host,girl,challenger,name;

		  if( !query("start") )
				return 0;

		  if( !( host=query("host")) )
		  {
			tell_room( this_object(), "�����˸���˵��"+query("age")+"�����±��������ڽ��У��Ͻ�����(baoming)ѽ��\n", this_object());
			delete("fighting");
			delete("challenger");
			delete_temp("no_challenger");
			remove_call_out("auto_check");
			call_out("auto_check",20);
			return 0;
		  }

		  old_host = query("host");
		  old_challenger = query("challenger");

		  ob1=find_player(host);

			if(ob1 && living(ob1) && ob1->query("qi") > 0 && ob1->query("bwdh/fighting") )
				message_vision("�����˸���˵��$N�����ڵ�����.\n", ob1);
			else
			{
				message_vision(HIR"$N����ʧ�ܣ���̧����̨.\n"NOR, ob1);
				ob1->restore();
				ob1->set("bwdh/defeated",1+ob1->query("bwdh/defeated"));
				ob1->delete("bwdh/fighting");
				ob1->set("bwdh/"+old_challenger+"/time",ob1->query("bwdh/"+old_challenger+"/time")+1 );
				ob1->set("bwdh/"+old_challenger+"/lose",ob1->query("bwdh/"+old_challenger+"/lose")+1 );
				sort_rank(ob1,-1);
				delete("fighting");
				full_all(ob1);
				ob1->save();
				//ob1->move(KANTAI); // move out will restore data
				call_out("move_me",1,ob1,KANTAI);

				delete("host");
				delete_temp("no_challenger");
				call_out("update_room",1,LEITAI,query("challenger") );
				//update_room( LEITAI,query("challenger") );
			}

	  if( ( challenger=query("challenger") ) )
		{
				  ob2=find_player(challenger);
				  if( ob2)
				  {
					 if( !( host=query("host")) )
					  if( living(ob2) && !ob2->is_ghost() && ob2->query("qi") > 0 )
					 {
						ob2->restore();
						ob2->set("bwdh/win",1+ob2->query("bwdh/win") );
						ob2->set("bwdh/"+old_host+"/time",ob2->query("bwdh/"+old_host+"/time")+1 );
						ob2->set("bwdh/"+old_host+"/win",ob2->query("bwdh/"+old_host+"/win")+1 );
						ob2->set("bwdh/once",1);
						ob2->set("bwdh/fighting",1);
						set("host",challenger);
						delete("challenger");
						delete_temp("no_challenger");
						host = challenger;

						sort_rank(ob2,1);
						message_vision(HIG"�����˸���˵��$N�ո�һ���$n������̨�������ڵ�����. ��λ�ú�����ŮӢ�����־���ѽ��\n"NOR, ob2,ob1);
						//update_player(ob2);
						full_all(ob2);
						call_out("update_player",1,ob2);
						ob2 = find_player(host);
						if(ob2)
						{
						 tell_object(ob2,"�������ñ�����\n");
						}

						set("fighting",0); // challenger win, host exchange, so no fighting
						remove_call_out("auto_check");
						call_out("auto_check",1);
						return 1;
					 }

					  if( !( living(ob2) ) || ob2->query("qi")<=0 )
					  {
						message_vision(HIR"$N��ս$nʧ�ܣ���̧����̨.\n\n"NOR, ob2,ob1);
						ob2->restore();
						ob2->set("bwdh/defeated",1+ob2->query("bwdh/defeated"));
						ob2->set("bwdh/"+old_host+"/time",ob2->query("bwdh/"+old_host+"/time")+1 );
						ob2->set("bwdh/"+old_host+"/lose",ob2->query("bwdh/"+old_host+"/lose")+1 );
						ob2->delete("bwdh/fighting");
						sort_rank(ob2,-1);
						full_all(ob2);
						ob2->save();
						//ob2->move(KANTAI);
						call_out("move_me",2,ob2,KANTAI);
						delete("challenger");
						delete_temp("no_challenger");
						//update_room(LEITAI, query("host") );
						call_out("update_room",1,LEITAI, query("host") );

						set("fighting",0);

						 if( ( host=query("host") ) && userp(ob1) && living(ob1) && !ob1->is_ghost() ) //host win twice, out to rest
						 {
							ob1->restore();
							ob1->set("bwdh/win",1+ob1->query("bwdh/win") );
							ob1->set("bwdh/"+old_challenger+"/time",ob1->query("bwdh/"+old_challenger+"/time")+1 );
							ob1->set("bwdh/"+old_challenger+"/win",ob1->query("bwdh/"+old_challenger+"/win")+1 );
							ob1->set("bwdh/fighting",1);
							sort_rank(ob1,1);
							message_vision("�����˸���˵�� $N���$n�����޳ɹ���\n", ob1,ob2);
							if( ob1->query("bwdh/once") )
							{
								message_vision("�����˸���˵�� $N�������£���Ȼ��ʤ���������³���Ϣһ�ᣡ\n", ob1);
								delete("host");
								delete_temp("no_challenger");
								message_vision(HIM"$N��ʷ����������̨��Ϣȥ��.\n"NOR, ob1);
								ob1->delete("bwdh/once");
								set("fighting",0);
								full_all(ob1);
								ob1->save();
								//ob1->move(KANTAI);
								call_out("move_me",2,ob1,KANTAI);
							}
							else
							{
							 ob1->set("bwdh/once",1);
							 //update_player(ob1);
							 full_all(ob1);
							 call_out("update_player",1,ob1);
							 ob1 = find_player(host);
							 if(ob1)
							 {
								tell_object(ob1,"�������ñ�����\n");
							 }
							}
						 }

						 remove_call_out("auto_check"); // challenger defeated
						 call_out("auto_check",1);
						 return 1;
					  }

					 // now both host and challenger on LEITAI, fighting ?
					 if( !query("fighting") && query("bet") )
					 {
						message_vision(HIY"�����˸���˵��$N��$n�����Ҫ��ʼ�ˣ��Ͻ���עѽ����עѽ����ע(bet id #gold)Խ�࣬Ӯ��Խ�ࡣ\n"NOR, ob1,ob2);
						message_vision(HIY"�����˸���˵��$N��$n�Ķ�ע�������ǣ� "+(query("bet_amount/" + host ))+"��"+(query("bet_amount/" + challenger ))+"��\n"NOR, ob1,ob2);
					 }

					 remove_call_out("auto_check");
					 call_out("auto_check",20);
					 return 0;

				 }
				 else
				 {
					 // if this challenger not online, count as defeated, this should not happen indeed

					 ob2 = new(USER_OB);
					 ob2->set("id", challenger);
					 if( !ob2->restore() )
					{
						destruct(ob2);
						// no this ppl, suicided ?
						return 0;
					 }

					delete("challenger");
					ob2->restore();
					ob2->set("bwdh/defeated",1+ob2->query("bwdh/defeated") );
					ob2->delete("bwdh/fighting");
					sort_rank(ob2,-1);
					set("fighting",0);
					message_vision("�����˸���˵�� $N��Ȼ��ս���ӣ�����ܼơ�\n", ob2);
					update_room(LEITAI,query("host"));
					ob2->save();
					destruct(ob2);

						 // count host win once
						 if( ( host=query("host") ) && userp(ob1) && living(ob1) && !ob1->is_ghost() ) //host win twice, out to rest
						  {
							ob1->restore();
							ob1->set("bwdh/win",1+ob1->query("bwdh/win") );
							ob1->set("bwdh/fighting",1);
							sort_rank(ob1,1);
							if( ob1->query("bwdh/once") )
							{
								message_vision("�����˸���˵�� $N�������£���Ȼ��ʤ���������³���Ϣһ�ᣡ\n", ob1);
								delete("host");
								message_vision("$N��ʷ����������̨��Ϣȥ��.\n", ob1);
								ob1->delete("bwdh/once");
											 full_all(ob1);
								ob1->save();
								ob1->move(KANTAI);
							}
							else
							{
							 ob1->set("bwdh/once",1);
							 update_player(ob1);
							 full_all(ob1);
							}
						  }

					set("fighting",0); // no fighting
					remove_call_out("auto_check");
					call_out("auto_check",1);
					return 0;
				}
		}
		else // no challenger, no fight
		{
			set("fighting",0);
		}


		  if( query("fighting") )
		  {
			  remove_call_out("auto_check");
			  call_out("auto_check",10);
			  return 0;
		  }


	if( !( host=query("host") ) )
	{
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return 1;
	}

	// nobody come challenge

	set_temp("no_challenger",query_temp("no_challenger")+1);
	if( query_temp("no_challenger") >= 3 && ( host=query("host") ) && userp(ob1) && living(ob1) && !ob1->is_ghost() )
	{
		delete_temp("no_challenger");
		delete("host");
		message_vision(HIM"\n�����˸���˵�� $N��������˷�����Ȼ���˸��ϳ���ս���ⳡ��Ӯ��.\n"NOR, ob1);
		message_vision(HIM"$N��ʷ����������̨��Ϣȥ��.\n"NOR, ob1);

		 // count host win once
		ob1->restore();
		ob1->set("bwdh/win",1+ob1->query("bwdh/win") );
		//ob1->set("bwdh/"+challenger,ob1->query("bwdh/"+challenger)+1 );
		//ob1->set("bwdh/"+challenger+"/win",ob1->query("bwdh/"+challenger+"/win")+1 );
		ob1->delete("bwdh/fighting");
		sort_rank(ob1,1);
		ob1->save();
		//ob1->move(KANTAI);
		call_out("move_me",1,ob1,KANTAI);
		remove_call_out("auto_check");
		call_out("auto_check",30);
		return 1;
	}

	if( query_temp("no_challenger") >= 2 )
	  {
		message_vision(HIY"�����˸���˵������ٹ�һ�����û���˸�������ս�Ļ�������$NӮ��.\n"NOR, ob1);
		remove_call_out("auto_check");
		call_out("auto_check",60);
		return 1;
	  }

	message_vision(HIW"�����˸���˵��$N�ո�Ⱥ�ۣ������ڵ���������λ����������սѽ��\n", ob1);

	remove_call_out("auto_check");
	call_out("auto_check",30);

	return 1;
}



int let(string arg)
{
  object ob;
  string pl1, pl2;
  object room = this_object();
  object *inv;
  object *old_basket, *basket;
  object cangku;
  int i;

	if(!arg) return 0;
	if(sscanf(arg, "%s play %s", pl1, pl2) != 2) {
		pl1 = arg;
		pl2 = arg;
	}

	ob = find_player(pl1);
	if(!ob)return 0;
	ob->set("bwdh/fighting",1);
	ob->save();

	inv = all_inventory(ob);
	basket = allocate(sizeof(inv));

	cangku = find_object(CANGKU);
	if (! objectp(cangku)) {
			cangku = load_object(CANGKU);
			if (!objectp(cangku)) {
					message_vision("$N����� wiz: cangku not found\n", ob);
					return 0;
			}
	}


	for (i=0; i<sizeof(inv); i++) {
			//if ( !inv[i]->query_autoload() && inv[i]->query("id")!="bu dai" )
		 if ( inv[i]->query("id")!="yu di" )
		{ // leave yudi etc.
				basket[i] = inv[i];
				inv[i]->move(cangku);
				message_vision("$N��һ"+
				  inv[i]->query("unit")+
				  inv[i]->query("name")+"���������ˡ�\n", ob);
		}else{
					basket[i] = 0;
		}
	  }

	old_basket=cangku->query("basket/"+ob->query("id"));

	if (arrayp(old_basket)) basket = basket + old_basket;
	cangku->set("basket/"+ ob->query("id"), basket);

	message_vision("$N������̨��\n", ob);

	ob->move(LEITAI);
	full_all(ob);

	message_vision("$N������̨��\n", ob);
	tell_object(ob, "�����˸�����" + RANK_D->query_respect(ob)+
								"�������������ȡ����(look jia; get armor from jia and get weapon from jia).\n");
	delete_temp("no_challenger");
	ob->set("bwdh/fighting",1);
	update_player(ob);
	return 1;
}



int update_player(object me)
{
		  object env, link_ob, obj;

		  env = environment(me);

		  // Save the data and exec the player to his/her link object.
		  me->save();

		  // First, create the new body.
		  link_ob = me->query_temp("link_ob");
		  obj = LOGIN_D->make_body(link_ob);
		  if (!obj) return 0;

		  exec(link_ob, me);
		  destruct(me);

		  // Restore new body and exec to it via enter_world in LOGIN_D
		  obj->restore();
		  LOGIN_D->enter_world(link_ob, obj, 1);

		  obj->move(env);

		  return 1;
}

void full_all(object me)
{
	  if( !living(me) )
	  {
		message_vision(HIW"�����������������ָ��$N������Ѩ��һ��һ����ԭ�����о��ǽ�����ʧ���Ѿõ�һָ���룬��˵��������������\n", me);
		me->revive(0);
	  }

	  message_vision(HIG"����������������ͻȻһ�ư���$N��ͷ���ٻ�Ѩ�ϣ�������ԴԴ���ϵĹ����ȥ��Ƭ��֮�䣬\n"+
		"$P�;���ȫ������޲��泩������������棬���о��ǽ�����˵�е����ƴ�������˵ʧ���Ѿá�\n\n", me);
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



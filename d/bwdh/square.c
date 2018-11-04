//Cracked by Kafei
// /d/bwdh/square.c
// ��̨
// by sdong 09/25/98
#include <localtime.h>
#include <ansi.h>
inherit ROOM;

string long_desc();
int do_start(string arg);
int do_stop(string arg);
int start(string host,string challenger);
int do_close_men();
int do_open_men(string arg);


void create()
{
    mixed *local;
    object *ob;
    local = localtime(time());

	set("short", HIR"���ִ���㳡"NOR);
	set("long", (: long_desc :));
	set("valid_startroom", 1);

	set("no_fight", 1);
	set("no_practice", 1);


    if( local[LT_HOUR] == 2 || local[LT_HOUR] == 4 || 
		local[LT_HOUR] == 6 || local[LT_HOUR] == 8 || 
		local[LT_HOUR] >= 10 && local[LT_HOUR] <= 12 
		)
	{
  		set("exits", ([
		"1" : "/d/bwdh/kantai1",
		"2" : "/d/bwdh/kantai2",
		"3" : "/d/bwdh/kantai3",
		"4" : "/d/bwdh/kantai4",
		"5" : "/d/bwdh/kantai5",
		"6" : "/d/bwdh/kantai6",
		"7" : "/d/bwdh/kantai7",
		"8" : "/d/bwdh/kantai8",
		"out": "/d/city/kedian",
		"northup": "/d/bwdh/sjsz/gate",
                "north": "/d/bwdh/sjsz2/gate",
                "south": "/d/bwdh/sjsz3/gate",

			]));
	}
	else
	{
  		set("exits", ([
		"1" : "/d/bwdh/kantai1",
		"2" : "/d/bwdh/kantai2",
		"3" : "/d/bwdh/kantai3",
		"4" : "/d/bwdh/kantai4",
		"5" : "/d/bwdh/kantai5",
		"6" : "/d/bwdh/kantai6",
		"7" : "/d/bwdh/kantai7",
		"8" : "/d/bwdh/kantai8",
		"out": "/d/city/kedian",
		"northup": "/d/bwdh/sjsz/gate",
                "north": "/d/bwdh/sjsz2/gate",
                "south": "/d/bwdh/sjsz3/gate",
			]));
	}

	setup();
}

void init()
{
	add_action("do_start", "start");
	add_action("do_stop", "stop");
	add_action("do_open_men", "open");	
	add_action("do_close_men", "close");
}

int do_open_men(string arg)
{
	object ob;
	object room;
	if ( !wizardp(this_player()) )
	  return notify_fail("�㲻����ʦ��\n");

	if (query("exits/northup"))
	  return notify_fail("�������Ѿ��Ǵ򿪵ġ�\n");
	if (!arg || (arg != "men" ))
	  return notify_fail("��Ҫ��ʲô��\n");
	set("exits/northup", "/d/bwdh/sjsz/gate");
	message_vision("$N����ָ���һ�㣬֨��һ������һ�����š�\n", this_player());
	return 1;
}

int do_close_men()
{
	if ( !wizardp(this_player()) )
	  return notify_fail("�㲻����ʦ��\n");

	if (!query("exits/northup"))
		return notify_fail("�������Ѿ��ǹ��ϵġ�\n");
	delete("exits/northup");
        delete("exits/north");
        delete("exits/south");


	message_vision("$N����ָ���һ�㣬���������ع����ˡ�\n", this_player());
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
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIR"�����ִ�᡿"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIC"|"+HIY"
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"|"+HIY"
			/||||||||||||||||||||||\\            "+HIC"|"+HIY"
		    T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T        "+HIC"|"+HIY"
	            ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^        "+HIC"|"+HIG"
			||                    ||            "+HIC"|"+HIW"
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIG"
             ||                                          ||
             ||  ________       �� �� ��       ________  ||
             ||  |                                    |  ||
             ||  |                                    |  ||\n";

		

	nRank = 1;
	for ( i=1;i<=8;i++)
	{
		if ( ("/d/bwdh/kantai"+i+".c")->query("age") <= 0 
			|| ! (("/d/bwdh/kantai"+i+".c")->query("rank"))  ) continue;

		temp = ("/d/bwdh/kantai"+i+".c")->query("age") + "����ھ��� ";
		temp += ("/d/bwdh/kantai"+i+".c")->query("rank/1/name") + "(";
		temp += ("/d/bwdh/kantai"+i+".c")->query("rank/1/id") + ") "; 
	
		desc += "             ||  |    ";
		desc += temp; 
		for(j=strlen(temp);j<=31;j++)
		{
			desc += " ";
		}

		desc += "|  ||\n"; 
		nRank ++;
	}

	for(i=nRank;i<=12;i++)
	{
		desc += "     	     ||  |                                    |  ||\n";
	}
  
	desc+="             ||  |____________________________________|  ||\n";
  	return desc;
}


int valid_leave(object me, string dir)
{

	if( dir=="out" ) {
		if( wizardp(me) || me->query("bwdh/defeated") >= 3 || !me->query("bwdh") ) return 1;
		else
		{
			return notify_fail("����ѡ��,���ڲ����뿪��\n");
		}
	}

	return ::valid_leave(me, dir);

}


int do_start(string arg)
{
	object me = this_player();
	int age;

	if (!wizardp(me)) {
			 tell_object(me,"�㲻����ʦ�����ܷ��������ᣡ\n");
			 return 1;
		  }

	if(query("start"))
		{
		   tell_object(me,"�����Ѿ���ʼ�ˣ���Ҫ��ֹ������STOP���\n");
		   return 1;
		}

	this_object()->set("start",1);

	"/d/bwdh/kantai1.c"->do_start("25");
	"/d/bwdh/kantai2.c"->do_start("30");
	"/d/bwdh/kantai3.c"->do_start("35");
	"/d/bwdh/kantai4.c"->do_start("40");
	"/d/bwdh/kantai5.c"->do_start("45");
	"/d/bwdh/kantai6.c"->do_start("55");
	"/d/bwdh/kantai7.c"->do_start("65");
	"/d/bwdh/kantai8.c"->do_start("99");
	"/d/city/kedian.c"->do_open_men("men");
	

	message_vision("$N�������������ڿ�ʼ���������\n",me);
	CHANNEL_D->do_channel(me, "chat*","�������������ִ�����ڿ�ʼ�����������ݿ͵��볡��\n");
	CHANNEL_D->do_channel(me, "xkx","���ִ�����ڿ�ʼ�����������ݿ͵��볡��\n");
	return 1;
}

int do_stop(string arg)
{
	object ob1,ob2,me = this_player();
	int age;
	string host,challenger;

	if (!wizardp(me)) {
					 tell_object(me,"�㲻����ʦ��������ֹ�����ᣡ\n");
					 return 1;
		  }

	if(!query("start"))
		{
					 tell_object(me,"���仹û��ʼ�ء���Ҫ��ʼ������start age���\n");
					 return 1;
		}

	delete("start");

	"/d/bwdh/kantai1.c"->do_stop("25");
	"/d/bwdh/kantai2.c"->do_stop("30");
	"/d/bwdh/kantai3.c"->do_stop("35");
	"/d/bwdh/kantai4.c"->do_stop("40");
	"/d/bwdh/kantai5.c"->do_stop("45");
	"/d/bwdh/kantai6.c"->do_stop("55");
	"/d/bwdh/kantai7.c"->do_stop("65");
	"/d/bwdh/kantai8.c"->do_stop("99");
	"/d/city/kedian.c"->do_close_men("men");
	message_vision("$N��������������������ڽ�����\n",me);
	CHANNEL_D->do_channel(me, "chat*","�������������ִ�����ڽ��������������ݿ͵��˳���\n");
	CHANNEL_D->do_channel(me, "xkx","���ִ�����ڽ��������������ݿ͵��˳���\n");
	return 1;
}


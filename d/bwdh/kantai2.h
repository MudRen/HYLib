//Cracked by Kafei
// /d/bwdh/kantai2.h
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

void create()
{
	set("short", "��̨");
	set("long", (: long_desc :));
	set("valid_startroom", 1);

	set("no_fight", 1);
	set("no_practice", 1);

	set("exits", ([
		"southup" : LEITAI,
		"south" : KANTAI,
	]));


	setup();
}

void init()
{
  object player = this_player();
  object *inv, cangku, *basket;
  int i;

  if ( objectp(player) && player->query("bwdh/fighting") ) {

    player->remove_all_killer();
    player->clear_condition();	
    inv = all_inventory(player);
    for (i=0; i<sizeof(inv); i++) {
    	if (! inv[i]->query_autoload()) 
	{
	        message_vision("$N�Ѵ���̨ȡ��"+inv[i]->query("name")+"���������ˡ�\n", player);
	        destruct(inv[i]);
	}
    }
  
  cangku = find_object(CANGKU);
  if (! objectp(cangku)) {
    cangku = load_object(CANGKU);
    if (!objectp(cangku)) {
      message_vision("$N����� wiz: cangku not found\n", player);
      return 0;
    }
  }

  //player->restore();	
  full_all(player);	

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
  player->delete("bwdh/admitted");
  player->delete("bwdh/fighting");

 }
		  add_action("do_practice",  "practice");
		  add_action("do_practice",  "lian");
		  add_action("do_study",  "study");
		  add_action("do_study",  "du");

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


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;
	object kantai = find_object(KANTAI);

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

	if(kantai)nRank = kantai->query("nRank");
	for ( i=1;i<=nRank && i <= 10;i++)
	{
		desc += "             ||  | ";
		desc += i + ". ";

		temp = kantai->query("rank/"+i+"/name") + "("; 
		temp += kantai->query("rank/"+i+"/id") + ") "; 
		temp += "ʤ��"+kantai->query("rank/"+i+"/win") + " "; 
		temp += "����"+kantai->query("rank/"+i+"/loss");
		
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
	if( dir=="southup" ) {
		if(  wizardp(me)  ) return 1;
		else return notify_fail("�㲻���Լ���ȥ��\n");
	}


	return ::valid_leave(me, dir);

}


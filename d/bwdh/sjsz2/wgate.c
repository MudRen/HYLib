//Cracked by Kafei
// /d/bwdh/sjsz/wgate.c
// �Խ�ɽׯ����
// by sdong 08/8/99

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

string long_desc();
int do_start(string arg);
int do_stop(string arg);
int start(string host,string challenger);
int do_close_men();
int do_open_men(string arg);


void create()
{
	set("short", HIR"�Խ�ɽׯ����"NOR);
	set("long", (: long_desc :));
	set("invalid_startroom", 1);

	//set("no_fight", 1);

	set("exits", ([
		"enter" : "/d/bwdh/sjsz/wgarden",
	]));

	create_room();
	setup();
}

void init()
{
	init_room();
}


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;

  	desc  = HIW"

		           /I______________I\\               
		         //||||||||||||||||||\\\\            
		     T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T       
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIM"[ �Խ�ɽׯ ]"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIY"
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIB"
             ||                   "+HIW"[����]"+HIB"                 ||
             ||                ___________               ||
             ||               @           @              ||
             ||               |           |              ||
             ||               |           |              ||
             ||               |           |              ||
             ||               |           |              ||
             ||               |           |              ||
             ||_______________|___________|______________||\n\n"NOR;

  	return desc;
}



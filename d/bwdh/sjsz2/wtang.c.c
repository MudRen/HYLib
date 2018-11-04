//Cracked by Kafei
// /d/bwdh/kantai.h
// �����̳
// by sdong 09/25/98

#include <ansi.h>
inherit ROOM;
#define BOARD "/clone/board/bwboard"
#include "sjsz_room.h"
string long_desc();
int do_withdraw(string arg);
int do_plant(string arg);

void create()
{
	set("short", HIR"�����̳"NOR);
	set("long", (: long_desc :));

	set("exits", ([
		"west" : "/d/bwdh/sjsz/wting",
		"east" : "/d/bwdh/sjsz/room_01",
	]));

	create_room();
	setup();
}


void init()
{
  init_room();
  add_action("do_withdraw", "ba");
  add_action("do_withdraw", "withdraw");
  add_action("do_plant", "plant");
}


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;

	if( query("flag") >0 )
	  	desc  = HIY"

		           /I______________I\\               "+HIC"|"+HIR"=====|"+HIY"
		         //||||||||||||||||||\\\\             "+HIC"|"+HIR" ��   |"+HIY"
		     T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T         "+HIC"|"+HIR"=====|"+HIY"
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIR"�������̳��"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIC"|"+HIY"
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"|"+HIY"
			/||||||||||||||||||||||\\            "+HIC"|"+HIY"
		    T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T        "+HIC"|"+HIY"
	            ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^        "+HIC"|"+HIG"
			||                    ||            "+HIC"|"+HIW"
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIR"
             ||                                          ||
\n"NOR;
	else
	  	desc  = HIY"

		           /I______________I\\               
		         //||||||||||||||||||\\\\            
		     T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T       
	             ^^^^"+HIG"||"NOR+HIY"^^^"+HIR"�������̳��"NOR+HIY"^^^"+HIG"||"+HIY"^^^^
		         "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"
			/||||||||||||||||||||||\\            
		    T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T
	            ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^
			||                    ||            
	  []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
	  |__________________|_|________|_|__________________|"+HIR"
             ||                                          ||
\n"NOR;

  	return desc;
}

int do_withdraw(string arg) {
    object flag, me=this_player(), *obj;
    string type;
    int i, bGuarded = 0;

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if ( arg != "flag" && arg != "qi") return 0;

	if ( query("flag") <= 0 ) return notify_fail("û��ɰΡ�\n");
	if ( me->query("sjsz/red") > 0 ) return notify_fail("͵�Լ����죿\n");
	
	message_vision(HIY"$N�����Ծ����һ�Ѱ������ӡ�\n"NOR, me);

	obj = all_inventory(environment(me));
	for(i=0;i<sizeof(obj);i++)	 {
			if( living(obj[i]) &&
			obj[i]->query("sjsz/team_name") != me->query("sjsz/team_name") 
			&& obj[i]->query("env/invisibility") < 1
				)
			{
				obj[i]->kill_ob(me);
				message_vision(HIR"$N����$n�ȵ�����$n����͵�죬���У���\n"NOR, obj[i],me,me);
				me->kill_ob(obj[i]);
				bGuarded = 1;
			}
	 }

	 if( !bGuarded )
	 {
	    flag = new("/d/bwdh/sjsz/obj/flag");
	    flag->set_name(query("team_name")+"����", ({ "flag" }) );
	    if(flag->move(me)) {
        	message_vision(HIG"$Nһ�ѳ����˴��죬�߸߾���\n"NOR, me);
		set("flag",0);
	    } else {
        	destruct(flag);
	    }
	   CHANNEL_D->do_channel(this_object(), "rumor",
		"��˵"+me->name()+"������"+query("team_name")+"�Ĵ��죡" );		

	}
	

    return 1;
}

int do_plant(string arg) {
    object flag, me=this_player(), *obj;
    string type;
    int i, bGuarded = 0;
    object board;
    mapping entryA, entryB;
    int scoreA,scoreB;

	 board =  find_object(BOARD);
	 if (!objectp(board)) {
		  board = load_object(BOARD);
		  if (!objectp(board))
				return notify_fail("�Ҳ����������ɼ��档\n");
	 }
	 entryA = board->query("team/" + board->query("east"));
	 entryB = board->query("team/" + board->query("west"));

	 if(!entryA || !entryB )return notify_fail("����û�б�����\n");

	 scoreA = entryA["this_score"];
	 scoreB = entryB["this_score"];

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if ( arg != "flag" && arg != "qi") return 0;

	if ( query("flag") > 0 ) return notify_fail("������������ˡ�\n");
	if ( !me->query("sjsz/red") ) return notify_fail("��ɲ�����Ĵ�Ӫ��\n");

	flag= present("flag",me );
	if(!flag)return notify_fail("������û����Բ塣\n");

	if( flag->query("name") != query("team_name")+"����"  ) 
		return notify_fail("�Լ��Ĵ�Ӫ��ô�ܲ��˼ҵ��죿\n");

	
	message_vision(HIY"$N�Ѵ��컩����չ������������ˡ�\n"NOR, me);

	destruct(flag);

	set("flag",1);

	CHANNEL_D->do_channel(this_object(), "rumor",
		"��˵"+me->name()+"���������˴�Ӫ��" );		

	me->add("sjsz/flag",1);
	me->add("sjsz/bw_score",1000);
	me->add("sjsz/this_flag",1);
	me->add("sjsz/this_score",1000);
	if( me->query("sjsz/white") )scoreA += 1000;
	else if( me->query("sjsz/red") )scoreB += 1000;
	entryA["this_score"]=scoreA;
 	entryB["this_score"]=scoreB;
	board->set("team/" + board->query("east"),entryA);
	board->set("team/" + board->query("west"),entryB);
	board->save();

    return 1;
}



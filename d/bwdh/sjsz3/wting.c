//Cracked by Kafei
// /d/bwdh/sjsz/wting.c
// �Խ�ͤ
// by sdong 08/8/99

#include <ansi.h>
inherit ROOM;
#include "sjsz_room.h"

string long_desc();
int do_get(string arg);
string look_jia();
int do_withdraw(string arg);
int do_plant(string arg);


void create()
{
	set("short", HIR"�Խ�ͤ"NOR);
	set("long", (: long_desc :));


	set("exits", ([
		"east" : "/d/bwdh/sjsz/wtower2",
	]));

        set("item_desc", ([
                "jia": (: look_jia :),
        ]));
	create_room();

	setup();
}

void init()
{
	init_room();
	add_action("do_get", "get");
	add_action("do_withdraw", "ba");
	add_action("do_withdraw", "withdraw");
	add_action("do_plant", "plant");	
}


string long_desc()
{
  	string desc,temp;
	int nRank,i,j;

	if( !query("flag") )
	  	desc  = HIW"
	           /I____________I\\               
	         //||||||||||||||||\\\\            
	     T\\//IIIIIIIIIIIIIIIIIIII\\\\/T       
	    ^^^^"+HIG"||"NOR+HIY"^^^"+HIM"[ �Խ�ͤ ]"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIY"
                "+HIG"||"NOR+HIY"________________"+HIG"||"NOR+HIY"             "+HIC"
	 []__|[]___[]___||___[]___[]|__[]___[]
	 |_________|_|________|_|____________|"+HIB"
               ||                  ||
               ||                  ||
               ||                  ||
               ||                  ||
               ||                  ||
               ||__________________||\n
	       "+HIC"��ǰ������һ�ű�����(jia)\n"NOR;
	else		
  		desc  = HIW"
	           /I____________I\\         "+HIR"��"+HIW"
	         //||||||||||||||||\\\\       "+HIY"||"+HIW"~~~~~~~~/
	     T\\//IIIIIIIIIIIIIIIIIIII\\\\/T   "+HIY"||   ��   "+HIW"{
	    ^^^^"+HIG"||"NOR+HIY"^^^"+HIM"[ �Խ�ͤ ]"NOR+HIY"^^^"+HIG"||"+HIY"^^^^    "+HIY"||         "+HIW"\\"+HIY"
                "+HIG"||"NOR+HIY"________________"+HIG"||"NOR+HIY"        ||"+HIW"~~~~~~~~~~~"+HIC"
	 []__|[]___[]___||___[]___[]|__[]___[]
	 |_________|_|________|_|____________|"+HIB"
               ||                  ||
               ||                  ||
               ||                  ||
               ||                  ||
               ||                  ||
               ||__________________||\n
	       "+HIC"��ǰ������һ�ű�����(jia)\n"NOR;

  	return desc;
}


int do_get(string arg) {
    object weapon, me=this_player(), *temp, env;
    string type;
    int i;

    if(!arg) return 0;
    if(me->is_busy()) return 0;
    if (sscanf(arg, "%s from jia", type) != 1) return 0;

    switch (type) {
    case "sword":   if(this_player()->query("gender") == "����")
                        weapon = new("/clone/test/xiuhua");
                    else
                        weapon = new("/clone/weapon/gangjian");
                    break;
    case "blade":   weapon = new("/clone/weapon/gangdao");
                    break;
    case "xiao" :   weapon = new("/d/taohua/obj/tiexiao");
                    break;
    case "stick":   weapon = new("/clone/weapon/gangbang");
                    break;
    case "staff":   weapon = new("/clone/weapon/shezhang");
                    break;
    case "falun":   weapon = new("clone/weapon/falun");
                    break;
    case "whip" :   weapon = new("/clone/weapon/changbian");
                    break;
    case "club" :   weapon = new("/clone/weapon/panguanbi");
                    break;
    case "armor":   weapon = new("/clone/armor/tiejia");
                    break;
    case "stone":   weapon = new("/d/city/obj/stone");
                    break;
    case "xiang":   weapon = new("/d/foshan/obj/tihu-xiang");
                    break;
    case "lubo" :   weapon = new("/d/xueshan/obj/lubo");
                    break;
    case "lian" :   weapon = new("/d/xueshan/obj/rtlian");
                    break;
    case "guan" :   weapon = new("/d/xueshan/obj/klguan");
                    break;
    case "bagua" :   weapon = new("/d/taohua/obj/bagua");
                    break;
    case "walkie-talkie" : 
                    temp = all_inventory(me);
                    for (i = 0; i < sizeof(temp); i++) {
                        if (temp[i]->query("id") == "walkie-talkie") {
                            write("���Ѿ����˶Խ����ˡ�\n");
                            return 1;
                        }
                    }
                    weapon = new(__DIR__"obj/walkie-talkie");
                    env = environment(me);
                    if ( me->query("sjsz/white") )
                        weapon->set("channel", 1);
                    else if ( me->query("sjsz/red") )
                        weapon->set("channel", 2);
                    break;
    default:        write("�Ҳ���"+type+"��\n");
                    return 1;
    }

    if(weapon->move(me)) {
        message_vision("$N�ӱ�������ȡ��һ"+weapon->query("unit")+weapon->name()+"��\n", me);
    } else {
        destruct(weapon);
    }
    return 1;
}


string look_jia() {
    string msg;
    msg = "
�����õı����н�(sword)����(blade)����(stick)����(staff)����(falun)��
��(whip)����(club)����������(armor)��ʯ��(stone)��������(xiang)��­��
(lubo)����ͷ��(lian)�����ù�(guan)���Խ���(walkie-talkie)����(xiao)��
������(bagua)��\n\n";
    return msg;
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
			if( living(obj[i]) 
			&& obj[i]->query("sjsz/team_name") != me->query("sjsz/team_name")
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
	    flag->set_name(query("flag_name"), ({ "flag" }) );
	    if(flag->move(me)) {
        	message_vision(HIG"$Nһ�ѳ����˴��죬�߸߾���\n"NOR, me);
		set("flag",0);
	    } else {
        	destruct(flag);
	    }
	   CHANNEL_D->do_channel(this_object(), "rumor",
		"��˵"+me->name()+"������"+query("flag_name")+"��" );		

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
	if ( !me->query("sjsz/red") ) return notify_fail("��ɲ�����ĵ��̡�\n");

	flag= present("flag",me );
	if(!flag)return notify_fail("������û����Բ塣\n");

	if( flag->query("name") == query("team_name")+"����"  ) 
		return notify_fail("�Լ��Ķ���Ӧ�ò��ڴ�Ӫ���ǡ�\n");

	
	message_vision(HIY"$N�Ѵ��컩����չ������������ˡ�\n"NOR, me);


	set("flag",1);

	CHANNEL_D->do_channel(this_object(), "rumor",
		"��˵"+me->name()+"��"+flag->query("name")+"�嵽���Խ�ͤ��" );		
	set("flag_name",flag->query("name"));

	destruct(flag);

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


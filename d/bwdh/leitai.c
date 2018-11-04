//Cracked by Kafei
// ��̨

#include <ansi.h>

inherit ROOM;

string look_jia();
int do_giveup();

void create()
{
	set("short",HIG"��̨"NOR);
	set("long", HIY"

		      /I______________I\\               "+HIC"|"+HIR"=====|"+HIY"
		    //||||||||||||||||||\\\\             "+HIC"|"+HIR" ��   |"+HIY"
	        T\\//IIIIIIIIIIIIIIIIIIIIII\\\\/T         "+HIC"|"+HIR"=====|"+HIY"
 		^^^^"+HIG"||"NOR+HIY"^^^"+HIR"��������̨��"NOR+HIY"^^^"+HIG"||"+HIY"^^^^         "+HIC"|"+HIY"
                    "+HIG"||"NOR+HIY"__________________"+HIG"||"NOR+HIY"             "+HIC"|"+HIY"
                   /||||||||||||||||||||||\\            "+HIC"|"+HIY"
               T\\//IIIIIIIIIIIIIIIIIIIIIIII\\\\/T        "+HIC"|"+HIY"
	       ^^^^"+HIG"||"+HIY"^^^^^^^^^^^^^^^^^^^^"+HIG"||"+HIY"^^^^        "+HIC"|"+HIG"
                   ||                    ||            "+HIC"|"+HIG"
	           ||                    ||            "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIG"
		   ||                    ||            "+HIC"|"+HIW"
     []___[]___[]__|[]___[]___||___[]___[]|__[]___[]___[]
     |__________________|_|________|_|__________________|
	       ||                            ||
	       ||                            ||

"+HIC"��ǰ������һ�ű�����(jia)��̨��Χ���˿����ֵ��ˡ�\n"NOR
	);
	set("invalid_startroom", 1);
	set("no_death", 1);


		  set("exits", ([
					 "down":__DIR__"kantai",
		  ]));

	set("item_desc", ([
		"jia": (: look_jia :),
	]));

		  set("objects", ([
					 __DIR__"obj/live" : 1,
		  ]));

		setup();

//	replace_program(ROOM);
}

void init()
{
	object me = this_player();
	if(wizardp(me) || me->query_temp("organizer") ) {
		add_action("do_let", "let");
		add_action("do_kickout", "kickout");
		add_action("do_guo", "guo");
		add_action("do_start", "start");
	}
	add_action("do_get", "get");
	add_action("do_disable", "kill");
	add_action("do_disable", "hit");
	add_action("do_disable", "steal");
	add_action("do_disable", "fight");
	add_action("do_disable", "quit");
	add_action("do_giveup", "giveup");

}

int do_giveup()
{
	object me = this_player();
	message_vision(me->query("family/family_name")+"$N�Զ����䡣\n", me);
	me->quit(me);
	return 1;
}


int do_kickout(string arg)
{
	object ob;
	if(!arg) return 0;
	if(objectp(ob = present(arg, this_object())) ) {
		if(base_name(ob) == "/d/city/npc/fighter") {
			message_vision("$N��$n�߳���̨��\n", this_player(), ob);
			ob->quit(ob);
			return 1;
		}
	}
	return 0;
}

int do_disable(string arg)
{
	tell_object(this_player(), "��������̨��������\n");
	return 1;
}

int do_start(string arg)
{
	object ob1, ob2;
	if(objectp(ob1 = present("fighter dummy 1", this_object()))
	&& objectp(ob2 = present("fighter dummy 2", this_object())) ) {
		message_vision("һ�����죬$N����"+ob1->name()+"��"+ob2->name()+"������ʼ��\n", this_player());
		ob1->kill_ob(ob2);
		ob2->kill_ob(ob1);
		return 1;
	}
	return notify_fail("��û���룡\n");
}

int do_guo(string arg)
{
	object guo = new("/d/quanzhou/obj/renshen-guo");
	guo->move(this_player());
	message_vision("$N���һ�˲ι���\n", this_player());
	return 1;
}

int do_get(string arg)
{
	object weapon, me=this_player();
	string type;
	if(!arg) return 0;
	if(me->is_busy()) return 0;
	if (sscanf(arg, "%s from jia", type) != 1) return 0;
	switch (type) {
	case "sword":	if(this_player()->query("gender") == "����")
				weapon = new("/clone/test/xiuhua");
			else    weapon = new("/clone/weapon/gangjian");
			break;
	case "blade":	weapon = new("/clone/weapon/gangdao");
			break;
	case "stick":	weapon = new("/clone/weapon/gangbang");
			break;
	case "staff":	weapon = new("/clone/weapon/shezhang");
			break;
//	case "falun":	weapon = new("/clone/test/falun");
	case "falun":	weapon = new("clone/weapon/falun");
			break;
	case "whip" :	weapon = new("/clone/weapon/changbian");
			break;
	case "armor":	weapon = new("/clone/armor/tiejia");
			break;
	default:	return notify_fail("�Ҳ���"+type+"\n");
	}
	if(weapon->move(me)) {
		message_vision("$N�ӱ�������ȡ��һ"+weapon->query("unit")+weapon->name()+"��\n", me);
		if (me->is_fighting()) me->start_busy(2);
	} else {
		destruct(weapon);
	}
	return 1;
}


int do_let(string arg)
{
	object ob, dummy;
	string pl1, pl2;

	if(!arg) return 0;
	if(sscanf(arg, "%s play %s", pl1, pl2) != 2) {
		pl1 = arg;
		pl2 = arg;
	}

	if(objectp(present("fighter dummy 2", this_object())) ) {
		return notify_fail("�Ѿ�����λѡ���ˡ�\n");
	}
	
	ob = find_player(pl1);
	if(!ob) return notify_fail("û��"+pl1+"�����ң�\n");
	seteuid(getuid());
	dummy = new("/clone/test/dummy");
	dummy->set("id", pl2);
	if(!dummy->restore()) {
		destruct(dummy);
		return notify_fail("û��"+pl2+"�����ң�\n");
	}
	dummy->set_temp("link_ob", ob);
	ob->set_temp("body_ob", dummy);
	ob->set_temp("netdead", 1);
	message_vision("$N������̨����$n��\n", ob, dummy);
	message_vision("$N��"+ob->name()+"������̨����"+dummy->name()+"��\n", this_player());
	exec(dummy, ob);
	dummy->set_name(dummy->name(1), ({pl2, "fighter dummy"}));
	dummy->setup();
	dummy->move(this_object());

	return 1;
}

string look_jia()
{
	string msg;
	msg = "����һ�������ܣ�ʮ�˰�������Ӧ�о��С�\n";
	msg+= "Ŀǰ����н�(sword)����(blade)����(stick)����(staff)����(falun)��\n��(whip)������һЩ����(armor)��\n";
	msg+= "����ָ�get ���� from jia����ȡ����ֵı�������С�\n";
	return msg;
}


int valid_leave(object me, string dir)
{
	if( !wizardp(me) ) return notify_fail("��׼�\n");
	return ::valid_leave(me, dir);
}

//Cracked by Kafei
// ��̨
// sdong 09/28/98

#include <ansi.h>

inherit ROOM;

int do_disable(string arg);
string look_jia();
int do_kickout(string arg);
int do_get(string arg);

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
					 "down":KANTAI,
					 "northdown":KANTAI2,
		  ]));

	set("item_desc", ([
		"jia": (: look_jia :),
	]));

		  set("objects", ([
					 __DIR__"obj/live" : 1,
		  ]));

		setup();
}

int do_disable(string arg)
{
	tell_object(this_player(), "��������̨��������\n");
	return 1;//notify_fail("����������̨��������\n");;
}


void init()
{
	add_action("do_get", "get");
	add_action("do_disable", "save");
	add_action("do_disable", "kill");
	add_action("do_disable", "hit");
	add_action("do_disable", "steal");
	add_action("do_disable", "fight");
	add_action("do_disable", "sleep");
	add_action("do_disable", "throw");
	add_action("do_disable", "halt");
	add_action("do_disable", "quit");
	add_action("do_kickout", "kickout");

}



int do_kickout(string arg)
{
	object ob,me = this_player();
	string id;
	
	if (!wizardp(me)) {
					 tell_object(me,"�㲻����ʦ�����ܸ��˼���ȥ��\n");
					 return 1;
		  }

	if (!arg || sscanf(arg, "%s", id)!=1)
		  {
					 tell_object(me,"usage: kickout someone\n");
					 return 1;
		  }

	ob = present(arg);
	if( !ob )
		{
					 tell_object(me,"����˲��������\n");
					 return 1;
		 }


	message_vision("$N��$n�߳���̨��\n",me,ob);
	ob->move(KANTAI);

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
	case "xiao":	weapon = new("/d/taohua/obj/tiexiao");
			break;
	case "blade":	weapon = new("/clone/weapon/gangdao");
			break;
	case "stick":	weapon = new("/clone/weapon/gangbang");
			break;
	case "staff":	weapon = new("/clone/weapon/shezhang");
			break;
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


string look_jia()
{
	string msg;
	msg = "����һ�������ܣ�ʮ�˰�������Ӧ�о��С�\n";
	msg+= "Ŀǰ����н�(sword)����(blade)����(stick)����(staff)����(falun)��\n��(whip)����(xiao)������һЩ����(armor)��\n";
	msg+= "����ָ�get ���� from jia����ȡ����ֵı�������С�\n";
	return msg;
}


int valid_leave(object me, string dir)
{
	if( !wizardp(me) ) return notify_fail("��׼�\n");
	return ::valid_leave(me, dir);
}

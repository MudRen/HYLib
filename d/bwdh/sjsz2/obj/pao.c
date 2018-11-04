//Cracked by Kafei
//
// sdong, 3/18/2000

#include <ansi.h>
#include <armor.h>
#include <room.h>
//inherit F_SSERVER;
inherit ITEM;
#define ORIGINAL "/d/bwdh/sjsz/room_28.c"
int explode(object me, object ob);
int do_fire(string arg);
int do_aim(string arg);
string look_room(object me, object env);
int do_load(string arg);

mapping default_dirs = ([
	"north":	"��",
	"south":	"��",
	"east":		"��",
	"west":		"��",
	"northup":	"����",
	"southup":	"�ϱ�",
	"eastup":	"����",
	"westup":	"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":	"����",
	"westdown":	"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
	"up":		"��",
	"down":		"��",
	"out":		"��",
	"enter":	"��",
	"in":		"��",
	"left":		"��",
	"right":	"��",
]);

string day_event(){return NATURE_D->outdoor_room_event();}

void create()
{
        set_name(HIY"��ͭ��"NOR, ({"pao","qingtong pao","bombgun"}));
        set_weight(1500000);
        set("value",150000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", 
"һ����ͭ����Ĵ��ڣ��޴���ڹܰ�Ȼͦ�գ��˵���������档
�����Խ�ɽׯ�����ռ��������ű�����û�뵽�����ڶ��У�ֻ��
��֪���ò����á�\n\n");

                set("unit", "��");
                set("material", "bronze");
        }
        setup();
}

void init()
{
	add_action( "do_load", "load" );
	add_action( "do_aim", "aim" );
	add_action( "do_fire", "shoot" );
}

int do_load(string arg)
{
	object ob = this_object(), huoyao, dantou;
	object me = this_player();
	int exp_time;

	if ( !arg || (arg!="powder" && arg!="huo yao" && arg!="dan tou" ) )
	   return notify_fail( "����Ҫ����ʲô��\n");

	if( me->is_busy() ) return notify_fail("�㻹��æ���أ�\n") ;
	
	if( arg=="powder" || arg =="huo yao" )
	{
		huoyao = present("huo yao");
		if( !huoyao || !objectp(huoyao) )return notify_fail( "����Ҫ����ʲô��\n");

		if( query_temp("yao_loaded") > 2 )return notify_fail("�����Ѿ�װ����ҩ�ˡ�\n");
		
		if( huoyao && objectp(huoyao) && huoyao->query("load") > 0 )
		{
			message_vision("$N����Ͳ�����һЩ��ҩ��\n",me);
			huoyao->set("load",huoyao->query("load")-1 );
			if( huoyao->query("load") <=0 ) destruct(huoyao);
			add_temp("yao_loaded",1);
			me->start_busy(1);
		}
	}
	else if( arg =="dan tou" )
	{
		dantou = present("dan tou");
		if( !dantou || !objectp(dantou) )return notify_fail( "����Ҫ����ʲô��\n");

		if( query_temp("dan_loaded") > 0 )return notify_fail("�����Ѿ�װ�е�ͷ�ˡ�\n");
		
		message_vision("$N����Ͳ�����һö��ͷ��\n",me);
		destruct(dantou);
		add_temp("dan_loaded",1);
		me->start_busy(1);
	}

	return 1;
}



string look_room(object me, object env)
{
		  int i;
		  object *inv;
		  mapping exits;
		  string str, *dirs;

		  if( !env ) {
					 return "������ܻ����ɵ�һƬ��ʲôҲû�С�\n";
		  }
		  str = sprintf( "%s - %s\n    %s%s",
					 env->query("short"),
					 wizardp(me)? file_name(env): "",
					 env->query("long"),
					 env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

		  if( mapp(exits = env->query("exits")) ) {
					 dirs = keys(exits);
					 for(i=0; i<sizeof(dirs); i++)
                        if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
										  dirs[i] = 0;
					 dirs -= ({ 0 });
					 if( sizeof(dirs)==0 )
								str += "    ����û���κ����Եĳ�·��\n";
					 else if( sizeof(dirs)==1 )
								str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
                else
                        str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
                                implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
		  }
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
					 if( inv[i]==me ) continue;
					 if( !me->visible(inv[i]) ) continue;
					 if( objectp(inv[i]->query("rider")) ) continue;
					 else inv[i]->delete("rider");
					 if( objectp(inv[i]->query("rided")) ) {
								str += "  " + inv[i]->short() + "����" +
								(inv[i]->query("rided"))->name() + "��";
					 if( stringp(inv[i]->query_temp("exit_blocked")))
								str += "������"+inv[i]->query_temp("exit_blocked")+
								"ȥ��·";
								str += "\n";
					 }
					 else {
								if (stringp(inv[i]->query_temp("exit_blocked")))
								str += "  " + inv[i]->short() + "������" + inv[i]->query_temp("exit_blocked")
										  +"ȥ��·\n";
								else
								str += "  " + inv[i]->short() + "\n";
								inv[i]->delete("rided");
					 }
		  }

		  return(str);
}


int do_aim(string arg)
{
	object me = this_player();
	object cur_target, target;
	string str, dest;
	mapping exit;

	if( me->is_busy() ) return notify_fail("�㻹��æ���أ�\n") ;

	cur_target = query_temp("target");

	if( !cur_target ){
		cur_target = find_object(ORIGINAL);
		if( !cur_target )cur_target=load_object(ORIGINAL);
		if (!objectp(cur_target))return notify_fail("�Ҳ���Ŀ�ꡣ\n");
	}

	if( arg=="down" || arg=="up" || arg=="out" || arg=="enter" )return notify_fail("�������û���򵽡�\n");
	
	if( arg )
	{
		if( !mapp( exit = cur_target->query("exits") ) || undefinedp(exit[arg]) ) {
			return notify_fail("�������û�г�·��\n");
		}

		if( !cur_target->valid_leave(me, arg) ) notify_fail("�������̫Զ�ˡ�\n");

		dest = exit[arg];

		if( !(target = load_object(dest)) )
			return notify_fail("�޷��ƶ���\n");
	}
	else target = cur_target;

	set_temp("target",target);

	str = look_room(me, target);
	tell_object(me, str+"\n");
	if(arg)
		message_vision(HIW"$N���ڿڻ�����"+ default_dirs[arg] + "ת����׼��"+target->query("short")+"��\n"NOR,me);

	me->start_busy(1);

	return 1;
}

int do_fire(string arg)
{
	object ob = this_object();
	object me = this_player();
	int exp_time;

    if( ob->query_temp("fired") ) return notify_fail("��һ���ŷ��ִ����ѱ���ȼ�ˣ��Ϳ췢���ˣ�\n");
	if( ob->query_temp( "dan_loaded" ) <=0 )return notify_fail("�ڻ�û���ϵ�ͷ�أ�\n");
	if( ob->query_temp( "yao_loaded" ) < 3 )return notify_fail("�ڻ�ûװ��\��ҩ�أ�\n");

	message_vision("$N��������һ����������$n��������\n", me,ob);
	ob->set_temp("fired", 1);
	ob->set_temp("owner",me);
	call_out("explode", 1 + random(5), me, ob);

	return 1;
}

int explode(object me, object ob)
{
	object *victims, env, owner;
	int i,damage;
	string str;

		ob->delete_temp("fired");
		ob->delete_temp("owner");
		ob->delete_temp("dan_loaded");
		ob->delete_temp("yao_loaded");

	env = query_temp("target");
	if( !env ){
		env = find_object(ORIGINAL);
		if( !env )env=load_object(ORIGINAL);
		if (!objectp(env))return notify_fail("�Ҳ���Ŀ�ꡣ\n");
	}

	message_vision(HIY"ֻ����һ�����춯�صı��죬$N"+HIY"�����ˣ���ͷ����һ�����߷���"+env->query("short")+HIY"������һƬ����������\n"NOR, ob);

	owner = query_temp("owner");

	if( !owner || !objectp(owner) )
	{
		if(me && objectp(me) )
			owner=me;
		else owner=ob;
	}

	tell_room(env,HIR"ֻ����һ�����춯�صı��죬һ���ڵ���أ�����һ�����̱�ը�ûҷ�����\n"NOR, me);

	if( env->query("no_fight") ){
		return 0;
	}
	
	victims = all_inventory(env);

	for (i=0; i<sizeof(victims); i++) {
	   	if (!living(victims[i]) || victims[i]==me ) continue;
		damage= 4000+random(8000);
        victims[i]->receive_damage("qi", damage,  owner);
        victims[i]->receive_wound("qi", random(damage), owner);
        str = COMBAT_D->status_msg((int)victims[i]->query("qi") * 100 /(int)victims[i]->query("max_qi"));

		message_vision(HIR"$N��ը����������\n"NOR,victims[i]);
		message_vision(HIR"��ԶԶ����"+victims[i]->query("name")+"��ը����������\n"NOR,ob);
        message_vision("($N"+str+")\n", victims[i]);
		message_vision(HIR"��ԶԶ����("+victims[i]->query("name")+str+")\n",ob);
	}

        if (!env->query("th_buzhen")) return 1;

        env->set("long", env->query("org_desc"));
        env->set("exits", env->query("org_exits"));
        env->set("cost", env->query("org_cost"));
        env->delete("org_desc");
        env->delete("org_cost");
        env->delete("org_exits");
        env->delete("th_buzhen");
        env->delete("th_pozhen");
        env->delete("th_zhen_owner");

	return 1;
}

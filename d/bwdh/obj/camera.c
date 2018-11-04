//Cracked by Kafei
// /d/bwdh/obj/camer.c  ��Ӱʦ
// sdong 09/30/98
#include <room.h>
#include <ansi.h>
inherit NPC;
//inherit ITEM;
int do_broadcast(string arg);
int do_shut(string arg);
int do_query();
void moving();

void create()
{
	object me = this_player();
	set_name("��Ӱʦ", ({ "zhi bo", "camera" }) );
	set("long", "һλ�����ܸɵ���Ӱʦ��\n");
	set_weight(100);
	set("unit", "λ");

	set("max_jingli",10000);
	set("max_jing",10000);
	set("max_neili",10000);
	set("max_qi",100000);
	set("combat_exp",5000000);
	set("env/invisibility", 10);
//	enable_commands();
	setup();
}

init()
{
	object ob = this_player();
	add_action("do_broadcast",  "broadcast");
	add_action("do_shut",  "shut");
	add_action("do_query",  "query");
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



int do_broadcast(string arg)
{
	string dest;
	object me = this_player();
	int i;
	if(!arg) return notify_fail("usage: broadcast room");
	if(sscanf(arg, "%s", dest) != 1) {
		return notify_fail("usage: broadcast room");
	}

	for(i=1;i <= query("destinations/nDest");i++)
	{
		if( query("destinations/"+i) == arg)
			return notify_fail("�Ѿ��ڲ���Ŀ�����ˡ�");;
	}

	set( "destinations/nDest",query("destinations/nDest")+1 );
	set( "destinations/"+i,arg);
	tell_object(me, "�ã�"+arg+"���벥��Ŀ����!\n");
	return 1;
}

int do_shut(string arg)
{
	string dest;
	object me = this_player();
	int i;
	if(!arg) return notify_fail("usage: shut room");
	if(sscanf(arg, "%s", dest) != 1) {
		return notify_fail("usage: shut room");
	}

	for(i=1;i <= query("destinations/nDest");i++)
	{
		if( query("destinations/"+i) == arg)break;
	}
	if(i >query("destinations/nDest") )
			return notify_fail("���ڲ���Ŀ�����ˡ�");;

	for(i=i;i < query("destinations/nDest");i++)
	{
		set( "destinations/"+i,query("destinations/"+(i+1) ) );
	}

	set( "destinations/nDest",query("destinations/nDest")-1 );
	tell_object(me, "�ã����ٲ�����"+arg+"!\n");
	return 1;
}

int do_query()
{
	string dest;
	object me = this_player();
	int i;

	tell_object(me,"���·���Ϊ��������Ŀ�ģ�\n");
	for(i=1;i <= query("destinations/nDest");i++)
	{
		tell_object(me, query("destinations/"+i )+"\n");
	}

	return 1;
}

void moving()
{
	int i;
	string msg;

	msg = "\n"+look_room(this_player(),environment(this_player()));

	for(i=1;i <= query("destinations/nDest");i++)
	{
		tell_room( query("destinations/"+i ), msg+"\n", this_object());
	}
}




void receive_message(string msgclass, string msg)
{
	int i,last = strsrch(msg, '\n', -1);
	string temp;
	string where = environment(this_object())->query("short");
	if(where==0){
		where = this_player()->query("name");
	}


	if(last != -1 )
		msg = msg[0..(last-1)];

	if (msg[0..0] != "\n")msg = GRN"��"+where+"��"NOR + msg;
	else msg = replace_string(msg, "\n", "\n"GRN"��"+where+"��"NOR);

	last = strlen(msg);
	temp = msg[(last-6)..(last-1)];

	if( temp == "�뿪��" || temp == "��ȥ��" ) {
		msg = replace_string(msg, "�뿪��", "��ȥ��");
		remove_call_out("moving");
		call_out("moving",1);
	}

	for(i=1;i <= query("destinations/nDest");i++)
	{
		tell_room( query("destinations/"+i ), msg+"\n", this_object());
	}
}



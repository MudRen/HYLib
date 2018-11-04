// go.c
#include <ansi.h>
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":	"����",
	"south":	"�Ϸ�",
	"east":		"����",
	"west":		"����",
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
	"up":		"����",
	"down":		"����",
	"enter":	"����",
	"out":		"����",
	"leitai":	"��̨����",
]);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string dest, mout, min, dir, blk, gud, skill, face, thing_msg;
string sbuffer,file,path,wild;
	object env, obj, blocker, thing;
	mapping block;
	mixed old_target;
	int result;
	int sen_cost;
	mapping exit;
	object *f_obs, *ob;
//for ̫��
	int i, my_dex, count = 0;

	if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

        if( (int)me->query_encumbrance() > (int)me->query_max_encumbrance() ) 
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

	if( me->over_encumbranced() )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

        if ( me->query_temp("biguan") )
                return notify_fail("�������������ء�\n");

	if (me->query("water") == 0 && me->query("food") == 0 && userp(me))
		    me->add("jing", -(1+random(2)));
	if ( me->query("jing") <= 8 )
		return notify_fail("���Ѿ�û����������·�ˣ���Ϣһ�°ɡ�\n");

	if( me->is_busy() )
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

	env = environment(me);
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]))
		if (5 + random((int)me->query("dex")) <= 
			random((int)f_obs[0]->query("dex"))) {
			me->start_busy(1);
                        message_vision("$N���Ʋ��ã�ת��Ҫ�ߣ���$nһ��������ǰ�����ߣ���û��ô���ף�\n", me, f_obs[0]);
			return notify_fail("������ʧ�ܡ�\n");
		}
    if(environment(me)->query("short")==BLU"ɽ��"NOR
       ||environment(me)->query("short")==WHT"����ʯ��"NOR
       ||environment(me)->query("short")==YEL"�Ҷ�"NOR
       ||environment(me)->query("short")==RED"���Ҷ�"NOR
       ||environment(me)->query("short")==CYN"ʯ��"NOR 
       ||environment(me)->query("magicset")==1
       )
{
if ( random(2)==0)
{
			me->start_busy(2);
                        message_vision("$N���Ʋ��ã�ת��Ҫ�ߣ���$nһ��������ǰ�����ߣ���û��ô���ף�\n", me, f_obs[0]);
			return notify_fail("������ʧ�ܡ�\n");
}
}

if( environment(me)->query("magicroom"))
{
if (random(2)==0)
{
			me->start_busy(2);
                        message_vision("$N���Ʋ��ã�ת��Ҫ�ߣ���$nһ��������ǰ�����ߣ���û��ô���ף�\n", me, f_obs[0]);
			return notify_fail("������ʧ�ܡ�\n");
}
}

if (me->query_condition("huaxunshan") || me->query_condition("shaolin_song")|| me->query_condition("lingjiu_song")
&& userp(me)) {
            message_vision("$N������������������,���ϸ�������\n", me);
			return notify_fail("������ʧ�ܡ�\n");
		}
            if (present("letter", me)||present("biao",me)||present("prize",me)){
            message_vision("$N����������Ҫ��������Ʒ,�������ӣ�\n", me);
			return notify_fail("������ʧ�ܡ�\n");
		}
	}

// ����������
file=base_name(env) + ".c";
if (file)
{
        sbuffer=read_file(file);
} else sbuffer=" ";
if (!userp(me) && sbuffer && !me->query_leader()
)
{                            
// && strsrch(sbuffer, "::valid_leave") >= 0        
// && strsrch(sbuffer, "int") >= 0
        if (strsrch(sbuffer, "move") >= 0
        && strsrch(sbuffer, "����㳡") <= 0)
	return notify_fail("���ROOM���������ã�\n");
        if (strsrch(sbuffer, "destruct") >= 0
        && strsrch(sbuffer, "����㳡") <= 0)
	return notify_fail("���ROOM���������ã�\n");
}

	result = env->valid_leave(me, arg);
	if ( result < 0 ) return 1;
	else if ( !result ) return 0;

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go")
			return notify_fail("�������û�г�·��\n");
		else
			return 0;
	}
/*
	if ( mapp(block = env->query("blocks")) && ( blk = block[arg] ) )
	{
		if ( objectp(blocker = present(blk, env)) &&  living(blocker) )	
		{
			if ( !env->query("block_msg") )
				return notify_fail("���������ƶ���ȴ��"
				+ blocker->name() + "��ס��ȥ· ��\n");	
		return notify_fail( env->query("block_msg") );             
		}
	}

	if ( old_target = me->query_temp("guardfor") )
	{
		if(objectp(old_target))
		{
			if( living(old_target) )
			tell_object(me,"���������"+old_target->name()+"��\n");
			else
        		tell_object(me,"�㲻�����"+old_target->name()+"����ֱ���ˡ�\n");
		}
		else 
		tell_object( me, "�㲻����ס������"+default_dirs[old_target]+"�ķ����뿪�����\n" );
		me->delete_temp("guardfor");
	}
*/
	dest = exit[ arg ];

if (!load_object(dest))
{
log_file("log", MUD_NAME + "�����ļ���" + base_name(environment(me)) +"\n", 1);
log_file("log", MUD_NAME + "����·����" + dest +"\n", 1);
 return notify_fail( sprintf( "�޷��� %s �ƶ���\n", dest ) );
}
	if ( !(obj = find_object(dest)) )
	    	call_other( dest, "???" );
	if ( !(obj = find_object(dest)) )
	    	return notify_fail( sprintf( "�޷��� %s �ƶ���\n", dest ) );
        if (!me) return notify_fail( sprintf( "�޷��� %s �ƶ���\n", dest ) );
	if ( me && me->query_temp("is_riding") &&
	    (arg=="up" || arg=="down" || arg=="leitai" || arg=="enter" || arg=="out"))
		return notify_fail("�������û�����������Ϲ�ȥ��\n");

// �ƶ�ǰ���Ƿ�̫��? ��̨�ϲ�����2��
	if ( arg == "leitai")
	{
                return notify_fail("ֻ��wiz�������������̨��\n");
		ob = all_inventory(obj);
		for(i=0; i<sizeof(ob); i++)
//			if( living(ob[i]) && ob[i] != me )
				count++;
	if (count>2)
		return notify_fail("��̨����̫���ˣ�����ȥ�ұ�ȥ��\n");
/*
	my_dex = (int)me->query_dex();
	if (!wizardp(me) &&
	    (((my_dex < 15) && (count > 6)) ||
	    ((my_dex < 20) && (count > 8)) ||
	    ((my_dex < 30) && (count > 10)) ||
	    ((my_dex < 40) && (count > 12))))
		return notify_fail("ǰ����̫���ˣ�����ô��Ҳ������ȥ��\n");
*/
	}
file=base_name(obj) + ".c";
if (file)
{
        sbuffer=read_file(file);
} else sbuffer=" ";
if (!userp(me) && sbuffer && !me->query_leader()
)
{
        if (strsrch(sbuffer, "move") >= 0
                && strsrch(sbuffer, "����㳡") <= 0)
	return notify_fail("���ROOM���������ã�\n");
        if (strsrch(sbuffer, "destruct") >= 0
                && strsrch(sbuffer, "����㳡") <= 0)
	return notify_fail("���ROOM���������ã�\n");
}

	if( !env->valid_leave(me, arg) ) return 0;
        if (!userp(me) && environment(me)==obj
        && !me->query_leader())
	return notify_fail("NPC����ȥ�Ǹ��ط���\n");
        if (!userp(me) && obj->query("no_npc")&& !me->query_leader()
        )
	return notify_fail("NPC����ȥ�Ǹ��ط���\n");

        if (!userp(me) && arg == "leitai")
	return notify_fail("NPC����ȥ�Ǹ��ط���\n");

        dir = obj->query("short");
        if (!undefinedp(default_dirs[arg]))
                dir = default_dirs[arg] + "��" + dir;

//	if( !undefinedp(default_dirs[arg]) )
//		dir = default_dirs[arg];
//	else
//		dir = arg;

	if( me->is_fighting() ) {
		mout = me->name() + "��" + dir + "��Ķ����ˡ�\n";
		min = me->name() + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
	}
	else
	if( wizardp(me) && me->query("env/invisibility") && (wiz_level(me) >= wiz_level(env)))
	{
		mout = "";
		min = "";
	}
	else
	{
		face="��";
		if (me->query("gender")=="Ů��")
		{
			if (me->query("per") >= 30) face ="���޾���" + face;
			if ((me->query("per") >= 28) && (me->query("per") < 30)) face= "��������" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 28)) face= "��������" + face;
			if ((me->query("per") >= 24) && (me->query("per") < 26)) face= "��ɫ����" + face;
			if ((me->query("per") >= 21) && (me->query("per") < 24)) face= "��Ŀ毺�" + face;
			if (me->query("str") <= 16) face = "ͤͤ����" + face;
			if ((me->query("str") <= 20) && (me->query("str") > 16)) face= "��̬��ӯ"+ face;
			if ((me->query("per")<21) && (me->query("str")>20) || !userp(me)) face = "";
		}
		else
		{
			if (me->query("per") >= 30) face= "�����ٷ��" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 30)) face="Ӣ������" + face;
			if ((me->query("per") >= 22) && (me->query("per") < 26)) face="�Ǳ�����" + face;
			if (me->query("str") >=23) face = "���׳˶" + face;
			if ((me->query("str") >= 20) && (me->query("str") < 23)) face= "�����Բ"+ face;
			if ((me->query("per")<22) && (me->query("str")<20) || !userp(me)) face = "";
		}
	        if (objectp(thing = me->query_temp("armor/cloth")))
			thing_msg = "����" + thing->query("name");
		else
			thing_msg = "ȫ���������";
	        if (objectp(thing = me->query_temp("weapon")))
			thing_msg += "��ִ" + thing->query("name");
		if ( me->query("race") == "Ұ��")
		{
			mout = me->name() + "������" + dir + "һ�ܾ���ʧ�ˡ�\n";
                        min = me->name() + "��" + env->query("short") + "���ش��˳�������������������š�\n";
		}
		else
		{
			if ( me->query_temp("is_riding"))
			{
				mout = me->name()+"����"+me->query_temp("is_riding")+"��" + dir + "���۶�ȥ��\n";
				min = face + me->name() + thing_msg + "��" + env->query("short") + "����"+me->query_temp("is_riding")+"һ·���۶�����\n";
			}
			else
			if ( arg == "leitai")
			{
				mout = me->name()+"˫�����ţ��������Σ�����Ծ����̨��\n";
				min = me->name()+"����̨��һԾ�������ȵ�����̨�ϡ�\n";
			}
			else
			{
				mout = me->name() + "��" + dir + "�뿪��\n";
				min = face + me->name() + thing_msg + "��" + env->query("short") + "���˹�����\n";
			}
		}
	}
	
	message( "vision", mout, environment(me), ({me}) );
	if( me->move(obj) ) {
		me->remove_all_enemy();
		message( "vision", min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "�������һ���������...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : go <����>
 
������ָ���ķ����ƶ���
 
HELP
    );
    return 1;
}



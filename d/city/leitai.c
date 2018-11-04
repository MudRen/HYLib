// Room: /city/leitai.c
// Date: Feb.27 1998 by Java
#include <ansi.h>
inherit ROOM;
string look_shelf();
string do_quit(string arg);
string look_gaoshi();
string look_pai();
string clear_title(string arg);
void add_title(object me,string arg);
void create()
{
	set("short", "��̨");
	set("long", @LONG
����һ�����ɼ�������̨����׳��ʵ��ľ������һƬƽ̨���Ľǵ�֧����
�߹����ĸ�����������Ĺ��ڶ�������ؿ���̨�ϵ�������䡣��̨�����и�
������(shelf) �������ް�������ȫ���������뿴���̰�(pai)
LONG );
        set("outdoors", "city");
	set("item_desc", ([
		"shelf" : (: look_shelf :),
"pai"    : (: look_pai :),
	]));

	set("exits", ([
		"up"        : __DIR__"wudao",
		"eastdown"  : __DIR__"wudao1",
		"westdown"  : __DIR__"wudao2",
		"southdown" : __DIR__"wudao3",
		"northdown" : __DIR__"wudao4",
	]));
	set("objects", ([
                __DIR__"npc/referee": 1,
//                "/u/zmud/gongping": 1,
	]));
        set("no_npc",1);
	set("no_clean_up", 0);
	set("no_openshelf", 1);
	setup();
}
string look_pai()
{
	return 
"\n
"HIR"start                  "HIY"----  ��̨��֮��ҿ�ʼ���䡣
"HIR"allow    <player id>   "HIY"----  �趨��������̨֮��ҡ�
"HIR"deny     <player id>   "HIY"----  ȡ�������̨�ʸ�
"HIR"load     <player id>   "HIY"----  ���������̨��
"HIR"kick     <player id>   "HIY"----  ���������̨��
"HIR"heal     <player id>   "HIY"----  ����̨����ҾŻ���¶�衣
"HIR"life     <player id>   "HIY"----  �ͱ�ɱ��������ûָ���

"HIG"titles  <player id> 01 "HIY"----  ������������µ�һ (15����)��
"HIG"titles  <player id> 02 "HIY"----  ������������µڶ� (15����)��
"HIG"titles  <player id> 11 "HIY"----  ������������µ�һ (20����)��
"HIG"titles  <player id> 12 "HIY"----  ������������µڶ� (20����)��
"HIG"titles  <player id> 21 "HIY"----  ��������µ�һ���� (30����)��
"HIG"titles  <player id> 22 "HIY"----  ��������µڶ����� (30����)��
"HIG"titles  <player id> 31 "HIY"----  ��������µ�һ���� (40����)��
"HIG"titles  <player id> 32 "HIY"----  ��������µڶ����� (40����)��
"HIG"titles  <player id> 41 "HIY"----  ��������µ�һ���� (40����)��
"HIG"titles  <player id> 42 "HIY"----  ��������µڶ����� (40����)��

\n"NOR;
}
string look_shelf()
{
	return 
"\n
һ��������ͷ�ı����ܣ����ᶼ����ò���ˡ�
���ϰ�����: 
                 �ֵ�(blade)    ����(sword)
                 ����(staff)    ����(whip)
                 ����(hammer)   ����(club)
                 ����(throwing) �̱�(dagger)
                 �ּ�(armor)

�μӱ����߿��԰���Ҫ�������ȡ(take)ʹ�á�

                                ��������̨  ����
\n";
}

void init()
{
//	add_action("do_yun","yun");
//	add_action("do_yun","exert");
//	add_action("do_quit","hit");
//	add_action("do_quit","fight");
//	add_action("do_quit","qiecuo");
//	add_action("do_quit","kill");
//	add_action("do_quit","quit");
	add_action("do_quit","exit");
	add_action("do_quit","dazuo");
	add_action("do_quit","exercise");
	add_action("do_quit","learn");
	add_action("do_quit","xue");
	add_action("do_quit","practice");
	add_action("do_quit","lian");
	add_action("do_quit","study");
	add_action("do_quit","du");
	add_action("do_take","take");
	add_action("do_open","open");
	add_action("do_close","close");

	add_action("do_start", "start");
	add_action("do_allow", "allow");
	add_action("do_deny", "deny");
	add_action("do_load", "load");
	add_action("do_kick", "kick");
	add_action("do_heal", "heal");
	add_action("do_life", "life");
	add_action("do_titles", "titles");
	
}
int valid_leave(object me, string dir)
{
        if( dir=="up" && !wizardp(me) && !userp(me))
                return notify_fail("����ϯֻ�б��������ܽ�ȥ��\n");
	me->set_temp("view_leitai",1);
        return ::valid_leave(me, dir);
}
int do_yun(string arg)
{
	if (arg=="roar")
	{
        write(this_player()->query("name")+"��ר�ı���ɣ�\n");
	return 0;
	}
	return 1;
}

int do_open()
{
	if(wizardp(this_player()))
	{
		message_vision("$N�ѱ����������ˡ�\n", this_player());
		this_object()->delete("no_openshelf");
		return 1;
	}
	else return 0;
}
int do_close()
{
	if(wizardp(this_player()))
	{
		message_vision("$N�����������ѱ����ܸ����ˡ�\n", this_player());
		this_object()->set("no_openshelf", 1);
		return 1;
	}
	else return 0;
}
int do_take(string arg)
{
	object obj,ob;
	ob = this_player();
	if(this_object()->query("no_openshelf"))
	{
		message_vision("�Ǵ�����ʱ�򣬱����ܸ���ס�ˡ�\n", ob);
		return 1;
	}
	if( !arg || arg=="" )
	{
		message_vision("$Nվ�ڱ�����ǰ����û���Ҫʲô������\n", ob);
		return 1;
	}
	switch (arg)
	{
		case "sword":
			obj = new("/clone/weapon/changjian");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�ڳ�����\n",ob);
			break;
		case "blade":
			obj = new("/clone/weapon/gangdao");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�ڸֵ���\n",ob);
			break;
		case "staff":
			obj = new("/clone/weapon/gangzhang");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�˸��ȡ�\n",ob);
			break;
		case "whip":
			obj = new("/clone/weapon/changbian");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�����ޡ�\n",ob);
			break;
		case "club":
			obj = new("/clone/weapon/qimeigun");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ����ü����\n",ob);
			break;
		case "hammer":
			obj = new("/clone/weapon/hammer");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ��������\n",ob);
			break;
		case "throwing":
			obj = new("/clone/weapon/lianzi");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�������ӡ�\n",ob);
			break;
		case "dagger":
			obj = new("/clone/weapon/dagger");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ��ذ�ס�\n",ob);
			break;
		case "armor":
			obj = new("/clone/weapon/tiejia");
			obj -> move(ob);
			message_vision("$N�ӱ�������ȡ��һ�����ס�\n",ob);
			break;
		default:
			message_vision("$Nվ�ڱ�����ǰ����û���Ҫʲô������\n", ob);
	}
	return 1;
}

int do_start()
{
        int i,j;
	object *allob, ob, me;
string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

        allob = users();
        me = this_object();
        ob = this_player();
        if (!me) return 1;
        if (!ob) return 1;
        j = 0;
        for ( i=sizeof(allob); i>0; i-- ) {
//             if (environment(allob[i-1])->query("short") =="��̨") {
                if (j == 0) {
                    me = allob[i-1];
                    j = 1;
                }
                else ob = allob[i-1]; 
             }
//        }
        if (ob != this_player()) me->fight_ob(ob);
        return 1;
}
int do_allow(string arg)
{
	object ob, me;
string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: allow <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N�趨��"+ob->name()+"����̨��\n"NOR, me);
	ob -> set_temp("leitai_allow",1);
	ob -> delete("env/combatd");
	tell_object(ob,HIR"\n��������̨�ˡ�\n"NOR);
	return 1;
}
int do_deny(string arg)
{
	object ob, me;
string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	me = this_player();
	if (!arg) return notify_fail("<Syntax>: deny <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N�趨��"+ob->name()+"����ʱ������̨��\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n�Ȳ�������̨�˰ɡ�\n"NOR);
	return 1;
}
int do_load(string arg)
{
	object ob, me;
string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");
	if (!arg) return notify_fail("<Syntax>: loadup <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"����̨��\n"NOR, me);
	message_vision(HIG"$N˫��һ�ţ��ڿն�������������̨���ϣ����ǽ�磬ʮ��������\n"NOR, ob);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n��ʲô��ѽ�㣬�������ɸ��ҡ�\n"NOR);
	ob -> move("/d/city/leitai");
	ob -> delete_temp("view_leitai");
	ob -> delete("env/combatd");
	message_vision(HIG"$N�ڿ�������̨���ϣ����ǽ�磬ʮ��������\n"NOR, ob);
	return 1;
}
int do_kick(string arg)
{
	object ob, me;

	string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");
	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if (!arg) return notify_fail("<Syntax>: kickdown <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"������̨��\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	message_vision(HIG"ֻ����$N໵�һ��������������̨ȥ�ˡ�\n"NOR, ob);
	tell_object(ob,HIR"\nû�湻��������ȥ������ҡ�\n"NOR);
	ob -> move("/d/city/wudao1");
	ob -> set_temp("view_leitai",1);
	message_vision(HIG"ֻ��$N�������У�һ����ƨ�ɶ����ڵ��ϰ���������\n"NOR, ob);
	return 1;
}
int do_heal(string arg)
{
	object ob, me, obj;
	string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if (!arg) return notify_fail("<Syntax>: heal <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"һ���Ż���¶�衣\n"NOR, me);
	obj = new("/clone/misc/jiuhua");
	obj -> move(ob); 
	tell_object(ob,HIR"\n����һ���Ż���¶��ָ�������\n"NOR);
	return 1;
}
int do_life(string arg)
{
	object ob, me;

	string wiz_status;
	me = this_player();
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if (!arg) return notify_fail("<Syntax>: reback <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("û�����Ү��\n");
	message_vision(HIG"$N��"+ob->name()+"�����ûָ���ʧ��\n"NOR, me);
	ob -> delete_temp("leitai_allow");
	tell_object(ob,HIR"\n���������ã�������ͻ�ָ��ġ�\n"NOR);
	ob -> move("/d/death/god2");
	ob -> delete_temp("view_leitai");
	return 1;
}
int do_titles(string arg)
{
	object obj, me=this_player();
	string dest, topic;
	string wiz_status;
	wiz_status = SECURITY_D->get_status(me);
if (!wizardp(me))
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if( wiz_status != "(admin)" && wiz_status != "(arch)"&& wiz_status != "(wizard)" )
		return notify_fail("ֻ�� (wizard) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

	if( !arg || sscanf(arg, "%s %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�ƺţ�\n");
	obj = find_player(dest);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
	switch (topic)
	{
		case "01": add_title(obj, "�������µ�һ"); break;
		case "02": add_title(obj, "�������µڶ�"); break;
		case "11": add_title(obj, "�������µ�һ"); break;
		case "12": add_title(obj, "�������µڶ�"); break;
		case "21": add_title(obj, "���µ�һ����"); break;
		case "22": add_title(obj, "���µڶ�����"); break;
		case "31": add_title(obj, "���µ�һ����"); break;
		case "32": add_title(obj, "���µڶ�����"); break;
		case "41": add_title(obj, "���µ�һ����"); break;
		case "42": add_title(obj, "���µڶ�����"); break;
		default: break;
	}
	message_vision(HIG"$N��"+obj->name()+"��š�\n"NOR, me);
	return 1;
}
void add_title(object me,string arg)
{
        string title;
        title=arg+clear_title(me->query("title"));
        me->set("title",title);
}
string clear_title(string arg)
{
        if( (strsrch(arg, "�������µ�һ") >= 0) ||
            (strsrch(arg, "�������µڶ�") >= 0) ||
            (strsrch(arg, "�������µ�һ") >= 0) ||
            (strsrch(arg, "�������µڶ�") >= 0) ||
            (strsrch(arg, "���µ�һ����") >= 0) ||
            (strsrch(arg, "���µڶ�����") >= 0) ||
            (strsrch(arg, "���µ�һ����") >= 0) ||
            (strsrch(arg, "���µڶ�����") >= 0) ||
            (strsrch(arg, "���µ�һ����") >= 0) ||
            (strsrch(arg, "���µڶ�����") >= 0))
                {
                arg = replace_string(arg, "�������µ�һ","");
                arg = replace_string(arg, "�������µڶ�","");
                arg = replace_string(arg, "�������µ�һ","");
                arg = replace_string(arg, "�������µڶ�","");
                arg = replace_string(arg, "���µ�һ����","");
                arg = replace_string(arg, "���µڶ�����","");
                arg = replace_string(arg, "���µ�һ����","");
                arg = replace_string(arg, "���µڶ�����","");
                arg = replace_string(arg, "���µ�һ����","");
                arg = replace_string(arg, "���µڶ�����","");
        }
        return arg;
}

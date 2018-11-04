// tell.c

#include <ansi.h>
#include <net/dns.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

int help(object me);

	void create() {seteuid(getuid());}

int main(object me, string arg)
{
	string target, msg, mud;
  string criname,result,ia,ib,ic,id;
object obj;
object *ob;
	if( !arg || sscanf(arg, "%s %s", target, msg)!=2 ) return help(me);

//	if( sscanf(target, "%s@%s", target, mud)==2 ) {
//		GTELL->send_gtell(mud, target, me, msg);
//		write("��·ѶϢ���ͳ�������Ҫ�Ժ���ܵõ���Ӧ��\n");
//		return 1;
//	}

	obj = find_player(target);
	if(!obj || !me->visible(obj)) return notify_fail("û�������....��\n");
	if(obj == me) return notify_fail("�����Լ���\n");
	if (!interactive(obj)) return notify_fail("����˶����ˡ�\n");
	if (!living(obj)) return notify_fail("����������޷�������Ļ���\n");
	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("���ڹ���������������Ļ�������\n");

	if (!wizardp(me) && obj->query("env/no_tell")=="all" + NOR)
		return notify_fail("����˲���������������\n");
	if (!wizardp(me) && obj->query("env/no_tell")=="ALL" + NOR)
		return notify_fail("����˲���������������\n");
	if (!wizardp(me) && obj->query("env/no_tell")==me->query("id") + NOR)
		return notify_fail("����˲���������������\n");
	if (!wizardp(me) && obj->query_temp("pigging_seat"))
		return notify_fail("���ڹ���������������Ļ�������\n");
        if ( ((int)time() - (int)me->query("tell_time")) < 1 )
        return notify_fail("�л��ú�˵Ŷ��\n");
if (me->query("combat_exp") < 100000 && strsrch(msg,"0")>=0 || strsrch(msg,"1")>=0 || strsrch(msg,"2")>=0 || strsrch(msg,"3")>=0
|| strsrch(msg,"4")>=0 || strsrch(msg,"5")>=0 || strsrch(msg,"6")>=0 || strsrch(msg,"7")>=0 
|| strsrch(msg,"8")>=0 || strsrch(msg,"9")>=0 )
{
        if( me->query("combat_exp") < 100000 && sscanf( msg, "%s.%s.%s.%s",ia,ib,ic,id) && strlen(ia)>=1  && strlen(ib)>=1
         && strlen(ic)>=1 && strlen(id)>=1 && strlen(msg)>=10
         && !wizardp(me))
        return notify_fail("����治�ðɣ�����û�е��µ���!\n");
}


        write(HIG "�����" + obj->name(1) + "��" + msg + "\n" NOR);
        tell_object(obj, sprintf( HIG "%s�����㣺%s\n" NOR,
		me->name(1)+"("+me->query("id")+")", msg));
                     me->set("tell_time", time());
//	CHANNEL_D->do_channel( this_object(), "adm", 
//		sprintf("%s����%s��%s��",me->name(1),obj->name(1),msg) );
//        ob=users();
        ob = filter_array(children(USER_OB),(: userp($1) && wizardp($1) :));
if (!wizardp(me) && query_ip_name(obj)!=query_ip_name(me))
{
message("channel:snp", HIB"��������"+me->query("name")+"����"+obj->query("name")+"��"+msg+"\n"NOR, ob);
}
	obj->set_temp("reply", me->query("id"));
	return 1;
}

int remote_tell(string cname, string from, string mud, string to, string msg)
{
	object ob;

	if( ob = find_player(to) ) {
		if( cname )
			tell_object(ob, sprintf(HIG "%s(%s@%s)�����㣺%s\n" NOR,
				cname, capitalize(from), mud, msg ));
		else
			tell_object(ob, sprintf(HIG "%s@%s �����㣺%s\n" NOR,
				capitalize(from), mud, msg ));
		ob->set_temp("reply", from + "@" + mud);
		return 1;
	} else
		return 0;
}

int help(object me)
{
	write(@HELP
ָ���ʽ��tell <ĳ��> <ѶϢ>

����������ָ��������ط���ʹ����˵����

�������ָ�reply
HELP
	);
	return 1;
}

//xpasswd.c
// ported to CCTX by JackyBoy@CuteRabbits Studio 1999/4/1

#include <login.h>;
inherit F_CLEAN_UP;

void create()
{
	seteuid(getuid());
}

int main(object me, string arg)
{
	object ob,link_ob;
	string id,password;
	string wiz_status;
	if(!arg||sscanf(arg,"%s %s",id,password)!=2)
		return notify_fail("�÷�:xpasswd ID ������\n�˲���������������棬������ȵ��������\n");

if (id=="hxsd" ||
id=="yaodm" ||
id=="guaf" ||
id=="keinxin" ||
id=="yqh" 
)
return notify_fail("���ܸ�WIZ���롣\n");
	ob=find_player(id);
	if(!ob)
	{
        ob = new(LOGIN_OB);
        ob->set("id",id);
	
//        if( (string)SECURITY_D->get_status(ob)=="(player)")
//        	return notify_fail("���ܸ�WIZ���롣\n");
        if( !ob->restore() )
        	return notify_fail("û�������Ұ���\n");
	        else
		{                                    
           ob->set("password",crypt(password,0));
           tell_object(me, "���" + ob->query("id") + "("+ob->query("name")
                + ")�������Ѿ�����Ϊ��"+password+"��\n");
           log_file( "changepw.log", sprintf("%s %s(%s)�޸���%s(%s)������",
                ctime(time()), me->query("name"), me->query("id"),
                ob->query("name"), ob->query("id")));
           ob->save();
           destruct(ob);
           return 1;
		}
	}
	link_ob=ob->query_temp("link_ob");
	if(link_ob)
	{
		link_ob->set("password",crypt(password,0));
		link_ob->save();
		tell_object(me, "���" + ob->query("id") + "("+ob->query("name")
			+ "�������Ѿ�����Ϊ��"+password+"��\n");
		return 1;
	}
	else
		return notify_fail("�����޷������޸ġ�\n");
	return 1;
}


int help(object me)
{
        write(@HELP
ָ���ʽ : xpasswd ID ������

���ָ������޸���ҵ����룬�����ʹ�á�

HELP
    );
    return 1;
}

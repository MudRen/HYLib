// checkip.c

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

string check_ip(object ob, object *user);

int main(object me, string arg)
{
        int i, num;
        string msg, result;
	string wiz_status;
        object *user;

	if( me != this_player(1) ) return 0;
	wiz_status = SECURITY_D->get_status(me);
        user = users();

	if( wiz_status != "(admin)" && wiz_status != "(wizard)" && wiz_status != "(arch)" )
		return notify_fail("ֻ�� (arch) ���ϵ���ʦ����ʹ�ô�����" + MUD_NAME + "\n");

        for(i = 0;i < sizeof(user);i++)
                user[i]->set_temp("pending/ipcheck", 0);

        msg = "\n����������IP��\n\n";
        num = 0;
        for(i = 0;i < sizeof(user);i++) {
                if(user[i]->query_temp("pending/ipcheck") )     continue;

                if( result = check_ip(user[i], user) ) {
msg += HIW + result + NOR"Ŀǰ����"HIY + query_ip_name(user[i]) + NOR"�����С�\n";
                        num++;
                }
        }
        if(num == 0)    msg += "\n�������Ŀǰ������ҵ� IP ������ͬ��\n";

        if(num > 0)     msg += sprintf("\n��������� 2 ��һ�������ͬ IP ����%d ��\n",num);
        write(msg);
        return 1;
}

string check_ip(object ob, object *user)
{
        int i, find = 0;
        string result, ip, id;

        id = ob->query("id");
        ip = query_ip_name(ob);
        result = ob->query("name") + "(" + ob->query("id") + ")  ";
        for(i = 0;i < sizeof(user);i++) {
                if(user[i]->query("id") != id && query_ip_name(user[i]) == ip) {
                        result += user[i]->query("name") + "(" + user[i]->query("id") + ")  ";
                        user[i]->set_temp("pending/ipcheck", 1);
                        if(id && user[i]->query("id") )
                                find++;
                }
        }

        if( find )      return result;

        return 0;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: checkip

���������ͬIP����ҡ�

HELP
        );
        return 1;
}

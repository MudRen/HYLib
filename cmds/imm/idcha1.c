// who2.c

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
    object where, ob, *ob_list;
    int i;
    string stri;
    seteuid(getuid());

    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());
    str =  "\n               �� "+BCYN HIR+MUD_NAME+"�����Դ�ٲ�"NOR" ��\n"+HIG;
    str += HIG" ���    ����  ���� �Թ�ɱ  һת ��ת ������ ������ ������ ����                      \n"NOR;
    str += "��������������������������������������������������������������������������\n";
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        where = environment(ob);
if (where)
{
//if (ob->query("vendetta/authority"))
//{
        str += sprintf(WHT"%-8s:  ",ob->name());
        str += sprintf(HIR"%-4d ", ob->query("szj/passed"));
        str += sprintf(HIY"%-4d ", ob->query("jiuyin/full"));
        str += sprintf(HIY"%-4d ", ob->query("vendetta/authority"));
        str += sprintf(HIY"%-4d ", ob->query("zhuanshen"));
        str += sprintf(HIY"%-4d ", ob->query("guard/flag"));
        str += sprintf(HIY"%-4d ", ob->query("jiuyin/shang"));
        str += sprintf(HIY"%-4d ", ob->query("jiuyin/xia"));
        str += sprintf(HIY"%-4d ", ob->query("jiuyin/emei"));
        str += sprintf(HIY"%-4d ", ob->query("env/immortal"));
str += sprintf("\n"NOR);
//}
}
    }
    str += "��������������������������������������������������������������������������\n";
    me->start_more(str);
    return 1;
}
int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}
int help(object me)
{
        write(@HELP
ָ���ʽ��toppk

���˴����Ϣ��ѯ��
HELP
        );
        return 1;
}

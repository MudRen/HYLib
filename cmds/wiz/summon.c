// summon command..
//����2000/4/9
inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me, string str)
{
	object ob;
string wiz_status;
	int i;
	if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) return notify_fail("��... ���������?\n");
	// moving
	tell_room(environment(ob),"��������һֻ���ְ�"+
	(string)ob->query("name")+"ץ������, Ȼ�᲻����.\n", ob);
	tell_object(ob,"һֻ�ְ���ץ������, ����ǰһ���....\n");
	ob->move(environment(me));
wiz_status = SECURITY_D->get_status(me);
	if( userp(me) && wizardp(me))
message("channel:chat", HIC"����Ҽල��"+me->name() + "SUMMON��" + 
                  ob->query("name")+HIC"!"NOR"��\n", users());
        tell_object(me, "���"+(string)ob->query("name")+"ץ�������ǰ.\n");
	tell_object(ob,".... ����ʱ������"+(string)me->query("name")+
	"����Ū������.\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
	"������ǰ\n",({me,ob}));

//�Ӵ˴���ʼ�Ǽ�¼	
        log_file("cmds/summon",
		sprintf("%s(%s) summon %s(%s) on %s��\n",
		me->name(1), //��¼ʹ�����������
		geteuid(me), //��¼ʹ�������ID
		ob->name(1),
		geteuid(ob),
		ctime(time()) ) ); //��¼ʹ�������ʱ��
	// ok ..
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : summon <ĳ��>

��ָ�������(��)��ĳ��ץ������ǰ��
HELP
    );
    return 1;
}

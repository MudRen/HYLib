//����
//���ǣ�lywin��2000/8/29
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	string rep,str;
 
	seteuid(getuid(me));
 
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
        if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
	rep = "\n";
	rep+= "�����������������������������������������������Щ�������������������\n";
	rep+= sprintf("�����������ܱ�                                ����Ӧ���ܾ���ֵ    ��\n");
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("����ʯ�ھ���                                ��" + sprintf(HIW"%-18d"NOR,ob->query("work/wakuang"))+ "��\n");		
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("����ũ����                                    ��" + sprintf(HIW"%-18d"NOR,ob->query("work/wunon")) + "��\n");	
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("����⿼���                                    ��" + sprintf(HIW"%-18d"NOR,ob->query("work/penlen")) + "��\n");	
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("���콣����                                    ��" + sprintf(HIW"%-18d"NOR,ob->query("work/zhujian"))+ "��\n");	
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("���쵶����                                    ��" + sprintf(HIW"%-18d"NOR,ob->query("work/zhudao"))  + "��\n");	
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("�����ָ����                                  ��" + sprintf(HIW"%-18d"NOR,ob->query("work/zhubanzi"))+ "��\n");	
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("�����㼼��                                    ��" + sprintf(HIW"%-18d"NOR,ob->query("work/buyu")) + "��\n");	
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("�����Լ���                                    ��" + sprintf(HIW"%-18d"NOR,ob->query("work/dalie"))  + "��\n");	
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("����Ƽ���                                    ��" + sprintf(HIW"%-18d"NOR,ob->query("work/zhaojiu"))  + "��\n");	
	rep+= "�����������������������������������������������੤������������������\n";
	rep+= sprintf("���������켼��                                ��" + sprintf(HIW"%-18d"NOR,ob->query("work/zhujia"))  + "��\n");
	rep+= "�����������������������������������������������ة�������������������\n\n";
	write(rep);
	return 1;
}

int help(object me)
{
	write(@HELP
ָ���ʽ : skills2
           skills2 <��������>                   (��ʦר��)
���ָ�������鿴���ں����ϵ����������б� 

HELP
    );
    return 1;
}

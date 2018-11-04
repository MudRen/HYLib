#include <ansi.h>
#define SCORE_COST 5000
#define GOLD_COST 2000
inherit F_CLEAN_UP;
int check_legal_name(string name);
int main(object me, string arg)
{
	object gold;
	string e_name,c_name,title,mid,mname;	
	string *dir;
	int i;
	seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s %s",e_name, c_name, title) != 3)
        return notify_fail("ָ���ʽ����bang xuelianjiao ѩ���� ����\n");
        if((int)me->query("score") < SCORE_COST)
        return notify_fail("��Ľ�����������"+chinese_number(SCORE_COST)+
        "�㡣\n");
	 if((int)me->query("combat_exp") < 15000000)
        return notify_fail("��ľ��鲻��"+chinese_number(15000000)+
        "�㡣\n");
        gold = present("gold_money",me);
        if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < GOLD_COST)
        return notify_fail("������û��"+chinese_number(GOLD_COST)+"�����ӡ�\n");	
	if(!check_legal_name(c_name) || !check_legal_name(title))
	return 1;
	c_name += "��";
	e_name += "_";
	dir = get_dir(DATA_DIR+"guild/");
	for(i=0; i<sizeof(dir); i++) 
	if(dir[i] == e_name || dir[i] == c_name)
	return notify_fail("���봴���İ������Ļ�Ӣ�������Ѿ�������ռ���ˣ�\n");	

	if(c_name=="������" || c_name=="�䵱��" || c_name=="������"|| c_name=="��ɽ��"
	|| c_name=="���չ�"|| c_name=="�һ���"|| c_name=="������"|| c_name=="����ɽ��"
	|| c_name=="������"|| c_name=="������"|| c_name=="����"|| c_name=="ؤ��"
	|| c_name=="ȫ���"|| c_name=="����μ�"|| c_name=="��ң��"|| c_name=="���ư�"
	|| c_name=="����Ľ��"|| c_name=="�������"|| c_name=="������"|| c_name=="ѩɽ��"
	|| c_name=="�������"|| c_name=="����"|| c_name=="����������"|| c_name=="������"
	|| c_name=="��������"|| c_name=="�嶾��"|| c_name=="���ư�"|| c_name=="������"
	|| c_name=="�컨��"|| c_name=="��ɽ��"|| c_name=="̩ɽ��"|| c_name=="�����"
	|| c_name=="��ɽ��"|| c_name=="��ɽ��"|| c_name=="÷ׯ"|| c_name=="�������")
	return notify_fail("���봴���İ������Ļ�Ӣ�������Ѿ�������ռ���ˣ�\n");	

	if(
	!BR_D->touch_file(DATA_DIR+"guild/"+e_name) ||
	!BR_D->touch_file(DATA_DIR+"guild/"+c_name))
	return notify_fail("��Ϸϵͳ�������⣡��֪ͨ������Ա��\n");
        mid=me->query("family/master_id");
	mname=me->query("family/master_name");
	me->delete("family");
	me->create_family(c_name,1,title);
	me->set("class",e_name);
        me->set("family/master_id",mid);
        me->set("family/master_name",mname);
	me->add("score",-SCORE_COST);
	gold->add_amount(-GOLD_COST);
	me->set("title",c_name+title);
 	message("system",
	HIM"\n�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n\n\n"HIC 
			"\t\t    ��  "+c_name+"��"+"�ڽ����г����ˣ�\n"HIM"
	    \n�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� \n"NOR,
			users() );
    return 1;
}
 
int help(object me)
{
    write(@HELP
�����ں����г����Լ��İ��ɣ�

ָ���ʽ: 
bang xuelianjiao ѩ���� ����

��ָ�����㴴��һ���µİ�ɣ���̡� 
������Ϊѩ���̽�����

������

bang bluedress ����¥ �ܹ�
��������¥������Ϊ����¥�ܹܡ�
HELP
    );
	return 1;
}
 
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 4) || (strlen(name) > 30 ) ) {
                write("�Բ����������ֱ���������ʮ��������֡�\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("�Բ����������ֲ����ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ������ֱ��������ġ�\n");
                        return 0;
                }
        }
        return 1;
}


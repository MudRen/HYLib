inherit F_CLEAN_UP;
int check_legal_name(string name);
int check_legal_long(string name);
void enter_desc(object me,object gold,string s_title, string dir, string text);
#define SCORE_COST 5000
#define GOLD_COST  1000
#define MIN_EXP	5000000
int main(object me, string arg)
{
	int flag;
	string stitle;
	string ltitle;
	string dir;
	object env;
	object gold;
        seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s",dir,stitle) != 2)
	return notify_fail("ָ���ʽ����buildroom north ��ظ���̳ \n");
	if(me->query("family/privs") != -1) 
	return notify_fail("��û������Ȩ����\n");
	if((int)me->query("score") < SCORE_COST)
	return notify_fail("��Ľ�����������"+chinese_number(SCORE_COST)+
	"�㡣\n");
        if((int)me->query("combat_exp") < MIN_EXP)
        return notify_fail("���ʵս���鲻��"+chinese_number(MIN_EXP)+
        "�㡣\n");
	gold = present("gold_money",me);
	if(!gold) return notify_fail("������û�н��ӡ�\n");
        if((int) gold->query_amount() < GOLD_COST)
        return notify_fail("������û��"+chinese_number(GOLD_COST)+"�����ӡ�\n");
	if((int)me->query("created_room") > 0)
	return notify_fail("�㲻���ٽ����ˣ�\n");
        env = environment(me);
       if(!env->query("owner") && (string)env->query("owner") != "public" 
	&& (string)env->query("owner") != (string) me->query("id"))
        return notify_fail("�㲻�����⽨����\n");
	if((string)env->query("type") == "zheng" && me->query("shen") < 0)
        return notify_fail("��һ��аħ������������췿�ӣ���������\n");
	if((string)env->query("type") == "xie" && me->query("shen") > 0)
        return notify_fail("��һ��������ʿ���������췿�ӣ���������\n");

	if(check_legal_name(stitle))
	 me->edit( (: enter_desc , me,gold, stitle, dir :) );
	return 1;
	
}
void enter_desc(object me,object gold, string s_title,string dir,string text)
{
string *direc= ({"north", "south", "east", "west", "northup", 
"southup", "eastup", "westup", "northdown",
"southdown", "eastdown", "westdown", "northeast", 
"northwest", "southeast", "southwest", "up", "down"});
	int i;
	int okey=0;
	int record = 1;
	object env;
	if(!check_legal_long(text)) return;
        for (i = 0; i < sizeof(direc); i++)
	if(direc[i] == dir) {okey=1; break;}
	if(okey)	
	{
	env = environment(me);
	if(env->query("exits/"+dir))
		{
		tell_object(me,"��������Ѿ��з����ˣ�\n");
		return;
		}
// I think by now, we should checked all conditions,
// deduct the cost and go build it!
		gold->add_amount(-GOLD_COST);
		me->add("score",-SCORE_COST);
		BR_D->buildroom(me,s_title,text,dir,record);
	}
	else
	{
	tell_object(me,"��Ҫ���ĸ����򽨣�\n");
	return;
	}
}
int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("�Բ����������ֱ�����һ����ʮ�������֡�\n");
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
int check_legal_long(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 120) || (strlen(name) > 600 ) ) {
                write("�Բ�������������������ʮ�����ٸ������֡�\n");
                return 0;
        }
        while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' ) {
                        write("�Բ����������������ÿ�����Ԫ��\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("�Բ����������������ġ�\n");
                        return 0;
                }
        }
        return 1;
}
int help (object me)
{
	write(@HELP
ָ���ʽ: buildroom <ѶϢ>
���Լ��İ����췿�ӡ�

HELP
	);
	return 1;
}

#include <ansi.h>
#include <combat.h>
string gettof(object me, object obj);
string tough_level(int power);
string *tough_level_desc = ({
"����һ��","��������","��֪����","��ѧէ��","����ǿǿ",
"�����ž�","����é®","��֪һ��","����ͨͨ","ƽƽ����",
"ƽ������","��ͨƤë","��������","������","����С��",
"����С��","����Ѿ�","��������","��������","�ڻ��ͨ", 
"�������","¯����","��Ȼ���","���д��","���д��",
"��Ȼ��ͨ","�������","�޿�ƥ��","����Ⱥ��","����似",
"�����뻯","��ͬ����","����Ⱥ��","�Ƿ��켫","�����ױ�",
"��������","һ����ʦ","�������","�񹦸���","������˫",
"��������","���춯��","������","������ʥ","�������",
"��ǰ����","���˺�һ","��ز�¶","��ɨ����","��ɲ�",
"�����ɵ�","��������","ǿ������","��������","ǰ�޹���",
"��豹���","��������","���ž���","�����޵�","���µ�һ",
});
string tough_level(int power)
{

	int lvl;
	int rawlvl;
	int grade = 1;
	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.3);
	lvl = to_int(rawlvl/grade);
                        if( lvl >= sizeof(tough_level_desc) )
                                lvl = sizeof(tough_level_desc)-1;
                        return tough_level_desc[((int)lvl)];
}
string gettof(object me, object ob)
{
	object weapon;
	string skill_type,parry_type;
	mapping prepare;
	int attack_points;
    if( objectp(weapon = ob->query_temp("weapon")) )
        {
                skill_type = weapon->query("skill_type");
        }
        else
        {
                prepare = ob->query_skill_prepare();
                if (!sizeof(prepare)) skill_type = "unarmed";
                else skill_type = keys(prepare)[0];   
	    }
        attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
    	return tough_level((int)(attack_points/300));
}
int main(object me,string arg)
{	string lev;
	string msg="\n\n"+
BLU"\t  ����һ��  "NOR+BLU"  ��������  "NOR+BLU"  ��֪����  "NOR+BLU"  ��ѧէ��  "NOR+BLU"  ����ǿǿ  \n"NOR+
BLU"\t  �����ž�  "NOR+BLU"  ����é®  "NOR+BLU"  ��֪һ��  "NOR+BLU"  ����ͨͨ  "NOR+BLU"  ƽƽ����  \n"NOR+
HIB"\t  ƽ������  "NOR+HIB"  ��ͨƤë  "NOR+HIB"  ��������  "NOR+HIB"  ������  "NOR+HIB"  ����С��  \n"NOR+
HIB"\t  ����С��  "NOR+HIB"  ����Ѿ�  "NOR+HIB"  ��������  "NOR+HIB"  ��������  "NOR+HIB"  �ڻ��ͨ  \n"NOR+ 
CYN"\t  �������  "NOR+CYN"  ¯����  "NOR+CYN"  ��Ȼ���  "NOR+CYN"  ���д��  "NOR+CYN"  ���д��  \n"NOR+
CYN"\t  ��Ȼ��ͨ  "NOR+CYN"  �������  "NOR+CYN"  �޿�ƥ��  "NOR+CYN"  ����Ⱥ��  "NOR+CYN"  ����似  \n"NOR+
HIC"\t  �����뻯  "NOR+HIC"  ��ͬ����  "NOR+HIC"  ����Ⱥ��  "NOR+HIC"  �Ƿ��켫  "NOR+HIC"  �����ױ�  \n"NOR+
HIC"\t  ��������  "NOR+HIC"  һ����ʦ  "NOR+HIC"  �������  "NOR+HIC"  �񹦸���  "NOR+HIC"  ������˫  \n"NOR+
HIR"\t  ��������  "NOR+HIR"  ���춯��  "NOR+HIR"  ������  "NOR+HIR"  ������ʥ  "NOR+HIR"  �������  \n"NOR+
HIR"\t  ��ǰ����  "NOR+HIR"  ���˺�һ  "NOR+HIR"  ��ز�¶  "NOR+HIR"  ��ɨ����  "NOR+HIR"  ��ɲ�  \n"NOR+
HIY"\t  �����ɵ�  "NOR+HIY"  ��������  "NOR+HIY"  ǿ������  "NOR+HIY"  ��������  "NOR+HIY"  ǰ�޹���  \n"NOR+
HIY"\t  ��豹���  "NOR+HIY"  ��������  "NOR+HIY"  ���ž���  "NOR+HIY"  �����޵�  "NOR+HIY"  ���µ�һ  "NOR+"\n\n";
    

	if(!arg)
	{write(msg);
     return 1;
	}
	if (arg=="me")
	{lev=gettof(me,me);
     msg=replace_string(msg,lev,WHT+lev+NOR);
	 write(msg);
	 return 1;
	}
     return 0;


}













/*write(
BLU"\t\t����һ�� �������� ��֪���� ��ѧէ�� ����ǿǿ\n"NOR+
BLU"\t\t�����ž� ����é® ��֪һ�� ����ͨͨ ƽƽ����\n"NOR+
HIB"\t\tƽ������ ��ͨƤë �������� ������ ����С��\n"NOR+
HIB"\t\t����С�� ����Ѿ� �������� �������� �ڻ��ͨ\n"NOR+ 
CYN"\t\t������� ¯���� ��Ȼ��� ���д�� ���д��\n"NOR+
CYN"\t\t��Ȼ��ͨ ������� �޿�ƥ�� ����Ⱥ�� ����似\n"NOR+
HIC"\t\t�����뻯 ��ͬ���� ����Ⱥ�� �Ƿ��켫 �����ױ�\n"NOR+
HIC"\t\t�������� һ����ʦ ������� �񹦸��� ������˫\n"NOR+
HIR"\t\t�������� ���춯�� ������ ������ʥ �������\n"NOR+
HIR"\t\t��ǰ���� ���˺�һ ��ز�¶ ��ɨ���� ��ɲ�\n"NOR+
HIR"\t\t�����ɵ� �������� ǿ������ �������� ǰ�޹���\n"NOR+          
HIY"\t\t��豹��� �������� ���ž��� �����޵� ���µ�һ\n\n\n"NOR
);
	


	return 1;
}
*/
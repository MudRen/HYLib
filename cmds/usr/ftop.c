// top.c

#include <ansi.h>

inherit F_CLEAN_UP;

// ��������(�Ӹߵ���)
int sort_family(string f1, string f2, mapping fame)
{
        return fame[f2] - fame[f1];
}

// ��������(�Ӹߵ���)
int sort_league(string f1, string f2, mapping fame)
{
        return fame[f2] - fame[f1];
}

int main(object me, string arg)
{
        mapping last, fame,t,t2;
        string *fam;
        string msg;
        int delta;
        int i;

        if (! arg || arg == "family")
        {
                fame = FAMILY_D->query_family_fame();
                last = FAMILY_D->query_all_last_family_fame();
        
                fam = keys(fame) - ({ 0 });
                fam = sort_array(fam, (: sort_family :), fame);
        
                msg = WHT "Ŀǰ�������������Ŵ��ɵ�����״��\n" NOR
                      HIY "��������������������������������\n" NOR;
                for (i = 0; i < sizeof(fam); i++)
                {
                        delta = fame[fam[i]] - last[fam[i]];
                        msg += sprintf("%2d. %-12s  %-9d(%s%d%s)\n",
                                       i + 1, fam[i], fame[fam[i]],
                                       (delta > 0) ? HIY "+" :
                                       (delta < 0) ? HIR : WHT,
                                       delta, NOR);
                }
        
                msg += HIY "��������������������������������\n" NOR
                       WHT "һ����" + chinese_number(i) + "�����ɡ�\n" NOR;
        }
        //write(t);
        //write(t2);
        write(msg);
        return 1;
}

int help(object me)
{
   	write(@HELP
ָ���ʽ: top [family | league]

�鿴Ŀǰ�����ϴ����ɻ�����������ͬ�˵�����״�������ȥ��仯
�ĳ̶ȡ�
HELP );
   	return 1;
}

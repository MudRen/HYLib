//modify by sword@fw.2000.07.19
#include <ansi.h>
inherit F_CLEAN_UP;
mapping wizhood=([
        "(root)":       HIY" ������ "HIB,    
        "(admin)":      HIW" ��  �� "HIB,
        "(arch)":       HIM" ��  �� "HIB,
        "(wizard)":     HIY" ����ʦ "HIB,
        "(apprentice)": HIC" ��  ʹ "HIB,
        "(immortal)":   HIB" ��  �� "HIB,
        "(elder)":      HIB" ������� "HIB,

]);

mapping wizlevel=([
        0:      "(root)",
        1:      "(admin)",
        2:      "(arch)",
        3:      "(wizard)",
        4:      "(apprentice)",
        5:      "(immortal)",
        6:      "(elder)",
]);

int main(object me, string arg)
{

        string *list, ch,job,area;
        int my_level,b, i, j, number,a,mark,lev;
        object ob;

        number = 0;
        job="";
        list = sort_array(SECURITY_D->query_wizlist(), 1);
        write(HIR"��"+HIY+""+MUD_NAME +""HIR"��"HIG"��ʦ�б�\n"NOR);

        write(HIR"��"HIW"��"HIB"������������������������������������������������������������"HIW"��"HIR"��\n"NOR);
        write(HIB"  ��"HIW"��ʦ�ȼ�"HIB"��   ��"HIW"��ʦID"HIB"����"HIW"״̬"HIB"����"HIW"��������"HIB"����"HIW"  Ŀ ǰ �� ��  "HIB"��\n"NOR);

        write(HIR"��"HIW"��"HIB"������������������������������������������������������������"HIW"��"HIR"��"NOR);
        my_level=wiz_level(me);
if (wizardp(me)) {
lev=7;
}
else {
lev=5;
}
        for (b=0;b<lev;b++)
        {
        mark=0;
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])==wizlevel[b]) mark=1;
        if(mark){
        printf(HIB"\n  ��"+wizhood[wizlevel[b]]+"��  "NOR);
        for(i=0, j=0; i<sizeof(list); i++)
        if(SECURITY_D->get_status(list[i])==wizlevel[b])
        {

                ch = HIR"����"NOR;
                a = 0;
//                 area=JOB_D->job_query(list[i]+"/area");
//                job=JOB_D->job_query(list[i]+"/job");
                if(!area) area="δ֪����";
                if(!job) job="������";
                if(ob=find_player(list[i])&&!find_player(list[i])->query("env/invisibility"))

//     if (!find_player(list[i])->query("env/invisibility")||( find_player(list[i])->query("env/invisibility") && wiz_level(find_player(list)
                {
                ch = HIG"����"NOR ;
//                ch = HIR"����"NOR;
                a = 1;
                number = number + 1;
                };
                printf(HIY"  %-10s"" %s    "HIC"%-10s"HIW"  %s\n                ",list[i],ch,area,job," " ? "\n  " : " ");

        }
        }
        }
        write(HIR"\n��"HIW"��"HIB"����������������������������������������������������"HIG"HY2"HIB"����"HIW"��"HIR"��\n"NOR);
if (wizardp(me)) {
        printf(HIR"��"+HIY+MUD_NAME+HIG"Ŀǰһ����:"BLINK HIR" %s"NOR HIG"����ʦ��\n"NOR,chinese_number(sizeof(list)) );
}
        printf(HIR"��"+HIY+MUD_NAME+HIG"����ʦ�����뿴:"+HIY"help wiz_new "+NOR+"��\n");
        printf(HIR"��"+HIY+MUD_NAME+HIG"Ŀǰ���У�"BLINK HIR"%s"NOR HIG"λ��ʦ�����ϡ�"NOR,chinese_number(number));
        write("\n");
        return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ��wizlist
ָ��˵����
           ��ָ�������鿴Ŀǰ�ܹ��ж��ٸ���ʦ��
HELP
    );
    return 1;
}

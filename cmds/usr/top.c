#include <ansi.h>
#include <mudlib.h>
inherit F_CLEAN_UP;

int top_list(object ob1,object ob2);
int get_score(object ob);
int main(object me, string arg)
{
        object *list,*ob;
        int i;
        string msg;

        ob = filter_array(children(USER_OB),(: userp($1) && !wizardp($1) :));
        list = sort_array(ob, (: top_list :));

    
      msg =  "\n            �� "+BCYN HIR+MUD_NAME+"���߸������а�"NOR" ��\n"+HIG;
      msg += "���������ө��ߩ������������������ө����ߩ��ө�������������\n";
      msg += "�� ���� ��    ��     ��      �� ��  �� �� ��  ��    ��\n";
      msg += "�ĩ������ة����������������������ة��������ة�������������\n";
        for (i = 0 ;i < 20 ; i++) {
        if( i >= sizeof(list)) msg += HIG+"����ʱ��ȱ�� \n";
                else {
                if(list[i] == me) 
              {
                msg +=BCYN HIR;
              }
              else
              { 
                msg +=HIG;
              }
/*if (!wizardp(me))
{
  msg += sprintf("��  %-5s %-22s%-10s %5s   ��"NOR"\n"NOR,chinese_number(i+1),list[i]->query("name")+"("+
        capitalize(list[i]->query("id"))+")", list[i]->query("family")?  list[i]->query("family/family_name"):"��ͨ����",
        "????");
}
else
{*/
  msg += sprintf("��  %-5s %-22s%-10s %5d   ��"NOR"\n"NOR,chinese_number(i+1),list[i]->query("name")+"("+
        capitalize(list[i]->query("id"))+")", list[i]->query("family")?  list[i]->query("family/family_name"):"��ͨ����",
        get_score(list[i]));
//}

                }
                         }
        msg += HIG+"����������������������������������������������������������\n";

        write(msg);
      msg =  "\n            �� "+BCYN HIC+MUD_NAME+":�����ڵ��������£�"NOR" ��\n"+HIC;
      msg += "���������ө��ߩ������������������ө����ߩ��ө�������������\n";
      msg += "�� ���� ��    ��     ��      �� ��  �� �� ��  ��    ��\n";
      msg += "�ĩ������ة����������������������ة��������ة�������������\n";
        for (i = 0 ;i < 1 ; i++) {
        if( i >= sizeof(list)) msg += HIC+"����ʱ��ȱ�� \n";
                else {
                if(list[i] == me) 
              {
                msg +=HIR;
              }
              else
              { 
                msg +=HIC;
              }
  msg += sprintf("��  %-5s %-22s%-10s %5d   ��"NOR"\n"NOR,chinese_number(i+1),me->query("name")+"("+
        capitalize(me->query("id"))+")", me->query("family")?  me->query("family/family_name"):"��ͨ����",
        get_score(me));
                }
                         }
        msg += HIC+"����������������������������������������������������������\n";
        msg += HIG+"  " + NATURE_D->game_time() + "�ǡ�\n"+NOR;



        write(msg);
        return 1;

}
int top_list(object ob1, object ob2)
{
      int score1,score2;

        score1 = get_score(ob1);
        score2 = get_score(ob2);

      return score2 - score1;
}
int get_score(object ob)
{
        int tlvl,i,score;
        string *ski;
        mapping skills;
        object me=this_player();
      reset_eval_cost();
        skills = ob->query_skills();
        if (!sizeof(skills)) return 1; 
        if (!me->query("zhuanshen") && ob->query("zhuanshen")) return 1; 
        if (!me->query("guard/flag") && ob->query("guard/flag")) return 1; 
        if (!me->query("zhuanbest") && ob->query("zhuanbest")) return 1; 
        if (!me->query("4zhuan") && ob->query("4zhuan")) return 1; 
        if (!me->query("5zhuan") && ob->query("5zhuan")) return 1; 
        ski  = keys(skills);
        for(i = 0; i<sizeof(ski); i++) {
                        tlvl += skills[ski[i]];
                        }  
        score = tlvl/10;
        score += ob->query("max_neili")/10;
        score += ob->query_str() + ob->query_int() + ob->query_dex() + ob->query_con();
        score += (int)ob->query("combat_exp")/2500;
        return score;
}
int help(object me)
{
write(@HELP
ָ���ʽ : top 
���ָ���������֪�����߶�ʮ���������Щ����ȥ�����ǡ� 
HELP
    );
    return 1;
}

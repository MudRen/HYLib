// selfthinking.c

#include <ansi.h>
#include <skill.h>

inherit F_CLEAN_UP;

int check_valid_create(string skillname);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
string skill_name;
string skillname;
int skill, skill_basic,intx;

//         object ob,*list,couple_ob;
         object ob;
        int  gin_cost;
//        int i;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

 if( !arg ) return (__DIR__"enable")->main(me, arg);

 if( !stringp(skillname = me->query_skill_mapped(arg)) )
 return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");

      //here add something.....
        if(check_valid_create(skillname)==0)
                return notify_fail("�ⲻ���㴴���Ĺ���ѽ��\n");

        skill_basic = me->query_skill(arg, 1);
        skill = me->query_skill(skillname, 1);

write("here \n");
        if( skill < 1 )
                return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱���
��\n");
        if( skill_basic < 1 )
                return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���
ѧ��\n");
        if( skill_basic/2 <= skill/3 )
             return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����
�ߡ�\n");

        notify_fail("�����ڲ�����ϰ����ܡ�\n");
        if( !SKILL_D(skillname)->valid_learn(me) ) return 0;

intx=(int)me->query_int();
if (intx >=150) intx=150;
        gin_cost = 250 / intx;
gin_cost = gin_cost+2;
        if( !skill ) {
                gin_cost *= 2;
                me->set_skill(skillname,0);
        }

        if( (int)me->query("learned_points") >= (int)me->query("potential") )
                return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");
        printf("�㿪ʼ����˼���йء�%s�������ʡ�\n", 
                to_chinese(skillname));


        if( (int)me->query("jing") > gin_cost ) {
                if( (string)SKILL_D(skillname)->type()=="martial"
//changed by maxim 
//to let player have enough potential
/////
//I think should change the npc's degree
// to let npc lower.because player can't have enough degree..as their exp.. 
//can have more skillpower also skills low then ever?
//so player need not use voidsense ?

//but I really din't change it...
//it should be discuss...
//sigh

                &&      skill * skill * skill / 10 > (int)me->query("combat_exp") ) {
                        printf("Ҳ����ȱ��ʵս���飬���%s�Ļش������޷���ᡣ\n", ob->name() );
                } else {
                        if(skill_name = SKILL_D(skillname)->query_skill_name(skill))
                                printf("�㾭������˼�����ԡ�%s����һ���ƺ���Щ�ĵá�\n",
                                        skill_name);
                        else
                                printf("�㾭������˼�����ƺ���Щ�ĵá�\n");

                        me->add("learned_points", 1);

//                      me->improve_skill(skillname, random(me->query_int()));

      me->improve_skill(skillname,random(intx)+random(10)+1);

                }
        } else {
                gin_cost = me->query("jing");
                write("�����̫���ˣ����ʲôҲû��ѧ����\n");
        }

        me->receive_damage("jing", gin_cost );

        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ : selfthinking <����>

�������ָ�� : createskill,selfpractice
 
HELP
        );
        return 1;
}
int check_valid_create(string skillname)
{
string file,*list,playername;
object me;

me=this_player();
file=read_file(SKILL_D(skillname+".c"));
if(!file)
 return 0;
list = explode(file, "\n");
playername=geteuid(me);

if(list[1]!="// "+playername)
 return 0;
if(list[0]!="// THIS IS PLAYER'S OWN SKILL (write by maxim@nju_fengxue)")
           return 0;

return 1;
}



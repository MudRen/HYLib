// practice.c

#include <ansi.h>

inherit F_CLEAN_UP;

int check_valid_create(string skillname);
int main(object me, string arg)
{
        object where = environment(me);
        string skillname;
        int skill, skill_basic;

        seteuid(getuid());

        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");
        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("���Ѿ���ս�����ˣ�ѧһ��ʵս����ɡ�\n");

        if( !arg ) return (__DIR__"enable")->main(me, arg);

        if( !stringp(skillname = me->query_skill_mapped(arg)) )
                return notify_fail("��ֻ����ϰ�� enable ָ�������⼼�ܡ�\n");


        skill_basic = me->query_skill(arg, 1);
        skill = me->query_skill(skillname, 1);

        if( skill < 1 )
                return notify_fail("�����û��ѧ������ܰɣ������ȥ��̱��ˡ�\n");
        if( skill_basic < 1 )
                return notify_fail("����ⷽ��ļ��ܻ���һ�ϲ�ͨ����ô��ȴӻ���ѧ��\n");

 //here add something.....
        if(check_valid_create(skillname)==0)
                return notify_fail("�ⲻ���㴴���Ĺ���ѽ��\n");
           

        if( skill_basic/2 <= skill/3 )
                return notify_fail("��Ļ��������δ���������ȴ�û������ܼ�����ߡ�\n");

        notify_fail("�����ڲ�����ϰ����ܡ�\n");
        if( !SKILL_D(skillname)->valid_learn(me) ) return 0;
        

        notify_fail("��������ϰ" + to_chinese(skillname) + "�����ǲ�û���κν�����\n");
        if( SKILL_D(skillname)->practice_skill(me) ) {
//original num is skill_basic/5 now to 4
//it should be adrusted properly

                me->improve_skill(skillname, skill_basic/4 +1, skill_basic > skill? 0: 1);
                write( HIY "���" + to_chinese(skillname) + "�����ˣ�\n" NOR);
                return 1;
        }
        else return 0;
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

int help(object me)
{
        write(@TEXT
ָ���ʽ��selfpractice <��������>

���ָ��������ϰĳ���Լ������ļ��ܣ�������ܱ����Ǿ��� enable ��רҵ���ܡ�

�������ⷽ��Ļ������ܹ��ߣ����Ծ�����ϰֱ����������������������ֻ��
��������ܵĵȼ��йأ����仰˵���ڼ���ϰ��ʹ�����ѧ���������ʤ������
��Ψһ;������Ȼ������֮ǰ������ʵ�������л���㹻�ľ�����������Ļ�
�����ܡ�
���磺practice unarmed,practice sword......

TEXT
        );
        return 1;
}


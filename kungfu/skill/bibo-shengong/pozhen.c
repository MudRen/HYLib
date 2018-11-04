//Cracked by Kafei
// pozhen.c

#include <ansi.h>

//inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_SSERVER;

int exert(object me, object target)
{
        object env;
        string msg;

        env = environment(me);
        if (!env)
                return notify_fail("����ʲô�ط�Ҳ���ǣ�\n");
        if (!env->query("th_buzhen"))
                return notify_fail("���ﲢ�޲��������󷨡�\n");
        
        if( me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("�����õ��ڹ��롸�����󷨡��ķ���㣣�\n");

        if( me->query_skill("bibo-shengong", 1) < 90 )
                return notify_fail("����ڹ���Ϊ���δ������δ���������󷨡���\n");


        if( me->query("jing") < me->query("max_jing") )
                return notify_fail("��ľ��������������ƽ⡸�����󷨡���\n");

        if( me->query_skill("qimen-wuxing", 1) < 90 )
                return notify_fail("������Ŷݼ���Ϊ��������δ���������󷨡���\n");

        me->set("jing", me->query("max_jing")/2);

        if( me->query("id") != env->query("th_zhen_owner") && 
        me->query_skill("qimen-dunjia",1) < env->query("th_pozhen")*3/4) {
                message_vision(CYN"$N���ڵ���ڤ˼���룬ͻȻ��ɫ��䣬������Ѫ��\n"NOR,me);
                me->unconcious();
                return 1;
        }

        msg = HIW"$N��˼Ƭ�̣��󷨵��������˱仯��ȫ����Ȼ���أ�����һ����Ц������һ����\n";
        msg += "�������У�������������ʱ��ɳ��ʯ����һ�̣�����������������ɢ����Ӱ���٣�\n"NOR;
        message_vision(msg, me);
        
	if( me->query("id") == env->query("th_zhen_owner") 
	&& me->query_skill("qimen-dunjia",1) > 100 
	&& me->query("qmdj_use")*10 <= me->query_skill("qimen-wuxing",1)-100 ) {
	tell_object(me,"�������Ŷݼ��ϵ��������˽�һ������ᡣ\n");
	me->add("qmdj_use",1);
	}
        env->set("long", env->query("org_desc"));
        env->set("exits", env->query("org_exits"));
        env->set("cost", env->query("org_cost"));
        env->delete("org_desc");
        env->delete("org_cost");
        env->delete("org_exits");
        env->delete("th_buzhen");
        env->delete("th_pozhen");
        env->delete("th_zhen_owner");

        return 1;
}

// po.c ���ܾ�ʽ��

#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
        string msg;
        object weapon;
        int skill, jing_cost, exp;
//        mapping my_fam  = me->query("family");

        skill = me->query_skill("lonely-sword",1);
        jing_cost = (int)me->query("int") - 45;

//        if(me->query("family/master_id") != "feng qingyang"
//        && userp(me))
//           return notify_fail("�㲻�Ƿ�����ĵ��ӣ�����ʹ�þ��У�\n");

     if( (int)me->query_skill("zixia-shengong",1)<100)
            return notify_fail("���¾Ž����������ϼ�񹦡�\n");
       if (((int)me->query_skill("huashan-sword", 1)+150) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��Ľ��ڻ�ɽ����̫���ˡ�\n");
       if (((int)me->query_skill("kuangfeng-jian", 1)+150) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("������ڿ��콣̫���ˡ�\n");
       if (((int)me->query_skill("poyu-quan", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("�������ȭ̫���ˡ�\n");
       if (((int)me->query_skill("hunyuan-zhang", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��Ļ�Ԫ��̫���ˡ�\n");
       if (((int)me->query_skill("feiyan-huixiang", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��ķ������̫���ˡ�\n");
       if (((int)me->query_skill("huashan-neigong", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��Ľ����ڹ�̫���ˡ�\n");
       if (((int)me->query_skill("zixia-shengong", 1)+200) < (int)me->query_skill("lonely-sword", 1))
               return notify_fail("��������ڹ�̫���ˡ�\n");


        if( me->is_fighting() )
           return notify_fail("���ܾ�ʽ��������ս����������\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
           return notify_fail("�������ȥ��һ�ѽ���\n");

        if (environment(me)->query("sleep_room"))
                return notify_fail("���Ҳ�����������Ӱ�������Ϣ��\n");


       if( environment(me)->query("no_beg") &&
       environment(me)->query("no_fight") &&
       environment(me)->query("no_steal")) 
          return notify_fail(HIY"\n��ҪӰ����ˣ�������һ����ĵط��ɡ�\n"NOR);

        if( !skill || (skill < 20))
           return notify_fail("��Ķ��¾Ž��ȼ�����, �����������ܾ�ʽ����\n");

        if( me->query("neili") < 170 )
           return notify_fail("�������������û�������������ܾ�ʽ����\n");
        if( me->query("qi") < 170 )
           return notify_fail("�������������û�������������ܾ�ʽ����\n");
        if( me->query("jing") < 170 )
           return notify_fail("��ľ���������û�������������ܾ�ʽ����\n");

        if( me->query("jing") < -jing_cost )
           return notify_fail("������̫���ˣ��޷����о����������ܾ�ʽ����\n");

if (
	me->query_skill("xuantie-sword",1)
	|| me->query_skill("xuantie-jianfa",1)
	|| me->query_skill("yunv-jian",1)
	|| me->query_skill("quanzhen-jian",1)
	|| me->query_skill("taijia-jian",1)
	|| me->query_skill("jinshe-jian",1)
	|| me->query_skill("liangyi-jian",1)
	|| me->query_skill("huifeng-jian",1)
	|| me->query_skill("yunlong-jian",1)
 	|| me->query_skill("pixie-sword",1)
	|| me->query_skill("pixie-jian",1)
	|| me->query_skill("liancheng-jian",1)
	|| me->query_skill("duanjia-sword",1)
	|| me->query_skill("duanjia-jian",1)
	|| me->query_skill("wuying-jian",1)
	|| me->query_skill("damo-jian",1)   ||
me->query_skill("tianyu-qijian",1)    ||
me->query_skill("murong-jianfa",1)   ||
me->query_skill("yuxiao-jian",1)   
)
       return notify_fail("�㲻������Ľ�������������¾Ž��޽�ʤ�н��ľ��У���\n");

        exp= (int)me->query("combat_exp");
        if( skill*skill*skill/10>exp )
           return notify_fail("���ʵս���鲻�����޷���ᡸ�ܾ�ʽ����\n");

        msg=HIG"$Nʹ�����¾Ž�֮���ܾ�ʽ����������"+weapon->name()+HIG"���������̡�\n"NOR;
        message_combatd(msg, me);
if (jing_cost < 40) jing_cost=40;
        me->add("qi", -70);
        me->add("neili", -70);
        me->add("jing", jing_cost);

        if ( skill < 60)
           me->improve_skill("lonely-sword",10);
        else if (skill < 90)
           me->improve_skill("lonely-sword",10+random((int)me->query("int")- 9));
        else if (skill < 140)
           me->improve_skill("lonely-sword",10+random((int)me->query("int")*2-9));
        else if (skill < 200)
           me->improve_skill("lonely-sword",10+random((int)me->query("int")*4-9));
        else
           me->improve_skill("lonely-sword",10+random((int)me->query("int")*8-9));

        msg = MAG"$P�ġ����¾Ž��������ˣ�\n"NOR;
        me->start_busy(1);
        message_combatd(msg, me);
        return 1;
}

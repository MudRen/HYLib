// qianshou ǧ������
// bren

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
void back(object target, int skill);
int perform(object me, object target)
{
        string msg;
        int skill;
        skill = (int)me->query_skill("qianye-shou", 1)/3;;
         skill = 1;;

        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("��ǧ��������ֻ����ս���жԶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("ʹ�á�ǧ��������ʱ˫�ֱ�����ţ�\n");

        if( (int)me->query_skill("qianye-shou", 1) < 150 )
                return notify_fail("�������ǧҶ�ֲ�����죬����ʹ�á�ǧ����������\n");

        if( (int)me->query_skill("yijinjing", 1) < 150 )
                return notify_fail("����׽�ڹ��ȼ�����������ʹ�á�ǧ����������\n");

        if( (int)me->query_dex() < 25 )
                return notify_fail("���������ǿ������ʹ�á�ǧ����������\n");

        if (me->query_skill_prepared("hand") != "qianye-shou"
        || me->query_skill_mapped("hand") != "qianye-shou")
                return notify_fail("�������޷�ʹ�á�ǧ�����������й�����\n");                                                                                 
      

        if( (int)me->query("neili") < 500 )
                return notify_fail("����������̫��������ʹ�á�ǧ����������\n");

        if( target->query_temp("qianshou")   )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɡ���\n");

        msg = HIY "$N˫�ֺ�ʮ��������Ȼ����һ�֣�˫�ƶ�ʱ�������Ʈ�ݣ��鶯�쳣����ʱ�����������Ӱ��\n" NOR;
        message_vision(msg, me, target);

        msg = HIR "$nֻ�������ܶ���$N����Ӱ�����ɵû���������\n" NOR;
        message_vision(msg, me, target);

        target->add_temp("apply/attack", -skill);
        target->add_temp("apply/dodge", -skill);
        target->add_temp("apply/parry", -skill); 
        target->set_temp("qianshou",1);   
        me->add("neili", -300);
        target->start_call_out( (: call_other, __FILE__, "back", target, skill :),skill/10);

        if( me->is_fighting() ) me->start_busy(2);

                              
        return 1;
}

void back(object target, int skill)
{
        target->add_temp("apply/attack", skill);
        target->add_temp("apply/dodge", skill);
        target->add_temp("apply/parry", skill);
        target->delete_temp("qianshou");
        tell_object(target, HIB"�㽥����Ӧ�����ֱ仯��״̬�ָֻ��糣��\n"NOR);
}

        


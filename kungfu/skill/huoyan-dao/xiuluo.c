// by snowman

#include <ansi.h>
inherit F_SSERVER;

int perform(object me, object target)
{
      int i, jiali;

       if( !target ) target = offensive_target(me);
       if( !target
        || !target->is_character()
        || !me->is_fighting(target) 
        || !living(target))
                return notify_fail("�������桹����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

       if (me->query_temp("weapon"))
           return notify_fail("�������桹�ǿ��־�����������������ʹ�������ģ�\n");

        if(me->query_skill("huoyan-dao", 1) < 130 )
                return notify_fail("��Ļ��浶����Ӳ������⡸�����桹��������Ҳ�ա�\n");

        if(me->query_skill("strike", 1) < 130 )
                return notify_fail("��Ļ����Ʒ���������죬ʹ�����������桹������\n");

        if( (int)me->query_con() < 34)
                return notify_fail("������廹����ǿ׳��ǿʹ�������桹�����������Է٣�\n");

        if(userp(me) && (int)me->query_skill("xiaowuxiang", 1) < 100 )
                return notify_fail("���С���๦�ȼ������ߣ�ʹ�����������𡹡�\n");

       if (me->query("max_neili") < 1500)
           return notify_fail("���������Ϊ�������⡸�����桹��������Ҳ�ա�\n");

       if (me->query("neili") < 1000)
           return notify_fail("����Ŀǰ�������������⡸�����桹��������Ҳ�ա�\n");

       if (me->query("jing") < 200)
           return notify_fail("��ľ���������\n");
       if(me->query_temp("combat_yield"))
           return notify_fail("Ŷ���������������򲻻����ء�\n");

        me->add("neili", -200);
     
        message_vision(HIR"\nͻȻ$N˫�ƴ��˼��ֻ꣬�����������죬�����浶����$P��ǿ�ھ��Ķ�Ȼ���֮�����ƴ�ʢ��������������ε��������һƬ�������������޽���������$nֱ�����£�\n"NOR,me,target);      

        i = me->query_skill("force") / 2 * (3+random(6));        
        jiali = me->query("jiali");

        me->set("jiali", i);
        me->add_temp("apply/attack", 80);
        me->add_temp("apply/damage", 500);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add_temp("apply/attack", -80);
        me->add_temp("apply/damage", -500);
        me->set("jiali", jiali);
        if(!me->query_temp("xiuluo")) me->add("neili", -50);
        else me->delete_temp("xiuluo");

        me->start_busy(2);
        return 1;
}


// newpfm.c ���������ŵ�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
int lev;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("[ʮ�����]ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");
                
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("�����������!\n");

        if( (int)me->query_skill("art", 1) < 100 )
                return notify_fail("����ټ������Ե�����˸��������\n");

        msg = HIW "$N�߶�����,һ��[ʮ�����]�������,��ͼ�߽�$n�Ĺ��ơ�\n";
lev=(int)me->query_skill("art", 1);
me->add("neili",-140);
     if (random(me->query("combat_exp"))+(lev*300) > target->query("combat_exp") / 2 )               
{
                msg += GRN " ���$p��$P��������,ֻ����Ҳ����,��Ҳ����,�������,��ʱ�������\n" NOR;
                target->start_busy( (int)me->query_skill("art",1) / 50 + 2 );
        } else {
                msg += HIR"����$p�������,��Ϊ$P����������,ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
        return 1;
}


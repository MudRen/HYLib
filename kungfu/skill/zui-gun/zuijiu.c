// zuijiu.c �������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int drunk, limit, zui, skill;
        if( !target ) target = offensive_target(me);
         if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        drunk = me->query_condition("drunk");
        limit = (me->query("con") + (int)me->query("max_neili") / 50) * 2;
        if( !target->query_temp("zui_baxian") )
               target->set_temp("zui_baxian", 1);
        zui = target->query_temp("zui_baxian");
        skill = (int)me->query_skill("zui-gun") / 15;

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("�������������㣡\n");     

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɢ�\n");

        message_vision(
    GRN "ֻ��$N���һ�ھ�����һʽ��������ơ���Χ��$nһҡһ�ڵ��߶��š�\n" NOR, me, target);

        me->start_busy(1);
        me->add("neili", -200);
        me->add("jing", -10);
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
            drunk > limit/4) {
                 message_vision(
    HIR " $N����ȴ�ǰ������ԣ��������ƣ�ʹ��$n���ְ������Գ��У�\n" NOR, me, target);
                target->start_busy( skill/zui + 2);
        } 
        else if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
            drunk > limit/2) {
                 message_vision(
    HIR " ȴ��$N���°������ԣ��������ƣ�ʹ��$n���ְ������Գ��У�\n" NOR, me, target);
                target->start_busy( skill/zui + 4);
        }
        else {
          message_vision(
    CYN "����$n������$N��������������˿�ȥ��\n" NOR, me, target);
          me->start_busy(2);
        }
        target->add_temp("zui_baxian", 1);
        return 1;
}

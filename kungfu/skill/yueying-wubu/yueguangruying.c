
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[�¹���Ӱ]ֻ����ս����ʹ�á�\n");

        if((int)me->query_skill("yueying-wubu",1) < 40)
                return notify_fail("�����Ӱ�貽����������\n" NOR);
        if ((int)me->query_skill("bahuang-gong", 1) < 60)
                return notify_fail("��İ˻�����Ψ�Ҷ�����Ϊ��������\n");

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ���Թ˲�Ͼ���ŵ������ɣ�\n");

	msg = YEL"$N�����¹��ӳ�䣬�Ų���Ӱ������������ʧ���¹��С�������\n" NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += NOR "���$p��$P�Ƶò�֪���룡\n" NOR;
                target->start_busy((int)me->query_skill("yueying-wubu",1)/50+3);
                me->add("neili", -100);
                       } else {
                msg +=  "���$P�Լ����˸�ͷ���ۻ���\n";
                me->add("neili", -100);
                me->start_busy(2);
        }
        message_combatd(msg, me, target);

        return 1;
}

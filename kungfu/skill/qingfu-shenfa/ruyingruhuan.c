
#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("[��Ӱ���]ֻ����ս����ʹ�á�\n");

        if((int)me->query_skill("qingfu-shenfa",1) < 50)
                return notify_fail("�������������������\n" NOR);

        if((int)me->query("neili") < 400)
                return notify_fail(HIY "�������������㡣\n" HIY);

        if( target->is_busy() )
                return notify_fail(target->name() + "�Ѿ���æ�ˣ�\n");

	msg = YEL"$N���ն��𣬻���һֻ����ʩչ���������$n��ȥ��\n" NOR;

if ((int)me->query_skill("jiuyang-shengong",1) > 50)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 ) {
                msg += NOR "���$p��$P�Ƶò�֪���룡\n" NOR;
                target->start_busy( (int)me->query_skill("qingfu-shenfa",1) / 50 + 4 );
                me->add("neili", -100);
                       } else {
                msg +=  "���$P�Լ����˸�ͷ���ۻ���\n";
                me->add("neili", -100);
if ((int)me->query_skill("jiuyang-shengong",1) > 50)
                me->start_busy(2);
else                me->start_busy(4);

        }
}
else
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += NOR "���$p��$P�Ƶò�֪���룡\n" NOR;
                target->start_busy(5);
                me->add("neili", -100);
                       } else {
                msg +=  "���$P�Լ����˸�ͷ���ۻ���\n";
                me->add("neili", -100);
if ((int)me->query_skill("jiuyang-shengong",1) > 50)
                me->start_busy(2);
else                me->start_busy(4);
        }
        message_combatd(msg, me, target);

        return 1;
}

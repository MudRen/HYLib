// fugu.c ����������-���ǲ���

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("���ǲ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( me->query_temp("weapon"))
                return notify_fail("�㲻�ǿ��֣�����ʹ�ø��ǲ���\n");

        if( (int)me->query_skill("jinshe-zhang", 1) < 100 )
                return notify_fail("��Ľ����Ʋ�����죬����ʹ�ø��ǲ���\n");

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("����������̫��������ʹ�ø��ǲ���\n");

        msg = YEL "$N���һ���������������һ̽��ס$n������������ɱ�֣�"NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "ֻ��$N���ֲ�ͣ����һ�����ߴ���$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N��Ŀ���������Գմ���һ��[���߳���]˫�Ʒ��ش���$n��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->start_busy(4);
        return 1;
}

// you.c ��Ůȭ-��Ĺ�ľ�

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
	object weapon;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("��Ĺ�ľ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("������ȷ������еı�����\n");

        if( (int)me->query_skill("meinv-quan", 1) < 50 )
                return notify_fail("�����Ůȭ���𲻹�������ʹ�ù�Ĺ�ľӡ�\n");

        if( (int)me->query_skill("yunv-xinfa", 1) < 40 )
                return notify_fail("�����Ů�ķ���δ��죬�����������˵С�\n");

        if( (int)me->query("neili", 1) < 150 )
                return notify_fail("����������̫��������ʹ�ù�Ĺ�ľӡ�\n");

        msg = RED "$N����֧�ã���������ӳ�����̾һ����ʹ������Ĺ�ľӡ������ּ���֮�⡣"NOR;

         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -100);
	
       me->start_busy(2);
        return 1;
}

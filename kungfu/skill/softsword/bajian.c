#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("softsword",1);

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail(RED"��ʲô��Ц��ûװ��������ʹ������һЦ����\n"NOR);

        if ((int)me->query_skill("softsword", 1) < 200)
                return notify_fail(WHT"��Ļط��������������죬��ʹ����������һЦ����\n"NOR);

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����°˽���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        msg = HIY  "$N"HIY"ʹ���ط���������еģ����°˽��ݣ�һ�������˽���������е�"+ weapon->name()+  HIY"�������$n�������½���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���ɽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "���콣��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "�μҽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "���Ž���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "ɱ�˽���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "���ֽ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIY  "佻�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 me->add("neili", -300);
        me->start_busy(3);
        return 1;
}

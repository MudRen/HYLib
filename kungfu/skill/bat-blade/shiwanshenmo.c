// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("bat-blade",1);
	if ( extra < 50) return notify_fail("���[���𵶷�]���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��ʮ����ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-200);


	weapon = me->query_temp("weapon");
	msg = MAG  "$N��������ؼ�ʮ����ħ���ޱ�������һʽ��ʮ������ħ ���缱�������$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIB  "$N����"+ weapon->name()+  "�ó�����Ĺ⻪����$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIR  "$N����"+ weapon->name()+  "�����������ǵĺ�Х��$n��ȥ��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIW  "$N����"+ weapon->name()+  "��Ȼ��������Ե���������$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC  "ʮ����ħ�����ƶ����֣�$N����"+ weapon->name()+  "����Ī����Ȼ����$n����ǰ��"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->start_busy(3);
       target->apply_condition("bat",random(10)+10);

	return 1;
}

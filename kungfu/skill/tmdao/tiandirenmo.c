// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	object weapon;
	extra = me->query_skill("tmdao",1);
	if ( extra < 190) return notify_fail("�����ħ�����������죡\n");
	dodskill = (string) me->query_skill_mapped("dodge");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ħ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( !(weapon = me->query_temp("weapon"))
        ||      (string)weapon->query("skill_type") != "blade" )
        return notify_fail("������û��װ������������\n");
        if( (int)me->query("neili")<500)
        return notify_fail("����������̫��������ʹ�ã�\n"NOR);


	weapon = me->query_temp("weapon");
	msg = HIY  "$N������ͨ���������ħ������ʽһ���ǳɣ�\n��ħ���ѣ�" NOR;
	me->set_temp("action_flag", 1);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "ħ�����ɣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "ħ��է�֣�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��ħ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "������ħ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��ħ���죡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��ħ���֣�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "��ħ���ڣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->delete_temp("action_flag");
	me->add("neili", -350);
	me->start_busy(2);
	return 1;
}

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,damage;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
        extra = me->query_skill("dusha-zhang", 1);
        if ( extra < 180) return notify_fail("��������书���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����а��ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");


        msg = HIB  "$N����Ȼ�ӿ죬����а���Ƶ���ʽ����$n��ͷ���״���һ�飡\n\n" NOR;
	message_vision(msg,me,target);

        damage=random(extra)+50;
        extra=extra/2;
        if (extra> 200) extra=200;

	message_vision("$N�Ųȹ��췽λ����$n��ǰ�ó������Ӱ��\n",me,target);
	        if( random(target->query("combat_exp")) < (int)me->query("combat_exp") / 2 ) {
                target->start_busy(3);
        message_vision("���$N���ŵ��ۻ����ң���֪���룡\n", target, me);
        }

        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage",-extra*10);
        msg = GRN  "�������ǣ�\n"NOR + HIG"$N������ϣ����ƴ�������$n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "���Ƹ��꣡\n"NOR + HIY"$N���ƻ���Ϊʵ����$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "�������룡\n"NOR + HIR"$Nһ������$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU  "����ǵأ�\n"NOR + HIB"$N˫��һ����������$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "�������У�\n"NOR + HIM"$N����������ǰ�������Ƴ�����$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "���κ��ˣ�\n"NOR + HIC"$N������շ��𣬴ӿ��е�ͷ���ƹ���$n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",extra*10);
	      me->add_temp("apply/attack", -extra);
	me->add("neili",-300);
	me->start_busy(3);
	return 1;
}

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
        int extrb;
	object weapon;
	 extra = me->query_skill("lansha-shou",1);
   if ( extra < 300) return notify_fail("��ģ���ɰ�֣ݻ��������죡\n");

        extrb = me->query("force");

    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");
        if (extra> 200) extra=200;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۵����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
        msg = HIB "$N����������� ���������ӣ��� ��ʹ���۵���������ݣ�һ������ʮ������\n\n" NOR;
	message_vision(msg,me,target);
        msg = HIB "ʮ��������ãã��\n"NOR + HIC"$N����Զ���������ᣬ����$nһ��ʱ��Ȼ���ֹ���$n��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "��˼������������\n"NOR + HIC"$N����$n����֧ͷ������������һ�ӣ�һ������ֱ��$n��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "ǧ��·أ��޴���������\n"NOR + HIC"$n��ǰһ������ʱʧȥ��$N����Ӱ��ֻ��һ�������Ӻ�ֱ��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "��ʹ���Ӧ��ʶ��\n"NOR + HIC"$Nӭ����$nײȥ��˫��΢����ͬʱ����$n��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "�����棬����˪\n"NOR + HIC"ֻ��$N��ͷ�ĺڷ��������𣬴���$n��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "ҹ�����κ����磬\n"NOR + HIC"$N����ͻת�����з������˻��ǵ����䣬����ȴ����$n��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "С����������ױ��\n"NOR + HIC"$N˫��ֱ�ᣬʮָ�ſ���ץ��$n��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "������ԣ�Ω����ǧ�У�\n"NOR + HIC"$n��ͷһ��$N����֪��ʱ�ѵ������ǧ��ָ�������ŷ���$n��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "�ϵ�����ϳ�����\n"NOR + HIC"$N����Ϊ������������ǰ����������������һ�����������ƿ���$n��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB "����ҹ�����ɸԣ�\n"NOR + HIC"$N�������죬���ľ���һ�£�������������̵Ľ�ˮ����������$n��$l"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-580);
        me->start_busy(5);
	return 1;
}

// ning@fengyun
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp;
	object weapon;
        extra = me->query_skill("wuzhan-mei",1);
        if ( extra < 280) return notify_fail("��ģ���չ÷�ݻ��������죡\n");



	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("���仨����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("����������̫��������ʹ�á��꼤÷������㡹��\n");

	if(me->query_skill("wuzhan-mei")<300)
	return notify_fail("�����չ÷������죬�������á��꼤÷������㡹��\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");


	weapon = me->query_temp("weapon");
        msg = HIW"$N��ϣ�÷������˫��һ�٣���ֱԾ������"+ weapon->name() + HIW"��ͣ�ز�����\n�����������ģ��� ɪ��һʫ��������ס$nȫ��\n\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "��ɪ�޶���ʮ�� \n" NOR + CYN "$N��������Ʈ������$w"NOR + CYN"����ʵʵ�׷���������$n��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "һ��һ��˼���� \n" NOR + CYN "$N������$n����һ�Σ�����$w"NOR + CYN"����һ�佣������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "ׯ�������Ժ��� \n" NOR + CYN "$N������$nһת������$w"NOR + CYN"����һָ���ó����콣Ӱ������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "���۴����жž� \n" NOR + CYN "$N����ƮȻ������Ȼһ������$w�������޵�������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "�׺����������� \n" NOR + CYN "$N�������࣬ͷ�½��ϣ�����$w"NOR + CYN"���һ����������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "������ů������ \n" NOR + CYN "$N����$w"NOR + CYN"����΢�񣬻ó�һ���׹����$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         me->add_temp("apply/damage",2000);
        msg = HIW  "����ɴ���׷�� \n" NOR + HIC "$N��������Ծ�𣬽�����ˮ��һкǧ�����$nȫ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "ֻ�ǵ�ʱ��ãȻ \n" NOR + HIC "$N����$w"NOR + HIC"һ����������Ϣ�ػ���$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-2000);
me->add("neili",-380);
        me->start_busy(5);
	return 1;
}

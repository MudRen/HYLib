// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int orforce;
	object weapon;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
        extra = me->query_skill("liumang-quan",1);
	if ( extra < 190) return notify_fail("�����å��ȭ���������죡\n");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���Ƹ����ۣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("�������������㣬����ʹ�ã�\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����书ֻ�ܿ���ʹ�á�\n");		
		
	orforce = (int) me->query("neili");
	me->add("neili",extra);
extra=extra/3;
if (extra> 200) extra=200;
	me->add_temp("apply/attack",extra);
if (random(3)==0) target->start_busy(3);
	weapon = me->query_temp("weapon");
        msg = HIY  "$Nʹ���������µ���å��ȭ��һ��[�Ƹ�����]�Դ�һ˿��ϧ֮ɫ��$n������\n" NOR;
	message_vision(msg,me,target);
        msg = HIC "��һȭ------Ц���߽�һָ�ɣ�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "�ڶ�ȭ------Ҷ��������ɽ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------�����������ͷ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------����̫����������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------���¹����忴�أ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------ãã��ˮ�����죡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "����ȭ------Ц��Ҷ�俴���ƣ�������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "���һȭ----���׻�������ˮ��������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(3);

        me->add_temp("apply/attack",-extra);

	return 1;
}

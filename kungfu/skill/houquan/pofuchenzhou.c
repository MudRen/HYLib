// tie@fengyun
// updated force->neili, force_factor->jiali (by xbd)

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
	extra = me->query_skill("houquan");
       if( (int)me->query_skill("houquan", 1) < 200 )
		return notify_fail("��ĺ�ȭ�������!\n");
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���Ƹ����ۡ�ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 800  ) 
		return notify_fail("�������������\n");

	if( (int)me->query_skill("yunlong-shengong", 1) < 100 )
		return notify_fail("��������񹦲����ߡ�\n");


	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���Ƹ����ۣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->add("jiali",extra/3);
	orforce = (int) me->query("force");
//	me->add("neili",extra/3*100);
	me->add_temp("apply/attack",80);
	me->add_temp("apply/damage",extra*2);

	weapon = me->query_temp("weapon");
	msg = HIY  "$Nʹ���������µģۺ�ȭ�ݣ�һ��[�Ƹ�����]����˵�һʽ��\n" NOR;
	message_vision(msg,me,target);
	msg = HIC  "��һȭ------Ц���߽�һָ�ɣ�" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "�ڶ�ȭ------Ҷ��������ɽ����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "����ȭ------�����������ͷ������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC  "����ȭ------����̫����������������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "����ȭ------���¹����忴�أ���������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "����ȭ------ãã��ˮ�����죡����������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg = HIC "����ȭ------Ц��Ҷ�俴���ƣ�������������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIC "���һȭ------���׻�������ˮ����������������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);me->start_busy(6);
        me->start_busy(3);
	me->set("jiali",0);
//	me->set("neili", orforce);
        me->add_temp("apply/attack",-80);
        me->add_temp("apply/damage",-extra*2);
	me->add("neili", -500);
	return 1;
}

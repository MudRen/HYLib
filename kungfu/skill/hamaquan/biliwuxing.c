#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("hamaquan",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("���������Ρ�ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("���������Ρ�ֻ�ܿ���ʹ�á�\n");		
       
	 if( (int)me->query("neili") < 100 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("hamaquan",1) < 20 )
                return notify_fail("��ĸ��ȭ��򲻹����޷�ʹ�á��������Ρ���\n");

        if( (int)me->query_skill("force",1) < 100 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á��������Ρ���\n");
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra/2);
	weapon = me->query_temp("weapon");

        msg = BLU "$N�Ųȸ�󡲽���������ɳ��⣬����ͣ�٣�ͻȻ��ȭ����$n�����������������֮ʽ��" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-extra/2);
	 me->add_temp("apply/damage",-extra/2);
        me->add("neili", -100);
        me->start_busy(2);
        return 1;
}


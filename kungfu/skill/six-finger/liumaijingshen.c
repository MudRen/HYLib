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
	extra = me->query_skill("six-finger",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����������ֻ����ս����ʹ�á�\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("����������ֻ�ܿ���ʹ�á�\n");		

        if (me->query_skill("kurong-changong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");
       	if(me->query_skill_mapped("force") != "kurong-changong")
		return notify_fail("û�п���������Ϊ׼�����޷�ʹ����\n"); 
	 if( (int)me->query("neili") < 600 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("six-finger",1) < 180 )
                return notify_fail("��������񽣻�򲻹����޷�ʹ�á��������񡹣�\n");

        if( (int)me->query_skill("force",1) < 150 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á��������񡹣�\n");
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra*2);
	weapon = me->query_temp("weapon");

        msg = CYN "$N��˼���ң���$n����ңָ�˼��£�����ȴʹ�������������ľ���"HIY"[��������]"CYN"��" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------------------------���̽���" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = GRN   "-------------------------------��������" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  MAG  "-------------------------------�г彣��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL   "-------------------------------�س彣��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT   "-------------------------------���󽣣�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU   "-------------------------------�ٳ彣��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-extra);
	 me->add_temp("apply/damage",-extra*2);
        me->add("neili", -500);
        me->start_busy(3);

        return 1;
}


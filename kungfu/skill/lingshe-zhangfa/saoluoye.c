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
	extra = me->query_skill("lingshe-zhangfa",1);
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("�����ɨ��Ҷ��ֻ����ս����ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");
       
	 if( (int)me->query("neili") < 1200 )
                return notify_fail("�������������\n");

	if( (int)me->query_skill("hamagong", 1) < 100 )
		return notify_fail("��ĸ�󡹦�������.\n");

        if( extra < 200 )
                return notify_fail("��������ȷ���򲻹����޷�ʹ�á����ɨ��Ҷ����\n");

        if( (int)me->query_skill("force",1) < 180 )
                return notify_fail("����ڹ���Ϊ�������޷�ʹ�á����ɨ��Ҷ����\n");
	me->add_temp("apply/attack",(extra/3));
	me->add_temp("apply/damage",(extra/2));
	weapon = me->query_temp("weapon");

        msg = HIY "$N���������⣬ͻȻһ�����ȣ���------ �� ----- �� ----- ɨ ----- �� ----- Ҷ ----- ��������" NOR;
	         message_vision(msg, me, target);                
	 msg =  YEL  "$N���μӿ죬����֮�����������" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  YEL  "$Nͻ�������Ĵӿ��������������$n��ǰ����һ�ȣ�" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N���Ȼ�������$n��࣬����һ����" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N����������һ�������Ӹ����£���ͷ����һ�ȣ�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "���ڰ�գ�$N����Ϊ�ƣ���ʵΪ�ȣ���$n��̹�ȥ��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL "$N�������裬�ܲ�͸�磬ʹ$n�����е�͸����������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = YEL "$N���л��ɳˣ�һ�Ƚ���һ�ȣ�����������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = YEL "$N�������֮���������е�"+ weapon->name() +"����ǧ����˳�$n��ȥ��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack",-(extra/3));
	 me->add_temp("apply/damage",-(extra/2));
if (extra > 250
&&  random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
{
	 msg = RED "�߶�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("snake_poison",10);
	 msg = RED "��ܶ�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("chanchu_poison",10);
	 msg = RED "�����߶�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("qx_snake_poison",20);
}
        me->add("neili", -500);
        me->start_busy(4);

        return 1;
}


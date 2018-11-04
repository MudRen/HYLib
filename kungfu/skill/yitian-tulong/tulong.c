#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
	object obj;
	string msg;
	int damage;
        int extra;
	object weapon;
	if( !target ) target = offensive_target(me);
        
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if((int)me->query_str() < 30)
		return notify_fail("���������,����ʹ����һ����!\n");

        if ((int)me->query_skill("yitian-tulong", 1) < 199)
                return notify_fail("��ġ����������������̫ǳ��\n");

        if ((int)me->query_skill("anranxiaohun-zhang", 1) > 1)
                return notify_fail("���С���Ȼ�����ơ��ò������!\n");


        if ((int)me->query_skill("taiji-shengong", 1) < 250)
                return notify_fail("��ġ�̫���񹦡����̫ǳ��\n");

        if ((int)me->query_skill("taiji-quan", 1) < 250)
                return notify_fail("��ġ�̫��ȭ�����̫ǳ��\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

	if((int)me->query("neili") < 800)
		return notify_fail("���������ڲ���, ����ʹ����������! \n");

	extra = me->query_skill("yitian-tulong",1) / 3;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", (extra+200));

	msg = HIY "$N��Хһ����" + YEL "�������𡢱����������������£�Ī�Ҳ��ӡ����첻����˭�����棿\n" + HIY "������������������������������������ڣ����������������������ʮ����һ��д�ϡ�\n"NOR;
        message_vision(msg, me, target);
	msg = HIW "���У�\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY "�У�\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY "�죡\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY "����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	msg = HIY "����\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        me->add("neili",-300);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -(extra+200));
        me->start_busy(2);
	if (random(me->query("combat_exp")) > target->query_skill("combat_exp")/3 )
	{
		
		damage = (int)me->query_skill("yitian-tulong", 1);
		
                damage = 100 + damage + random(damage/2);
		
		target->receive_damage("qi", damage*2);
		target->receive_wound("qi", damage);
                me->add("neili", -damage/2);
		
		if( damage < 100 )
			msg = HIY"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
        else if( damage < 200 )
			msg = HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
        else if( damage < 300 )
			msg = RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
		else
			msg = HIR"���$n��$N������һ����ǰһ�ڣ���һ������һ���ɳ�ȥ�ü���Զ��\n"NOR;
		
	}
	message_vision(msg, me, target);

	return 1;
}

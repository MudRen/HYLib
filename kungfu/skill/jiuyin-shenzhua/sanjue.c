// sanjue ��������צ

#include <ansi.h>
#include <combat.h> 
inherit F_SSERVER;

int perform(object me, object target)
{
        int exp, str, dex, skill, i, damage;
	string msg;
        exp = (int)me->query("combat_exp");
        str = (int)me->query("str");
        dex = (int)me->query("dex");
        skill = (int)me->query_skill("jiuyin-shenzhua", 1);
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("����������צ��ֻ����ս����ʹ�á�\n");
        if( me->query_temp("weapon"))
                return notify_fail("������������ô��ʹ�á���������צ����\n");   
        if(me->query_skill("jiuyin-zhengong",1) < 150 )
                return notify_fail("��ľ����湦��������죬ʹ��������������צ��������\n");
        if( skill < 150 )
                return notify_fail("��ľ�����צ��������죬ʹ��������������צ��������\n");
        if ( skill < 200 ) i = 3;
        if ( skill < 300 ) i = 3;
        else i = 3;
        if ( me->query_skill_mapped("claw") != "jiuyin-shenzhua" )
               return notify_fail("�������޷�ʹ�á���������צ����\n");
        if( (int)me->query("max_neili") < 800 )
                return notify_fail("����������̫����ʹ��������������צ����\n");      
        if( (int)me->query("neili") < 1100 )
                return notify_fail("����������̫����ʹ��������������צ����\n");
        me->start_perform(2, "��������צ");
        message_vision(HIR"\n$N�ֱ�ͻȻ�쳤����$nץȥ��\n"NOR,me,target);
        message_vision(RED"\n$N��ʹ���ƺ��ǽ����г�����������������׹�צ����������������������ǿ����\n"NOR,me,target);
	if (!target->is_busy()) target->start_busy(1);
        me->add_temp("apply/strength",str/i);
        me->add_temp("apply/dexerity",dex/i);
        me->add("neili", -600);
        me->add_temp("apply/attack", skill/i);
        me->add_temp("apply/damage", skill/i);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
        me->add_temp("apply/damage", -skill/i);
        me->add_temp("apply/attack", -skill/i);
        me->add_temp("apply/strength",-str/i);
        me->add_temp("apply/dexerity",-dex/i);

	msg = HIB "\n$Nһ����Х������$n��ת��Ȧ������ʩչ�����ݽ��ƹǡ���˫צ�����ֱ��$nǰ�ء�\n"NOR;
	if (userp(target))
{
	if (	random(me->query("combat_exp")) > target->query("combat_exp")/3	)
{
		msg += HIR"$N����$nǰ��������������������ָ����$nֻ���ؿھ�ʹ����Ѫ�������������\n"NOR;
		damage = skill * 4 + random(skill);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		me->add("neili", - 600);
	} else {
		msg += HIY"$Nֻ��$n�������˫צ�����ܹ��ض��롣\n" NOR;
	}
	message_vision(msg, me, target);
        me->start_busy(2 + random(i));
if (userp(target)) me->start_busy(4);
}
else{if (random(me->query("combat_exp")) > target->query("combat_exp")/3) {
		msg += HIR"$N����$nǰ��������������������ָ����$nֻ���ؿھ�ʹ����Ѫ�������������\n"NOR;
		damage = skill * 4 + random(skill);
		target->receive_damage("qi", damage);
		target->receive_wound("qi", damage/3);
		if( damage < 300 ) msg += HIY"\n���$n��ɫһ�±�òҰף��������������˺ü�����\n"NOR;
        	else if( damage < 400 ) msg += HIY"\n������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"NOR;
        	else if( damage < 500 ) msg += RED"\n������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"NOR;
        	else msg += HIR"\n���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n"NOR;
		me->add("neili", - 600);
	} else {
		msg += HIY"$Nֻ��$n�������˫צ�����ܹ��ض��롣\n" NOR;
	}
	message_vision(msg, me, target);
        me->start_busy(2 + random(i));
if (userp(target)) me->start_busy(4);
}
        return 1;
}

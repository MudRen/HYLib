//by congw
// qu.c perform laincheng-jian
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{      object weapon;
       object obj;
       string msg;
	int extra;
	extra = me->query_skill("liancheng-jian",1) / 23;
	extra += me->query_skill("liancheng-jian",1) /23;

    if( !target ) target = offensive_target(me);
if( !target || !target->is_character() || !me->is_fighting(target) )
return notify_fail("ȥ����ֻ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("����������̫����\n");

if(me->query_skill("liancheng-jian")<30)
return notify_fail("������ǽ���������죬����ʩ�á�ȥ���־���\n");
if (!objectp(weapon = target->query_temp("weapon")))
return notify_fail("���ֲ�û��ʹ��������\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("��ʹ�õ��������ԡ�\n");
me->add("neili",-100);
msg =  HIW"$N��Хһ������ֱ���еı��У������ǽ����ġ�ȥ���־�˳�ƴ�����$n�ı�����\n"NOR;
if( !target->is_killing(me) ) me->kill_ob(target);
me->start_busy(2);
if( random( (int)me->query("combat_exp",1))
> target->query("combat_exp") /3 )  {
msg +=HIY"ֻ����һ���������֮�������$p�ı��б�$P���еı���һ��һ����ԶԶ�ط��˿�ȥ��\n" NOR;
obj=target->query_temp("weapon");
obj->move(environment(me));
message_vision(msg, me, target);
msg = HIR  "$Nһ���֣����Ͻ��ż����������Ļ���$n��" NOR;
msg = HIW  "��һ����" NOR;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIG  "��һ����" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIY  "��һ����" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg = HIC  "��һ����" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);
//destruct(obj);
} else {
msg += "����$p������$P����ͼ����û���ϵ���\n" NOR;
me->start_busy(2);
message_vision(msg, me, target);
}
return 1;
}

// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
int extra;
	object weapon;
	string msg;
	extra = me->query_skill("shedao-qigong",1);
	if( !target ) target = offensive_target(me);

	if( environment(me)->query("no_fight") )
		return notify_fail("���ﲻ�ܹ�������! \n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���߾�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( !target || !target->is_character() )
		return notify_fail("���߾�ֻ�ܶԶ���ʹ�á�\n");

        if ((int)me->query_skill("shedao-qigong", 1) < 200 )
		return notify_fail("����ߵ��湦�ȼ�����, �����ô˾��У�\n");

        if ((int)me->query_skill("shenlong-xinfa", 1) < 200 )
        return notify_fail(RED"�������ķ���򲻹���ʹ���������ΰ˴򡹡�\n"NOR);

        if (me->query_skill_mapped("force") != "shenlong-xinfa")
                return notify_fail("��û�м��������ķ�Ϊ�ڹ����޷�ʩչ��\n");
                
	if( (int)me->query("neili", 1) < 400 )
		return notify_fail("������������������綾��\n");

	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff"
	)
            return notify_fail("��ʹ�õ��������ԡ�\n");

        me->add("neili", -200);
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",2*extra);
        msg = HIY "$Nʹ���������ľ������߾�!\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIG "$N���쳤Х��������У�����������Ψ�Ҳ��ܣ�\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        msg = HIW "$N���쳤Х��������У�����������Ψ�Ҳ��ܣ�\n" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);

	me->add_temp("apply/attack",-extra);
	 me->add_temp("apply/damage",-2*extra);

	msg = HIR "$N���������дʣ����֮���书������߸�Ծ��$P���о޶�����Ѫ����$nȫ����ȥ!\n";

        if( (random(me->query("combat_exp"))) >(int)target->query("combat_exp")/3 )
        {
		msg += MAG "���$p���޶�����Ѫ���С�n" NOR;
	msg += HIR "$pֻ�ŵ�һ��ͷ�裬�����³�һ�����Ѫ��\n" NOR;
	msg += HIC "$p������ð��������������������ǰ�趯����\n" NOR;
	message_combatd(msg, me, target);

         if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3)
        {                
        msg = HIW "��һ������"+HIR+"����$n������\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",10);
        }
        if (random(me->query("combat_exp"))> target->query("combat_exp")/3 )
        {                
        msg = HIC "�ڶ�������"+HIM+"ɨ��$n������\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",10);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 3)
        {                
        msg = MAG "���һ������"+HIB+"ɨ��$n������!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",10);
        }
	target->apply_condition("ill_fashao",20);
	target->apply_condition("ill_kesou",20);
	target->apply_condition("ill_shanghan",20);
	target->apply_condition("ill_zhongshu",20);
	target->apply_condition("ill_dongshang",20);

if ((random(me->query("combat_exp"))+extra*800) >(int)target->query("combat_exp")/2 )
{
        target->add("jing",-(target->query("jing")/4));
        target->add("eff_jing",-(target->query("eff_jing")/4));
        target->add("qi",-(target->query("qi")/4));
        target->add("eff_qi",-(target->query("eff_qi")/4));
        msg = RED "$nȫ��������������"+HIR+"�����³�������Ѫ!\n"NOR;   
}
else {

	target->receive_damage("qi",(int)me->query_skill("shedao-qigong",1)*2);
	target->receive_wound("qi",(int)me->query_skill("shedao-qigong",1));
	target->receive_wound("jing", 50);
}
	message_combatd(msg, me, target);
        me->add("neili", -300);
	me->start_busy(3);
	} else {
		msg += CYN"����$p��æ����һ�ԣ����˿�ȥ��\n" NOR;
		me->start_busy(3);
		message_combatd(msg, me, target);
	}
if (random(5)==0 && (int)me->query_skill("shedao-qigong",1) > 300
&& (int)me->query_skill("zhaosheshu",1) > 200
&& (int)me->query_skill("yangsheshu",1) > 200)
{
	message_combatd(
        HIW "$N�� �������ͨ���ս�޲�ʤ�����޲��ˣ��޼᲻�ݣ��޵в��ƣ�
$n��һ���������֣�$n�Ŀ�һ���ʹ��\n" NOR, me, target);
target->apply_condition("shenlong_poison",50);
}
//	if( !target->is_killing(me) ) me->kill_ob(target);
	return 1;
}

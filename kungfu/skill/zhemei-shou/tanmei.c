// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,damage;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("����÷.��ѩ.ɢ���㡿ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	myexp = (int) me->query("combat_exp");
	yourexp = (int) target->query("combat_exp");
	lvl = (int) me->query_skill("zhemei-shou") / 10 + 1;
	damage = (int)me->query_skill("zhemei-shou", 1)/4;  
         if( (int)me->query_skill("bahuang-gong", 1) < 150 )
                 return notify_fail("��İ˻����Ϲ��ȼ���������\n");
         if( (int)me->query_skill("force") < 150 )
                 return notify_fail("����ڹ��ȼ�������\n");

 if( (int)me->query_skill("zhemei-shou", 1) < 120 )
                return notify_fail("�����ɽ��÷�ֲ�����죬����ʹ�á���÷.��ѩ.ɢ���㡿��\n");

        if( (int)me->query_skill("bahuang-gong", 1) < 150 )
                return notify_fail("���Ψ�Ҷ����𹦵ȼ�����������ʹ�á���÷.��ѩ.ɢ���㡿��\n");  if (me->query_skill_prepared("hand") != "zhemei-shou"
        || me->query_skill_mapped("hand") != "zhemei-shou")
                return notify_fail("�������޷�ʹ�á���÷.��ѩ.ɢ���㡿���й�����\n");            
	if( (int)me->query("neili") < 500 )
    return notify_fail("�������������\n");
  
	if( (int)me->query("max_neili") < 2000 )
    return notify_fail("���������Ϊ̫�\n");
  if( (int)me->query("jing") < 200 )
    return notify_fail("��ľ���������\n");
  
me->add_temp("apply/damage", damage);
 me->add_temp("apply/strength", damage);
  me->add_temp("apply/attack", damage); 
msg = YEL "$N΢΢һЦ��������$n���ᵯ����������Ҫ��ȥ÷�������¶�飡" NOR;
COMBAT_D->do_attack(me,target, weapon, 1,msg);                                             message_vision(HIW"                                          ���� ÷��"NOR, me, target); 
msg = YEL "$N˫�ּ��ӣ�����ҡ�ڣ��ó�����÷������ѩ�Ƶ���$n������" NOR;
COMBAT_D->do_attack(me,target, weapon, 2,msg);                                           message_vision(HIW"                                          ���� ѩ��"NOR, me, target); 
msg = YEL "$nͻȻ�ŵ�һ���������޵���ζ����Գ����֮��$N��˫������$p�ؿ�������" NOR;
COMBAT_D->do_attack(me,target, weapon, 3,msg);                                             message_vision(HIW"                                          ��ɢ���㡿\n"NOR, me, target); 
me->add_temp("apply/damage", -damage);
 me->add_temp("apply/strength", -damage);
  me->add_temp("apply/attack", -damage); 
  me->start_busy(2);
  me->add("neili",-350);

if( ( random(me->query("combat_exp")) > target->query("combat_exp")/3 ) 
)
	{msg = HIR "$N˫�ֻó�������Ӱ���������÷������$n������һƬ÷��֮�У�" NOR;
		message_vision(msg + "\n", me, target);
		msg = HIY"���$n��$N���˸���æ���ң�\n"NOR;
                message_vision(msg, me, target);

if (!target->is_busy())
{
		target->start_busy(3+random(2));
		me->add("neili",-100);
}
	} else
{
me->start_busy(2);
}
	return 1;
}

//fireball.c  ��ʥ֮��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(RED"����ʥ֮��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 600)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-fire",1)< 200)
	return notify_fail("��Ļ�ϵħ��̫���ˣ�\n");

if (target->is_busy())
return notify_fail("���������ù������˵�ʱ�򰡣�\n");
                me->start_busy(1);
        msg = RED "$N"RED"��������������������..\n"NOR;
        msg += HIY"$N"HIY"�����ҫ�Ľ�ɫʥ���������֮����������\n"NOR;
        msg += HIY"$N"HIY"��������������ò���Ļ����������ҡ�������\n"NOR;
        msg += HIY"$N"HIY"���һ��  ��ʥ֮��!!  ,$n"HIY"�ĸ���ͻȻ��ը�˿���.��\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-fire", 1);
//�Ի�����Ŀ��������
       if ((int)target->query("magicgift")==1)
{
target->start_busy(2);
damagic=damage;
                target->receive_damage("qi", damagic);
damagic=damage;
                target->receive_wound("qi", damagic);
}
//��ˮ����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==2)
{
target->start_busy(8);
damagic=damage*3;
                target->receive_damage("qi", damagic);
damagic=damage;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=damage;
target->receive_damage("qi", damage);
target->receive_wound("qi", damage);
target->start_busy(3);
}

        msg += HIR"$n"HIR"���һ������ը������!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIY"$n"HIY"����Ծ���ӹ���һ�ѡ�\n"NOR;
		message_combatd(msg, me, target);
                me->start_busy(3);
        }
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
                me->add("neili", -300);
        return 1;
}


#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIC"���������硹ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 600)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-ice",1)< 200)
	return notify_fail("�����ϵħ��̫���ˣ�\n");

if (target->is_busy())
return notify_fail("���������ù������˵�ʱ�򰡣�\n");
                me->start_busy(1);
        msg = HIC "$N"HIC"��������������������..\n"NOR;
        msg += HIC"$N"HIC"���ѣĿ��������������һ���޴����赲��������\n"NOR;
        msg += HIC"$N"HIC"����ƿն�ȥ�Ĺ�֮��ì�����̴��ޱߵĺڰ���������\n"NOR;
        msg += HIC"$N"HIC"���һ��  ��������!!  ,$n"HIC"�ĸ���������һ����������.��\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-ice", 1);
//��������Ŀ��������
       if ((int)target->query("magicgift")==3)
{
target->start_busy(2);
damagic=damage;
                target->receive_damage("qi", damagic);
damagic=damage;
                target->receive_wound("qi", damagic);
}
//��������Ŀ��ǿ��
else  if ((int)target->query("magicgift")==4)
{
target->start_busy(8);
damagic=damage*2;
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

        msg += HIR"$n"HIR"���һ����������򵽶�������!!\n"NOR;
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


#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIC"����������ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 600)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-ice",1)< 150)
	return notify_fail("�����ϵħ��̫���ˣ�\n");

        msg = HIC "$N"HIC"��������������������.\n"NOR;
        msg += HIC"$N"HIC"� ѣĿ������������һ���޴����赲����$n"HIC"��$n"HIC"����һ������!�����Ծ��\n"NOR;
        msg += HIC"$N"HIC"���һ��  �׻�!!  ,���ϵ���һ��������$n"HIC"��ȥ���������.��\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-ice", 1);
//��������Ŀ��������
       if ((int)target->query("magicgift")==3)
{
damagic=200+damage;
                target->receive_damage("qi", damagic);
damagic=150+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
//��������Ŀ��ǿ��
else  if ((int)target->query("magicgift")==4)
{
damagic=1800+damage*4;
                target->receive_damage("qi", damagic);
damagic=1800+damage*2;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
else 
{
damagic=350+damage;
target->receive_damage("qi", 350+damage*2);
target->receive_wound("qi", 350+damage);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}

        msg += HIR"$n"HIR"����û����ܣ�һ������,�˶���\n"NOR;
        msg += HIR"������$n"HIR"�����ϣ�!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIG"����$p"HIG"����һЦ��������ת.\n"NOR;
        msg += HIG"������$p"HIG"��໮�����������ˡ�\n"NOR;
		message_combatd(msg, me, target);
        }
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
                me->start_busy(2);
                me->add("neili", -250);
        return 1;
}

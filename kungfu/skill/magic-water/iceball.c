//iceball ������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(WHT"����������ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 600)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-water",1)< 150)
	return notify_fail("���ˮϵħ��̫���ˣ�\n");

        msg = WHT "$N"WHT"��������������������.���н���������һ�ű���.���򽥴�.\n"NOR;
        msg += WHT"$N"WHT"��������,��֪�������Ѷ�׼��$n"WHT"��$n"WHT"�������캮���������Ծ��\n"NOR;
        msg +=WHT "$N"WHT"����.��ѩ�ľ��鰡����Ϊ˺���ߣ������ҵĵ��˰ɣ�������\n"NOR;
        msg += WHT"$N"WHT"���һ��  ������!!  ,���еĺ�����ֱ��$n"WHT"��ȥ���������.��\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-water", 1);
//��ˮ����Ŀ��������
       if ((int)target->query("magicgift")==2)
{
damagic=100+damage;
                target->receive_damage("qi", damagic);
damagic=50+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
//�Ի�����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==1)
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
damagic=550+damage;
target->receive_damage("qi", 550+damage*2);
target->receive_wound("qi", 550+damage);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}

        msg += WHT"$n"WHT"����û����ܣ�һ���޴󺮱���,�˶���\n"NOR;
        msg += WHT"������$n"WHT"�����ϣ�$n"WHT"ȫ����ס��!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIY"����$p"HIY"����һЦ��������ת.\n"NOR;
        msg += HIY"��������$p"HIY"��໮�����������ˡ�\n"NOR;
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

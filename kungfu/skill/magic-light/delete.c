//delete ����̽��

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIY"������̽�⡹ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 600)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-light",1)< 150)
	return notify_fail("��Ĺ���ħ��̫���ˣ�\n");

        msg = HIY "$N"HIY"��������������������.$N"HIY"�����ϲ���һ��ө��.\n"NOR;
        msg += HIY"$N"HIY"� ��֮�񰡣����������������ҵ����ɣ���\n"NOR;
        msg += HIY"$N"HIY"��������,��֪�������Ѷ�׼��$n"HIY"��$n"HIY"����һ���׹���������ϳ����Ծ��\n"NOR;
        msg += HIY"$N"HIY"���һ��  ̽��Ⲩ��!!  ,$n"HIY"����������ˣ�\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-light", 1);
//�Թ�����Ŀ��������
       if ((int)target->query("magicgift")==6 )
{
damagic=600+damage;
                target->receive_damage("qi", damagic);
damagic=350+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
//�Ժڰ�����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==5)
{
damagic=1000+damage*4;
                target->receive_damage("qi", damagic);
damagic=1000+damage*2;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
else 
{
damagic=600+damage;
target->receive_damage("qi", 600+damage*2);
target->receive_wound("qi", 600+damage);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}

        msg += HIY"$n"HIY"����û����ܣ�$n�������Χ��!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += YEL"����$p"YEL"����һЦ����ħ������һ��������.\n"NOR;
        msg += YEL"�����ƫ�� $p"YEL"�������ˡ�\n"NOR;
		message_combatd(msg, me, target);
        }
if ((int)target->query("magicgift")==1)
tell_object(me, HIR"\n���˵����������ǻ�\n" NOR);
if ((int)target->query("magicgift")==2)
tell_object(me, HIW"\n���˵�����������ˮ��\n" NOR);
if ((int)target->query("magicgift")==3)
tell_object(me, HIC"\n���˵���������������\n" NOR);
if ((int)target->query("magicgift")==4)
tell_object(me, YEL"\n���˵���������������\n" NOR);
if ((int)target->query("magicgift")==5)
tell_object(me, BLK"\n���˵����������ǰ���\n" NOR);
if ((int)target->query("magicgift")==6)
tell_object(me, HIY"\n���˵����������ǹ⡣\n" NOR);
if (!target->query("magicgift"))
tell_object(me, HIG"\n����û���������ԡ�\n" NOR);


if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
                me->start_busy(2);
                me->add("neili", -300);
        return 1;
}

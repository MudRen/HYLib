//zeroring ���������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIW"�������������ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-water",1)< 700)
	return notify_fail("���ˮϵħ��̫���ˣ�\n");

	msg = HIW "$N"HIW"��������ջ���һ����â�ǣ������૵��������ģ�\n" NOR;
       msg += HIW"$N"HIW"�  ڤ���������������ϵ�ǿ������ע�������ڵ���֮�����ȥ��!!\n"NOR;
msg += HIW"$N"HIW"� ����ɢ������ѩ����������\n"NOR;
msg += HIW"$N"HIW"� �������Ļ������Ļ��չ���������̬������������ �����Ҷ�������\n"NOR;
       msg += HIW"��Ѫ�������У�һ��"HIW"����"HIW"��$n"HIW"��ȥ��\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-water", 1);
//��ˮ����Ŀ��������
       if ((int)target->query("magicgift")==2)
{
damagic=2500+damage;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);

damagic=3000+damage;
                target->receive_wound("qi", damagic);
}
//�Ի�����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==1)
{
damagic=6500+damage*8;
                target->receive_damage("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
damagic=6500+damage*4;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=3000+damage*3;
target->receive_damage("qi", 3000+damage*3);
target->receive_wound("qi", 3000+damage*2);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
target->start_busy(1);
msg += HIW"    \n"NOR;
msg += HIW"������������������������������������   \n"NOR;
msg += HIW"���   ����ԡ�㡤 ��������࣮   \n"NOR;
msg += HIW"�㣮�� ����   �� ����� �㣮��㣮��   \n"NOR;
msg += HIW"�������㣮�㣮�ࡤ���������  ��   \n"NOR;
msg += HIW"������������������������������������   \n"NOR;
msg += HIW"    \n"NOR;        
        msg += HIW"�����������Ӱ�������ɣ�!!$n�ĸ������˱��ĵ���!!\n"NOR;
        msg += HIW"$nȫ����������������!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
damagic=1500+damage;
                target->receive_damage("qi", damagic);
damagic=1000+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
msg += HIW"    \n"NOR;
msg += HIW"������������������������������������   \n"NOR;
msg += HIW"���   ����ԡ�㡤 ��������࣮   \n"NOR;
msg += HIW"�㣮�� ����   �� ����� �㣮��㣮��   \n"NOR;
msg += HIW"�������㣮�㣮�ࡤ���������  ��   \n"NOR;
msg += HIW"������������������������������������   \n"NOR;
msg += HIW"    \n"NOR;
        msg += HIW"�����������Ӱ�������ɣ�!!$n�ĸ������˱��ĵ���!!\n"NOR;
        msg += HIW"$pʹ��ȫ�����ֿ������������Ǹ��������������ˡ�\n"NOR;
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

                me->start_busy(4);
                me->add("neili", -2000);
        return 1;
}

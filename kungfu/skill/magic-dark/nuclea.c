//nuclea���ں�����

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(BLK"�����ں�������ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 600)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-dark",1)< 150)
	return notify_fail("��ĺڰ�ħ��̫���ˣ�\n");

        msg = HIR "$N"HIR"��������������������.��վ�Ȼ��$N"HIR"�ô�����ħ�������С�͵ĺڶ�.\n"NOR;
        msg += HIR"$N"HIR"��������,��֪�������Ѷ�׼��$n"HIR"��$n"HIR"�����ڶ����Ŀ�ʼ���ںϣ������Ծ��\n"NOR;
        msg += HIR"$N"HIR"� �Ӹ���Ļ��绽�ѵĽ��ϵĺ��װ������赲������ǰ�ĵ��˶���Ϊ�Ҿ��ɣ���\n"NOR;
        msg += HIR"$N"HIR"���һ��  ���ں�����!!  ,$n"HIR"���������˺˱���\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//�Ի�����Ŀ��������
       if ((int)target->query("magicgift")==1 )
{
damagic=600+damage;
                target->receive_damage("qi", damagic);
damagic=650+damage;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
//��ˮ������Ŀ��ǿ��
else  if ((int)target->query("magicgift")==2
||(int)target->query("magicgift")==6)
{
damagic=2800+damage*4;
                target->receive_damage("qi", damagic);
damagic=2800+damage*2;
                target->receive_wound("qi", damagic);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}
else 
{
damagic=900+damage;
target->receive_damage("qi", 900+damage*2);
target->receive_wound("qi", 900+damage);
if (wizardp(me))
tell_object(me, "\n����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
}

        msg += BLK"$n"BLK"����û����ܣ�$n���˺ڰ��ĺ˵���!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += YEL"����$p"YEL"����һЦ����ħ������һ��������.\n"NOR;
        msg += YEL"�˱����� $p"YEL"�������ˡ�\n"NOR;
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
                me->add("neili", -300);
        return 1;
}

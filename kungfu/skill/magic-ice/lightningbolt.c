// tie@fengyun

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	int i;
	object weapon;
        int damage,damagic;

	if( !target ) target = offensive_target(me);

	        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIC"���������硹ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 1000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-ice",1)< 250)
	return notify_fail("�����ϵħ��̫���ˣ�\n");


	extra = me->query_skill("spells",1) / 40;
	extra += me->query_skill("magic-ice",1) /40;
 	if (extra> 33) extra = 33;
        i = extra/4;
        msg = HIC "$N"HIC"���и�����һ��������.$N"HIC"���Ͽ��γ���"+chinese_number(i)+"������.\n"NOR;
        msg += HIC"$N"HIC"� ����˹͡����������յľ��飬����������Լ����������ɣ�������\n"NOR;
        msg += HIC"$N"HIC"��������,���е�"HIC"����"NOR","HIC"ȫ����׼��$n"HIC"�����ȥ!\n"NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
        msg = HIC"    ��"+chinese_number(i+1)+"��"HIC"����!\n"NOR;
        msg += HIC"     ***�� "NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        {
                damage = (int)me->query_skill("magic-ice", 1);
//��������Ŀ��������
       if ((int)target->query("magicgift")==3)
{
damagic=150+damage;
                target->receive_damage("qi", damagic);
damagic=125+damage;
                target->receive_wound("qi", damagic);
}

else  if ((int)target->query("magicgift")==4)
{
damagic=850+damage*3;
                target->receive_damage("qi", damagic);
damagic=850+damage;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=200+damage;
target->receive_damage("qi", 200+damage);
target->receive_wound("qi", 200+damage/2);
}

        msg += HIR"\n  $n"HIR"û����ܣ�������ը�÷���������\n"NOR;
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"\n  $p"HIG"����Ծ�𣬽��������$p"HIC"���±�ը��\n"NOR;
		message_combatd(msg, me, target);
        }

	}
	i = extra/4;
		COMBAT_D->report_status(target);
if (wizardp(me))
tell_object(me, "����ɱ��Ϊ"+damagic+"�㡣\n" NOR);
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
	me->add("neili", - 120 * i);
	me->start_busy(3);
	return 1;
}


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
                return notify_fail(HIB"���������Ǳ���ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 1000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-dark",1)< 250)
	return notify_fail("��ĺڰ�ħ��̫���ˣ�\n");


	extra = me->query_skill("spells",1) / 40;
	extra += me->query_skill("magic-dark",1) /40;
 	if (extra> 37) extra = 37;
        i = extra/4;
        msg = YEL "$N"YEL"���и�����һ��������.$N"YEL"���Ͽճ�����"+chinese_number(i)+"���ڰ�����.\n"NOR;
        msg += YEL"$N"YEL"� ��صĺڰ��� ������ʵ�ͻش��ҵ�������ɣ���а�����������һ�У���������\n"NOR;
        msg += YEL"$N"YEL"��������,���е�"HIM"�ڰ�����"NOR","YEL"ȫ����׼��$n"YEL"�����ȥ!\n"NOR;
        message_vision(msg, me, target);
	for(i=0;i<extra/4;i++)
	{
        msg = YEL"    ��"+chinese_number(i+1)+"��"BLK"��ڰ�����!\n"NOR;
        msg += BLK"   ===@ "NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/2)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//��������Ŀ��������
       if ((int)target->query("magicgift")==4)
{
damagic=300+damage;
                target->receive_damage("qi", damagic);
damagic=350+damage;
                target->receive_wound("qi", damagic);
}

else  if ((int)target->query("magicgift")==2
||(int)target->query("magicgift")==6)
{
damagic=1900+damage*3;
                target->receive_damage("qi", damagic);
damagic=1900+damage;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=600+damage;
target->receive_damage("qi", 600+damage);
target->receive_wound("qi", 600+damage/2);
}

        msg += HIR"\n  $n"HIR"û����ܣ�������ը�����������\n"NOR;
		message_combatd(msg, me, target);
        } else
        {
        msg += HIG"\n  $p"HIB"����Ծ�𣬽���ڰ�������$p"HIB"���±�ը��\n"NOR;
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
	me->add("neili", - 150 * i);
	me->start_busy(3);
	return 1;
}


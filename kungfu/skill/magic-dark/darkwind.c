//darkwind���������

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage,damagic;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIB"����������硹ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);
        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 600)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-dark",1)< 350)
	return notify_fail("��ĺڰ�ħ��̫���ˣ�\n");

if (target->is_busy())
return notify_fail("���������ù������˵�ʱ�򰡣�\n");
                me->start_busy(1);
        msg = HIC "$N"HIC"��������������������..\n"NOR;
        msg += HIC"$N"HIC"���� ��ŭ������ǣ�����������������Ʋá�������\n"NOR;
        msg += HIC"$N"HIC"����������ԪΪ�����ټ��ķ���֮���飬ʮ����ĺڰ�֮������ʹ��������\n"NOR;
        msg += HIC"$N"HIC"���һ��  ���������!!  ,$n"HIC"�ĸ���ͻȻ�����˺�ɫ�������.��\n"NOR;
        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-dark", 1);
//��������Ŀ��������
       if ((int)target->query("magicgift")==3)
{
target->start_busy(3);
damagic=damage;
                target->receive_damage("qi", damagic);
damagic=damage;
                target->receive_wound("qi", damagic);
}
//����������Ŀ��ǿ��
else  if ((int)target->query("magicgift")==4
||(int)target->query("magicgift")==6)
{
target->start_busy(8);
damagic=damage*3;
                target->receive_damage("qi", damagic);
damagic=damage;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=damage+300;
target->receive_damage("qi", damage+300);
target->receive_wound("qi", damage+300);
target->start_busy(4);
}

target->apply_condition("ill_dongshang",10);
target->apply_condition("ill_fashao",10);
target->apply_condition("ill_kesou",10);
target->apply_condition("ill_shanghan",10);
target->apply_condition("ill_zhongshu",10);
target->apply_condition("ice_poison",10);
target->apply_condition("xx_poison",10);
target->apply_condition("cold_poison",10);
target->apply_condition("flower_poison",10);
target->apply_condition("rose_poison",10);
target->apply_condition("scorpion_poison",10);
        msg += BLK"$n"BLK"���һ�������ڰ�����!!\n"NOR;
	msg += BLK"$n"BLK"�ںڰ��е�ȫ��˵����������!!\n"NOR;
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIG"$n"HIG"����Ծ���ӹ���һ�ѡ�\n"NOR;
		message_combatd(msg, me, target);
                me->start_busy(2);
        }
if (target->query("qi") < 1)target->set("qi",0);
if (target->query("eff_qi") < 1)target->set("eff_qi",0);
if (target->query("max_qi") < 1)target->set("max_qi",0);                
if (target->query("jing") < 1)target->set("jing",0);
if (target->query("eff_jing") < 1)target->set("eff_jing",0);
if (target->query("max_jing") < 1)target->set("max_jing",0);                
if (target->query("neili") < 1)target->set("neili",1);
if (target->query("max_neili") < 1)target->set("max_neili",0);
                me->add("neili", -400);
        return 1;
}

// ������

#include <ansi.h>

inherit F_SSERVER;

int thunderspell(object me, object target)
{
	int	kee, damage, spells;
	string msg;
	int extra;
	int i;
	object weapon;
        int damagic;

	spells = me->query_skill("spells");
	if((int)me->query("neili")< 1100)
	return notify_fail("��ķ���̫���ˣ�\n");

        msg = HIW"   ��*****��  \n"NOR;
        msg += HIW"\nһ����ѩ�籩ͻ����մ���$n"HIW"!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-water", 1);
//��ˮ����Ŀ��������
       if ((int)target->query("magicgift")==2)
{
damagic=700+damage;
                target->receive_damage("qi", damagic);
damagic=700+damage;
                target->receive_wound("qi", damagic);
}
//�Ի�����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==1)
{
damagic=2800+damage*5;
                target->receive_damage("qi", damagic);
damagic=2800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=800+damage*3;
target->receive_damage("qi", 800+damage*3);
target->receive_wound("qi", 800+damage);
}

        msg += HIW"$n"HIW"�ĸ�����Ϊ��һƬ����!!\n"NOR;
                target->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIW"$n"HIW"����Ծ���ӹ���һ�ѡ�\n"NOR;
		message_combatd(msg, me, target);
        }
if (target->query("qi") < 3)target->set("qi",1);
if (target->query("eff_qi") < 3)target->set("eff_qi",1);
if (target->query("max_qi") < 3)target->set("max_qi",1);                
if (target->query("jing") < 3)target->set("jing",1);
if (target->query("eff_jing") < 3)target->set("eff_jing",1);
if (target->query("max_jing") < 3)target->set("max_jing",1);                
if (target->query("neili") < 3)target->set("neili",1);
if (target->query("max_neili") < 3)target->set("max_neili",1);
me->add("neili",-450);
if (wizardp(me))
tell_object(me, "����ɱ��Ϊ"+damagic+"�㡣\n" NOR);

	return 1;
	
}
int perform(object me, object target)
{
	string 	msg;
	object	env;
	object	*inv;
	int	i;
	if( !target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail(HIW"����ѩ�籩��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-water",1)< 400)
	return notify_fail("���ˮϵħ��̫���ˣ�\n");


	msg = HIW "$N"HIW"��������ջ���һ����â�ǣ������૵��������ģ�\n" NOR;
       msg += HIW"$N"HIW"� ڤ�������������������ϵ���������������\n"NOR;
       msg += HIW"$N"HIW"� �����������䶳�籩��������µ���Լ�ռ���ѩ֮��������!!\n"NOR;
       msg += HIW"ͻȻ���ѩ�׵���գ�����$n"HIW"�����ĵط������˱�ѩ�籩��\n"NOR;
       msg += HIW"  ����ѩ�籩�� \n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->start_busy(3);
	return 1;
}



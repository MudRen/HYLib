// darkstorm���ڱ���ѩ

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
                damage = (int)me->query_skill("magic-dark", 1);
//��ˮ����Ŀ��������
       if ((int)target->query("magicgift")==2)
{
damagic=630+damage;
                target->receive_damage("qi", damagic);
damagic=630+damage;
                target->receive_wound("qi", damagic);
}
//�Ի������Ŀ��ǿ��
else  if ((int)target->query("magicgift")==1
||(int)target->query("magicgift")==6)
{
damagic=2260+damage*3;
                target->receive_damage("qi", damagic);
damagic=2260+damage*2;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=840+damage*2;
target->receive_damage("qi", 800+damage*2);
target->receive_wound("qi", 800+damage);
}
        msg += HIB"$n"HIB"�ĸ�����Ϊ�˺ڰ��ı���!!$n����ȫ���ʹ������������!!\n"NOR;
                if (!target->is_busy())
                target->start_busy(3);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIB"$n"HIB"����Ծ���ӹ���һ�ѡ�\n"NOR;
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
                return notify_fail(HIB"�����ڱ���ѩ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-dark",1)< 450)
	return notify_fail("��ĺڰ�ħ��̫���ˣ�\n");


	msg = HIW "$N"HIW"��������ջ���һ����â�ǣ������૵��������ģ�\n" NOR;
       msg += HIW"$N"HIW"� ڤ���������������ϵ�ǿ������ע�������ڵ���֮�����ȥ�ɣ�\n"NOR;
       msg += HIW"$N"HIW"� �����������䶳�籩��������µ���Լ�ռ���ѩ֮����\n"NOR;
       msg += HIW"$N"HIW"� ���ɣ���а�����������һ�У�����\n"NOR;
       msg += HIW"���ͻȻ�����ڣ�$n"HIW"�����ĵط��¶�ͻȻ�½�,�����˱���ѩ��\n"NOR;
       msg += HIB"  �����ڱ���ѩ�� \n"NOR;
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



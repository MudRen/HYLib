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

        msg = HIR"   �䨍������¡  \n"NOR;
        msg += YEL"\n$n���ڵĵط��ѿ���!!"YEL"!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-earth", 1);
//��������Ŀ��������
       if ((int)target->query("magicgift")==4)
{
damagic=800+damage;
                target->receive_damage("qi", damagic);
damagic=800+damage;
                target->receive_wound("qi", damagic);
}
//��������Ŀ��ǿ��
else  if ((int)target->query("magicgift")==3)
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

        msg += HIR"$n"HIR"�ĸ����������ҵĺ���!!\n"NOR;
                target->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIG"$n"HIG"����Ծ���ӹ���һ�ѡ�\n"NOR;
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
                return notify_fail(YEL"��������ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-earth",1)< 400)
	return notify_fail("�����ϵħ��̫���ˣ�\n");


	msg = YEL "$N"YEL"��������ջ���һ����â�ǣ������૵��������ģ�\n" NOR;
       msg += YEL"$N"YEL"� ˹���������飬ʢѪ��ʥ������������������ɣ�������\n"NOR;
       msg += YEL"$N"YEL"� ������ū��ϣ�ɰ�����������ΰ����������ܻ�һ�и���֮��ɣ�������\n"NOR;
       msg += YEL"$N"YEL"�  ��ر����� ! ���ұ����� !����!\n"NOR;
       msg += YEL"$n"YEL"�����ĵط��Ĵ���ѿ������ұ�����\n"NOR;
       msg += HIR"    �������� \n"NOR;
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



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
	if((int)me->query("neili")< 500)
	return notify_fail("��ķ���̫���ˣ�\n");

        msg = HIC"   $N��Ӱ��$n��ǰ��ʧ��!  \n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp"))
        {

        msg += HIC"$n"HIC"ͻȻ����$N�����ˣ�ֻ��ͣ���˹���!!\n"NOR;
                target->remove_all_enemy();
                me->remove_all_enemy();
		message_combatd(msg, me, target);
//		COMBAT_D->report_status(target);
        } else
        {
        msg += HIC"$n"HIC"˫Ŀһ����ʶ�������������!\n"NOR;
		message_combatd(msg, me, target);
        }
me->add("neili",-150);

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
                return notify_fail(HIC"����������ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 500)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-ice",1)< 100)
	return notify_fail("�����ϵħ��̫���ˣ�\n");

       if ((int)me->query_condition("inv_busy"))  
       return notify_fail("����ù���������Ҫ��һ������ã�\n");



	msg = HIC "$N"HIC"����һ���������૵��������ģ�\n" NOR;
       msg += HIC"$N�Ķ���ͻȻ�������������������ɫ�Ĺ�â��, $N������������͸��������\n"NOR;
       msg += HIC"  ���������� \n"NOR;
	message_vision(msg, me,target);
	env = environment(me);
        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( !inv[i]->is_fighting(me) ) continue;
                if( inv[i]==me ) continue;
	        if( !inv[i]->is_character() || inv[i]->is_corpse() ) continue;
		thunderspell(me, inv[i]);
        }
	me->apply_condition("inv_busy",8+random(8));
	me->start_busy(3);
	return 1;
}



// holyword��ħʥ��

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

        msg = HIY"�K���L���I�J�K�L\n"NOR;
        msg += HIY"һ��ʥ������$n"HIY"!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-light", 1);

//�Թ�����Ŀ��������
       if ((int)target->query("magicgift")==6)
{
damagic=530+damage;
                target->receive_damage("qi", damagic);
damagic=530+damage;
                target->receive_wound("qi", damagic);
}
//�Ժڰ�����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==5)
{
damagic=1680+damage*6;
                target->receive_damage("qi", damagic);
damagic=1680+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=960+damage*2;
target->receive_damage("qi", 960+damage*2);
target->receive_wound("qi", 960+damage);
}
	if(target->is_ghost()==1
	&& !userp(target)) {
		message_vision(RED "$N"RED"�ҽ���һ������Ϊ�˻ҽ���\n" NOR, target);
		target->die();
		return 1;
	}

        msg += YEL"$n"YEL"�ĸ���ʥ������!!$n����ȫ��Ҫ�ܻ�����!!\n"NOR;
                if (!target->is_busy())
                target->start_busy(3);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIY"$n"HIY"ʹ����ħ���������ӹ���һ��!\n"NOR;
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
                return notify_fail(HIY"����ħʥ�ԡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-light",1)< 550)
	return notify_fail("��Ĺ���ħ��̫���ˣ�\n");


	msg = HIY "$N"HIY"��������ջ���һ����â�ǣ������૵��������ģ�\n" NOR;
       msg += HIY"$N"HIY"� �������ҵ������߰������������ҵ�����������ǵĹǣ���Ѫ�����⣬��ʹ�ɣ�����\n"NOR;
       msg += HIY"$N"HIY"� ���������в��ҵ����飬����а��������꣡\n"NOR;
       msg += HIY"$N"HIY"� ����������֮�⣬�������������ϡ�\n"NOR;
       msg += HIY"$N"HIY"� �ص�����ԭ������֮���ɣ�����������\n"NOR;
       msg += HIY"���ͻȻ������ʥ�⣬$n"HIY"�����ĵط���ʥ����ҫ!!\n"NOR;
       msg += HIY"  ����ħʥ�ԡ� \n"NOR;
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



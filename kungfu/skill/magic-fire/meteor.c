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

        msg = HIM"   ��(*��*)¡  \n"NOR;
        msg += HIR"\nһ�����ǹ�����մ���$n"HIR"!!\n"NOR;

        if ( random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("magic-fire", 1);
//�Ի�����Ŀ��������
       if ((int)target->query("magicgift")==1)
{
damagic=800+damage;
                target->receive_damage("qi", damagic);
damagic=800+damage;
                target->receive_wound("qi", damagic);
}
//��ˮ����Ŀ��ǿ��
else  if ((int)target->query("magicgift")==2)
{
damagic=2800+damage*5;
                target->receive_damage("qi", damagic);
damagic=2800+damage*3;
                target->receive_wound("qi", damagic);
}
else 
{
damagic=1000+damage*3;
target->receive_damage("qi", 1000+damage*3);
target->receive_wound("qi", 1000+damage);
}

        msg += HIR"$n"HIR"�ĸ�����Ϊ��һƬ��!!\n"NOR;
                target->start_busy(1);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
        msg += HIY"$n"HIY"����Ծ���ӹ���һ�ѡ�\n"NOR;
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
                return notify_fail(RED"�����Ƿ籩��ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

        if( !me->query("zhuanbest",1))
        return notify_fail("��û���ʸ�ʹ������ܣ�\n");

	if((int)me->query("neili")< 3000)
	return notify_fail("��ķ���̫���ˣ�\n");

if (userp(me) && userp(target) && target->query("combat_exp",1) < me->query("combat_exp",1)) 
	return notify_fail("ħ�����������Ը���С��ҵģ�\n");
	
	if((int)me->query_skill("magic-fire",1)< 400)
	return notify_fail("��Ļ�ϵħ��̫���ˣ�\n");


	msg = RED "$N"RED"��������ջ���һ����â�ǣ������૵��������ģ�\n" NOR;
       msg += RED"$N"RED"� ΰ��Ļ�֮���飬��������մ�������һ�е���������\n"NOR;
       msg += RED"$N"RED"� �ҵ����������������У�ֱ��ȼ�ɻҾ���ȥ���ҵĵ��˵��ʺ��ϰɣ�����\n"NOR;
       msg += HIR"ͻȻ���Ѫ�����գ�����$n"HIR"�����ĵط�������Ѫ������ǣ�\n"NOR;
       msg += HIR"  �����Ƿ籩�� \n"NOR;
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



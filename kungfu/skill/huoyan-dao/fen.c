// fen.c �����Ի�
// by secret
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
	string msg;
	object weapon, target, *inv;
	int skill, ap, dp, equip;
	int neili_wound, qi_wound ;

	me->clean_up_enemy();
       if( !target ) target = offensive_target(me);

       if( !target
        || !target->is_character()
        || !me->is_fighting(target) )
                return notify_fail("�������Ի�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        skill = me->query_skill("huoyan-dao",1);

 
//	if (objectp(weapon = me->query_temp("weapon")))
//              return notify_fail("���������˹���\n");

	if( skill < 120)
                return notify_fail("��ġ����浶���ȼ�����, ����ʹ���������Ի𡹣�\n");

	if( me->query_skill("xiaowuxiang",1) < 60)
                return notify_fail("��ġ�С���ࡹ�ȼ�����, ����ʹ���������Ի𡹣�\n");

	if( me->query("neili") < 600 )
                return notify_fail("��������������޷��˹���\n");
 
        msg = HIC "$N�������ƣ�ʹ��һ�С������Ի𡹣���$n���ؿڻ�ȥ��\n"NOR;

	ap = me->query("combat_exp") + skill * 800;
	dp = target->query("combat_exp") / 2;

	if( dp < 1 )
		dp = 1;
	if( (random(ap)+ skill*800) > dp )
	{
		if(userp(me))
			me->add("neili",-500);


		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		
                qi_wound = target->query("qi") - 100;
if (qi_wound <10) qi_wound=10;
if (neili_wound <10) neili_wound=10;
		target->receive_damage("qi", qi_wound/2);
		target->receive_wound("qi", qi_wound/2);
		target->add("neili", -neili_wound/2);
		if(userp(me)) me->add("neili",-300);
		me->start_busy(2);

		inv = all_inventory(target);
msg += HIR "$nֻ������ǰһ�ڣ�һ������������������ۡ���һ�����һ����Ѫ��\n"NOR;
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
msg += HIR "$n�ŵ�һ�ɽ�ζ���������ϵ�"+inv[equip]->query("name")+HIR"�ѱ��յò��Ʋ����������˵��ϣ�\n"NOR;
			inv[equip]->unequip();
			inv[equip]->reset_action();
			inv[equip]->move(environment(target));
			inv[equip]->set("name", inv[equip]->query("name") + "����Ƭ");
			inv[equip]->set("value", 0);
			inv[equip]->set("armor_prop", 0);
			inv[equip]->set("long", "һ���������£������ǲ�Ƭ��Ƭʲô�ġ�\n");
			}
		}
	}
	else
	{
msg += HIG "ֻ��$n���Ų�æ������һ���������$N�ı�ɱһ����\n"NOR;
		if(userp(me)) me->add("neili",-300);
		me->start_busy(2);
	}
	message_combatd(msg, me, target);

	if(!target->is_fighting(me)) me->fight_ob(target);

	return 1;
}

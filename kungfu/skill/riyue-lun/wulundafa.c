// jianzhang.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob,*inv,target_w;
        string msg, string1;
	int skill, ap, dp, equip;
	int extra;
        int count;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("�����ִ󷨡�ֻ����ս����ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("�����ִ󷨡��õı������������\n");
	if((int)me->query_skill("force") < 160 )
		return notify_fail("����ڹ��ȼ�������ʹ���������ִ󷨡�������\n");

	if(me->query_skill_mapped("force") != "longxiang")
		return notify_fail("û�������������Ϊ���������޷�ʹ�������ִ󷨡������ģ�\n"); 
	if( (int)me->query("neili") < 300 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("riyue-lun",1) < 150 )
		return notify_fail("��������ַ�������\n");
	if( !target ) target = offensive_target(me);

	if( !target
	  ||!target->is_character()
	  ||!me->is_fighting(target) 
	  ||!living(target))
		return notify_fail("�����ִ󷨡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	extra = me->query_skill("riyue-lun",1) / 6;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIY "$N��Ծ���ᣬ��ʱ���ء����ˡ����֮���������������������˸˸����ֻ���Ӵ������ͬ��λ��Ϯ������" NOR;
	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIC  "���ֻ�ת�� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIR  "���ֻ�ת�� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "ͭ�ֻ�ת�� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  BLU   "���ֻ�ת�� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
if (me->query_skill("necromancy",1) > 200)
{
	if (target->query_temp("weapon"))
	{
	target_w = target->query_temp("weapon");

		if( target->query("combat_exp")/2 < 
			random(me->query("combat_exp", 1) )
			&& random(2)==0 )
		{
			target_w->unequip();
			target_w->reset_action();
			target_w->move(environment(target));
			target_w->set("name", target_w->query("name") + "����Ƭ");
			target_w->set("value", 0);
			target_w->set("weapon_prop", 0);
			target_w->set("long", "һ���������£������Ǳ�����Ƭ��\n");
        message_vision(RED"\n$N��������������һ������������������Լ��ı�����Ƭ����һ�أ���\n"NOR,target);

		}
	}
}
if (me->query_skill("xiaowuxiang",1) > 200)
{

		if( target->query("combat_exp")/2 < 
			random(me->query("combat_exp", 1) )
			&& random(2)==0 )
		{
		inv = all_inventory(target);
		for(equip=0; equip<sizeof(inv); equip++)
		{
			if( inv[equip]->query("equipped") &&
				!inv[equip]->query("weapon_prop") )
			{
message_vision(RED"\n$N�ŵ�һ�ɽ�ζ���������ϵ�"+inv[equip]->query("name")+HIR"�ѱ��յò��Ʋ����������˵��ϣ�\n"NOR,target);
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
}
	me->add("neili", -250);
	me->start_busy(3);
	return 1;
}

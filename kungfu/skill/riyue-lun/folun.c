// ����ת
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
	int extra;
        int count;
	object *inv;
	int skill, ap, dp, equip,damage;
	int neili_wound, qi_wound ;
  if( !target ) target = offensive_target(me);
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("�������������\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");
	me->clean_up_enemy();
	target = me->select_opponent();

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("huoyan-dao", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

       if( !wizardp(me) &&(int)me->query_skill("riyue-lun", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("longxiang", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "longxiang")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨѩɽ��ѧ��ʹ����ѩɽ�ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);   
	extra = me->query_skill("riyue-lun",1);
        me->add_temp("apply/strength", extra/3);
	me->add_temp("apply/attack", extra/2);	
	me->add_temp("apply/damage", extra);
	msg = HIY "$N��Ծ���ᣬ��ʱ���ء����ˡ����֮���������������������˸˸����ֻ���Ӵ������ͬ��λ��Ϯ������" NOR;
	damage = (int)me->query_skill("longxiang", 1);
	if (random(2)==0) target->start_busy(3);
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	                 target->receive_wound("qi", random(damage));
	 msg =  HIC  "$N���ִ��ڷ�������б��һ���������ڿ��л���һ�����ߣ���$n��ȥ��" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 	         target->receive_wound("qi", random(damage));
	 msg =  HIR  "$N����������˫�����ƣ�����ȥ�ƾ������ص�һ������$n�� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	                 target->receive_wound("qi", random(damage));
	 msg =  YEL  "$N˫�ֻ��ţ�����$n��ǰ�������ڿ�����ת���أ�Ϯ��$n�ĺ��ԡ� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		          target->receive_wound("qi", random(damage));
	msg =  BLU   "$N������һ���Ϻȣ�����ȭӲ�������ڷ����ϣ����ַ����͵�һת��ֱ׷��$n��" NOR;
	                 target->receive_wound("qi", random(damage));
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	                 target->receive_wound("qi", random(damage));              
        me->add_temp("apply/strength", -extra/3);
	me->add_temp("apply/attack", -extra/2);
	me->add_temp("apply/damage", -extra);
        message_vision(RED"\n$N������浶֮�������𡹾����������������ʺ�ɫ����ӿ��������ǰ����֮�����㼴ͣס������
����Ʈ���޶����������ڰ�գ�������������翣�����׽����ȴ��ɱ�������Σ�ʵ������������\n"NOR,me);

        msg = HIC "$N�������ƣ�ʹ��һ�С������Ի𡹣���$n���ؿڻ�ȥ��\n"NOR;

	ap = me->query("combat_exp") + skill * 200;
	dp = target->query("combat_exp") / 3;

	if( dp < 1 )
		dp = 1;
	if( random(ap) > dp )
	{


		neili_wound = 100 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");
		
                qi_wound = target->query("qi") - 100;
if (qi_wound <100) qi_wound=100;
if (neili_wound <100) neili_wound=100;
		target->receive_damage("qi", qi_wound/3);
		target->receive_wound("qi", qi_wound/3);
		target->add("neili", -neili_wound/3);

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

	}
	message_combatd(msg, me, target);
	me->start_busy(4);
	return 1;
}

// jingsng.c ���ȭ ������ͨ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
	object weapon;	
  	string msg;
	int d_count, count, qi, maxqi, skill;

	if( (int)me->query_temp("jingang") ) 
		return notify_fail(HIG"���Ѿ����˹����ˡ�\n");
	if( (int)me->query_temp("powerup"))
		return notify_fail(HIG"���Ѿ������ڹ������ˣ�û�и��������ʹ�ô�����ͨ��\n"NOR);

	if( !me->is_fighting() )
		return notify_fail("��������ͨ��ֻ����ս����ʹ�á�\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("���������������\n");

	if( (int)me->query_skill("hunyuan-yiqi", 1) < 60)
		return notify_fail("��Ļ�Ԫһ��������Ϊ����������ʹ�ô�����ͨ! \n");

	if( (int)me->query_skill("cuff") < 150 )
		return notify_fail("���ȭ���������ң��޷�ʹ�ô�����ͨ��\n");

	if( me->query_skill_mapped("cuff") != "jingang-quan") 
		return notify_fail("��û�м������ȭ���޷�ʹ�ô�����ͨ��\n");
	
	msg = HIY "$Nʹ������ȭ�ľ�����������ͨ����������Ȼ���ӣ�\n" NOR;
	
	qi = me->query("qi");
	maxqi = me->query("max_qi");
	skill = (int) (me->query_skill("jingang-quan",1) / 3);
	count = me->query_str();
	d_count = (int)me->query_dex() / 2;

	if(qi > (maxqi * 0.4))
	{	
		message_combatd(msg, me, target);
		
		me->add_temp("str", count * 2);	
		me->add_temp("dex", 0-d_count);
		me->set_temp("jingang", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*2, d_count :), skill);

		me->add("neili", -150);
	}
	else{
		msg = HIR "$Nƴ����������ʹ���˴���ȭ���ռ�����, ȫ�����һ����, �������ͬ���ھ�!\n" NOR;
		message_combatd(msg, me, target);
		me->add_temp("str", count * 9);
		me->set_temp("jingang", 1);

		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, count*9, 0 :), 2);

 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
		me->set("neili",0);
		me->add("max_neili",-10);

		msg = HIR "$N�þ������һ������, ���һ����Ѫ, һͷ�Ե��ڵ�!\n" NOR;
		message_combatd(msg, me, target);

		me->set("jing",0);
		me->set("qi",0);

		me->unconcious();
	}
//	if(userp(target)) target->fight_ob(me);
//	else if( !target->is_killing(me) ) target->kill_ob(me);
	return 1;
}

void remove_effect(object me, int aamount, int damount)
{
	
	if ( (int)me->query_temp("jingang") ) 
	{
		me->add_temp("str", -aamount);
		me->add_temp("dex", damount);
		me->delete_temp("jingang");
		tell_object(me, HIY "��Ĵ�����ͨ������ϣ��������ջص��\n" NOR);
		me->start_busy(2);
	}
}

// jianzhang.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
int extra;
  if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���һ����衹ֻ����ս����ʹ�á�\n");

        if( me->query_skill("bibo-shengong",1) < 150)
            return notify_fail("��ı̲��񹦵ȼ�����, ����ʹ�á��һ����衹��\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("��ʹ�õ��������ԡ�\n");

        if( me->query_skill("yuxiao-jian",1) < 150)
            return notify_fail("������｣���ȼ�����, ����ʹ�á��һ����衹��\n");

        if( me->query("neili") < 400 )
            return notify_fail("��������������޷����á��һ����衹��\n");
	extra = me->query_skill("yuxiao-jian",1) / 20;
	extra += me->query_skill("bibo-shengong",1) /10;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);

	msg = HIY "$Nʹ���һ����������һ����衹������Ȼ�ӿ졣��Ӣ�ͷף�" NOR;
	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  YEL  "�����һ��� " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  RED  "�����䣡 " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  BLU  "���컨�꣡ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "�仨���⣡ " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra);

if ( me->query_skill("yuxiao-jian",1) >230)
{
        msg = HIG 
HIG"$Nһ����Х����������������һ����������������һʽ��������������"+weapon->name()
+"������ֹ����Ӱ��ҹĻ������$n��\n"NOR;

	extra = me->query_skill("yuxiao-jian",1) / 5;
	extra += me->query_skill("bibo-shengong",1) /5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 2*extra);

       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -2*extra);
	me->add("neili", -150);
	me->start_busy(1);

}
	me->add("neili", -220);
	me->start_busy(2);
	return 1;
}

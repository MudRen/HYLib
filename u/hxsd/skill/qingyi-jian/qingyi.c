// qingyi-jian  ����һʽ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int damage;

	if( !target ) target = offensive_target(me);
        
        if( !target
        ||  !target->is_character()
        ||  !me->is_fighting(target) )
		return notify_fail("������һʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if((int)me->query_skill("qingyi-jian", 1) < 200)
                return notify_fail("��Ĵ����书�ȼ���������\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		    || (string)weapon->query("skill_type") != "sword")
			return notify_fail("��ʹ�õ��������ԡ�\n");

	if((int)me->query_dex() < 30)
			return notify_fail("���������, Ŀǰ������ʹ���������! \n");

	if((int)me->query_skill("dodge") < 100)
			return notify_fail("����Ṧ��Ϊ����, ����ʹ�þ���һʽ��\n");
 
	if((int)me->query_skill("sword") < 135)
			return notify_fail("��Ľ�����Ϊ������ Ŀǰ����ʹ�þ���һʽ! \n");

    	if( (int)me->query("neili") < 500 )
			return notify_fail("�������������\n");
			
   	msg = HIG"$N����һ�䣬һ����Ц��ʹ�����彣����������һʽ������ȫ����\n���ڽ��ϣ�" + weapon->name()+ "����һ�����磬ֱ��$n��ȥ��\n\n"NOR;

        if (random(me->query_skill("sword", 1)) > target->query_skill("sword", 1) / 2 )
	{
			damage = me->query_skill("qingyi-jian",1) + (int)me->query_skill("sword", 1)*2;
			damage = damage - random( target->query_skill("dodge")/3 );
//                      target->receive_wound("jing", random( damage/2 ));
			target->receive_damage("qi", 20 + random(damage));
			target->receive_wound("qi", 20 + damage);

			me->start_busy(2);

			msg += HIR"���$n��$N�ġ�����һʽ����͸ǰ�ģ���ǰһ�ڣ����ۡ����³���һ���Ѫ����\n"NOR;
			me->add("neili", -200);
	} else 
	{
		msg += CYN"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
		me->add("neili", -200);
		me->start_busy(4);
	}
	message_vision(msg, me, target);

   return 1;

}

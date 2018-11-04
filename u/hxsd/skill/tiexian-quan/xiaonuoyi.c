#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

object *enemy = ({});
int perform(object me, object target1,object target2)

{

        int extra;

	object weapon;

	if(me->is_busy())

		return notify_fail("������û�գ���\n");

	if( (int)me->query_skill("tiexian-quan", 1) < 150 )
		return notify_fail("��Ĵ����书�������ҡ�\n");

	if( (int)me->query_skill("unarmed") < 60 ||

	    me->query_skill_mapped("unarmed") != "tiexian-quan")

		return notify_fail(HIW "��ġ�����ȭ���������ң��޷�ʹ�á�СŲ�ơ���\n"NOR);

	enemy=me->query_enemy();

        if (sizeof(enemy)<2) return notify_fail("�����ͬʱ���������ϵĵ���ս������ʹ��СŲ�ƣ�\n");

        if( !target1 && target2) return notify_fail("�����ͬʱָ����������\n");

        if( !target2 && target1) return notify_fail("�����ͬʱָ����������\n");

	if(!target1 && !target2)

        {

           target1=enemy[0];

           target2=enemy[1];

         }

        if( !target1 || !target2

	||	!target1->is_character() || !target2->is_character()

	||	!me->is_fighting(target1) || !me->is_fighting(target2))

		return notify_fail(HIW "��СŲ�ƣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

	if (me->query("neili")<=100) return notify_fail(HIW "����������㣬�޷��������˹��ƣ�\n"NOR);

        me->add("neili",-100);

        message_vision(HIR "\n$Nʹ��佻����ɵĲ���֮�ء�СŲ�ơ�\n\n"NOR,me);

        me->start_busy(1);

        weapon = target1->query_temp("weapon");

//        extra = me->query_skill("tiexian-quan",1) + (int)me->query_skill("unarmed", 1);

        if ((me->query("combat_exp")*random(10))>target1->query("combat_exp"))

        {

          message_vision(HIY "$N���ִ���$n�Ĺ��ƣ�ʹ֮����"+target2->name()+"��\n" NOR,me,target1);

          COMBAT_D->do_attack(target1,target2, weapon);  

          COMBAT_D->do_attack(target2,target1, weapon);  

 	  COMBAT_D->do_attack(target1,target2, weapon);  

          COMBAT_D->do_attack(target2,target1, weapon);

          target1->receive_damage("qi",0,me);

          target1->start_busy(2);

        }

        else

        {

          message_vision(HIR "��$n����$N����ͼ�����Ʒ���������\n"NOR,me,target1);

          COMBAT_D->do_attack(target1,me,weapon);

        }

        weapon = target2->query_temp("weapon");

        if (random(me->query("combat_exp")*(extra/30+1))>target2->query("combat_exp"))

        {

          message_vision(HIY "$N���ִ���$n�Ĺ��ƣ�ʹ֮����"+target1->name()+"��\n" NOR,me,target2);

          COMBAT_D->do_attack(target2,target1, weapon);  

          target2->receive_damage("qi",0,me);

          target2->start_busy(2);

        }

        else

        {

          message_vision(HIR "��$n����$N����ͼ�����Ʒ���������\n"NOR,me,target2);

          COMBAT_D->do_attack(target2,me,weapon);

        }

     	return 1;

}


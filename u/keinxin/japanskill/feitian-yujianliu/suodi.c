// suodi.c ����������.����

#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("����������.����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "blade")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

    if ((int)me->query_skill("shayi-xinfa", 1) < 50)
   return notify_fail("���ɱ���ķ���򲻹���\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "Ŀǰ�Ѿ���æ�����ˣ��ŵ������ɢ�\n");
                
	if((int)me->query_skill("feitian-yujianliu",1) < 30)
		return notify_fail("��ķ�������������Ϊ����, ����ʹ����һ���� !\n");
	if((int)me->query_skill("blade") < 30)
		return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ��! \n");

	if( (int)me->query("neili") < 100  ) 
		return notify_fail("�������������\n");

        msg = HIG "$N��ͼ����$n����ͻȻ�ӿ죬�Գ���������$n������Χ,��ͬ����������һ�㡣\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIW " ���$p��$P�����Լ��Ĺ�����Χ��������һ����\n" NOR;
                target->start_busy( (int)me->query_skill("feitian-yujianliu",1) / 50 + 2 );
        } else {
                msg += HIC"����$p������$P����ͼ��ȫ�����ˣ��ӿ������صĹ�����Χ��\n"NOR NOR;
                me->start_busy(2);
        }
        message_combatd(msg, me, target);
	me->add("neili", - 60);
        if(!target->is_fighting(me)) target->fight_ob(me);
if ((int)me->query_skill("feitian-yujianliu",1) > 200)
{
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
         {
         attack_time = random((int)me->query_skill("feitian-yujianliu", 1) / 30);
        msg = HIY "�� ������! ��$Nʹ�����ٵ��յ���,�ɼ��ٵ��յ�������������,������$n��ƽ��������\n";
        target->start_busy(1);
        message_combatd(msg, me, target);
  
        for(i = 0; i < attack_time; i++){
         msg = HIM "$N��ʤ׷��! �������޾���ӣ���У������һ��������\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                                        }
         }
                me->start_busy(3);
}
        return 1;
}


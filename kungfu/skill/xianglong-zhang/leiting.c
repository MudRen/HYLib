//leiting.c  ������һ����
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
   return notify_fail("������һ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( objectp(me->query_temp("weapon")) )
   return notify_fail("��������ʹ�á�����һ������\n");

    if( (int)me->query_skill("huntian-qigong", 1) < 100 )
   return notify_fail("��Ļ���������򲻹���ʹ����������һ������\n");

    if( (int)me->query_skill("xianglong-zhang", 1) < 120 )
   return notify_fail("��Ľ���ʮ���Ʋ�������������ʹ�á�����һ������\n");

        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("��ı����ڹ����δ������\n");

    if( (int)me->query("neili") < 500 )
   return notify_fail("���������Ϊ�������ߡ�\n");

    msg = HIB "
$NĬ�˻���������ʩչ��������һ������ȫ����ת��������Խ��Խ�죬������һ�����磬��Ȼ�䣬$N�Ѿ��������÷�����$n��"NOR;  

    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) { 
      me->start_busy(3);

   damage = (int)me->query_skill("xianglong-zhang", 1)*3+(int)me->query_skill("huntian-qigong",1);

   damage = damage + random(damage);

   target->receive_damage("qi", damage);
   target->receive_wound("qi", damage/3);
   me->add("neili", -500);
   msg += "
$nֻ��һ������Ӱ�ж�Ȼ�ֳ�$N��˫�ƣ�������������ܣ������ػ��У������������ڲ��ݣ�������Ѫ��������������\n"NOR;
message_combatd(msg, me, target);
COMBAT_D->report_status(target);

    } else
    {
      me->start_busy(3);
      me->add("neili", -300);
       msg += "����$n������$N����ͼ����Ȼ��$N������\n"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->report_status(me);
    }
    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}


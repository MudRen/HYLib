// huanying.c
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
      int skill;
    if( !target ) target = offensive_target(me);

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "blade")
      return notify_fail("��ʹ�õ��������ԡ�\n");

      if( !target || !me->is_fighting(target) )
      return notify_fail("����Ӱ��ֻ����ս���жԶ���ʹ�á�\n");

    if ((int)me->query_skill("hujia-daofa", 1) < 100 )
        return notify_fail("��ĺ��ҵ����ȼ����������ܺ�����꣡\n");    
    if ((int)me->query_skill("blade", 1) < 100 )
        return notify_fail("��Ļ���������������죬���ܺ�������Ļ�Ӱ��\n");    
    if ((int)me->query("neili") < 300 )
        return notify_fail("����������̫�������ܺ�����Ӱ��\n");
    me->add("neili", -100);        
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
    message_vision(HIY"$Nǰ�����ߣ��������������иֵ�ԽʹԽ�죬�����������⻯���������Ρ�
$n���˺��ҵ���֮�����λ�Ӱ�����Ի������޴룬��֪�ĸ�$N���棬�ĸ��Ǽ١�\n"NOR, me, target);
    target->start_busy(6);
    skill = me->query_skill("hujia-daofa", 1)/3;
    return 1;
        } else {
   message_vision(HIR"����$n������$N����ͼ������㣬ȫ��Ӧ�����硣\n" NOR,me,target);
           me->start_busy(2);
    return 1;
        }

}


// zhen.c ̫��ȭ�����־�

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
    string msg;

    if( !target ) target = offensive_target(me);

    if( !target || !target->is_character() || !me->is_fighting(target) )
      return notify_fail("�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if( objectp(me->query_temp("weapon")) )
      return notify_fail("�������ֲ���ʹ�á����־���\n");

    if( (int)me->query_skill("taiji-quan", 1) < 30 )
      return notify_fail("���̫��ȭ������죬����ʹ�á����־���\n");

    if( (int)me->query_skill("taiji-shengong", 1) < 30 )
      return notify_fail("���̫���񹦲����ߣ��������������˵С�\n");

    if( (int)me->query("neili", 1) < 100 )
      return notify_fail("����������̫��������ʹ�á����־���\n");

    msg = CYN "$NĬ���񹦣�ʹ��̫��ȭ�����־�����ͼ����������$n��\n"NOR;

    if (random(me->query_skill("force")) > target->query_skill("force")/3 )
    {
      me->start_busy(3);
      damage = (int)me->query_skill("taiji-shengong", 1);
      damage = damage/2 + random(damage);

      target->receive_damage("qi", damage);
      target->receive_wound("qi", damage/3);
      me->add("neili", -damage/10);

      if( damage < 20 ) msg += HIY"���$n�ܵ�$N�����������ƺ�һ����\n"NOR;
      else if( damage < 40 ) msg += HIY"���$n��$N���������𣬡��١���һ������������\n"NOR;
      else if( damage < 80 ) msg += RED"���$n��$N������һ���ؿ������ܵ�һ���ش�����������������\n"NOR;
      else msg += HIR"���$n��$N������һ����ǰһ�ڣ��������ɳ�������\n"NOR;

    } else
    {
      me->start_busy(1);
      msg += CYN"����$p������$P����ͼ����û���ϵ���\n"NOR;
    }
    message_combatd(msg, me, target);

    if(!target->is_fighting(me)) target->fight_ob(me);
    return 1;
}


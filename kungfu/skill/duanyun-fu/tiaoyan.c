// tiaoyan.c ��������֮������ʽ��
// Modified by Venus Oct.1997

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
object weapon;
    if( !target ) target = offensive_target(me);

    if( !target
    ||      !target->is_character()
    ||      !me->is_fighting(target) )
      return notify_fail("������ʽ��ֻ����ս����ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("��ı����ڹ���δ���ɣ�����ʹ�ã�\n");
        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("�������������㣡\n");     


    if( target->is_busy() )
   return notify_fail(target->name() + "����ֻ��ͷ��Ӭ����ŵ������ɡ�\n");
    msg = HIG "$Nʹ����������֮������ʽ�������⼲��$n˫�ۡ�\n";

//    me->start_busy(1);
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3
 ) {
    msg += "���$pֻ������ǰһ�ڣ�˫��һ���ʹ������ʲôҲ�������ˡ�\n" NOR;
  target->start_busy( (int)me->query_skill("duanyun-fu") / 50 + 3);
 target->add("qi",-((int)me->query_skill("duanyun-fu")*2));
    target->add("eff_qi",-((int)me->query_skill("duanyun-fu")*2));
    } else {
   msg += "����$p������$P����ͼ������æ�㿪�ˡ�\n" NOR;
    me->start_busy(3);
    }
me->add("neili", -100);
    message_combatd(msg, me, target);

    return 1;
}



#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int perform(object me, object target)
{
    int damage,extra,num,p;
    string msg;
    object weapon;

    if (!target ) target = offensive_target(me);
    if (!objectp(weapon = me->query_temp("weapon"))
       || (string)weapon->query("skill_type") != "throwing")
               return notify_fail("��ʹ�õ��������ԡ�\n");
    if (!target || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("������𻨡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if ((int)me->query_skill("duoming-jinhua", 1) < 80 )
        return notify_fail("������𻨲�����죬ʹ����������𻨡���\n");
    if ((int)me->query_skill("jiuyang-shengong", 1) < 40 )
        return notify_fail("�㱾���ڹ���򲻹���ʹ����������𻨡���\n");

    if ((int)me->query("max_neili")<400)
        return notify_fail("��������Ϊ���㣬�޷�����������\n");
    if ((int)me->query("neili")<200)
    {
        return notify_fail("����������������û�ܽ������컨�꡹ʹ�꣡\n");
    }
	extra = me->query_skill("jiuyang-shengong",1) / 20;
	extra += me->query_skill("duoming-jinhua",1) /20;
	me->add_temp("apply/attack", (extra*2));	
	me->add_temp("apply/damage", 400);

    msg = HIR "$N�����ָ�ץ��ö�������ƺ�����������$n��\n"NOR;
    msg += HIY"������\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg =  HIY"���컨��\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"�绨ѩ��\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"��Ůɢ��\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY"������\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -(extra*2));
	me->add_temp("apply/damage", -400);

	me->start_busy(2);
        me->add("neili", -300);
        num=random(11)+1;
        msg = HIW"\n$N��߳һ��������ƮƮ��ֻ��"+chinese_number(num)+"����������컨��֮�ƣ�������˷���$n�����ȥ��\n"NOR;
        if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3
         ){
          msg += HIR"ֻ��$n����������ʹ��Ĵ��һ����"+weapon->name()+HIR"��ȫ��������ȫ��ҪѨ��\n"NOR;
          me->add("neili", -200);
          damage = me->query_skill("duoming-jinhua", 1);
          damage +=me->query_skill("throwing", 1);
          damage = damage * num /10;
          damage = damage + random(damage);
          target->receive_damage("qi", damage);
          target->receive_wound("qi", damage/2);
          if (!target->is_busy())
          target->start_busy(3);
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg += "( $n"+eff_status_msg(p)+" )\n";
         }
         else {
          msg += CYN"$n��ͷ����һ������������Ȼ�㿪��"+weapon->name()+CYN"�Ĺ�����\n"NOR;
          me->start_busy(2);
         }
         message_vision(msg, me, target);

    return 1;
}

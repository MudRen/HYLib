// binghuo.c ���溮����--
// looo/2001/6/23
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg;
        int damage, dp,skill;
skill = me->query_skill("bazhen-zhang",1);
        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("������������ֻ����ս����ʹ�á�\n");

        if( objectp( me->query_temp("weapon")) )
                return notify_fail("ֻ�п��ֲ���ʩչ��������������\n");

        if( (int)me->query_skill("bazhen-zhang", 1) < 150 )
                return notify_fail("��������ƹ��򻹲�����죬����ʹ�á�������������\n");

        if(me->query_skill("yunlong-shengong", 1) < 120)
                return notify_fail("�������ڵ������ķ���ʹ������������������\n");

        if (me->query_temp("weapon"))
                return notify_fail("��ֻ�ܿ���ʹ�á�������������\n");

        if( (int)me->query("max_neili") < 800 )
                return notify_fail("���������Ϊ̫��������ʹ�á�������������\n");

        if( (int)me->query("neili") < 800 )
                return notify_fail("�������������\n");

   
                msg = HIR "\n$N" HIR "������������͸��⣬һ�ɳ�������ֱϮ" HIR "$n" HIR "�ؿڣ�\n"NOR;
                if (living(target))
                       dp = target->query_skill("parry") / 3;
                else   dp = 0;
                if (random(me->query_skill("parry")) > dp)
                {
                       me->start_busy(1);
                       target->start_busy(1);
                       me->add("neili", -300);
                       damage = (int)me->query_skill("bazhen-zhang", 1);
                       damage = (int)me->query_skill("force", 1) + damage;
                       damage = random(damage) + 300;
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIR "$n" HIR" ��ʱ�����ؿ��类���գ�һ���������Լ̻أ�!!\n"NOR;

                       if(me->query_skill("bazhen-zhang", 1) > 150)
                              call_out("perform2", 0, me, target);
                }   else
                {
                       me->start_busy(3);
                       me->add("neili", -100);
                       msg += HIW"����$pһ�����Ʒ���ԶԶ�Ķ��˿�ȥ��\n"NOR;
                }

        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
        string msg;
        int damage,dp,ap;
                int skill;
skill = me->query_skill("bazhen-zhang",1);
        if (!me || !target || environment(me) != environment(target)) return 0;
        if(!living(target))
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("���Ҫ�ٳ��ڶ��ƣ�ȴ�����Լ������������ˣ�\n");

        msg = HIB "\n����" HIB "$N" HIB "��ӳ����֣����ľ��ǰ���������������Ƕ���" HIB "$n" HIB "�Ĺ�ȥ!\n"NOR;
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
              {

                me->start_busy(1);

                me->add("neili", -300);
                damage = (int)me->query_skill("bazhen-zhang", 1);
                damage = random(damage)+300;
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIW  "���һ�ƻ��У�" HIW "$n" HIW "ֻ����ȫ������ͨ�����ⶳ�ᣬ��ɫһ�±�ף�\n"NOR;

                }
        else {
           me->start_busy(3);
           me->add("neili", -100);
           msg += HIY "\n$p" HIY "�ۿ��������ˣ�����������˳�����˿�ȥ��\n" NOR;
           }
        message_vision(msg, me, target);

if (skill> 250)
{
     msg = HIR "$N" HIR "һ�����ȣ��ֱ������ͻ��ʹ��������һ��������һ�Σ����ֳ�צ����$n" HIR
              "ǰ��Ѹ��ץ����\n" NOR;

        dp = target->query_skill("force", 1);
        if (dp < 1)  dp = 1;
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -150);
                damage = ap + (int)me->query_skill("force", 1);
                damage += random(damage / 2);
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIR "$n" HIR "���ܲ�����ǰ�ض�ʱ��ץ��"
                                           "����Ѫ�ۣ����������Һ���\n" NOR;

                me->start_busy(2 + random(3));
        } else
        {
                me->add("neili", -50);
                damage = ap / 2 + random(ap / 2);
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIM "$n" HIM "����С����У�ƴ����⣬"
                                           "��˫���Ա�ץ���˼���Ѫӡ��\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
}

if (skill> 350)
{
      msg = HIY "���ֻ��$N" HIY "�������ƣ�ƽƽ�Ƴ�����ʱ�Ʒ����ȣ�����"
              "Я�š����������֮���͹���$n" HIY "��ȥ��\n" NOR;

        if (random(me->query_skill("strike")) > target->query_skill("dodge") / 2)
        {
                me->start_busy(3);

                damage = me->query_skill("bazhen-zhang", 1);
                damage = damage * 3 + random(damage * 5);
target->add("qi",-damage);
target->add("eff_qi",-damage);
target->apply_condition("zhua_poison",10);

                        msg +=HIR "���ֻ��$n" HIR "һ���ƺߣ�$N"
                                           HIR "�ƾ����ض��������ۡ������һ��"
                                           "����Ѫ��\n" NOR;
                me->add("neili", -300);
        } else
        {
                me->start_busy(2);
                me->add("neili", -200);
                msg += CYN "����$p" CYN "������$N" CYN
                       "����ͼ���㿪������ɱ�š�\n" NOR;
        }
        message_combatd(msg, me, target);
}
        return 1;
}


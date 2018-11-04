// fochen.c ����

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int angry;
        string msg;
        int skill, ap, dp, damage;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! me->is_fighting(target))
                return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        skill = me->query_skill("yujiamu-quan", 1);

        if (skill < 100)
                return notify_fail("��Ľ�����ĸȭ��Ϊ����, �޷�ʹ�á���������\n");

        if (me->query("neili") < 180)
                return notify_fail("��������������޷����á���������\n");

        if( objectp(me->query_temp("weapon")) || me->query_temp("secondary_weapon") ) 
                return notify_fail("��������ֻ�ܿ������á�\n"); 

        if (angry = me->query("qi") < me->query("max_qi") / 2)
                msg = HIY "$N" HIY "Ŀ�����ѣ�һ�����ȣ�ȭͷ����������$n"
                      HIY "��Ҫ����\n" NOR;
        else
                msg = HIY "$N" HIY "���һ����ȭͷ����������$n"
                      HIY "��Ҫ����\n" NOR;

        ap = me->query_skill("cuff", 1) / 2 + skill;
        dp = target->query_skill("dodge");
        if (dp < 1) dp = 1;
        if (ap / 2 + random(ap * 4 / 5) > dp || !living(target))
        {
                me->add("neili", -150);
                me->start_busy(1);
                damage = skill + random(skill / 2);
                if (angry) damage += random(damage / 2);
                damage = 150 + damage;
   target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg += HIR "���$p" HIR "�޷��ֵ�$P"
                                           HIR "������һ������ʱ������������ҡ�β�����\n" NOR;                	
        } else
        {
                me->add("neili",-40);
                msg += CYN "����$p" CYN "��δ�����������壬���ƽŲ����㿪��$P"
                       CYN "�Ĺ�����\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);

        return 1;
}

#include <ansi.h>
#include <combat.h>

#define ZHEN "「" HIW "反璞归真" NOR "」"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        int i, ap, dp;
        object weapon;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(ZHEN "只能对战斗中的对手使用。\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon")) 
                return notify_fail(ZHEN "只能空手使用。\n");

        if ((int)me->query_skill("force") < 300)
                return notify_fail("你内功修为不够，难以施展" ZHEN "。\n");

        if ((int)me->query("max_neili") < 3600)
                return notify_fail("你内力修为不够，难以施展" ZHEN "。\n");

        if ((int)me->query_skill("tmzhang", 1) < 220)
                return notify_fail("天魔掌法火候不够，难以施展" ZHEN "。\n");

        if (me->query_skill_mapped("strike") != "tmzhang")
                return notify_fail("你没有激发天魔掌法，难以施展" ZHEN "。\n");



        if ((int)me->query("neili") < 500)
                return notify_fail("你现在真气不够，难以施展" ZHEN "。\n");

        if (! living(target))
                return notify_fail("对方都已经这样了，用不着这么费力吧？\n");

        msg = HIW "陡然间$N" HIW "施出「" HIY "璞" HIW "」字诀，双掌向$n"
              HIW "平平推去，招数朴实无华，毫无半点花巧可言。\n" NOR;  


        ap = (int)me->query("combat_exp");
        dp = (int)target->query("combat_exp");

        if (ap / 2 + random(ap) > dp)
        { 
                damage = me->query_skill("tmzhang",1) + random(me->query_skill("tmzhang",1) / 2)+ 500;
                target->add("qi",-damage);
		target->add("eff_qi",-damage);
                msg +=HIR "$n" HIR "勘破不透掌中虚实，$N" HIR
                                           "双掌正中$p" HIR "前胸，“喀嚓喀嚓”接"
                                           "连断了数根肋骨。\n" NOR;
        } else
        {
                msg += CYN "$n" CYN "见$N" CYN "这掌来势非凡，不敢"
                       "轻易招架，当即飞身纵跃闪开。\n" NOR;
        }

        msg += HIW "\n紧接着$N" HIW "变招「" HIY "真" HIW "」字诀，霎"
               "时只见$N" HIW "双掌纷飞，化出漫天掌影笼罩$n" HIW "四面"
               "八方。\n"NOR;
        message_combatd(msg, me, target);


        for (i = 0; i < 5; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(1);

        	COMBAT_D->do_attack(me, target, 0, 0);
        }
        me->add("neili", -400);
        me->start_busy(3);
        return 1;
}


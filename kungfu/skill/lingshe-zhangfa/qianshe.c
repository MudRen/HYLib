#include <ansi.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon;
        string msg;
        int count;
        int lvl;
        int i;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("��ǧ�߳�����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "staff")
                return notify_fail("������ֳ�һ���Ȳ���ʩչ��ǧ�߳�������\n");

        if ((int)me->query_skill("force") < 150)
                return notify_fail("����ڹ���򲻹�������ʩչ��ǧ�߳�������\n");

	if( (int)me->query_skill("hamagong", 1) < 100 )
		return notify_fail("��ĸ�󡹦�������.\n");
        if ((int)me->query("neili") < 100)
                return notify_fail("��������������޷�ʩչ��ǧ�߳�������\n");
        if (me->query_skill_mapped("force") != "hamagong")
                return notify_fail("��û�м�����󡹦Ϊ�ڹ����޷�ʩչ��\n");

        if ((lvl = (int)me->query_skill("lingshe-zhangfa", 1)) < 120)
                return notify_fail("��������ȷ��������ң��޷�ʹ��ǧ�߳�����\n");

        if (me->query_skill_mapped("staff") != "lingshe-zhangfa")
                return notify_fail("��û�м��������ȷ����޷�ʹ��ǧ�߳�����\n");

       if (! living(target))
              return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        msg = HIW "$N" HIW "���һ����������ǰ�����е�" + weapon->name() +
              HIW "���������â��һ������$n" HIW "��\n" NOR;

        if (lvl / 2 + random(lvl) > target->query_skill("parry") * 2 / 3)
        {
                msg += HIY "$n" HIY "��$N" HIY "��" + weapon->name() +
                       HIY "ʹ�û�����֣���������һ�㣬ʵ�������Եֵ���ֻ�к��ˡ�\n" NOR;
                count = lvl / 7;
target->apply_condition("snake_poison",10);
target->apply_condition("chanchu_poison",10);
target->apply_condition("qx_snake_poison",20);
        } else
                count = 0;

        message_combatd(msg, me, target);
        me->add("neili", -100);
                me->add_temp("apply/attack", 50);
        me->add_temp("apply/damage", 300);

        for (i = 0; i < 6; i++)
        {
                if (! me->is_fighting(target))
                        break;
                if (random(2) && ! target->is_busy())
                        target->start_busy(1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -50);
        me->add_temp("apply/damage", -300);
        me->start_busy(2);
if (random(5)==0 && (int)me->query_skill("lingshe-zhangfa",1) > 300
&& (int)me->query_skill("zhaosheshu",1) > 200
&& (int)me->query_skill("yangsheshu",1) > 200)
{
	message_combatd(
        HIW "$N�ø�󡹦�������ɽ���Ź��߷ۣ�������$n��ȫ��
$n��һ���������֣�$n�Ŀ�һ���ʹ��\n" NOR, me, target);
target->apply_condition("baituo_poison",50);
}
        return 1;
}


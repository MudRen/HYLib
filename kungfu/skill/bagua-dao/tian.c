#include <ansi.h>
#include <combat.h>

#define TIAN "��" HIY "�쵶����" NOR "��"

inherit F_SSERVER;

int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;
        int i, count;


        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TIAN "ֻ����ս���жԶ���ʹ�á�\n");

        if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "blade")
                return notify_fail("����ʹ�õ��������ԣ�����ʩչ" TIAN "��\n");

        if ((int)me->query_skill("bagua-dao", 1) < 250)
                return notify_fail("��İ��Ե���������죬����ʩչ" TIAN "��\n");


        if ((int)me->query_skill("linji-zhuang", 1) < 120)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
                
        if (me->query_skill("bagua-dao", 1) < 220)
                return notify_fail("��İ��Ե�����Ϊ����������ʩչ" TIAN "��\n");

        if (me->query_skill_mapped("blade") != "bagua-dao")
                return notify_fail("��û�м������Ե���������ʩչ" TIAN "��\n");


        if ((int)me->query_skill("bagua-zhang") < 150)
                return notify_fail("��İ����ƻ��̫ǳ��\n");
                
        if ((int)me->query("max_neili") < 3000)
                return notify_fail("����ڹ���Ϊ���㣬����ʩչ" TIAN "��\n");

        if ((int)me->query("neili") < 500)
                return notify_fail("��������������������ʩչ" TIAN "��\n");

        if (me->query_skill_mapped("blade") != "bagua-dao")
                return notify_fail("��û�м������Ե���������ʩչ" TIAN "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        message_combatd(HIY "$N" HIY "���һ������" + weapon->name() +
                        HIY "��������ǧ��������ʱ���������������ӿ��"
                        "������$n" HIY "ȫ��\n" NOR, me, target);

        count = me->query_skill("bagua-dao", 1) / 6;

        me->add("neili", -250);
        me->add_temp("apply/attack", count);

        for (i = 0; i < 8; i++)
        {
                if (! me->is_fighting(target))
                        break;

                if (random(3) == 1 && ! target->is_busy())
                        target->start_busy(2);

                me->add_temp("pfm_tiandao", 1);
                COMBAT_D->do_attack(me, target, weapon, 0);
        }

        me->add_temp("apply/attack", -count);
        me->delete_temp("pfm_tiandao");
        me->start_busy(4);
        return 1;
}

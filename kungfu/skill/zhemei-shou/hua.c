// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

#define HUA "��" HIR "������" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        object weapon;
        int damage,extra,i;
        string msg;
        int ap, dp, p;
        int lv, cost_neili;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }
        if (! target || ! me->is_fighting(target))
                return notify_fail(HUA "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUA "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("beiming-shengong", 1) < 220
        &&  (int)me->query_skill("xiaowuxiang", 1) < 220
        &&  (int)me->query_skill("bahuang-gong", 1) < 220)
                return notify_fail("��ı�ڤ�񹦻�򲻹�������ʩչ" HUA "��\n");

        if (lv = (int)me->query_skill("zhemei-shou", 1) < 220)
                return notify_fail("����ң��÷�ֵȼ�����������ʩչ" HUA "��\n");

        if (me->query("max_neili") < 4000)
                return notify_fail("���������Ϊ���㣬����ʩչ" HUA "��\n");

        if (me->query("neili") < 800)
                return notify_fail("�������������㣬����ʩչ" HUA "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

       if ((int)me->query_skill("zhougong-jian", 1) < 150)
               return notify_fail("����ܹ�����򲻹���\n");
       if ((int)me->query_skill("wuliang-jian", 1) < 150)
               return notify_fail("�������������򲻹���\n");   

       if ((int)me->query_skill("pidi-shenzhen", 1) < 150)
               return notify_fail("��ıٵ������򲻹���\n");
       if ((int)me->query_skill("wudoumi-shengong", 1) < 150)
               return notify_fail("����嶷���񹦻�򲻹���\n");

        msg = HIM "$N" HIM "��������һ���������ֻӳ�����Ե��ʱϼ�����������"
              "��ɫ�����$n" HIM "ϯ�������\n" NOR;

        ap = me->query_skill("hand") + me->query_skill("dodge");
        dp = target->query_skill("parry") + target->query_skill("dodge");

        if (target->query("shen") < 0 || ! userp(target))
                ap += ap / 10;

        if (ap *2 / 3 + random(ap) > dp)
        {
                damage = 0;
                lv = me->query_skill("zhemei-shou", 1);
                if (lv >= 220)cost_neili = -500;
                if (lv >= 240)cost_neili = -470;
                if (lv >= 260)cost_neili = -440;
                if (lv >= 280)cost_neili = -400;
                if (lv >= 300)cost_neili = -360;
                if (lv >= 320)cost_neili = -320;
                if (lv >= 340)cost_neili = -300;
                if (lv >= 360)cost_neili = -270;
                if (lv >= 400)cost_neili = -200; 
                if (me->query("max_neili") > target->query("max_neili") * 2)
                {
                        msg += HIM "ֻ��$n" HIM "һ����Х��$N" HIM "����ɫ��"
                               "���Ѿ���ע��$p" HIM "���ڣ���ʱ��$p" HIM "��"
                               "Ϊһ̲Ѫˮ��\n" NOR "( $n" RED "���˹��أ���"
                               "��������в�����ʱ�����ܶ�����" NOR ")\n";
                        damage = -1;
                        me->add("neili", cost_neili);
                        me->start_busy(1);
                } else
                {
                        damage = me->query_skill("hand");
                        damage += me->query_temp("apply/unarmed_damage");

                        target->receive_damage("qi", damage*2+200);
                        target->receive_wound("qi", damage*2+200);
                        target->receive_damage("jing", damage / 4);
                        target->receive_wound("jing", damage / 8);
                        p = (int)target->query("qi") * 100 / (int)target->query("max_qi");

                        msg += HIM "$n" HIM "ֻ��΢΢һ㶣�$N" HIM "����ɫ�ƾ��������"
                               "�룬$p" HIM "���������ú�¯һ�㣬��Ż������Ѫ��\n" NOR;
                        msg += "( $n" + eff_status_msg(p) + " )\n";
                        
                        me->add("neili", cost_neili);
                        me->start_busy(2);
                }
        } else
        {
                msg += CYN "$p" CYN "��״��ʧɫ����ȫ���Ʋ�͸$P"
                       CYN "���а��أ���������Ծ����������������\n" NOR;
                me->add("neili", -200);
                me->start_busy(4);
        }
        message_combatd(msg, me, target);

	msg = HIY "$N����������������һ��������˫�ֻ���Ϊצ�����������Ҫ��$n˺�����룡\n" NOR;
	message_combatd(msg, me, target);
	extra=100;
	extra=100;
	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", 800);
for (i=0; i< 7 ;i++){	
	msg = HIR  "$N˫�ֳ�ӥצ״��ȫ���ڿգ������ƴ��巭�ɣ�����$nץȥ��" NOR;
	COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
}
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -800);
   msg = HIW "$n��ɫ��òҰ���ֽ��˫������ָ�ⷢ��ӨӨ�Ĺ�â�� 
$n��Ȼ����һ˿Ʈ�ư�����$N��ǰ��˫צ�������ץ��$N�Ŀڣ� \n"NOR;
        
       
//  give bonus to NPC kill

    if( random((int)me->query("combat_exp"))> (int)target->query("combat_exp")/4) {
        msg += RED"\n\n$N"RED"�ò������ŵ��۹⿴���Լ��Ŀڵ�Ѫ��������һ�Σ����ڵ��ϡ� \n" NOR;
        target->receive_damage("qi",damage*2);
        target->receive_wound("qi",damage);
    }
    else msg += HIC"\n\n$N��æ���з�ס$n������ɭɭצӰ�������ˣ��㿪��$n������һ���� \n" NOR; 
    message_vision(msg, target, me);
        return 1;
}


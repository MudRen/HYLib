// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// tuo.c
// �����ս���ַ���ʱ��ʩչ�ľ���ʤ����һ�С�

#include <ansi.h>
#include <combat.h>

#define TUO "��" HIM "�����ˮ" NOR "��"

inherit F_SSERVER;


int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp;
        int effqi, maxqi,skill;
        string couple;
        object cob;


                
        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(TUO "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if(me->query_skill_mapped("force") != "yunv-xinfa" )
        return notify_fail("��Ҫ����Ů�ķ���Ϊ�ڹ������á�\n");

        if ((int)me->query_skill("force") < 250)
                return notify_fail("����ڹ���򲻹���ʹ����" TUO "��\n");

        if ((int)me->query_skill("anranxiaohun-zhang", 1) < 180)
                return notify_fail("�����Ȼ�����Ʋ�������������ʹ��" TUO "��\n");
        if ((int)me->query_skill("yunv-jian", 1) < 80)
                return notify_fail("�����Ů�������̫ǳ��\n");
        if ((int)me->query_skill("yunv-shenfa", 1) < 80)
                return notify_fail("�����Ů�����̫ǳ��\n");
        if ((int)me->query_skill("tianluo-diwang", 1) < 80)
                return notify_fail("������޵������̫ǳ��\n");
        if ((int)me->query_skill("meinv-quan", 1) < 80)
                return notify_fail("�����Ůȭ���̫ǳ��\n");
        if ((int)me->query_skill("wuzhan-mei", 1) < 80)
                return notify_fail("�����չ÷���̫ǳ��\n");
        if ((int)me->query_skill("yinsuo-jinling", 1) < 80)
                return notify_fail("�������������̫ǳ��\n");
        if ((int)me->query("neili") < 500)
                return notify_fail("��������������޷�ʹ��" TUO "��\n");



        //if (! stringp(couple = me->query("couple/couple_id"))) 
        //        return notify_fail("��û�����ӣ���᲻�����������ҵĸо���\n");
        /*
        if (! objectp(cob = find_player(couple)))
                return notify_fail("���Ų��ڰ���������˭����\n");
        */

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        effqi = me->query("eff_qi");
        maxqi = me->query("max_qi");

        ap = me->query_skill("unarmed") +
             me->query_skill("force");

        dp = target->query_skill("parry") +
             target->query_skill("force");
             
        me->start_busy(3);

        if (effqi < maxqi * 25 / 100)
        {
                msg = HIR "$N" HIR "���������ң���Ȼ������"
                      HIR "����һ�ۣ������������ˣ����Լ����ء���\n"
                      "����ʧ�����ǣ�����һ�У�ǡ��ʹ������Ȼ��������"
                      "�ġ������ˮ����\n" NOR;
                ap += ap * 20 / 100;
        } else
        {
                msg = HIM "ֻ��$N" HIM "û����ɵĻ��������ĳ�һ�ƣ�����"
                      "��Ȼ�������еġ������ˮ����\n"NOR;
        }
        if (ap * 2 / 3 + random(ap) > dp)
        { 
                damage = me->query_skill("unarmed");
                me->add("neili", -300);
target->add("qi",-damage*2);
target->add("eff_qi",-damage*2);

                        msg +=HIR "ֻ��$n" HIR "һ���ƺߣ����ۡ���һ"
                                           "������һ�����û���$p" HIR "��ͷ�� \n"
                                           NOR;
//                me->set_temp("last_perform/sad-strike/tuo", 1);
        } else
        {
                me->add("neili", -100);
                msg += HIC "����$p" HIC "С��Ӧ���������мܣ���������һ�С�\n"
                       NOR;
        }
        message_combatd(msg, me, target);
skill=(int)me->query_skill("anranxiaohun-zhang", 1);
if (skill > 350)
{
me->add_temp("apply/damage",1000);
me->add_temp("apply/attack",80);
msg = HIB"$N���������ң�û����ɵĻ��������ĳ�һ�ƣ�ֻ�����۵�һ������һ�����û���$n��ͷ��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIY"������$N�߳�һ�š���һ�ŷ���ʱ�л��㱣�����ԼԼ���������ޡ����һ�죬��$n�ؿ�Ϯȥ����" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIC"$Nһ����;ĩ·����$n���ԣ����ƾٵ���ǰƽ�ƶ�������������бб����$n��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIR"$Nһ�С�"MAG"���񲻰�"HIR"���������ݼ�ת��չ���ṦΧ��$n�������ߣ���Ȼ�����������$n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIB"$Nһ�С�"RED"������ʩ"HIB"��ͻȻ�������࣬ͷ�½��ϣ��������ӣ�һ������$n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIM"$Nһ�С�"HIY"��������"HIM"�������ո���ͷ�������£��Ų����أ����������������$n" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add_temp("apply/damage",-1000);
me->add_temp("apply/attack",-80);
}
        return 1;
}

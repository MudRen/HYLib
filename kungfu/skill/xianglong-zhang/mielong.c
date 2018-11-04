// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#define HUI "��" HIR "����һ��" NOR "��"

inherit F_SSERVER;
void remove_effect(object me, object target, int lvl);
void msg_display(object me, object target, int lvl);

int perform(object me, object target)
{
        int damage;
        string msg;
        int ap, dp,lvl;



        if (! target) target = offensive_target(me);

        if (! target || ! me->is_fighting(target))
                return notify_fail(HUI "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(HUI "ֻ�ܿ���ʹ�á�\n");

        if ((int)me->query_skill("force") < 260)
                return notify_fail("���ڹ���Ϊ����������ʩչ" HUI "��\n");

        if ((int)me->query("max_neili") < 5000)
                return notify_fail("��������Ϊ����������ʩչ" HUI "��\n");

        if ((int)me->query_skill("xianglong-zhang", 1) < 300)
                return notify_fail("�㽵��ʮ���ƻ�򲻹�������ʩչ" HUI "��\n");

        if (me->query_skill_mapped("strike") != "xianglong-zhang")
                return notify_fail("��û�м�������ʮ���ƣ�����ʩչ" HUI "��\n");

if ((int)me->query_skill("huntian-qigong",1) < 120)
                return notify_fail("��Ļ���������Ϊ������\n");
       if (((int)me->query_skill("liuhe-zhang", 1)) < 150)
               return notify_fail("��������Ʒ�̫���ˡ�\n");
       if (((int)me->query_skill("fengmo-zhang", 1)) < 150)
               return notify_fail("��ķ�ħ�ȷ�̫���ˡ�\n");
       if (((int)me->query_skill("xiaoyaoyou", 1)) < 150)
               return notify_fail("�����ң��̫���ˡ�\n");
       if (((int)me->query_skill("dagou-bang", 1)) < 150)
               return notify_fail("��Ĵ򹷰�̫���ˡ�\n");
       if (((int)me->query_skill("chansi-shou", 1)) < 150)
               return notify_fail("�������̫���ˡ�\n");
       if (((int)me->query_skill("suohou-gong", 1)) < 150)
               return notify_fail("��Ĳ�˿������̫���ˡ�\n");

        if ((int)me->query("neili") < 1000)
                return notify_fail("��������������������ʩչ" HUI "��\n");

        if (! living(target))
                return notify_fail("�Է����Ѿ������ˣ��ò�����ô�����ɣ�\n");

        // ��һ��
        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("dodge") + target->query("dex") * 10;
        
        message_vision(HIW "\n��Ȼ��$N" HIW "���μ���������һ�������ֺ���һ�ƣ���"
                     "��$n" HIW "��ȥ�����ǽ���ʮ���ơ�" NOR + HIY "�����л�" NOR
                     + HIW "��һ�У���������֮��˵���㵽������ɽ����֮����$n" HIW
                     "��ӿ��ȥ������ʯ���쾪�������ޱȡ�\n" NOR, me, target);
        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
target->add("qi",-damage*2);
target->add("eff_qi",-damage);
                       msg =HIR "$p" HIR "һ�㣬ֻ��$P" HIR "����"
                                          "һ�����ѻ����Լ���ǰ����������������"
                                          "�����С�\n" NOR;

                message_vision(msg, me, target);

        } else
        {
                msg = HIC "$p" HIC "����˫�ۣ�����Ӧ�ԣ��������࣬$P"
                      HIC "��������ţ�뺣������жȥ��\n" NOR;
                message_vision(msg, me, target);
        }

        // �ڶ���
        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("parry") + target->query("int") * 10;

        message_vision(HIW "\n$N" HIW "һ�Ƽȳ���������Ȼ������$n" HIW "������֮��"
                     "��������ǰ�ƣ������������ϲ�������һ�С�" NOR + HIY "������"
                     "��" NOR + HIW "����������������ŭ����ӿ���Ʋ��ɵ�����ʱ$n"
                     HIW "�����Ϣ���ͣ����㲻�ȡ�\n" NOR, me, target);
        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = me->query_skill("strike");
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg =HIR "ֻ��$p" HIR "һ���Һ�����$P" HIR
                                           "һ�ƻ�����ǰ�������꿦�ꡱ���˼�����"
                                           "�ǡ�\n" NOR;

                message_vision(msg, me, target);
        } else
        {
                msg = HIC "$p" HIC "����˫�ۣ�����Ӧ�ԣ��������࣬$P"
                      HIC "��������ţ�뺣������жȥ��\n" NOR;
                message_vision(msg, me, target);
        }

        // ������
        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("force") + target->query("con") * 10;

        message_vision(HIW "\n������$N" HIW "һ�����ȣ�����бб�ӳ���ǰ������δ��"
                     "�����������ֵ�����Ȼ�ֹ���һ�С�" NOR + HIY "�����л�" NOR
                     + HIW "�����Ƽз��ƣ��������񣬱���һ��������ǽ����ǰ�����"
                     "ȥ��$n" HIW "ֻ����Ѫ��ӿ����Ϣ���ǡ�\n" NOR, me, target);

        if (ap * 3 / 5 + random(ap) > dp)
        {
                damage = me->query_skill("force");
target->add("qi",-damage*2);
target->add("eff_qi",-damage);

                        msg =HIR "���$p" HIR "����������$P" HIR
                                           "���ƾ���ʱ���ض��������ۡ������һ��"
                                           "����Ѫ��\n" NOR;


                message_vision(msg, me, target);
                me->start_busy(5);
                me->add("neili", -500);
               // return 1;
        } else
        {
                msg = HIC "$p" HIC "�������������ͣ����μ��ˣ�˲��Ʈ����"
                      "�ɣ��ѳ�$P" HIC "����֮�⡣\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(5);
                me->add("neili", -500);
                //return 1;
        }
        //message_combatd(msg, me, target);

        me->set_temp("xianglong",1);
        message_vision(HIR "$N���۵��˫����������ת�˸�ԲȦ������������ȫ������\n\n" NOR, me,target);

        lvl = (int)(lvl / 5);

        me->add_temp("apply/dodge", 100);


        call_out("msg_display",3,me,target,lvl);
        
        return 1;
}




void msg_display(object me, object target, int lvl)
{
        string *circle, msg;
        object weapon;
        int ap,dp;
        if (!me) return;
        
        if (!target ||
            !target->is_character() ||
            !me->is_fighting(target) ||
            !living(me))
        {
                me->delete_temp("xianglong");
                me->add_temp("apply/dodge",-100);
                return;
        }
        if ( objectp(weapon = target->query_temp("weapon")))
{
       msg = HIR "$N" HIR "����һ����ȫ���ھ��ŷ��������ұ۷����⳶����ͼ��$n"
              HIR "��" + weapon->name() + HIR "�������С�\n" NOR;

        ap = me->query_skill("strike") + me->query("str") * 10;
        dp = target->query_skill("parry") + target->query("int") * 10;

        if (ap / 3 + random(ap) > dp)
        {
                me->add("neili", -300);
                msg += HIR "$n" HIR "ֻ����Χ����ӿ��������" + weapon->name()
                       + HIR "��Ȼ����ס����$N" HIR "�������ַ�ȥ��\n" NOR;
                me->start_busy(2);
                weapon->move(environment(target));
        } else
        {
                me->add("neili", -200);
                msg += CYN "$n" CYN "ֻ����Χ����ӿ������æ����������"
                       + weapon->name() + CYN "������ܲ�͸�磬ʹ��$N"
                       CYN "�޴����֡�\n" NOR;
                me->start_busy(3);
        }
        message_combatd(msg, me, target);
 }      
        circle = ({
                YEL"$NͻȻ���һ����˫���������$p�����ͻ���ȥ��\n"NOR,
                HIG"$N������������һ�������ֺ���һ�ƣ�����$p��ȥ��\n"NOR
        });

        msg = HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;

        circle = ({
                HIC"����δ����$p�Ѹ��ؿں������������֮�䣬$N��������ŭ������ӿ������"NOR,
                HIM"ֻһ˲֮�䣬$p�����Ϣ���ͣ�$N��������ŭ����ӿ���Ʋ��ɵ���������һ�����εĸ�ǽ����$p��ǰ���塣"NOR
        });

        msg += HIG"\n"+ circle[random(sizeof(circle))] +"\n" NOR;

        if( target
            &&  target->is_character()
            &&  me->is_fighting(target) ) {
                message_vision(msg, me, target);
                call_out("remove_effect",2,me,target,lvl);
        } else {
                me->delete_temp("xianglong");
                me->add_temp("apply/dodge",-100);
        }
        return 0;
}

void remove_effect(object me, object target, int lvl)
{
        int jiali, jianu, ap, dp, pp,dmg,damage;
        object weapon;
        string *limbs, limb, result, str, type;
string msg;
        if (!me) return;
        
        if (!target ||
            !target->is_character() ||
            !me->is_fighting(target) ||
            !living(me))
        {
                me->delete_temp("xianglong");
                me->add_temp("apply/dodge",-100);
                return;
        }

        weapon=target->query_temp("weapon");
        jiali = me->query("jiali");
        jianu = me->query("jianu")*5;
        ap = me->query_skill("strike");
        ap += (jiali + jianu)/4;
        ap *= 2;
        if (living(target))
        {
            pp = target->query_skill("parry");
            dp = target->query_skill("dodge");
        }  else
        {
            pp = 0;
            dp = 0;
        }
        type = "����";
        
        if( target
        &&      target->is_character()
        &&      me->is_fighting(target) ) {
        
        if (wizardp(me))
                printf("ap = %d , pp = %d , dp = %d , me->query_temp(apply/parry) = %d , lvl = %d .\n",ap,pp,dp,me->query_temp("apply/parry"),lvl);

        if( ap/2 + random(ap) > dp + pp ) {
            message_vision(HIM"$N��˫���Ѹ��Ż��������һ���������ش���$p�ؿڣ����ſ������������߹Ƕ��˼�����\n"NOR, me, target);
            dmg = ap;
            dmg += jiali + jianu*5;
            dmg += random(dmg/2);
dmg=dmg+me->query_skill("strike")+100;
        if (wizardp(me))
                printf("damage = %d\n",dmg);
           

            target->receive_damage("qi", dmg);
            target->receive_wound("qi", dmg+random(dmg/2));
            target->start_busy(1+random(2));
        
            //me->add("neili", -dmg/3);
            //me->add("jing", -dmg/6);

            limbs = target->query("limbs");

            result = COMBAT_D->damage_msg(dmg, type);
            result = replace_string( result, "$l", limbs[random(sizeof(limbs))]);
            result = replace_string( result, "$p", target->name() );
            message_vision(result, me, target);

            str = COMBAT_D->status_msg((int)target->query("qi") * 100 /(int)target->query("max_qi"));
            message_vision("($N"+str+")\n", target);
        } else {
            if ( objectp(weapon) )
            {
                message_vision(HIC "$n��֮�£�$p����������Բ��ס��ǰ��ͬʱ���������Ʈ����ˣ��ܿ���$N��һ�ơ�\n" NOR, me, target, weapon);
            }
            else {
                message_vision(HIC "$n��֮�£�˫������������Բ��ס��ǰ��ͬʱ���������Ʈ����ˣ��ܿ���$N��һ�ơ�\n" NOR, me, target);
            }
        }
        }
        me->start_busy(3);
        me->delete_temp("xianglong");
        me->add_temp("apply/dodge",-100);
        msg = WHT "$N" WHT "ʩ������ʮ����֮��" HIW "��ɽ����" NOR +
              WHT "����ȫ�������Ķ���˫������ɽ������ѹ��$n" WHT "��\n"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);      
        msg = HIY "$N" HIY "����һ��������ǰһ����˫����Ȼ������"
              "�ͷ׶���������һ�����������ھ���֮�ϣ�\n\n" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  
        
                msg = HIC "$N" HIC "Ĭ���ڹ���ʩչ��" HIY "����һ��" NOR "��ȫ����ת��������"
              "Խ��Խ�죬��\n����һ�����磬��Ȼ�䣬$N" HIC "�Ѿ�������"
              "�÷�����" HIC "$n��\n"NOR;  
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);  

        msg = YEL  "$N����һת��ͻȻ�۵�$n��ǰ��һʽ����ս��Ұ��ֱ����$n����" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW "$NͻȻ����˫�ƾӸ��������һʽ����Х���졹ȫ������$n��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        return 0;
}

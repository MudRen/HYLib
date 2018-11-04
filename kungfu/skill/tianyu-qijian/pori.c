// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// pori.c �Ż�����

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        int damage, p, i, wadd, at, df;
        string msg;

        weapon = me->query_temp("weapon");

                
        if ( ! target )
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if ( ! target || ! me->is_fighting(target) )
                return notify_fail("���Ż����ա�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if ( !weapon || weapon->query("skill_type") != "sword" )
                return notify_fail("������û�н����޷�ʹ�á��Ż����ա�������\n");

        if ( me->query_skill_mapped("sword") != "tianyu-qijian"
                || me->query_skill_mapped("parry") != "tianyu-qijian" )
                return notify_fail("��û���������潣����ôʩչ���Ż����ա�������\n");

        //if ( weapon->query("unique", 1) )
        //        return notify_fail("����������һ���������޷����������飡\n");

        if ( me->query_skill("tianyu-qijian", 1) < 160 )
                return notify_fail("��������潣����㣬ʹ�������Ż����ա�������\n");

        if ( me->query_skill("sword", 1) < 140 )
                return notify_fail("��Ļ���������������죬ʹ�������Ż����ա�������\n");
       if ((int)me->query_skill("zhougong-jian", 1) < 50)
               return notify_fail("����ܹ�����򲻹���\n");
       if ((int)me->query_skill("wuliang-jian", 1) < 50)
               return notify_fail("�������������򲻹���\n");   

       if ((int)me->query_skill("pidi-shenzhen", 1) < 50)
               return notify_fail("��ıٵ������򲻹���\n");
       if ((int)me->query_skill("wudoumi-shengong", 1) < 50)
               return notify_fail("����嶷���񹦻�򲻹���\n");
        if ( me->query("09g/ring") == "li" )
        {
                if ( me->query_skill("xiaowuxiang", 1) < 140 )
                        return notify_fail("���С���๦��Ϊ���㣬ʹ�������Ż����ա�������\n");
                if ( me->query_skill_mapped("force") != "bahuang-gong" )
                        return notify_fail("��û��ʹ��С���๦���޷�ʹ�á��Ż����ա�������\n");
        }

        else
        {
                if ( me->query_skill("bahuang-gong", 1) < 140 )
                        return notify_fail("��İ˻�����Ω�Ҷ�����Ϊ���㣬ʹ�������Ż����ա�������\n");
                if ( me->query_skill_mapped("force") != "bahuang-gong" )
                        return notify_fail("��û��ʹ�ð˻�����Ω�Ҷ��𹦣��޷�ʹ�á��Ż����ա�������\n");
        }

        if ( me->query_str() < 28 )
                return notify_fail("�������������ǿ����ʹ�������Ż����ա�������\n");

        if ( me->query_dex() < 30 )
                return notify_fail("��������������飬�޷�ʩչ���Ż����ա�������\n");
 
        if ( me->query("max_neili") < 2000 )
                return notify_fail("���������Ϊ���㣬�޷�ʹ�á��Ż����ա�������\n");

        if ( me->query("neili") < 1000 )
                return notify_fail("��������������޷��������г�����\n");


        msg = HIY"\n$N����һ��������"+weapon->name()+HIY"���������������Ϊ�����ǹ������㼤����$n��\n"NOR;      

        //Damage is also decided by how many times the player used this perform
        i = me->query("09g/pori");

        if ( i > me->query_skill("tianyu-qijian") )
                i = me->query_skill("tianyu-qijian");

        i -= me->query("age");


        //Damage Target
        if ( (at=random(me->query("combat_exp"))) > (df=target->query("combat_exp")/3) )
        {                
                me->start_busy(1);
                target->start_busy(1);
                me->add("neili", -300);
                damage = me->query_skill("tianyu-qijian", 1)+me->query_skill("sword", 1)+
                        random(me->query_skill("sword", 1))+me->query_skill("bahuang-gong", 1)-
                        random(target->query_skill("parry", 1));
                damage = damage*2+i*2;

                //Damage is also decided by how strong the weapon is
                wadd = (weapon->query("weapon_prop/damage")+1);
                damage = damage+(random(wadd)+wadd)*2;

                if ( me->query("neili") > target->query("neili")*2 )
                        damage += random(damage);

                if ( damage > 2000 )
                        damage = damage+random(me->query_skill("sword", 1));

                if ( damage < 200 )
                        damage = damage-random(target->query_skill("dodge", 1)/2);

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);

                msg += HIR"\n���$N���������"+weapon->name()+
                       HIR"��������������$n���ϣ�һ������Ѫ���˿ڴ�ӿ����\n"NOR;

                p = target->query("qi")*100/target->query("max_qi");
                msg = replace_string(msg, "$w", "����");
                msg = replace_string(msg, "$l", "����ദ");

                if ( me->query_skill("tianyu-qijian", 1) > 140
                && me->query_skill("sword") > 140 )
                        call_out("perform2", 0, me, target);
        }

        else
        {
                me->add("neili", -100);
        
                me->start_busy(3);
                msg += HIC"\n$n�ۼ�"+weapon->name()+
                       HIC"������������ǰ��ֻ���������գ��˾��������佫�������˿���\n"NOR;
        }

        message_combatd(msg, me, target);

        //weapon->unequip();
        //weapon->move(environment(me));
        //weapon->set("name", "���ѵ�" + weapon->query("name"));
        //weapon->set("value", 1);
        //weapon->set("weapon_prop", 0);
        me->reset_action();
        me->add("09g/pfm_pori", 1);

        return 1;
}

//If possible, also busy target
int perform2(object me, object target)
{
        string msg;

        if ( !me || !target || !living(target) )
                return 0;

        msg = MAG "\n���ϣ�$N����Ľ���������������������������$n������ҪѨ��\n\n"NOR;

        if ( me->query("max_neili") > target->query("max_neili")*2/3 && random(3) ==0 )
        {
                msg += HIR "���$nֻ���˴���Ѫ�����������Ѿ��޷���ת����ʱ����һ��������\n" NOR;
                me->start_busy(3);
                target->start_busy(me->query_skill("force",1)/50+1);
                me->add("neili", -(me->query_skill("force",1)/5));
        }

        else
        {
                me->add("neili", -10);
                target->add("neili", -10);
                me->start_busy(3);
                msg += HIC "\n$pֻ����������������������������Ѩ�������Ҷ�����׼����û���ϵ���\n" NOR;
        }

        message_combatd(msg, me, target);

        return 1;
}

int help(object me)
{
        write(WHT"\n���Ż����ա�\n\n"CYN+
                 " ������һʽ�Ż��������������潣��������ʽ��ϵ������ڹ�ʹ���Լ���\n"+
                 " �������������컨����ַ�����������ʵ������������Ȼ��������������\n"+
                 " ���ڹ��������������൱�Ľ���������ܵ���ʩչ��Ҳ�������Ͼ�������\n"+
                 " ���գ������һ�е��������������迿"HIY"������ʹ��"CYN"����ߣ���ʽ��������\n"+
                 " ��ʹ�õ���������Ҳ�кܴ��ϵ��������ˣ�������������ﵽһ������\n"+
                 " ֮ʱ�������"HIG"���ӹ�Ч"CYN"��\n\n"+

              WHT" Ҫ�󣺰˻�����Ψ�Ҷ��𹦡�"HIR"140"WHT" ��\n"+
              WHT" ������С���๦          ��"HIR"140"WHT" ��\n"+
              WHT" �����������潣  ����������"HIR"160"WHT" ��\n"+
              WHT" ��������������������������"HIR"140"WHT" ��\n"+
              WHT" ����������ķ�  ����������"HIR" 80"WHT" ��\n"+
              WHT" ��������������  ��������  "HIR" 28"WHT" ��\n"+
              WHT" ������������  ��������  "HIR" 30"WHT" ��\n"+
              WHT" ��������ǰ����  �������� "HIR" 200"WHT" ��\n"+
              WHT" ��������ǰ����  �������� "HIR"1000"WHT" ��\n"+
              WHT" ����������������������� "HIR"2000"WHT" ��\n\n"+
                
              WHT" ս����ʹ�á�\n"NOR);

        return 1;
}

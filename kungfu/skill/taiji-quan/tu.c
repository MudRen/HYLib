// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;

#define TU "��" HIW "̫��ͼ" NOR "��"

int perform(object me, object target)
{
        object *obs;
        string msg;
        int damage;
        int ap, dp;
        int flag;
        int i;
        int p;



        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail(TU "ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail(TU "ֻ�ܿ���ʩչ��\n");

        if ((int)me->query_skill("taiji-quan", 1) < 250)
                return notify_fail("���̫��ȭ������죬����ʩչ" TU "��\n");

        if ((int)me->query_skill("taiji-jian", 1) < 200)
                return notify_fail("���̫������������죬����ʹ�á�" + TU + "����\n");

        if ((int)me->query_skill("raozhi-roujian", 1) < 200)
                return notify_fail("�����ָ�ὣ���̫ǳ��\n");

        if ((int)me->query_skill("yitian-zhang", 1) < 200)
                return notify_fail("������������ƻ��̫ǳ��\n");

        if ((int)me->query_skill("paiyun-shou", 1) < 200)
                return notify_fail("����������ֻ��̫ǳ��\n");
                
        if ((int)me->query_skill("shenmen-jian", 1) < 200)
                return notify_fail("�������ʮ�������̫ǳ��\n");


        if ((int)me->query_skill("taiji-shengong", 1) < 300)
                return notify_fail("���̫������Ϊ�������ߣ�����ʩչ" TU "��\n");

        if ((int)me->query_skill("taoism", 1) < 300)
                return notify_fail("��ĵ�ѧ�ķ���Ϊ�������ߣ�����ʩչ" TU "��\n");

        if (me->query_skill_mapped("unarmed") != "taiji-quan")
                return notify_fail("������û�м���̫��ȭ������ʩչ" TU "��\n");

        if (me->query_skill_mapped("parry") != "taiji-quan")
                return notify_fail("������û�м���̫��ȭ������ʩչ" TU "��\n");


        if (me->query_skill_mapped("force") != "taiji-shengong")
                return notify_fail("������û�м���̫���񹦣�����ʩչ" TU "��\n");

        if ((int)me->query("jing") < 1000)
                return notify_fail("�����ھ�������������ʩչ" TU "��\n");

        if ((int)me->query("neili", 1) < 1000)
                return notify_fail("��������������������ʩչ" TU "��\n");

        msg = HIM "$N" HIM "��ȻһЦ��˫�����Ữ������Ȧ�ӣ���ʱ���ܵ���"
              "��������ԴԴ���ϵı�ǣ��������\n\n" NOR;
        message_combatd(msg, me, target);

        me->add("neili", -1000);
        me->add("jing", -1000);
        me->start_busy(4);
        ap = me->query_skill("taoism", 1) +
             me->query_skill("taiji-quan", 1) * 3 / 2 +
             me->query_skill("taiji-shengong", 1);
        obs = me->query_enemy();
        for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = obs[i]->query_skill("force") * 2 +
                     obs[i]->query_skill("taoism", 1);
                if (ap + random(ap) > dp)
                {
                        switch (random(3))
                        {
                        case 0:
                                tell_object(obs[i], HIY "���֮�����ƺ��ص��˹�ȥ�����磬��"
                                                    "Ȼ���޷��������ң���Ȼ��ǰ��һ��\n"
                                                    "��ȫȻ����������ͷһ�ң�����һ���"
                                                    "ʹ�������������Կ��ƣ�\n" NOR);
                                break;
                        case 1:
                                tell_object(obs[i], HIW "����ǰһ�н�����ģ�������������ǵ�"
                                                    "���ɾ���Ȼ����ȴ������ϢԽ��Խ�ң�\n"
                                                    "��֫һ����ʹ������Ҫվ����ס��\n" NOR);
                                break;
                        default:
                                tell_object(obs[i], HIR "����ߺ�Ȼ����һ���������ۼ������"
                                                    "��紸����������㲻�����һ����\n"
                                                    "�������¶�����ʹ����ֻ�и������ȡ�\n" NOR);
                                break;
                        }
                        damage = ap + random(ap);

                        obs[i]->receive_damage("qi", damage+500);
                        obs[i]->receive_wound("qi", damage / 2+500);

                        obs[i]->receive_damage("jing", damage / 3);
                        obs[i]->receive_wound("jing", damage / 6);

                        p = (int)obs[i]->query("qi") * 100 / (int)obs[i]->query("max_qi");

                        switch (random(3))
                        {
                        case 0:
                                msg = HIR "ֻ��" + obs[i]->name() +
                                      HIR "�����㵸���������ԣ���"
                                      "Ȼ���һ������Ѫ��ֹ��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        case 1:
                                msg = HIR "ȴ��" + obs[i]->name() +
                                      HIR "��ò���ݣ��ƺ�������ʲ"
                                      "ô����֮�£�����һ�Σ�Ż��������Ѫ��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        default:
                                msg = HIR + obs[i]->name() +
                                      HIR "����������һ��������������"
                                      "а�����϶��ų���Ѫ����\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                                break;
                        }
                        obs[i]->start_busy(3);
                        message("vision", msg, environment(me), ({ obs[i] }));
                        obs[i]->add("neili", -500);
                        flag = 1;
                } else
                {
                        tell_object(obs[i], HIC "�㷢����ǰ�ľ����ƻ����棬��æ"
                                            "Ĭ���ڹ����������š�\n" NOR);
                        obs[i]->add("neili", -200);
                }
                if (obs[i]->query("neili") < 0)
                        obs[i]->set("neili", 0);
        }


        msg = HIW "$N" HIW "˫��һȦ��ʩ���������־����籧̫����һ��"
              "�ۻ��ޱȵ����������һ�����У�Ȧ�������ķ���\n" NOR;
        
        message_combatd(msg, me, target);

     for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = obs[i]->query_skill("force") * 2 +
                     obs[i]->query_skill("taiji-quan", 1);
                if (ap + random(ap) > dp || random(6)==0)
                {
                        damage = ap + random(ap);

                        obs[i]->receive_damage("qi", damage);
                        obs[i]->receive_wound("qi", damage /2);

                        //obs[i]->receive_damage("jing", damage /6);
                        //obs[i]->receive_wound("jing", damage /6);

                        p = (int)obs[i]->query("qi") * 100 / (int)obs[i]->query("max_qi");


                                msg = HIR + obs[i]->name() +HIR "΢΢һ�㣬��ʱ����������"
                                           "����ԭ�ؼ�ת�߰��£���ת���ݣ�������"
                                           "����\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
 
                         obs[i]->start_busy(3);
                        flag = 1;
                } else
                {
                                msg = CYN + obs[i]->name() +CYN "��״��æʹ����ǧ��׹��֮����"
                       "ס���Σ����������" CYN "��������\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                        obs[i]->add("neili", -200);
                }
                message("vision", msg, environment(me), ({ obs[i] }));
                if (obs[i]->query("neili") < 0)
                        obs[i]->set("neili", 0);
        }

   


       msg = HIY "$N" HIY "Ĭ���񹦣�������ת��˫������������һ��ԲȦ�ѽ���Χ��"
              HIY "��ס��\n̫��ȭ�е����־�����ʹ����һ��"
              HIY "��������������" HIY "��ȥ��\n" NOR;
        
        message_combatd(msg, me, target);

     for (flag = 0, i = 0; i < sizeof(obs); i++)
        {
                dp = obs[i]->query_skill("unarmed") * 2 +
                     obs[i]->query_skill("taiji-quan", 1);
                if (ap + random(ap) > dp || random(6)==0)
                {
                        damage = ap + random(ap);

                        obs[i]->receive_damage("qi", damage);
                        obs[i]->receive_wound("qi", damage /2);

                        //obs[i]->receive_damage("jing", damage /6);
                        //obs[i]->receive_wound("jing", damage /6);

                        p = (int)obs[i]->query("qi") * 100 / (int)obs[i]->query("max_qi");


                                msg = HIC + obs[i]->name() + HIC "��"+ me->name() +"��̫������ѹ��͸����������ֻ����"
                                                   HIC "���顱��һ������"+ obs[i]->name() +"" HIC "��"+ obs[i]->name() +"ȫ���������ɢ��"
                                                   HIC "��һ�㵹����ȥ��\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
 
                        obs[i]->start_busy(3);
                        flag = 1;
                } else
                {
                                msg = "\n��"+ obs[i]->name() +"�����ֱ��"+ me->name() +"���ȫ�����������ܿ���\n" NOR;
                                msg += "( " + obs[i]->name() + eff_status_msg(p) + " )\n\n";
                        obs[i]->add("neili", -200);
                }
                message("vision", msg, environment(me), ({ obs[i] }));
                if (obs[i]->query("neili") < 0)
                        obs[i]->set("neili", 0);
        }


        if (! flag) 
                message_vision(HIM "Ȼ��û���κ�������$N"
                               HIM "��Ӱ�졣\n\n" NOR, me, 0, obs);

        return 1;
}


// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// baihong.c ���׺�������

/*
����ˮ������Ԯ�֣��ܹ���ͯ�ѵļ�������Ϣ��Ȼ���ȣ�˵���������ɣ���
�Ѳ����£����ÿ��ɡ��������ĳ�������һ��������֮���ƹ��������ϣ���
ͯ�ѹ�ȥ��ͯ�����°�����������˾�Ȼ�����ˡ��׺�����������ֱ���⣬
�����˵á�������������ӭ��
*/

#include <ansi.h>

void remove_effect(object me,int strike);

int perform(object me, object target)
{
        int strike;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");


        if( me->query_temp("yield") )
                return notify_fail("�㲻���У����ʹ�����׺���������\n");

        if( me->query_temp("lingjiu/baihong") )
                return notify_fail("���Ѿ���ʹ�á��׺��������ˣ�\n");

        if ( me->query_skill_mapped("force") != "xiaowu-xiang"
                && me->query_skill_mapped("force") != "bahuang-gong"
                && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("�����õ��ڹ��롸�׺��������ķ���㣣�\n");

        if( (int)me->query_skill("strike", 1) < 120 )
                return notify_fail("����Ʒ���Ϊ������������ʩչ���׺���������\n");

        if( (int)me->query_skill("force", 1) < 120 )
                return notify_fail("����ڹ���Ϊ���δ�㣬�޷��԰������������磡\n");

        if( me->query("max_neili") <= 1500 )
                return notify_fail("�������������������޷��������磡\n");

        if( me->query("neili") <= 500 )
                return notify_fail("������������������޷��������磡\n");

        if( me->query("jing") <= 200 )
                return notify_fail("��ľ������ޣ�����ʩչ���׺���������\n");

        me->add("neili", -100);
        me->add("jing", -150);

        strike = me->query_skill("strike") / 8;

        me->add_temp("apply/attack", strike);
        me->set_temp("lingjiu/baihong", strike);

        message_combatd(WHT "\n$N�����ĳ�������һ��������֮�����²��������Ź���������ң���ϳ��Ʒ���\n"
                            "��"+ HIW +"���׺�������"+ NOR + WHT +"���˿�$N������ֱ���⣬�����˵ã�\n" NOR, me);

        call_out("checking", 1, me, strike);
        return 1;
}

void checking(object me, int strike)
{
        if( !me ) return;

        if( !living(me) || me->is_ghost() )
        {
                remove_effect(me, strike);
                return;
        }
        else if( !me->is_fighting() && !me->is_busy() )
        {
                remove_effect(me, strike);
                message_combatd(WHT "\n$N����һ�ӣ�������ǰ�ػ��˸��������������²�����������\n"NOR, me);
                me->start_busy(1);
                return;
        }
        else if( (int)me->query("neili") < (int)me->query("max_neili") / 5 ||
                (int)me->query("jing") < (int)me->query("max_jing") / 4 )
        {
                remove_effect(me, strike);
                tell_object(me, HIR "\n��΢����Ϣ���������ò��������ջأ�\n" NOR);
                message_combatd(CYN "\n" + me->name() + CYN "˫��һ�ͣ������Ѳ���֮ǰ�����޳�����ò�����\n" NOR, 
                                me);
                me->start_busy(2);
                return;
        }
        else if( me->query_skill_mapped("strike") != "liuyang-zhang" && !me->is_busy() )
        {
                remove_effect(me, strike);
                message_combatd(CYN "\n$NȦת���ƣ�ͻȻ���У������Ѳ���֮ǰ�����޳�����ò�����\n"NOR, me);
                return; 
        }
        else if( me->query_temp("lingjiu/baihong") <= 50 )
        {
                remove_effect(me, strike);
                message_combatd(HIC "\n$N����Ȧת���ѿ�����һ·"+ HIW +"���׺�������"+ HIC +"����ʹ����\n"NOR, me);
                return; 
        }

        call_out("checking", 1, me, strike);
} 

void remove_effect(object me, int strike)
{
        if (! objectp(me)) return;
        
        me->delete_temp("lingjiu/baihong");
        me->add_temp("apply/attack", -strike);
}


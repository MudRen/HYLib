// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// youming.c  ��ڤ��Ӱ

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        int skill;


        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("����ڤ��Ӱ��ֻ����ս����ʹ�á�\n");

        if ((int)me->query_skill("youming-guizhao", 1) < 120 )
                return notify_fail("�����ڤ��צ�ȼ����������ܺ�����Ӱ��\n");    

        if ((int)me->query_skill("claw", 1) < 120 )
                return notify_fail("��Ļ���צ����������죬���ܺ�����Ӱ��\n");    

        if (objectp(me->query_temp("weapon")))
                return notify_fail("��������ʹ�á���ڤ��Ӱ����\n");

        
        if ((int)me->query_skill("xiaowuxiang", 1)<100
		&& (int)me->query_skill("bahuang-gong", 1)<100
		&& (int)me->query_skill("beiming-shengong", 1)<100)
                return notify_fail("�����ң���ڹ���򲻹���\n");

        if (me->query_skill_mapped("force") != "xiaowuxiang"
		&& me->query_skill_mapped("force") != "bahuang-gong"
		&& me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û��������ң���ڹ���\n");	
        

        if (me->query_skill_prepared("claw") != "youming-guizhao"
                || me->query_skill_mapped("claw") != "youming-guizhao"
                )
                return notify_fail("�������޷���������Ӱ���й�����\n"); 

        if ((int)me->query("neili") < 800)
                return notify_fail("����������̫�������ܺ�����Ӱ��\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("����������̫�������ܺ�����Ӱ��\n");

        if ((int)me->query_temp("lingjiu/youming", 1)) 
                return notify_fail("���Ѿ�����������ڤ��Ӱ��\n");

        skill = me->query_skill("claw");

        message_combatd(HIR "ͻȻ$Nҧ����⣬�����л���ع�����ͬ����һ�㣡���ŵ���������ˮ����ֻ��\n"
                        "һ��"HIB"��Ӱ"HIR"�ӵص�ð�������ڰ�գ�����Ʈ�첻����ʱ����һ����ʱ����һ��Ӱ��\n\n" NOR, 
                        me);

        me->add("neili", -skill);    
        me->set_temp("lingjiu/youming", 1);
	me->add_temp("apply/defense",  skill / 2);

        call_out("checking", 1, me, target);
        call_out("remove_effect", skill/5+2, me); 
        
        return 1;
}
void checking(object me, object target)
{
        int skill;
        skill = me->query_skill("claw");

        if( !living(me) || me->is_ghost() )
	{
		message_combatd(HIR"����"HIB"��Ӱ"HIR"�ڰ���ǻ���һ�󣬾���ʧ�ڵص��ˣ�\n"NOR, me);
		me->add_temp("apply/defense",  -skill/2);
		me->delete_temp("lingjiu/youming");
		remove_call_out("remove_effect");
		return ;
	}
        if( !me->is_fighting() )
	{
		message_combatd(HIR"����"HIB"��Ӱ"HIR"�ڰ���ǻ���һ�󣬾���ʧ�ڵص��ˣ�\n"NOR, me);
		me->add_temp("apply/defense",  -skill/2);
		me->delete_temp("lingjiu/youming");
		remove_call_out("remove_effect");
		return ;
	}
        if( me->query_skill_mapped("force") != "bahuang-gong"
	   || me->query_skill_mapped("claw") != "youming-guizhao"
	    )
	{
		tell_object(me,"\n$N��Ȼ�任�����������ټ�������ڤ��Ӱǣ�ƶ��ֵĹ�����\n");
		me->add_temp("apply/defense",  -skill/2);
		message_combatd(HIR"����"HIB"��Ӱ"HIR"�ڰ���ǻ���һ�󣬾���ʧ�ڵص��ˣ�\n"NOR, me);
		me->delete_temp("lingjiu/youming");
		remove_call_out("remove_effect");
		return ;
	}
        else 
	        call_out("checking", 1, me, target);
        return;
}
void remove_effect(object me)
{
        int skill;
        
        if (! me) return;
                
        skill = me->query_skill("claw");

        message_combatd(HIR"����Ĳ�����������������"HIB"��Ӱ"HIR"�ڰ���ǻ���һ�󣬾���ʧ�ڵص��ˣ�\n"NOR, me);
	me->add_temp("apply/defense",  -skill/2);
	me->delete_temp("lingjiu/youming");
        return;
}

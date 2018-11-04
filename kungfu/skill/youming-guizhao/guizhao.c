// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// guizhao.c  �����צ

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;


int perform(object me, object target)
{
        int skill, ap, dp, damage;
        string msg, pmsg;
        object weapon;
        int extra,i;
        int p;
        int lv, cost_neili;

        if (! target)
        {
                me->clean_up_enemy();
                target = me->select_opponent();
        }

        if (! target || ! me->is_fighting(target))
                return notify_fail("�������צ��ֻ����ս����ʹ�á�\n");

        //if ((string)me->query("gender") != "Ů��")
        //        return notify_fail("����Ϊ���ӣ�������ᡸ�����צ�����еİ��\n");

        //if ((int)me->query("shen", 1) > 0)
        //        return notify_fail("�����������ʿ���������á������צ�����������书��\n");

        if ((int)me->query_skill("youming-guizhao", 1) < 180)
                return notify_fail("�����ڤ��צ�ȼ�����������ʹ�á������צ����\n");    

        if ((int)me->query_skill("claw", 1) < 180)
                return notify_fail("��Ļ���צ����������죬����ʹ�á������צ����\n");    

        if ((int)me->query_skill("force", 1) < 180)
                return notify_fail("��Ļ����ڹ���򲻹���ǿ��ʹ�á������צ���������Լ��ľ�����\n");

        
        if ((int)me->query_skill("xiaowuxiang", 1) < 180
                && (int)me->query_skill("bahuang-gong", 1) < 180
                && (int)me->query_skill("beiming-shengong", 1) < 180)
                return notify_fail("�����ң���ڹ���򲻹���\n");

        if (me->query_skill_mapped("force") != "xiaowuxiang"
                && me->query_skill_mapped("force") != "bahuang-gong"
                && me->query_skill_mapped("force") != "beiming-shengong")
                return notify_fail("��û��������ң���ڹ���\n");	
        

        if ((int)me->query("neili") < 800)
                return notify_fail("����������̫��������ʹ�á������צ����\n");

        if ((int)me->query("max_neili") < 1000)
                return notify_fail("����������̫��������ʹ�á������צ����\n");

        if (me->query_temp("gz_pfmed") == 1)
                return notify_fail("���ʹ����һ�У����ܾۼ��㹻��Ԫ����\n");

        if (! me->query("jiali"))
                return notify_fail("��צ�ϴ������㣬����ʹ�á������צ����\n");

        skill = (int)me->query_skill("youming-guizhao", 1);

        message_combatd(HIB "\nͻȻ$N" HIB "��˫�Ʊ�צ������ǰ����糵�㼱ת��Ȧ������˫צ����һ��\n"
                        "����$n" HIB "��ת��Ȧ�������ָ����$n����ֱ�²��䡣\n\n" NOR, me, target);

	me->add("neili", -400);
	me->set_temp("gz_pfmed", 1);
	
        call_out("recover", 1800 / skill, me);
	

        ap =  me->query_skill("claw");
        dp =  target->query_skill("dodge");
        
        if (ap / 2 + random(ap) > dp)
        {
                me->add("neili", -100);
                damage =  me->query_skill("claw");
   target->add("qi",-damage*2);
		target->add("eff_qi",-damage*2);
                msg = HIR "$n" HIR "ֻ����ͷ��һ��������$N"
                       HIR "����צ����$n" HIR "ͷ������������������ָ����\n" NOR;

               // pmsg = HIR "$n" HIR "ֻ����ͷ��һ��������$N"
               //        HIR "����צ����$n" HIR "ͷ������������������ָ����\n" NOR; 
//                msg = COMBAT_D->do_damage(me, target, UNARMED_ATTACK, damage, 90, pmsg);
                me->start_busy(4);                
	} else
	{
	        msg = CYN "����$p" CYN"��������������������ͷ������㣬���ǿ����ܹ�$P"
	              CYN "�Ĺ��������Ѿ�����һ���亹��\n\n" NOR;
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
	if (random(3)==0) target->start_busy(3);
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

int recover(object me)
{
        if (! me) return 0;
        
        me->delete_temp("gz_pfmed");
        return 1;
}

// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// bafang.c ����˷�
         
#include <ansi.h>
#include <combat.h> 
         
inherit F_SSERVER; 

         
int perform(object me, object target) 
{ 
        object weapon; 
        string msg; 
        int ap, dp; 
        int damage; 
                        
        if (! target) target = offensive_target(me); 
        
        if (! target || ! me->is_fighting(target)) 
                return notify_fail("������˷���ֻ����ս���жԶ���ʹ�á�\n"); 
         
        if (me->query_temp("weapon") || 
            me->query_temp("secondary_weapon")) 
                return notify_fail("�������ֲ���ʹ�á�����˷�����\n"); 
         
        if (me->query_skill("force") < 300) 
                return notify_fail("����ڹ�����Ϊ����������ʹ����һ������\n"); 
        
        if (me->query_skill("bazhen-zhang", 1) < 200) 
                return notify_fail("��������书��Ϊ������Ŀǰ����ʹ�á�����˷�����\n"); 
         
        if (me->query("neili") < 700) 
                return notify_fail("��������������޷�ʹ�á�����˷�����\n"); 
         
        if (me->query_skill_mapped("strike") != "bazhen-zhang") 
                return notify_fail("��û�м��������书������ʹ�á�����˷�����\n"); 
         
        msg = HIY "$N" HIY "���������һ���������һ����ȫ�������޷��Թģ�" 
                   HIY "Ȼ����������һ�ݣ��Ӹ����£�˫�Ʒ������£�ɲ�Ǽ䣬�ھ����������"
                   "����$n" + HIY "��\n" NOR; 
         
        ap = me->query_skill("strike") + me->query("str") * 20;
        dp = target->query_skill("parry") + target->query("dex") * 20;
        
        if (ap / 2 + random(ap) > dp)
        { 
                damage = me->query_skill("strike");
                me->add("neili", -350); 
         
target->add("qi",-damage*2);
target->add("eff_qi",-damage*2);
target->apply_condition("zhua_poison",10);

                        msg +=                 HIR "ֻ��$n" HIR "���һ�����ֻ�֮�²������㣬��$N"
                                           HIR "һ�ƴ��˸����У��ƺ�һ��������������\n" NOR;
        } else 
        { 
                me->add("neili", -100); 
                me->start_busy(3); 
                msg += CYN "����$p" CYN "������$N" CYN "����ͼ������" 
                       CYN "���Ʈ�����ɣ��������һ������һ����\n"NOR; 
        } 
        message_combatd(msg, me, target); 
	      msg = HIC  "���򶫷���$N�Ӷ�������һ�ƣ�" NOR;
	      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "����������$N����������һ�ƣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "�����Ϸ���$N���Ϸ�����һ�ƣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "���򱱷���$N�ӱ�������һ�ƣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIG  "�����Ϸ���$N���Ϸ�����һ�ƣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "�����·���$N���·�����һ�ƣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);         
        msg = HIY  "����ǰ����$N��ǰ������һ�ƣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);         

        msg = CYN  "����󷽣�$N�Ӻ󷽴���һ�ƣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);         
                me->start_busy(3);
                me->add("neili", -380);
        return 1; 
}

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra,bonus, exp_bonus;
        if( !target ) target = offensive_target(me); 
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ƽ���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");
        extra = me->query_skill("hanshan-strike",1) ;
        if( extra < 90) return notify_fail("��ģۺ�ɽ�Ʒ��ݻ�����������\n");
        
        bonus=extra/3;
         if((int)me->query_skill("bingxue-xinfa",1) < 150)
                return notify_fail("��ı�ѩ�ķ���Ϊ������\n");

         if((int)me->query_skill("snow-zhang",1) < 150)
                return notify_fail("��ķ�ѩӳ÷����Ϊ������\n");

         if((int)me->query_skill("hanshan-strike",1) < 50)
                return notify_fail("��������书��Ϊ������\n");
        
        exp_bonus= me->query("combat_exp")/1000*extra/5000;
        if (exp_bonus>extra) exp_bonus=extra;
        
        bonus = bonus + exp_bonus;
        
        if (bonus> 300) bonus=300;
        
        me->add_temp("apply/attack", bonus);
        me->add_temp("apply/damage", bonus);
        msg = HIM  "$N˫�ƻ��ཻ��ͻһ����˫�ֻ���Ϊ������$n"NOR+HIM"��ȥ��" NOR;
        if (random(3)==0) target->start_busy(3);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$Nһ����һ��ײ��$n"NOR+HIY"�����ţ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (extra>110) {
        msg = HIW  "$N��һ����˫�Ƽ���$n"NOR+HIW"��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        }
        if (extra>150) {
        msg = HIR  "$N���ֺ��أ����ֺ�һ���ƣ������Ѿõģ��ƽ����ƿ���$n"NOR+HIR"��ȥ��" NOR;
        me->add_temp("apply/attack", bonus);
        me->add_temp("apply/damage", bonus);
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if (random(2)==0 ) 
{
        message_vision( MAG "$N���Ʒ������Ļ������Ի�,�Ե�������ã...�� ���������ص�һ���ƺߣ�һ��Ѫ���Ӷ�����ӿ������\n" NOR,target);
        target->receive_wound("qi",bonus*8);
}
        me->add_temp("apply/attack", -bonus);
   me->add_temp("apply/damage", -bonus);
        }
        me->add_temp("apply/attack", -bonus);
        me->add_temp("apply/damage", -bonus);
me->start_busy(3);
me->add("neili", -250);
        return 1;
}      

 // silencer@fengyun ����է�� ����ʱ��NPC, players ���� pfm,
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra, my_exp,your_exp, lvl, duration;

        lvl= me->query_skill("lansha-shou",1);
        if (lvl<80)
                return notify_fail("�����ɰ�ֻ���������\n");         
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۲���է�֣�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");

        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail( "ֻ�ܿ���ʩչ��\n");        
                if (extra> 200) extra=200;
        
        extra = me->query_skill("lansha-shou",1);
        me->add_temp("apply/attack", extra);    
        msg = HIR  "$N"+HIR"����һת��ͻȻ���η���˫����������ڿ�һ���͵���$n"+HIR"�߳���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -extra);
        me->add("neili",-200);
                 me->start_busy(2);
        if (me->query_skill("lansha-shou",1)>188 && random(3)==0 ) {
                target->receive_wound("qi",(extra*5+300));
                message_vision(RED"$n"+RED"һ���ҽУ���$N"+RED"�ߵÿ�����Ѫ��\n\n"NOR,me,target);
        }               
        
        my_exp=me->query("combat_exp");
        your_exp=target->query("combat_exp");
        
        if (your_exp>5000000) your_exp = your_exp*3/2;
                
        // lvl = 160/30 = 5+1 = random(6)
   lvl=lvl/30;
        if (lvl<1) lvl=1;
                        
        if ((lvl+1)*random(my_exp)>your_exp) {  
                if (!target->query_temp("till_death/lockup")) {
                        message_vision(HIW"$N"+HIW"�������ȷ�ɨ����$n"+HIW"ֻ���������ͣ�һ���������᲻������\n"NOR,me,target);
                        target->start_busy(5);
                        target->receive_wound("qi",(extra*3));
                        duration = 10+ random(lvl*2);
                        if (your_exp>=5000000)  duration = 6+random(lvl);
                        if (target->query("big_boss") || target->query("boss")) duration = random(4);
                        target->start_call_out( (: call_other, __FILE__, "remove_effect",target:),duration );           
                }
                if (me->query_skill("lansha-shou",1)>149 && !target->is_busy()) {
                                        target->start_busy(3);
                                        message_vision(HIY"$N"+HIY"�Ų����ģ�˫������ǰ��,��վ�����ȡ�\n"NOR,target);
                } else if (me->query_skill("lansha-shou",1)>99 && !target->is_busy()) {
                                                target->start_busy(3);
                        message_vision(HIY"$N"+HIY"�Ų����ģ�˫������ǰ��,��վ�����ȡ�\n"NOR,target);   
                }
        }
        
        return 1;
}  
void remove_effect(object target)
{
        target->delete_temp("till_death/lockup");
        tell_object(target,HIG"������һ������������ת�糣��\n"NOR);
}     

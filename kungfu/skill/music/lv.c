#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
         extra = me->query_skill("music",1);
        if ( extra < 180) return notify_fail("����ٵ����������죡\n");
                
        dodskill = (string) me->query_skill_mapped("dodge");

    if( (int)me->query_skill("xuantian-wuji", 1) < 50 )
	return notify_fail("��ı����ڹ���δ���ɣ�����ʹ�ã�\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");
                
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ʮ���ɣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        tmp=tmp/2;       
        if (extra> 200) extra=200;
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra*3);
    msg = HIW "\n\n$N���һ������Ȼʹ����--����ʮ����--��!!\n$N����12������ �ɻ�������$n"+HIW"Ϯ����\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR  "����������̫�ء�\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIM  "����ӡ��ơ��ϴ��\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG  "��������Ρ�ި����\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIM  "�����ӡ︽�������\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIC  "����������������\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = CYN  "��Ӧ�ӡ�ϡ���ӡ�\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "\n$N"+HIC"�Ღ���ң�����������ƽ���кͣ�����������֮�⣡\n" NOR;
		msg += HIC "�����ÿ�������֮��������������������ȸ�񣬻�ֹЪ���ۣ������°��裬ë���ͷף�εΪ��ۡ�\n\n"NOR;
        message_vision(msg, me);
 if (random((int)target->query("combat_exp")) < (int)me->query("combat_exp")) {
            message_vision(HIY"һ����������������$N"+HIY"ʹ�������˫�����Ų�Ư���������࿪ʼ����Ժ���\n"NOR, target); 
			target->receive_wound("qi", me->query_skill("music",1)*3+800);
            target->start_busy(3);
}            
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra*3);

me->add("neili",-380);
                me->start_busy(3);
        return 1;
}   

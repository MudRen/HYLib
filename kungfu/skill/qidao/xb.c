#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
         extra = me->query_skill("qidao",1);
        if ( extra < 250) return notify_fail("���������������죡\n");
                
        dodskill = (string) me->query_skill_mapped("dodge");

    if( (int)me->query_skill("xuantian-wuji", 1) < 150 )
	return notify_fail("��ı����ڹ���δ���ɣ�����ʹ�ã�\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");
                
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۴�ѩ���Ͷ�ʽ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        tmp=tmp/2;       
        if (extra> 200) extra=200;
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra*3);
    msg = HIW "\n\n$N���һ����˫ָ��磬��Ȼʹ����--��ѩ���Ͷ�ʽ--��!!\n$N��ָ������ɫ��â��������ƬƬ����$n"+HIW"Ϯ����\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR  "��һ�ӽ�˫����\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIM  "�����֮ͷʽ��\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG  "�������ѽ�ʽ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIM  "���ĽǴ���ʽ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIC  "�������ɹ�ʽ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = CYN  "�������ر�ʽ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY  "�������˻�ʽ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY  "�����̫��ʽ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);



        msg = HIC "\n$N"+HIG"˫ָ���� �����ر߻�Ҳ�䣬����ͬ�������У������а���֮�⣡\n" NOR;
		msg += HIW "�����ÿ������ӷ���֮��������������ܻ�����ݺ�˵�һ�㡣\n\n"NOR;
        message_vision(msg, me);
 if (random((int)target->query("combat_exp")) < (int)me->query("combat_exp")) {
            message_vision(HIR"һ��������ص�������$N"+HIR"���϶��˼���Ѫ����\n"NOR, target); 
			target->receive_wound("qi", me->query_skill("qidao",1)*5+800);
            target->start_busy(3);
}            
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra*3);

me->add("neili",-380);
                me->start_busy(3);
        return 1;
}   

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER; 
int begin_perform(object me,object target,int count,int tmp,int extra,object weapon);
int perform(object me, object target)
{
        string forceskill,msg;
        int extra, exp_bonus;
        int tmp;
        object weapon;
        forceskill= me->query_skill_mapped("force"); 
        weapon=me->query_temp("weapon");
        extra = me->query_skill("yuejia-qian",1);
        if ( extra < 280) 
                return notify_fail("���������ƽǹ�����������죡\n");

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���ݺ����¡�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 1500  ) 
		return notify_fail("�������������\n");
        
                
        exp_bonus = me->query("combat_exp")/1000*extra/2000;    
        if (exp_bonus>extra*4) exp_bonus=extra*4;
        
        forceskill = (string) me->query_skill_mapped("force");
if (random(3)==0) target->start_busy(2);
                
        me->add_temp("apply/attack",100);
        me->add_temp("apply/damage",1000);  
        msg = HIW "\n$N���쳤Х����Ȼ����ֱ������������$w"+HIW"�û���ǧ��ìӰ�����ǡ�������ƽǹ����\n��ս�޵�֮ʽ��--��-��-��-��--��!!"NOR+HIC"\n\n��\n$N����$w"HIC"ֱָ���գ���Ȼֱ��$n!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIC  "����\n$Nŭ��һ����ǧ��ìӰ���κ��˰�ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIC  "����Ȼ\n$N��ǹ֮�������м䣬ǹͷǹβ���������������$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		me->add_temp("apply/damage",extra);  
    msg = HIR  "�ݺ�����\n$N����$w"+HIR"������Ҷ���޴����ڣ�����ǹӰ��һ����ֱ��$n��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra); 
    msg = HIC  "��˻\n$w"+HIC"�������磬�������죬�·������ڣ�" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);        
    msg = HIC  "Ѫ��\n$N����$w"+HIC"ǹͷ����ٿ�ñ������������Ѫ�⣡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIW  "��\n����һ��ͻ��������$N����$w"+HIW"ǹӰ��ʧ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack",-100);
        me->add_temp("apply/damage",-1000); 
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
   {
 target->add("qi",extra*3);
 target->add("eff_qi",extra*3);
 target->add("eff_jing",extra);
 target->start_busy(3);
                message_vision(HIG"$N�������ƣ���������Ц̸������ūѪ������ǹӰ����������գ�\n"NOR,me,target);
message_vision(RED"$n������ǹ��Ŀ�ɿڴ�����֪����мܣ���\n"NOR,me,target);
}           
me->add("neili",-380);
         me->start_busy(3);   
        return 1;
}       

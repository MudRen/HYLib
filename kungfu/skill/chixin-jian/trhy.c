 // ���������콣���ľ��С����˺�һ��
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int delay,i,skill;
        object weapon;
        skill=(int)me->query_skill("chixin-jian",1);
	if ((int)me->query_skill("chixin-jian",1)>=200)
	            i=(me->query_skill("chixin-jian",1) - 180)/20;
	if(i == 0) i=1;
	if(i >= 3) i=3;          

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����˺�һ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if((int) me->query_skill("chixin-jian",1) < 200)
                return notify_fail("������Ž������������������ܷ��������˺�һ����\n");
        if (me->query_skill("bibo-shengong", 1) < 150)  
                return notify_fail("��ı���������Ϊ������\n");  

         if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");                       

        if (me->query("neili") < 600)
                return notify_fail("��������������޷�ʹ�á�������������\n");


        delay=1+ random(3-i);
        message_vision(HIG"$N�������ֹˮ������������ء�\n"NOR,me,target);
        me->start_call_out( (: call_other, __FILE__, "kill_him", me, 
target :), delay);
        me->start_busy(1+random(3-i));
        return 1;
}
void kill_him(object me, object target)
{
        int targetexp,damage,mylevel,myexp,targetkee;
        int res_kee;
        int i,x,lvl,skill;
        string msg;
        skill=(int)me->query_skill("chixin-jian",1);
        if ((int)me->query_skill("chixin-jian",1)>=200)
	    i=(me->query_skill("chixin-jian",1) - 180)/20;
	if(i == 0) i=1;
	if(i >= 3) i=3;   
	
	lvl=me->query_skill("chixin-jian",1);
	x=(lvl-190)/2;
        if(x==0) x=1;
        if(x>=50) x=50;

        if(me->is_fighting() && target->is_fighting() &&
        environment(me) == environment(target))
        {
msg = HIY "\n����һ����û������$N���У���ʱ��ͣ��ֹ�������Ϣ���ղŵ�һ���� 
���ƺ�ֻ��һ�����Σ���Ȼ�޴档" ;
        targetexp=target->query("combat_exp");
        myexp=me->query("combat_exp");
	mylevel=me->query_skill("chixin-jian", 1)/3;
        targetkee=target->query("max_qi");
        damage=targetkee*(20+random(50)+random(mylevel))/100;
        if (damage > 12000) damage=12000;
        
        if(random(targetexp*2)+myexp>targetexp)
           {     msg += HIR "\n$nֻ������һ����һ֧Ѫ��ͻȻ��$p��ǰ������\n" NOR;
                 target->start_busy(random(i));
           }                
        else {
                msg+=HIR "\n$n�͵�һ�����ǳ��Ǳ��Ķ����$N����һ������ȴ�޷��������Ľ�����\n"NOR;
                damage=random(damage/2);
                target->start_busy(1+random(i));
        }
        target->receive_wound("qi",damage); 
        message_vision(msg, me, target);

        COMBAT_D->report_status(target);

        }
me->add("neili",-300);
if( (!userp(me) || skill>300)) {
if (random(3)==0) target->start_busy(3);
               msg=HIG "�ɽ�����$N����ᵯ����$w��ֱ��$n��$l��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIR "��ɽ�续����$N����Ծ��ֱ�����죬����$w�������������϶��¹���$n��$l��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIG "�ƽ�����$N����$w�������ƣ�Ʈ��$n��$l��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIR "������������$N�����һ������������$w��Х��������$n��$l��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIG "ʯ������$N����$w������ǧ�����$n��$l��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIR "�������ڣ���$N����һ��������$wȦת��Х����ǿ������Х����Ȼһ�壬����$n��$l��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIG "Ȫ������$N�����ڶ�������$w����ˮ��Ϯ��$n��$l��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add("neili",-200);
}

        me->start_busy(2);
        return ;
}  


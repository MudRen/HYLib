 // mimicat@fy4
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int begin_perform(object me,object target,int extra, int skill);
int perform(object me, object target)
{
        string msg;
        int extra, skill,resist;
        object weapon;
        

                        

        if(me->query_skill("chixin-jian",1)<150)
                return notify_fail("������鳤������Ϊ������\n"); 



        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ĺ��ɺ��ֻ�ܶ�ս���еĶ���ʹ�á�\n"); 
        if (me->query_temp("muyu"))
                return notify_fail("���Ѿ���ʹ�ã�ĺ��ɺ���ˡ�\n");

        if (me->query_skill("bibo-shengong", 1) < 150)  
                return notify_fail("��ı���������Ϊ������\n");  

         if (! objectp(weapon = me->query_temp("weapon")) ||
              (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");                       

        if (me->query("neili") < 600)
                return notify_fail("��������������޷�ʹ�á�������������\n");
                
        weapon = me->query_temp("weapon");
        
        extra = me->query_skill("sword");
        skill = me->query_skill("chixin-jian",1);
        

        
        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 1000);
        msg = HIC "$Nһ���ӳ�����Ϧ�����������գ���ʺ磬�������ƣ��綯�־���������ʵ��
�����������ң�����ǰ�������ᣬ��������������ʵ�� \n"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1000);
   
        if( (!userp(me) || skill>170)) {
                msg=HIW"������ɺ磬ɭ���Ľ��������������衣\n"NOR;   

        me->add_temp("apply/attack", 100);    
        me->add_temp("apply/damage", 1000);      
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         me->add_temp("apply/attack", -100);
        me->add_temp("apply/damage", -1000);

                me->start_busy(3);
                }
        else {
                 me->add("neili",-200);
                 me->start_busy(3);
                }

                
if( (!userp(me) || skill>300)) {
               msg=HIG"�����������ԣ���"NOR + "$N�Ӷ�����$w����������Ƶ���$n��$l��ȥ��";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIR"��������Ʈҡ����"NOR + "$N�����ƶ����壬����$w�������꣬��$nΧ���м䣡";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIC"����ϸˮ��������"NOR + "$N����ǰ�������������ޣ�$w��������$n��$l��ȥ";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIY"����������磪��"NOR + "$N����$w����΢�񣬻ó�һ���������$n��$l";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIG"����������񣪡�"NOR +  "$N����$w�й�ֱ����������Ϣ�ض�׼$n��$l�̳�һ��";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIR"���������޷죪��"NOR +  "$N����$wбָ���죬��â���£���׼$n��$lбб����";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
               msg=HIC"����������·����"NOR +  "$Nһ�����е�$w��������ʱ��к����������$n��������Ȼ����";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add("neili",-200);
}

        return 1;
}   

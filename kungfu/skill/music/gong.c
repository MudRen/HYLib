#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
        int basic;
        int i, flag;
        object weapon;
        
         extra = me->query_skill("music",1);
        if ( extra < 30) return notify_fail("����ٵ����������죡\n");
                
        dodskill = (string) me->query_skill_mapped("dodge");

    if( (int)me->query_skill("xuantian-wuji", 1) < 50 )
	return notify_fail("��ı����ڹ���δ���ɣ�����ʹ�ã�\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");
        
                
        basic = extra/40 + tmp/40;
        if (basic>7)
                basic=7;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���������ң�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
        weapon = me->query_temp("weapon");
        msg = HIR"$N ���쳤Х һ��Ϊ���ӣ�����Ϊ���������Ϊ���ǣ�Х�����죡\n"NOR;
        message_vision(msg, me, target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
   {
                message_vision("���$NĿ�ɿڴ�����֪����мܣ�\n",target);
				if (!target->is_busy()) 
                            target->start_busy(5);

                        msg = HIY"��Х���У�$N����»��������ֽ�����Ծ��\n"NOR;
                        message_vision(msg, me, target);
                me->add_temp("apply/attack",100);
                me->add_temp("apply/damage",2000);
                for(i=0;i<basic;i++)
                {
                        if (me->is_busy()) continue;
              msg=HIG"�������� ��"+(i+1)+"ʽ"NOR;
              COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

 me->add("neili",-50);
                }
				me->add_temp("apply/attack",-100);
                me->add_temp("apply/damage",-2000);
                        me->start_busy(3);

        }
        else{
                message_vision("����$N�Ѿ�����$n�Ĺ�ʽ��$n�������ƣ�\n",target,me);
                me->start_busy(2);
              
                
        }
       
        return 1;
}      

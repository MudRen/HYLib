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
        
        extra = me->query_skill("yuejia-qian",1);
        tmp = me->query_skill("club",1);
        flag = 0;
        
        if ( extra < 60) 
                return notify_fail("�������ǹ�����������죡\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "club")
		return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");

        dodskill = (string) me->query_skill_mapped("dodge");

        

        
                
        basic = extra/40 + tmp/40;
        if (basic>9)
                basic=9;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("������ȸߣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        msg = HIR"$N������"NOR+weapon->name()+HIR"��أ�����������չ�ᣬһ�ɳ��죡\n"NOR;
        message_vision(msg, me, target);
        if(random((int)target->query("combat_exp")) < (int)me->query("combat_exp"))
   {
                message_vision("���$NĿ�ɿڴ�����֪����мܣ�\n",target);

                            target->start_busy(3);


                me->add_temp("apply/attack",100);
                me->add_temp("apply/damage",1000);
                for(i=0;i<basic;i++)
                {
                        if (me->is_busy()) continue;
                        msg = HIY"��Ц���У�$N����»��������ֽ�����Ծ��\n"NOR;

                        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                        me->add("neili",-30);
                }

                        me->start_busy(3);
				me->add_temp("apply/attack",-100);
                me->add_temp("apply/damage",-1000);
        }
        else{
                message_vision("����$N�Ѿ�����$n�Ĺ�ʽ��$n�������ƣ�\n",target,me);
                me->start_busy(2);
                        COMBAT_D->do_attack(target,me,target->query_temp("weapon"),TYPE_REGULAR,msg);
                
        }
        return 1;
}      

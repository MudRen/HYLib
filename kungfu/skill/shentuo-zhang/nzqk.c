 // tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int mine,yours;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��ŤתǬ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	if ((int)me->query_skill("shentuo-zhang", 1) < 180)
		return notify_fail("�������ѩɽ�Ʋ�����졣\n");
	                        
	if ((int)me->query("neili") < 200)
		return notify_fail("����������������\n");

        mine = (int) me->query("combat_exp");
        yours = (int) target->query("combat_exp");
        message_vision(HIW"\n$NͻȻ����һ����Ť����ת����Ǭ������������\n\n",me);
        if(random(mine) > yours)
        {
                //me->add("force_factor",yours/2);
                msg= HIY "$N������ѩɽ���еģ�ŤתǬ����ʹ����˫�Ƽд���$n����������$n" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                target->start_busy(3);
               
                //me->add("force_factor",-yours/2);
        }               
        else
        {
                //target->add("force_factor",mine/2);
                msg= HIY "$N����$n����֮�ʣ�����ֱ�ߣ���Ѹ���ޱȵ��ٶȹ���$n��" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
                //target->add("force_factor",-mine/2); 
        }
        
	      msg = RED  "��һ�ƣ�" NOR;
	      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "��һ�ƣ���" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "��һ�ƣ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "��һ�ƣ�������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "ǰһ�ƣ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED  "��һ�ƣ�������" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = RED  "���һ��!!!!" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -300);
         me->start_busy(2);
        return 1;
}   

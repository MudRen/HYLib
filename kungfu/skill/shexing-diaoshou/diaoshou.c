#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	 int extra;
	 object weapon;
        extra = me->query_skill("shexing-diaoshou",1);
	 if( !target ) target = offensive_target(me);
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("���������Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

               if( objectp(me->query_temp("weapon")) )
              return notify_fail("��������ʹ�á��������Ρ���\n");
     
        if( (int)me->query_skill("shexing-diaoshou", 1) < 200 )
                return notify_fail("��Ĺ��򲻹���죬�޷�ʩչ�����������Ρ���\n");
       
	if ((int)me->query_skill("hamagong", 1) < 20)
		return notify_fail("��ĸ�󡹦��򲻹���\n");

        if ( (int)me->query("max_neili") < 500)
                return notify_fail("��������������޷�ʩչ�����������Ρ���\n");
        if ( (int)me->query("neili") < 100)
                return notify_fail("��������������޷�ʩչ�����������Ρ���\n");
	          me->add_temp("apply/strength", extra/4);
                 me->add_temp("apply/attack", extra);
me->set_temp("noauto",1);
	me->add("neili", -100);
		 msg = YEL "$Nȭ���������֣��������ޣ���ɫ����Ļ�������ʲô��ֵĴ���$n��" NOR;
       	         message_vision(msg, me, target);                
	 msg =  HIC  "$N��$n��ߴ�������ͻȻ����$n�ұߣ�" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "$N��$n�ұߴ�������ͻȻ����$n��ߣ�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "$N��$n�ϱߴ�������ͻȻ����$n�±ߣ�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->delete_temp("noauto");
        me->add_temp("apply/strength", -extra/4);
        me->add_temp("apply/attack", -extra);
        me->start_busy(2);
        return 1;
}

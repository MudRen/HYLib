// shuangjue.c  ȭ��˫��

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
        extra = me->query_skill("chanyun-tui",1);
	 if( !target ) target = offensive_target(me);
        if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("ȭ��˫��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

               if( objectp(me->query_temp("weapon")) )
               return notify_fail("��������ʹ�á�ȭ��˫������\n");

        if (me->query_skill_mapped("unarmed") != "chuanyun-tui")
                return notify_fail("�������޷�ʹ�á�ȭ��˫�������й���.\n");                                                                                 

        if (me->query_skill_mapped("cuff") != "zhentian-quan")
                return notify_fail("�������޷�ʹ�á�ȭ��˫�������й�����\n");

        if( (int)me->query_skill("zhentian-quan", 1) < 100 )
                return notify_fail("�������ȭ������죬�޷�ʩչ��ȭ��˫����\n");
        
        if( (int)me->query_skill("chuanyun-tui", 1) < 150 )
                return notify_fail("��Ĵ����Ȳ�����죬�޷�ʩչ��ȭ��˫����\n");
        if ( (int)me->query("max_neili") < 1000)
                return notify_fail("��������������޷�ʩչ��ȭ��˫����\n");
        if ( (int)me->query("neili") < 1000)
                return notify_fail("��������������޷�ʩչ��ȭ��˫����\n");
	                 me->add_temp("apply/damage", extra);
                 me->add_temp("apply/attack", extra);

		 msg = RED "$Nһ����Х��ȭ����ʩ��ʹ�����ؾ�ѧ��ȭ��˫����Ѹ�����׵ع���$n��\n" NOR;
       	         message_vision(msg, me, target);                
	 msg =  HIC  "��һȭ��\n" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "��һ�ȣ�\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "��һȭ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "��һ�ȣ�\n" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC "�м�����һȭ��\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/damage", -extra);
        me->add_temp("apply/attack", -extra);
      me->add("neili",-200);
        me->start_busy(2);
        return 1;
}

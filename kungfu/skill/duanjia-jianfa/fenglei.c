//���� fenglei.c 

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	object weapon, ob;
        mapping prepare;
        string msg;
       int i;
i = (int)me->query_skill("duanjia-jianfa", 1)  /10;
 
 

        weapon = me->query_temp("weapon");
       
	 if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("�������Ļ���ֻ����ս����ʹ�á�\n");
 
	if (!weapon || weapon->query("skill_type") != "sword"
       || me->query_skill_mapped("sword") != "duanjia-jianfa")
      return notify_fail("�����޽�,����ôʹ�ó��������Ļ�����\n");

    if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");
         
	if( (int)me->query_skill("duanjia-jianfa",1) < 100 ||
	    me->query_skill_mapped("sword") != "duanjia-jianfa")
		return notify_fail("��Ķμҽ����������ң��޷�ʹ�á������Ļ���������\n");

 message_vision(BLU"\n $N��Цһ�����������֣�������ϣ�ʩչ�������Ļ�������,��ͼ���ٻ���$n \n"NOR, me,target);
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili",-300); 
      me->add("jingli",-200); 
    me->add_temp("apply/attack", i);
    me->add_temp("apply/dodge", i);
	 msg =  HIY  "$N�ս�ֱ�ϣ�����$n����һ����\n" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N�Ų����ǲ�������ǰ�����֮���ѵ�$n��ǰ��\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N�������һ�׳��죬һ��[����׵�]���������$n�� \n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->start_busy(5);
      me->add_temp("apply/dodge", -i);
    me->add_temp("apply/attack", -i);
 

           return 1;
}

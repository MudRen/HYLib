// jianzhang.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count;
  if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("���ն����¡�ֻ����ս����ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�������������\n");

	if( (int)me->query_skill("staff",1) < 150 ||
	    me->query_skill_mapped("staff") != "pudu-zhang")
		return notify_fail("����ն��ȷ��������ң��޷�ʹ���ն����£�\n");

	msg = HIY "$N������ţ�ʹ�������ɾ������ն����¡�����һʽ    ��ɮ�в���" NOR;
	
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIY  "�ڶ�ʽ   �Ⱥ��նɣ�  " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIB  "����ʽ   �ն����£�  " NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili", -100);
	me->start_busy(2);
	return 1;
}

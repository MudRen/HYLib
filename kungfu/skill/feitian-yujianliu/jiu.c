// sanjue.c  ��������������ͷ����
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	string msg;
        int extra;
        extra = me->query_skill("feitian-yujianliu",1);

	 if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("����ͷ������ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("��ʹ�õ��������ԡ�\n");
	if((int)me->query_skill("feitian-yujianliu",1) < 250)
		return notify_fail("��ķ�������������Ϊ����, ����ʹ����һ���� !\n");

        if( userp(me) && !me->query("feitian/jiu"))
                return notify_fail("��ֻ��˵��,�������á���ͷ��������\n");     

	if((int)me->query_skill("blade") < 250)
		return notify_fail("��ĵ�����Ϊ������ Ŀǰ����ʹ��! \n");
	weapon = me->query_temp("weapon");
	if( (int)me->query("neili") < 600 )
		return notify_fail("�������������\n");
    if ((int)me->query_skill("shayi-xinfa", 1) < 160)
   return notify_fail("���ɱ���ķ���򲻹���\n");
	
	extra = me->query_skill("feitian-yujianliu",1) / 15;
	extra += me->query_skill("feitian-yujianliu",1) /15;
	me->add_temp("apply/attack", 100);	

	msg = HIR "$N�ٶ�ͻȻ�ӿ�!��Ÿ���ʹ���˾��ֲ�ͬ������! $n��Ȼ�е��޷������Ͷ�ܣ���\n" NOR;     
message_vision(msg, me, target);
	msg = HIG "Ҽ������" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIC "��������ն��" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIB "���������ģ�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIY "������̣�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR "�飡�Ҵ̣�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM "½�������ϣ�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIW "�⣡�����ϣ�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = CYN "�ƣ���磡" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = BLU "������ͻ����" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

	me->add_temp("apply/attack", -100);

	me->add("neili", -500);
	me->start_busy(3);
	return 1;
}

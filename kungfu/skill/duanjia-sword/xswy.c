#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra,tmp;
	object weapon;
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[��˼����]ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("duanjia-sword",1);
	if ( extra < 300) return notify_fail("���[�μҽ���]���������죡\n");

        if (!objectp(weapon) || weapon->query("skill_type") != "sword")
                return notify_fail("�������޽������ʹ�ó�����ɽ���⣿\n");
		
        if ((int)me->query_skill("kurong-changong",1) < 180)
            return notify_fail("��Ŀ�������̫�͡�\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 180)
		return notify_fail("��Ķμҽ����̫ǳ��\n");    
        if ((int)me->query_skill("jinyu-quan", 1) < 180)
		return notify_fail("��Ľ���ȭ���̫ǳ��\n");
        if ((int)me->query_skill("wuluo-zhang", 1) < 180)
		return notify_fail("������������ƻ��̫ǳ��\n");
        if ((int)me->query_skill("feifeng-whip", 1) < 180)
		return notify_fail("��ķɷ�޻��̫ǳ��\n");

        if (me->query("neili") <= 500)
                return notify_fail("�������������\n");
 if (extra> 200) extra=200;
 	
        me->add_temp("apply/attack", extra); 
	me->add_temp("apply/damage", extra);
       msg =  HIG  "$N���ӳ��μҽ����е���߾������˼���ãݣ���ǰͻȻ����һ��ٻӰ�����е�"+ weapon->name()+"������ʳ��������Ļ���$n��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "ٻӰһ�֣���ʧ�ˣ�������\n" NOR;
       message_vision(msg,me,target);
       msg =  HIW "$NͻȻ������һ����" + HIG "\n��˼���õ�һʽ����ɫ���������̣�" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "������ʧ��$NͻȻ������һ����" + HIC "\n��˼���õڶ�ʽ���������س�ߣ�" NOR; 
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "������ʧ��$NͻȻ������һ����" + HIY "\n��˼���õ���ʽ����ɪ��ͣ�������" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "������ʧ��$NͻȻ������һ����" + HIR "\n��˼���õ���ʽ����������ԧ���ң�" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "������ʧ��$NͻȻ������һ����" + HIW "\n��˼���õ���ʽ�������������˴���" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "������ʧ��$NͻȻ������һ����" + HIB "\n��˼���õ���ʽ��Ը�洺�����Ȼ��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "������ʧ��$NͻȻ������һ����" + HIC "\n��˼���õ���ʽ��������������죡" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "������ʧ��$NͻȻ������һ����" + HIM "\n��˼���õڰ�ʽ����ʱ�ᲨĿ����������Ȫ��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "������ʧ��$NͻȻ������һ���� "+ HIB "\n��˼�������һʽ������檳��ϣ�������ȡ����ǰ��" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
        me->add_temp("apply/damage", -extra);
	me->add("neili",-500);
        me->start_busy(5);
	return 1;
}

// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
	extra = me->query_skill("qingshe-sword",1);
	if ( extra < 70) return notify_fail("���[�����书]���������죡\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ƽˮ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	weapon = me->query_temp("weapon");
if (extra>=200) extra=200;
me->add_temp("apply/damage", extra);
me->add_temp("apply/attack", extra/10);
	msg =  HIW "$N���һ����Ƽ--ˮ--��--�꣡\n"+HIR "Ƽ---���е�"+ weapon->name()+ HIR "�����߰����$n��ȥ��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR "ˮ---ֻ��"+ weapon->name()+ HIR"�������ԣ�����$n����磡" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
     msg =  HIR "��---$N���һ����"+ weapon->name()+ HIR"�����������$n���ؿڣ�" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
   msg = HIR "��---$Nͼ��ذ�֣��Ӹ����£�����"+ weapon->name()+ HIR"��$n�Ĵ�����ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
me->add_temp("apply/damage", -extra);
me->add_temp("apply/attack", -extra/10);
	me->start_busy(3);
	return 1;
}

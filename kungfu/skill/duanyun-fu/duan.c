//duan.c -��������֮������ն��
// Modified by Venus Oct.1997
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    int damage;
object weapon;
    string msg;
	int extra;

    if( !target ) target = offensive_target(me);
    if( !target||!target->is_character()||!me->is_fighting(target) )
    return notify_fail("��ֻ�ܶ�ս���еĶ���ʹ�á�����ն����\n");
extra = me->query_skill("duanyun-fu",1);

    if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("��ı����ڹ���δ���ɣ�����ʹ�ã�\n");

    if( (int)me->query_skill("duanyun-fu",1) < 70)
    return notify_fail("��Ŀǰ������ʹ����������ն����\n");
    if( (int)me->query("neili") < 400 )
    return notify_fail("�������������\n");
    me->add("neili", -100);
msg = HIC"$NͻȻ����һ���������о޸�б���Ͼ���Ȼ���ڰ���л���һ
��Բ�����漴��ֱб��ն��$n����һ˲�䣬$nֻ���ú�����ֹͣ�ˣ�\n"NOR;
        me->add_temp("apply/attack", 80);    
        me->add_temp("apply/damage", 500);
if (random(2)==0) target->start_busy(2);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIC"$N�������о޸�б���Ͼ����ڰ���л���һ
��Բ�����漴��ֱб��ն��$n��\n"NOR;

	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIC"$Nת�����о޸�б���Ͼ����ڰ���л���һ
��Բ�����漴��ֱб��ն��$n��\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/attack", -80);    
        me->add_temp("apply/damage", -500);
	me->start_busy(2);    
return 1;
}


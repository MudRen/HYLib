#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("xuanyuan-axe",1);
        if ( extra < 250) return notify_fail("�����ԯ�������������죡\n");
        
        

        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�۾���������ֻ�ܶ�ս���еĶ���ʹ�á�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "axe")
                        return notify_fail("��ʹ�õ��������ԡ�\n");

    if( (int)me->query_skill("guiyuan-tunafa", 1) < 50 )
	return notify_fail("��ı����ڹ���δ���ɣ�����ʹ�ã�\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("�������������\n");
                
                
        weapon = me->query_temp("weapon");
extra=extra/3;
if (extra> 200) extra=200;
        me->add_temp("apply/attack",extra);
		me->add_temp("apply/damage",2000);
        msg = HIY  "$N���е�"+ weapon->name()+HIY"�趯���ٶ��������죬������������\n������"+weapon->name()+HIY"ͻȻ������������$n"NOR+HIY"����һʽ������������������\n" NOR;
        message_vision(msg,me,target);
        msg = HIW  "��⣡" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "��ʯ��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "����ɽ��" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIB  "��������" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
		msg = HIC  "�ƾ�����" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

msg = HIC"$NͻȻ����һ���������о޸�б���Ͼ���Ȼ���ڰ���л���һ
��Բ�����漴��ֱб��ն��$n����һ˲�䣬$nֻ���ú�����ֹͣ�ˣ�\n"NOR;
if (random(2)==0) target->start_busy(3);
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIC"$N�������о޸�б���Ͼ����ڰ���л���һ
��Բ�����漴��ֱб��ն��$n��\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIC"$Nת�����о޸�б���Ͼ����ڰ���л���һ
��Բ�����漴��ֱб��ն��$n��\n"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

me->add("neili",-390);
        me->add_temp("apply/attack",-extra);
		me->add_temp("apply/damage",-2000);

                me->start_busy(3);
        return 1;
}     

//XXDER/TIE
//charge.c
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int extra,damage;
    string msg;

            if(!target) target=offensive_target(me);
	     extra=me->query_skill("blood-sword",1);
            if(extra<50) return notify_fail("��ģ�Ѫ�½����ݻ��������죡\n");
            if(!target
       	||!target->is_character()
	       ||!me->is_fighting(target) )
            return notify_fail("��ƽ���ۣ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-200);

  	     weapon=me->query_temp("weapon");
	     extra/=2;
	     extra+=me->query_skill("move")/2;

            msg=HIC"\n$Nƽƽ�ؾ���" + weapon->query("name") + HIC"����������΢б����΢ƫ����Ȼ�����������ˡ���\n"NOR;
            msg+=HIC"\n$N����ӰͻȻ���˵���������ʧ�ˣ�"NOR;
            me->add_temp("apply/damage",extra/5);
            me->add_temp("apply/attack",extra/5);
            damage=COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);
            me->add_temp("apply/attack",-extra/5);
            me->add_temp("apply/damage",-extra/5);
            if(damage>1) 
            {
            me->start_busy(2);
            return 1;
            }

            msg=HIR"$Nһ�����У����ϳ�ؽ���̤ǰһ������$n��ȥ��"NOR;
            me->add_temp("apply/damage",extra/2);
            me->add_temp("apply/attack",extra/2);
            damage=COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);
            me->add_temp("apply/attack",-extra/2);
            me->add_temp("apply/damage",-extra/2);
            if(damage>1) 
            {
            me->start_busy(2);
            return 1;
            }

            msg=HIR"$N�����δ�ŵأ����е�" + weapon->query("name") + HIR"����������$n��ȥ��"NOR;
            me->add_temp("apply/damage",extra);
            me->add_temp("apply/attack",extra);
            damage=COMBAT_D->do_attack(me,target,weapon,TYPE_REGULAR,msg);
            me->add_temp("apply/attack",-extra);
            me->add_temp("apply/damage",-extra);
            me->start_busy(2);
            return 1;
}


//fatangel@fengyun
//trap attack
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    object weapon;
    int extra,ddg,damage;
    string msg;

            if(!target) target=offensive_target(me);
            if((string) me->query_skill_mapped("dodge")!="chaos-steps")
	     return notify_fail("��ƽ���������뵹�����ǲ������ʹ�ã�\n");
	     weapon=me->query_temp("weapon");
	     extra=me->query_skill("qingpingsword",1);
            if(extra<50) return notify_fail("��ģ���ƽ�����ݻ��������죡\n");
            if(!target
       	||!target->is_character()
	       ||!me->is_fighting(target) )
            return notify_fail("�����־���ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                        return notify_fail("��ʹ�õ��������ԡ�\n");
	if( (int)me->query("neili") < 500  ) 
		return notify_fail("�������������\n");
        me->add("neili",-200);

            if(target->is_busy()||target->query_temp("is_unconcious"))
            return notify_fail("��Ķ����Ѿ���æ�����ˣ��ŵ������ɣ�\n");                    

            msg=HIW"\n$nƽƽһ�����˳�ȥ�����Ʋ������Ʋ��ϣ��°�����ǿ��Ŵ�¶��\n\n"NOR;

            if(random(me->query("combat_exp"))<target->query("combat_exp")/4
             &&random(target->query("combat_exp"))<me->query("combat_exp")/2)
            {
            msg+=HIC"$N������թ����δ��϶��������������һ����\n"NOR;
            message_vision(msg,target,me);
            me->start_busy(2);
            return 1;
            }

            if(me->query("combat_exp")<random(target->query("combat_exp")/4))
            {
            msg+=HIW"$N������թ��ȴ�������أ����ƾͼƵ���$n��ȥ��\n"NOR;
            damage=COMBAT_D->do_attack(target,me,target->query_temp("weapon"),TYPE_REGULAR,msg);
            }
            else
            {
            msg+=HIW"$N����������ʧ��������$n��ȥ��"NOR;
            ddg=me->query_skill("chaos-steps",1)/10;
            me->add_temp("apply/dodge",ddg);
            damage=COMBAT_D->do_attack(target,me,target->query_temp("weapon"),TYPE_REGULAR,msg);
            me->add_temp("apply/dodge",-ddg);
            }
                 if(damage>1)
                 {
                 msg=HIR"\n����$NŪ�ɷ�׾����$n�����϶����ʱ��æ���ң�\n"NOR;
                 message_vision(msg, me, target);
                 me->start_busy(2);
                 return 1;
                 }

            msg=HIY"\n$N���μ�ת����������$n�����$n��û��Ӧ����ʱ�ѷ�����һ�����Ĺ�����\n"NOR;
            message_vision(msg, me, target);
            target->start_busy(2);
            me->add_temp("apply/damage",300+extra);
            msg=HIY"��һ�У�"NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            msg=HIY"�ڶ��У�"NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            msg=HIY"�����У�"NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            msg=HIY"���һ�У�"NOR;
            COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
            me->add_temp("apply/damage",-(300+extra));
            me->start_busy(2);
            return 1;
}


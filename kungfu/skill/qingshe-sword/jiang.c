// jiang.c �����콵
// smallbear 11/2/2002

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        object weapon;
        string msg,force;
        int damage,sk1,sk2,exp1,exp2,skill,dp,ap;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�������콵��ֻ����ս����ʹ�á�\n");


        skill = (int)me->query_skill("qingshe-sword",1);
        
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԡ�\n");
                
        if( skill < 100 )
                return notify_fail("�����������������죬����ʹ�á������콵����\n");
                                
        if(  (int)me->query_skill("shenlong-xinfa", 1)<100) 
                return notify_fail("����ڹ���򲻹����޷����ӽ���������\n");
                        
        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("����������̫��������ʹ�þ��С�\n");

        if (  me->query_skill_mapped("force") != "shenlong-xinfa") 
                 return notify_fail("��û������������ϵ���ڹ���\n");

/*        sk1 = (int)me->query_skill("sword");
        if(target->query_skill_mapped("parry")==target->query_attack_skill())
                sk2 = ((int)target->query_skill("parry")+(int)target->query_skill("dodge"))/2;
        else
                sk2 = ((int)target->query_skill("parry",1)+(int)target->query_skill("dodge"))/2;
        exp1 = (int)me->query("combat_exp");
        exp2 = (int)target->query("combat_exp"); */

        ap = me->query_skill("qingshe-sword",1) + me->query_skill("sword",1) + me->query_skill("force",1);
        dp = target->query_skill("dodge",1) + target->query_skill("parry",1) + target->query_skill("force",1);

        msg = CYN "$N��Ծһ�������󽣾������������дʣ�ͻȻ���һ���������콵������\n"NOR;

        if (ap / 2 + random(ap) > dp || !living(target))
        {
                if(skill<350)
                target->start_busy(1 + random(2));
        else
                target->start_busy(1 + random(3));
                damage = (int)me->query_skill("qingshe-sword", 1);
                damage = damage +  skill;
                damage = damage +  (int)me->query_skill("sword", 1);

        target->receive_damage("qi", damage,me);
        target->receive_wound("qi", damage,me);
        target->receive_damage("jing", damage/3,me);
        target->receive_wound("jing", damage/2,me);
        me->add("neili", -damage);
        msg += HIY"$N�Ľ�����ʱ��ù���ʮ�֣��ó���佣������������������Ѹ����$n��ȥ��\n"
                "$n��ͼ�ܿ����У���ȫ��Ӳ���ܶ������ɻ����Ѿ������������������ӻ��������\n"NOR;
        me->start_busy(3);
        }
        else
        {
        msg += CYN"$n�ٸ����屻�ƣ���֪�������������Ԫ������ͻ�ƶԷ����ơ�\n"NOR;
                me->add("neili", -100);
                me->start_busy(4);
        }
        message_vision(msg, me, target);
        if(!userp(target)&& !target->is_killing(me->query("id")) ) target->kill_ob(me);
        return 1;
}



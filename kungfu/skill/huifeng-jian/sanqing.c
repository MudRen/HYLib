// sanqing.c һ��������

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int extra;
        int count;
 	if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("��һ�������塹ֻ����ս����ʹ�á�\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��һ�������塹��ʼʱ��������һ�ѽ���\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("huifeng-jian",1) < 100 )
                return notify_fail("��Ļط�������������ң��޷�ʹ�á�һ�������塹��\n");

	extra = me->query_skill("huifeng-jian",1) / 15;
	extra += me->query_skill("huifeng-jian",1) /15;
 
        msg = YEL "$Nʹ���ط������������һ�������塹��һ���������������е�"+ weapon->name()+  "����㹥����һ����" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", extra*4);
        me->add_temp("apply/damage", extra*2);

if ((int)me->query_skill("linji-zhuang",1) > 249 && (int)me->query_skill("huifeng-jian",1) > 250 )
{
        msg = HIC "����ׯ֮��һ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY "����ׯ֮�ڶ�����" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  HIW "��Сׯ֮��������!" NOR;
      	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -150);
        me->start_busy(1);
}
        msg = HIY "ֻ��$N����һ����"+ weapon->name()+ HIY"����$n����磡" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "��һ������"+HIR+"����$n����$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;   
        message_vision(msg, me, target);
  if( !target->is_busy() )
{
        target->start_busy(2);
}
        }
        msg =  HIW "$N���һ����"+ weapon->name()+ GRN"����$n���Ҽ磡" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "�ڶ�������"+HIM+"ɨ��$n������,$nֻ����ȫ��һ��ʹ��\n"NOR;   
                message_vision(msg, me, target);
        target->add("jing",-extra);
        target->add("eff_jing",-extra);
        }
        msg = CYN "$N��Хһ�����۹��������֣�ʹ����������߾���--�𽣣���$n����ǰ��ȥ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "���һ������"+HIB+"ɨ��$n������Ѩ,$nֻ����ȫ�������᲻�����ˣ�\n"NOR;   
        message_vision(msg, me, target);
        target->add("neili",-extra*4);
        target->add("eff_neili",-extra*4);
        }
        me->add("neili", -300);
        me->add_temp("apply/attack", - extra*4);
        me->add_temp("apply/damage", - extra*2);
        me->start_busy(3);

        return 1;
}


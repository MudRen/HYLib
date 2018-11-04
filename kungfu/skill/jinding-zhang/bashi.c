// bashi.c ������ ��ʽ��һ

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object target, int aamount, int damount);

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int count,d_count,qi, maxqi, skill;

        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("����ʽ��һ��ֻ����ս����ʹ�á�\n");
        if( (int)target->query_temp("bashi") )
                return notify_fail("���Ѿ����˹����ˡ�\n");
        if( (int)me->query("neili") < 300 )
                return notify_fail("��������������ߣ�\n");
        if( (int)me->query_skill("linji-zhuang", 1) < 40)
                return notify_fail("����ټ�ʹ��ׯ����Ϊ����������ʹ�ð�ʽ��һ!\n");
        if( (int)me->query_skill("jinding-zhang",1) <100)
                return notify_fail("��Ľ����Ƶİ�ʽ��ϰ��ȫ���޷�ʹ�ð�ʽ��һ��\n");
        if( me->query_skill_mapped("strike") != "jinding-zhang")
                return notify_fail("��û�м��������ƣ��޷�ʹ�ð�ʽ��һ��\n");
        if( me->query_temp("weapon"))
                return notify_fail("���ȷ������е�������˵�ɣ���\n");     

//        if( !target->is_killing(me) ) target->kill_ob(me);

        msg = HIY "$N��������һ����������ȫ��Ĺ�����˫�ƣ�ֻ����$N����һ���죡\n" NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("linji-zhuang", 1)/2;
                damage = damage +  (int)me->query_skill("jinding-zhang", 1);
                target->set_temp("bashi", 1);
                
                target->add_temp("apply/attack", -damage/2);
                target->add_temp("apply/defence", -damage/2);
                target->add_temp("apply/dodge", -damage/2);
                msg += HIR "$N�ڿն���ʹ���ˡ���ʽ��һ�����������Ӱ��Ʈ������������$nȫ�������λ��\n" NOR;
                me->start_call_out( (: call_other, __FILE__, "remove_effect",target,damage/2, damage/2:), damage/30);
                me->add("neili",-200);
                target->start_busy(3);
         }
         else {
                msg += NOR"����$p�͵���ǰһԾ,������$P�Ĺ�����Χ��\n"NOR;
         }
                me->start_busy(2);
         message_combatd(msg, me, target);
         return 1;
}

void remove_effect(object target,int aamount, int damount)
{
if (target)
{
               target->add_temp("apply/attack", aamount);
               target->add_temp("apply/defence", aamount);
               target->add_temp("apply/dodge", damount);
               target->delete_temp("bashi");
               message_combatd(YEL"$N�����ҵĹ����а����˳�������������,��ס�˽Ų�\n"NOR, target);
}
}


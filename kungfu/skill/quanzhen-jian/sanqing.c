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
        int count;
 	if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
        return notify_fail("��һ�������塹ֻ����ս����ʹ�á�\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("��һ�������塹��ʼʱ��������һ�ѽ���\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("�������������\n");

        if( (int)me->query_skill("quanzhen-jian",1) < 135 )
                return notify_fail("���ȫ�潣���������ң��޷�ʹ�á�һ�������塹��\n");

        if( (int)me->query_skill("xiantian-qigong",1) < 60 )
                return notify_fail("��������񹦻�򲻹����޷�ʹ�á�һ�������塹��\n");
    if(me->query_skill_mapped("force") != "xiantian-qigong" )
        return notify_fail("��Ҫ����������Ϊ�ڹ������á�\n");

        msg = YEL "$Nʹ��ȫ���ɾ�����һ�������塹������Ȼ�ӿ�,���ս����γ�����������" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", (int)me->query_skill("quanzhen-jian",1)/2);
        me->add_temp("apply/damage", (int)me->query_skill("quanzhen-jian",1)/3);

       msg = WHT  "��Ѫ������" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT  "��Ѫ������" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT "ŭѪ������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query_skill("qixing-array",1)>80)
{
        msg = HIG "�������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -80);
}
        if (me->query_skill("qixing-array",1)>150)
{
        msg = HIG "������λ��" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili", -80);
}
        if (me->query_skill("qixing-array",1)>200)
{
        if (random(me->query("combat_exp")) > target->query("combat_exp")/2 )
        {
        message_vision(HIW"\n$N��������,Χ��$n��������Ȧ��$nֻ��һ���ۻ���\n"NOR,me,target);
//         msg = HIY "$N��������,Χ��$n��������Ȧ��$nֻ��һ���ۻ���" NOR;              
  if( !target->is_busy() )
{
         target->start_busy(2);
}
}

}

        me->add_temp("apply/attack", - (int)me->query_skill("quanzhen-jian",1)/2);
        me->add_temp("apply/damage", - (int)me->query_skill("quanzhen-jian",1)/3);
        me->add("neili", -250);
        me->start_busy(2);

        return 1;
}


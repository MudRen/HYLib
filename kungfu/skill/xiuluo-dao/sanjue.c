//sanjue.c 
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg,msg1;
        int i;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("��������������ֻ����ս���жԶ���ʹ�á�\n");
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "blade"
           || me->query_skill_mapped("blade") != "xiuluo-dao")
                return notify_fail("�����ʹ���ڵ�ʱ����ʹ������������������\n");

        if( (int)me->query_skill("xiuluo-dao", 1) < 80 )
                return notify_fail("������޵�������죬����ʹ�á���������������\n");

        if( (int)me->query_skill("yijinjing", 1) < 60 )
                return notify_fail("����׽�ڹ���Ϊ����������ʹ�á���������������\n");

        if( (int)me->query_dex() < 30 )
                return notify_fail("�����̫�ͣ�����ʹ�á���������������\n");

//        if (me->query_skill_mapped("force") != "yijinjing")
//                return notify_fail("����ڹ��ȼ�����������ʹ�á���������������\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("����������̫��������ʹ�á���������������\n");
        if((int)me->query("jing",1)<200)
               return notify_fail("�����ھ���̫�٣�����ʹ�á���������������\n");
        i = (me->query_skill("xiuluo-dao", 1)/6);
        msg = RED "$N������ţ�������Ҷ����裬Ѹ����ɰ㷢��������\n"NOR;
        msg1=HIY"$Nһ����Х������������������\n"NOR;
        me->add_temp("apply/strength", i);
        me->add_temp("apply/attack", i); 
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        me->add("neili", -200);
        me->start_busy(2);
        me->add_temp("apply/strength",-i);
        me->add_temp("apply/attack", -i); 
        message_vision(msg1, me,target);
      return 1;
}

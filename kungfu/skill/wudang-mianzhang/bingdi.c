// bingdi.c ��������

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl,jiali;

      if(objectp(me->query_temp("weapon")))
           return notify_fail("���������١�ֻ�ܿ���ʹ�á�\n");

      lvl = (int)me->query_skill("wudang-mianzhang", 1);

      if( !target ) target = offensive_target(me);

      if( !target
       || !me->is_fighting(target) )
           return notify_fail("���������١�ֻ����ս���жԶ���ʹ�á�\n");

      if( lvl < 120 )
           return notify_fail("��������Ϊ�в�����,�޷�ʹ�á��������١���\n");             

      if((int)me->query_skill("taiji-shengong",1) < 120 )
           return notify_fail("���̫������Ϊ��ǳ�޷�ʹ�á��������١���\n");
 
      if((int)me->query_skill("strike",1) < 120 )
           return notify_fail("��Ļ����Ʒ��ȼ�����������ʹ�á��������١���\n");  

      if((int)me->query("max_neili") < 2000 )
           return notify_fail("���������Ϊ̫��������ʹ�á��������١���\n");
     
      if((int)me->query("neili") < 700 )
           return notify_fail("�������̫���ˣ��޷�ʹ�ó����������١���\n");   

      if((int)me->query("jing") < 500 )
           return notify_fail("��ľ���̫���ˣ��޷�ʹ�ó����������١���\n");

      if(me->query_skill_mapped("parry") != "wudang-mianzhang"
       || me->query_skill_mapped("force") != "taiji-shengong")
           return notify_fail("�������޷�ʹ�á��������١����й�����\n");



      message_vision(HIC"\n$N������һ���������ֻ����ͻ�$n�Ҽգ����ֳ�ָ����$n��硰ȱ��Ѩ����\n"
                       +"�������ƻ�$n��գ�����ʳָ��$n�Ҽ��ȱ��Ѩ����������ʽ�����籩��\n"
                       +"�����ʹ������һ�н������������١������ƺ���������ȴʮ��������\n"NOR,me,target);

        jiali = (int)me->query("jiali");
        me->add("neili",-( 300 + random(jiali)));
        me->add("jing", -80);

        lvl /= 6;
        me->add_temp("apply/strike", lvl);
        me->add_temp("apply/attack", lvl);
        me->add_temp("apply/damage", 300);
        COMBAT_D->do_attack(me, target, 0, 1);  

        if (present(target,environment(me)) && me->is_fighting(target))
                COMBAT_D->do_attack(me, target, 0);  

        if(me->query_skill("zhenshan-mianzhang", 1) > 150
        && present(target,environment(me))
        && me->is_fighting(target))
                COMBAT_D->do_attack(me, target, 0);  

        me->start_busy(2);
        me->add_temp("apply/strike", -lvl);
        me->add_temp("apply/attack", -lvl);
me->add_temp("apply/damage", -300);
        lvl /= 2;
        if ( lvl < 4 ) lvl = 4;
        if ( lvl > 10 ) lvl = 10;
        return 1;
}


// liaoyuan.c ��ԭ�ٻ�

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
      int lvl;
      object weapon;
      string name;
      weapon = me->query_temp("weapon");
      if (weapon) name = weapon->query("name");

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("��ԭ�ٻ�ֻ����ս���жԶ���ʹ�á�\n");

      if (!weapon || weapon->query("skill_type") != "sword"
       || me->query_skill_mapped("sword") != "huifeng-jian")
      return notify_fail("������û�н����޷�ʹ����ԭ�ٻ���\n");             

      if( (int)me->query_skill("huifeng-jian",1) < 120 )
      return notify_fail("��Ļط������������죬����ʹ����ԭ�ٻ���\n");
      
      if( (int)me->query_skill("sword",1) < 120 )
      return notify_fail("��Ļ��������ȼ�����������ʹ����ԭ�ٻ���\n");  

      if( (int)me->query_skill("jinding-zhang", 1) < 120 )
      return notify_fail("��Ľ����Ƶȼ�����������ʹ����ԭ�ٻ���\n");
      
      if( (int)me->query_skill("linji-zhuang", 1) < 120 )
      return notify_fail("����ټ�ʮ��ׯ�ȼ�����������ʹ����ԭ�ٻ���\n");
      if (me->query_skill_mapped("force") != "linji-zhuang")
                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");
      if( (int)me->query("max_neili") < 1000 )
      return notify_fail("�������̫��������ʹ����ԭ�ٻ���\n");
      
      if( (int)me->query("neili") < 500 )
      return notify_fail("�������̫���ˣ��޷�ʹ�ó���ԭ�ٻ���\n");   
                                                                                 
      if (me->query_skill_prepared("strike") != "jinding-zhang"
          || me->query_skill_mapped("strike") != "jinding-zhang")
      return notify_fail("��û��ʹ�ý����ƣ������޷�ʹ����ԭ�ٻ����й�����\n");

      lvl = ( (int)me->query_skill("huifeng-jian", 1) + (int)me->query_skill("jinding-zhang", 1) ) /20;
      message_vision(HIW"\n$N��Хһ�����������߿���ȥ���պ���ס$n��������"+name+"ɲ�Ǽ������ռ䡣\n"NOR, me,target);
// update ���־�ʽ -> ������ (by xbd)
      message_vision(HIW"����ʹ�������ƣ���������С������������Ȼ��ǿ��\n"NOR, me,target);
      me->add("neili", -300); 
      me->add("jingli", -150);      
      me->add_temp("apply/strength", lvl);
      me->add_temp("apply/attack", lvl); 
      me->add_temp("apply/dexerity", lvl/2);

      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 3);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
      COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
      weapon->unequip(); 
      COMBAT_D->do_attack(me, target, 0, 3);  
      COMBAT_D->do_attack(me, target, 0, 0);
      COMBAT_D->do_attack(me, target, 0, 3);  
      me->add_temp("apply/strength", -lvl);
      me->add_temp("apply/attack", -lvl);
      me->add_temp("apply/dexerity", -(lvl/2));
      weapon->wield();
      me->start_busy(3);
       return 1;
}

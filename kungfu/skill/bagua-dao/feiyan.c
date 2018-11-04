#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
       object weapon;
       string msg,dodge_skill;
       int p;
       
       if( !target ) target = offensive_target(me);

       if(!objectp(weapon = me->query_temp("weapon"))
        ||(string)weapon->query("skill_type") != "blade")
            return notify_fail("��ʹ�õ��������ԡ�\n");

       if( !target 
        || !me->is_fighting(target) )
            return notify_fail("����������С�ֻ����ս���жԶ���ʹ�á�\n");

       if((int)me->query_skill("linji-zhuang", 1) < 150 )
            return notify_fail("����ټ�ʮ��ׯ�ȼ�����������ʹ�÷�������С�\n");       

        if ((int)me->query_skill("linji-zhuang", 1) < 120)
                return notify_fail("����ټ�ʮ��ׯ���̫ǳ��\n");
                
        if (me->query_skill("bagua-dao", 1) < 140)
                return notify_fail("��İ��Ե�����Ϊ����������ʩչ��\n");

        if (me->query_skill_mapped("blade") != "bagua-dao")
                return notify_fail("��û�м������Ե���������ʩչ��\n");


        if ((int)me->query_skill("bagua-zhang") < 150)
                return notify_fail("��İ����ƻ��̫ǳ��\n");
                                
       if ((int)me->query("neili") < 500 )
            return notify_fail("����������̫��������ʹ�÷�������У�\n");

       if ((int)me->query("max_neili") < 2000 )
            return notify_fail("����������̫��������ʹ�÷�������У�\n");

       message_vision(HIY"$NͻȻ������"+weapon->query("name")+"����һ�ӣ�\n"NOR, me, target);
       message_vision(HIR"$N��$nһ��������ʹ��һ�������Ƶľ�ѧ��Ʈѩ�����ơ���\n"NOR, me, target);
       me->add_temp("apply/dexerity",me->query_skill("dodge")/20);
       if (random(me->query_skill("dodge")) > target->query_skill("dodge")/2){
          target->receive_damage("qi", me->query_skill("bagua-zhang")*3);
          target->receive_wound("qi", me->query_skill("bagua-zhang")*3);
          message_vision(HIY"$nһ�������$N���صĻ��У�\n"NOR, me, target); 
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg = "( $n"+eff_status_msg(p)+" )\n"; 
          message( msg, me, target);
       }
       else{
          dodge_skill = target->query_skill_mapped("dodge");
          if( !dodge_skill ) dodge_skill = "dodge";
          msg = SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
          message( msg, me, target);
       }          
       message_vision(HIR"\n$N���˿����������ĵ����������嵶��\n"NOR, me, target);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
       me->add_temp("apply/dexerity",-me->query_skill("dodge")/20);
       me->start_busy(2);
       me->add("neili", -(int)me->query_skill("bagua-dao", 1));    
       return 1;
}

//sanhua-zhang perform �ļ�ɢ��(�����ﶬ)
// by beyond
// rewrite by snowman
#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
      string msg;
      int damage, p;                                   

      if( !target ) target = offensive_target(me);
     
      if( !target || !me->is_fighting(target) )
      return notify_fail("���ļ�ɢ����ֻ����ս���жԶ���ʹ�á�\n");
             
      if(me->query_temp("weapon"))
      return notify_fail("��������ʹ�á��ļ�ɢ������\n");
      
      if( (int)me->query_skill("sanhua-zhang",1) < 100 )
      return notify_fail("���ɢ���Ʋ�����죬����ʹ�á��ļ�ɢ������\n");
      
      if( (int)me->query_skill("yijinjing",1) < 100 )
      return notify_fail("����׽�ڹ��ȼ�����������ʹ�á��ļ�ɢ������\n");  
      
      if( (int)me->query_str() < 30 )
      return notify_fail("��ı�������ǿ������ʹ�á��ļ�ɢ������\n");
      
      if( (int)me->query("neili") < 800 )
      return notify_fail("�������̫��������ʹ�á��ļ�ɢ������\n");
      
                                                                                 
      if (me->query_skill_prepared("strike") != "sanhua-zhang"
          || me->query_skill_mapped("strike") != "sanhua-zhang")
      return notify_fail("�������޷�ʹ�á��ļ�ɢ�������й�����\n");     
     
      damage = (int)me->query_skill("sanhua-zhang", 1);
      damage = (int)me->query_skill("yijinjing", 1)+damage;
      damage = (int)me->query_skill("yijinjing", 1)+damage;
      
        switch(random(4)) {
        case 0:
           { msg = GRN"
$NͻȻ���΢Ц������΢�ţ�����ӿ��һ�ɾ��磬�к���һƬƬ���̵�"CYN"�����ݡ�"GRN"��ֱ��$n����շ�ȥ��\n"NOR;
                damage = damage/3 + random(damage/3);               
                me->set_temp("nl", -120);} break;
          
        case 1:        
          { msg = MAG"
ֻ��$N����ѽ��һ����������ǰ��ȥ��ͻȻһ���������֣��ƿ�֮���м���"WHT"��������"MAG"��$n����ǰ��ȥ��\n"NOR;             
                damage = damage/3 + random(damage/2);                
                me->set_temp("nl", -180);} break;

        case 2:        
          { msg = HIY"
ͻȻ$N˫��Ī��ģ�$n��Ȼ������ǰ��Ӱ��ɽ��������ɽ����������������ɽ��ˮ��
����һ�ж�����$nԶȥ������һ�����˵�"GRN"����ա�"HIY"�����˱Ƕ���������\n"NOR;           
                damage = damage/2 + random(damage/3);                                
                me->set_temp("nl", -220);} break;
        
        case 3:
         { msg = HIW"
ͻȻ$N���һ������ʱ��$nϹ��һ�����飬֮��$N��ü��֮�䲼����һ�㱡˪��
˫Ŀ����ĵ���$n������ɮ��һ��һ���������"MAG"����÷��"HIW"��$n����������\n"NOR;          
                damage = damage/2 + random(damage/2);               
                me->set_temp("nl", -300);} break;
        }
    if (random((int)me->query("combat_exp")) > (int)target->query("combat_exp")/2 &&
        random(10) > 2)
            {
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/3);
                me->add("neili", me->query_temp("nl"));
                me->add("jing", -50);
                me->delete_temp("nl");
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                } 
            else 
               {       
                me->start_busy(3);
                me->add("neili", -(100+random(100))); 
                me->add("jing", -25);
                me->delete_temp("nl");
                message_vision(msg, me, target);               
                msg = CYN" ����$pһ�����Ʒ���ԶԶ�Ķ��˿�ȥ��\n"NOR;
               }
            message_vision(msg, me, target);
           return 1;
       
}

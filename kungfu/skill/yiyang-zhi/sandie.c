#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
 
int perform(object me, object target)
{       
        string msg;
        int damage, p;

        if( !target ) target = offensive_target(me);
 
         if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("������������ֻ����ս����ʹ�á�\n");
        
        if( objectp( me->query_temp("weapon")) )
                return notify_fail("ֻ�п��ֲ���ʩչ��������������\n");

        if( (int)me->query_skill("yiyang-zhi", 1) < 100 ||
            (int)me->query_skill("finger", 1) < 100 ||
            (int)me->query_str() < 25)
                return notify_fail("���еĹ��򻹲�����죬����ʹ�á�������������\n");

        if(!me->query_skill("kurong-changong", 1))
           if(me->query_skill("kurong-changong", 1) <180)
                return notify_fail("�������ڵ��ڹ���Ϊ��ʹ������������������\n");        
         
//           if (me->query_skill_mapped("force") != "kurong-changong" )
//            if (me->query_skill_mapped("force") != "qiantian-yiyang")
//                return notify_fail("����ʹ�õ��ڹ����ԡ�\n");

        if ( me->query_skill_mapped("finger") != "yiyang-zhi" )
                return notify_fail("�������޷�ʹ�á��������������й�����\n");  
      
//            if (me->query_skill_mapped("parry") != "kurong-changong" )
            if (me->query_skill_mapped("parry") != "yiyang-zhi")
                return notify_fail("����ʹ�õ��мܲ��ԡ�\n");
        if( (int)me->query("neili") < 1200 )
                return notify_fail("���������Ϊ̫��������ʹ�á�������������\n");

        
        if( (int)me->query("neili") < 800 )
                return notify_fail("�������������\n");
  if( target->is_busy() )
                return notify_fail("�Է��Ѿ���æ�����ˣ�\n");

//modified by cool for hamagong
        if (me->query("yd_2") && (target->query_skill_mapped("force")=="hamagong" || 
            target->query_skill_mapped("strike") == "hamagong")){
            msg = YEL "\n$N����$n��������ָ��һʽ���������������ֻ������������ָ��ֱϮ$n�ؿڣ�\n" NOR;

         if (random(me->query_skill("force",1)) > target->query_skill("force",1) /3 
         || random(me->query("combat_exp")) > target->query("combat_exp")/2 ){
                me->start_busy(1);
                if (!target->is_busy()) target->start_busy(2);
                damage = (int)me->query_skill("yiyang-zhi", 1);
//                damage = (int)me->query_skill("qiantian-yiyang", 1) +damage;
                damage = (int)me->query_skill("kurong-changong", 1) +damage;
                damage = random(damage)+150;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);               
target->apply_condition("yyz_damage",50);
                me->add("neili", -100);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += HIR "$nһ��֮�£���Ϊʧɫ���������ƺ������Լ��Ŀ��ǣ�\n"NOR;   
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                } 
         else {       
                me->start_busy(random(2)+1);
                me->add("neili", -100);                
                msg += HIY"$p���ⷴ�ֵ�Ѩ�ƺ����Ǹ�󡹦�Ŀ��ǣ�ʶ��������Σ��֮��һ�������ţ��������һ�������ѵĶ����һ�С�\n"NOR;
                }
         }
       else{
         msg = YEL "\n$N������ָ��һʽ������������������������������죬һ�ɴ���������ֱϮ$n�ؿڣ�\n" NOR;
          if (random(me->query_skill("parry")) > target->query_skill("parry") / 3)
             {
                me->start_busy(2);
                if (!target->is_busy()) target->start_busy(2);
target->apply_condition("yyz_damage",50);
                damage = (int)me->query_skill("yiyang-zhi", 1);
  //              damage = (int)me->query_skill("qiantian-yiyang", 1) +damage;
                damage = (int)me->query_skill("kurong-changong", 1) +damage;
       damage = damage + random(damage/2);
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage);               
             me->add("neili", -(damage/5));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("yiyang-zhi", 1) > 180)
                call_out("perform2", 0, me, target);    
              } 
         else {       
                me->start_busy(2);
                me->add("neili", -100);                
                msg += HIY"����$pһ�����Ʒ���ԶԶ�Ķ��˿�ȥ��\n"NOR;

              }
         }         
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target)
{
        string msg;

        if (!me)
{
        me->delete_temp("yyz_hama");
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("yyz_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}

        if(!living(target)) 
{
        me->delete_temp("yyz_hama");
          return notify_fail("�����Ѿ�������ս���ˡ�\n");  
}
        if( (int)me->query("neili", 1) < 600 )
{
        me->delete_temp("yyz_hama");
                return notify_fail("���Ҫ�ٳ��ڶ�ָ��ȴ�����Լ������������ˣ�\n");     
}       
        msg = YEL "\n����$N̤ǰһ�������ڶ�ָ���յ���$n��ǰ������Ѩ������Ѩ�������֮�\n"NOR;
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3){                
                me->start_busy(2);
                
                msg += HIR "���һָ���У�$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;   
                target->start_busy(me->query_skill("force",1)/50+3);
                me->add("neili", -(me->query_skill("force",1)/4));
//else            msg += HIG "���һָ���У���$n�Ѿ�ȫ������ͨ������������û��ʲôЧ����\n"NOR;   
                if((int)me->query_skill("yiyang-zhi", 1) > 249)
                call_out("perform3", 0, me, target);    
                } 
        else {
           me->start_busy(2);
           me->add("neili", -150);
           target->add("neili", -50);
           msg += HIY"\n$p�ۿ����޿ɱƣ���Ҳһָ��ȥ������ָ��������$p˳�����˿�ȥ��\n" NOR;

           }
        message_vision(msg, me, target);
        return 1;
}

int perform3(object me, object target)
{
        int skill;
        string msg;
        if (!me)
{
        me->delete_temp("yyz_hama");
         return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("yyz_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}
        skill = (int)me->query_skill("yiyang-zhi", 1);                
        skill = skill/10;
       
        if(!living(target)) 
{
        me->delete_temp("yyz_hama");
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
}
        if( (int)me->query("neili", 1) < 400 )
{
        me->delete_temp("yyz_hama");
                return notify_fail("���Ҫ�ٳ�����ָ��ȴ�����Լ������������ˣ�\n");     
}
        msg = YEL "\n������$Nһ��ָ�����ε�����Դ���������ͬʱ͸��$n���������Ϲ�Ѩ��
��ά�����Ѩ����������Ѩ����������Ѩ������������Ѩ��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3){                
                me->add("neili", -100);
                msg += HIR "$nֻ�������澭��������ϢΪ֮һ����ȫ��������Ȼ�᲻�����ˣ�\n" NOR;
                target->add_temp("apply/attack", -100);
                target->add_temp("apply/dodge", -100);
                target->add_temp("apply/parry", -100);  
                target->add("neili", -500);                 
                call_out("back", 3 + skill, target);
                } 
        else {
//                me->start_busy(target->query_skill("force",1)/30);
                me->start_busy(2);
                me->add("neili", -200);
//                target->start_busy(2);
                msg += HIY"\n$p��Ϣδ������$Pָ��������������æ��Ծ�����ߣ��Ǳ��رܿ���\n" NOR;
             }

        message_vision(msg, me, target);
        return 1;
}

void back(object target)
{
    if (!target) return;
        target->add_temp("apply/attack", 100);
        target->add_temp("apply/dodge", 100);
        target->add_temp("apply/parry", 100);
}

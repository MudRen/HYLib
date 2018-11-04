// junji.c
// by snowman@SJ 13/05/99

#include <ansi.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
  string msg, dodge_skill;
  int damage, p, jiali, skill, neili, neili2;

  if( !target ) target = offensive_target(me);

  if( !target || !target->is_character() ||  !me->is_fighting(target) 
      || environment(target)!=environment(me) || !living(target))
         return notify_fail("���������ơ�ֻ����ս�����á�\n");

  if( me->query_temp("weapon")) 
         return notify_fail("���������������ʹ�ó����������ơ���\n");
         
  if( me->query_temp("combat_yield") )
         return notify_fail("�㲻���֣����ʹ�ó����������ơ���\n");

  if( (int)me->query_temp("ss_junji") )
         return notify_fail("���ʩչ�꡸�������ơ����ȵ�Ϣһ�°ɣ�\n");
         
  if( (skill = (int)me->query_skill("songyang-zhang", 1)) < 140 )
         return notify_fail("��Ĵ��������Ʋ�����죬����ʹ���������ơ���\n");

  if( (int)me->query_skill("hanbing-zhenqi", 1) < 100 )
         if( (int)me->query_skill("songshan-qigong", 1) < 140 )
                return notify_fail("����ڹ���򲻹�������ʹ�á��������ơ���\n");

  if( me->query_skill_mapped("force") != "hanbing-zhenqi"
   && me->query_skill_mapped("force") != "songshan-qigong" )
         return notify_fail("�����õ��ڹ��͡��������ơ��໥��ͻ��\n");

  if (me->query_skill_prepared("strike") != "songyang-zhang" ||
      me->query_skill_mapped("strike") != "songyang-zhang")
         return notify_fail("������Ƚ������������������Ʒ�֮�в��С�\n");

  if( (jiali = (int)me->query("jiali")) < 50 )
         return notify_fail("�����ϲ�����������ôʹ�ó����������ơ�����\n");

  if( (neili = (int)me->query("neili")) < 500 )
         return notify_fail("����������㣬����ʩչ���������ơ���\n");
  if( (int)me->query("max_neili") < 1500 )
         return notify_fail("����������㣬����ʩչ���������ơ���\n");
  if( (int)me->query("jing") < 300 )
         return notify_fail("��ľ������㣬����ʩչ���������ơ���\n");

  me->start_busy(2+random(2));
  me->receive_damage("neili", me->query_skill("force") );
  me->receive_damage("jing", 50);
  msg = CYN "\nֻ����ž����һ���죬$N"CYN"����ǰ������$n"CYN"Ѹ�ٻ���һ�ƣ�";

  if( random( me->query("combat_exp") ) < target->query("combat_exp")/2) {
  	 dodge_skill = target->query_skill_mapped("dodge");
         if( !dodge_skill ) dodge_skill = "dodge";
         msg += "�Ʒ�����������С�ӣ�\n"NOR + SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
         message_vision(msg, me, target);
         return 1;
         }
  
  msg += "$p��æ���֣�˫���漴�ཻ��\n"NOR;
  neili = me->query("neili");
  neili2 = target->query("neili");
  
  if( me->query_skill("force") < target->query_skill("force")/2
     || neili < neili2/2){
     	 msg += "�����ƴ֮�£�$n��ռ�Ϸ磬��$Nһ�������˿�����\n";
     	 damage = target->query_skill("force") * 3;
     	 me->receive_damage("qi", damage,  target);
     	 me->receive_wound("qi", random(damage/2), target);
     	 p = (int)me->query("qi")*100/(int)me->query("max_qi");
         msg += damage_msg(damage, "����") + "( $N"+eff_status_msg(p)+" )\n";     
         }
  else if( me->query_skill("force") < target->query_skill("force")/3*2
         || neili < neili2/3*2)        
         msg += "�����ƴ֮�£����˶�����һ�Σ�˭Ҳû��ռ���ô���\n";
            
  else {
         damage = me->query_skill("force") + jiali * (3+random(5));
         if(neili > neili2*2) damage *= 2;
         if(damage > 6000) damage = 6000;
         if(damage < 10) damage = 10;         
           
         if(!target->is_busy())
                 target->start_busy(1);
         target->receive_damage("qi", damage,  me);
         target->receive_wound("qi", random(damage/3), me);
         p = (int)target->query("qi")*100/(int)target->query("max_qi");
         msg += damage_msg(damage, "����") + "( $n"+eff_status_msg(p)+" )\n"; 
         if(target->is_killing(me->query("id"))
            || me->is_killing(target->query("id")))
                 call_out("perform2", 0, me, target, p, damage);
                 
         p = 30 - skill/10;
         if(p < 7) p = 7;
         call_out("remove_effect", p, me);
         }
  message_vision(msg, me, target);
  return 1;
}

int perform2(object me, object target, int p, int damage)
{
        string msg, dodge_skill;

        if( !target || !target->is_character() ||  !me->is_fighting(target) 
           || environment(target)!=environment(me) || !living(target))
                return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili") < me->query_skill("force")*2 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = CYN "\n$N"CYN"΢΢һЦ��˫�ƶ�Ȼ�ཻ��$n"CYN"�����ٴ���������Ȼ������$P����������ɽ������ѹ����\n"NOR;        
        if ( me->query("neili") > target->query("neili") / 2 
          && random( me->query("combat_exp") ) > target->query("combat_exp")/2){
          	me->start_busy(2);
                me->receive_damage("neili", me->query_skill("force")*2);
                me->receive_damage("jing", 20);                              
                damage = damage*3;
                if(me->query("neili") > target->query("neili")*2 ) 
                       damage += random(damage);
                target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����") + "( $n"+eff_status_msg(p)+" )\n"; 
        } 
        else 
        {
                me->start_busy(3);
                me->add("neili", -200);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}

void remove_effect(object me)
{
        if (!me) return;
        me->delete_temp("ss_junji");
        if(living(me))
            tell_object(me, "\n�㾭��һ��ʱ�������Ϣ���ֿ���ʹ�á��������ơ��ˡ�\n"); 
}


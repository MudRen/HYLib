#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target);
int perform(object me, object target)
{
      object ob,weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����򡹹���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
      
	weapon = me->query_temp("weapon");
	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "staff")
		return notify_fail("�������ֲ���ʹ�����������\n");		
//        if(!objectp(ob = present("huo yan", environment(me))))
//                return notify_fail("û�л����ô���������򡹽��й�����\n");
        if(me->query_temp("pfm_chousui"))
                return notify_fail("������������ѽ��й�����\n");

       message_vision(HIR"\n$N������ȣ�������ʢ��������ͻȻ����һ�������"RED"����"HIR"���ڿ��й�µµ��Ѹ��ת����\n\n"NOR,me);

       me->start_busy(2);
       me->add_temp("max_guard",-1);
       me->set_temp("pfm_chousui", 1);
       if(random(me->query_kar()) > 15)
             check_pfm(me, target);
       else call_out("check_pfm", 6, me, target);
       return 1;
}

int check_armor(object target)
{
       object *inv;
       int i, j;
       inv = all_inventory(target);
       j=0;
          for(i=0; i<sizeof(inv); i++)
            if( (string)inv[i]->query("equipped")=="worn" ) j++;
       return j;
}
int check_pfm(object me, object target)
{
        string msg, *limbs;
        int i, neili, ap, dp, damage, p;
        object *inv;
        if(!me) return 0;
        if(!target) return 0;
        i = (int)me->query_skill("xuantian-strike", 1);
        neili = (int)me->query("neili");
        damage = (i+me->query("jiali"))*2;

        me->delete_temp("pfm_chousui");
        me->start_busy(1);
        if(!living(me) || me->is_ghost()) return 1;
        if( i < 180 ){
                tell_object(me, "�㷢���Լ�����������ƻ�������죬�޷�ʹ�á����򡹽��й�����\n");
                return 1;
                }
        if( (int)me->query_skill("huagong-dafa",1) < 180 ){
                tell_object(me,"�㷢���Լ��Ļ�������Ϊ�������޷�ʹ�á����򡹽��й�����\n");
                return 1;
                }
        if( me->query_skill_mapped("force") != "huagong-dafa"){
                tell_object(me,"�㷢���Լ����õ��ڹ��޷����С����򡹹�����\n");
                return 1;
                }
        if( (int)me->query("max_neili") < 1500) {
                tell_object(me,"�㷢���Լ�����̫�����޷����������򡹽��й�����\n");
                return 1;
                }
        if(neili < 1500){
                tell_object(me,"�㷢���Լ���������̫����ʹ���������򡹽��й�����\n");           
                return 1;
                }           
        if(!target || !me->is_fighting(target) || environment(me)->query("no_fight")
           || environment(me)!=environment(target)){
           message_vision(HIY"$N�����ٷ����������"RED"����"HIY"ѹ�ػ���֮�С�\n"NOR,me);
           return 1;
           }


        ap = me->query("combat_exp")/1000 * i * me->query_str();
        dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_con();
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;
        me->add("neili", -600);
        me->add("jing", -10);

        msg = WHT"\n��ʱ$N�������ް��Ѫɫ��һ�ڿ���Ѫ��ס��"RED"����"WHT"����ȥ��"HIR"����һʢ�������������죬
��������𻨣�"RED"����"HIR"��Ȼ�����$n���������\n"NOR;

       
       if(random(ap) > dp/4){
          inv = all_inventory(target);
          if(check_armor(target) >= 1){     
            if(me->query("neili") > target->query("neili")*2){
               if(me->query_str() > random(target->query_str())){
                  me->start_busy(2);
                  target->start_busy(2);
                  msg += HIY"���Ҽ�����¶�������𻨱��䣬ը����$p�Ļ��ߣ�\n" NOR;
                  for(i=0; i<sizeof(inv); i++)
                     if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique")){
                         inv[i]->unequip();
                         inv[i]->move(environment(target));
                         inv[i]->set("name", "�����" + inv[i]->query("name"));
                         inv[i]->delete("value");
                         inv[i]->set("armor_prop", 0);
                         }
                  target->reset_action();
                  damage = damage * 3;
                  if (damage > 2000) damage = 2000;
                  damage = damage - target->query_temp("apply/armor");
                  target->receive_damage("qi", damage, me);   
                  target->receive_wound("qi", damage/4, me);             
                          target->apply_condition("xx_poison",20);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
target->apply_condition("fire_poison",60);
                  target->apply_condition("xx_poison", random(15) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
                  p = (int)target->query("qi")*100/(int)target->query("max_qi");
                  msg += damage_msg(damage, "����");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  me->start_busy(1);
                  target->start_busy(1);               
                  }                   
            else {
                  me->start_busy(2);
                  target->start_busy(2);
                  msg += HIY"ֻ��������Ȼ���£����Ľ�������ֱ͸$p�Ļ��ߣ�\n" NOR;
                  for(i=0; i<sizeof(inv); i++)
                     if((string)inv[i]->query("equipped")=="worn" && !inv[i]->query("unique")){
                         inv[i]->set("name", "���ѵ�" + inv[i]->query("name"));
                         inv[i]->set("value", 49);
                         if(inv[i]->query("armor_prop/armor"))
                             inv[i]->set("armor_prop/armor", inv[i]->query("armor_prop/armor")/2);
                         }
                  target->reset_action();
                  damage = damage * 3;
                  if (damage > 1800) damage = 1800;
                  damage = damage - target->query_temp("apply/armor");
                  target->receive_damage("qi", damage, me); 
                  target->receive_wound("qi", damage/4, me);            
                  target->apply_condition("xx_poison", random(5) + (me->query_skill("poison", 1)/10) + target->query_condition("xx_poison"));
                  p = (int)target->query("qi")*100/(int)target->query("max_qi");
                  msg += damage_msg(damage, "����");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  me->start_busy(2);
                  target->start_busy(1);
                  }
               }
           else {
                  me->start_busy(3);
                  target->start_busy(3);
                  msg += HIY"�����ٹ���������Ľ��������������ײ��$p���\n" NOR;                  
                  damage = damage * 2;
                  if (damage > 1800) damage = 1800;
                  target->receive_damage("qi", damage, me);
                  target->receive_wound("qi", damage/6, me);                
                  target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
                  p = (int)target->query("qi")*100/(int)target->query("max_qi");
                  msg += damage_msg(damage, "����");
                  msg += "( $n"+eff_status_msg(p)+" )\n";
                  me->start_busy(2);
                  target->start_busy(1);
                  }
            }
        else{
                //target has no armor, so, hehe...
                damage = damage*2 + random(damage);
                if(neili > target->query("neili")*2) damage = damage*2;
                if (damage > 2800) damage = 2800;
                target->receive_damage("qi", damage, me);   
                target->receive_wound("qi", damage/2, me);             
                target->apply_condition("xx_poison", 30 + target->query_condition("xx_poison"));
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                me->start_busy(2);
                target->start_busy(1);
                }
        }
     else{
          me->add_temp("max_guard",-1);
        me->start_busy(4);
        msg += HIY"\n$p�ۿ���Ҫ�����У�ð��һ���������š���ȫ����ϥ�Ǵ����ȥ�������ܹ�$w"HIY"��\n" NOR;
        }
       limbs = target->query("limbs");
       msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
       msg = replace_string(msg, "$w", RED"����"NOR);       
       message_vision(msg, me, target);
//me->kill_ob(target);
//       if(!target->is_killing(me->query("id"))) target->kill_ob(me);
       return 1;
} 


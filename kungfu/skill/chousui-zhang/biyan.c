#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
int check_pfm(object me, object target);
int perform(object me, object target)
{
      object ob,weapon;
weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("�����桹����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
      
	if( objectp(me->query_temp("weapon")) 
	&& (string)weapon->query("skill_type") != "staff")
		return notify_fail("�������ֲ���ʹ�á����桹��\n");		

//        if(!objectp(ob = present("huo yan", environment(me))))
//                return notify_fail("û�л����ô���������桹���й�����\n");
        if(me->query_temp("pfm_chousui"))
                return notify_fail("������������ѽ��й�����\n");
       message_vision(HIC"\n$N����ָ��"HIR"���"HIC"��Ĭ��������ע���Ż��棬���ư��أ������૵Ĳ�֪˵Щʲô������\n"NOR,me);
       me->start_busy(1);
       me->set_temp("pfm_chousui", 1);
       if(random(me->query_kar()) > 15)
             check_pfm(me, target);
       else call_out("check_pfm", 2, me, target);
       return 1;
}

int check_pfm(object me, object target)
{
        string msg, *limbs;
        int i, neili, ap, dp, damage, p;

        if(!me) return 0;
        if(!target) return 0;
        i = (int)me->query_skill("chousui-zhang", 1);
        neili = (int)me->query("neili");        

        me->delete_temp("pfm_chousui");
        if(!living(me) || me->is_ghost()) return 1;
        if( i < 80 ){
                tell_object(me, "�㷢���Լ������޶��ƻ�������죬�޷�ʹ�á����桹���й�����\n");
                return 1;
                }
        if( (int)me->query_skill("huagong-dafa",1) < 80 ){
                tell_object(me,"�㷢���Լ��Ļ�������Ϊ�������޷�ʹ�á����桹���й�����\n");
                return 1;
                }
        if( me->query_skill_mapped("force") != "huagong-dafa"){
                tell_object(me,"�㷢���Լ����õ��ڹ��޷����С����桹������\n");
                return 1;
                }
        if( (int)me->query("max_neili") < 500) {
                tell_object(me,"�㷢���Լ�����̫�����޷����������桹���й�����\n");
                return 1;
                }
        if(neili < 300){
                tell_object(me,"�㷢���Լ���������̫����ʹ���������桹���й�����\n");           
                return 1;
                }     
          
        if(!living(target) || !target || !me->is_fighting(target) || environment(me)->query("no_fight")
           || environment(me)!=environment(target)){
           message_vision(HIY"$N�����������ջأ�ɢ����Ϣ��˫���´�������\n"NOR,me);
           return 1;
           }
 
        if(target->query_condition("xx_poison") > 100){
                tell_object(me,"�Է��Ѿ����������綾���㲻���ٽ��С����桹�����ˡ�\n");           
                return 1;
                }
        ap = me->query("combat_exp")/1000 * i * me->query_str();
        dp = target->query("combat_exp")/1000 * target->query_skill("parry",1) * target->query_dex();
        if (ap < 1) ap = 1;
        if (dp < 1) dp = 1;
        me->add("neili", -100);
        me->add("jing", -10);

        msg = HIC"\nȻ��$NͻȻ˫����ǰƽƽ�Ƴ�������"RED"����"HIC"΢΢���������£��³�һ��"GRN"����"HIC"������$n��$l��\n"NOR;        
        if(random(ap) > dp/4){
          damage = random(i)*2+me->query("jiali")*2;
          if(neili > target->query("neili")*2) damage = damage*2;
          if (damage > 700) damage = 700;
          target->receive_damage("qi", damage, me);
          target->receive_wound("qi", damage/2, me);
	 target->apply_condition("x2_sandu",20);
	 target->apply_condition("sanpoison",20);
          target->apply_condition("xx_poison",  (me->query_skill("poison", 1)/2) + target->query_condition("xx_poison"));
          p = (int)target->query("qi")*100/(int)target->query("max_qi");
          msg += damage_msg(damage, "����");
          msg += "( $n"+eff_status_msg(p)+" )\n";
          me->start_busy(1);
          me->add_temp("max_guard",-1);
          target->start_busy(1);
          }
        else{
          me->start_busy(2);
          me->add_temp("max_guard",-1);
          msg += HIY"\n$pȫ�����һ��һ����������ֵرܿ����Ǽ��ٶ�����$w"HIY"��\n" NOR;
          }       
       limbs = target->query("limbs");
       msg = replace_string(msg, "$l", limbs[random(sizeof(limbs))]);
       msg = replace_string(msg, "$w", GRN"����"NOR);
       message_vision(msg, me, target);
       return 1;
}


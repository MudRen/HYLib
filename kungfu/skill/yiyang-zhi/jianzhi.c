//��ָս��
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h"; 
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
int damage,p;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("six-finger",1);
        if( !target ) target = offensive_target(me);

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("ֻ�ܿ���ʹ�á�\n");		

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���ž�ѧֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("six-finger", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

       if( !wizardp(me) &&(int)me->query_skill("yiyang-zhi", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("kurong-changong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "kurong-changong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ������ѧ��ʹ���˴���ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);   
	me->add_temp("apply/attack",extra);
	me->add_temp("apply/damage",extra*3);
	weapon = me->query_temp("weapon");
if (random(3)==0) target->start_busy(3);
        msg = CYN "$N��˼���ң���$n����ңָ�˼��£�����ȴʹ�������������ľ���"HIY"[��������]"CYN"��" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------------------------���̽���" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = GRN   "-------------------------------��������" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg =  MAG  "-------------------------------�г彣��" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL   "-------------------------------�س彣��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = WHT   "-------------------------------���󽣣�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = BLU   "-------------------------------�ٳ彣��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-extra);
	 me->add_temp("apply/damage",-extra*3);
        me->add("neili", -500);
        me->start_busy(4);
        if ((target->query_skill_mapped("force")=="hamagong" || 
            target->query_skill_mapped("strike") == "hamagong")){
            msg = YEL "\n$N����$n��������ָ��һʽ���������������ֻ������������ָ��ֱϮ$n�ؿڣ�\n" NOR;
         if (random(me->query_skill("force",1)) > target->query_skill("force",1) /3 
         || random(me->query("combat_exp")) > target->query("combat_exp")/2 ){
                target->start_busy(1);
                damage = (int)me->query_skill("yiyang-zhi", 1);
//                damage = (int)me->query_skill("qiantian-yiyang", 1) +damage;
                damage = (int)me->query_skill("kurong-changong", 1) +damage*2;
                damage = random(damage)+650;
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage);               
                me->add("neili", -100);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += HIR "$nһ��֮�£���Ϊʧɫ���������ƺ������Լ��Ŀ��ǣ�\n"NOR;   
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                } 
         else {       
           
                msg += HIY"$p���ⷴ�ֵ�Ѩ�ƺ����Ǹ�󡹦�Ŀ��ǣ�ʶ��������Σ��֮��һ�������ţ��������һ�������ѵĶ����һ�С�\n"NOR;
                }
         }
       else{
         msg = YEL "\n$N������ָ��һʽ������������������������������죬һ�ɴ���������ֱϮ$n�ؿڣ�\n" NOR;
          if (random(me->query_skill("parry")) > target->query_skill("parry") / 3)
             {
                target->start_busy(2);
                damage = (int)me->query_skill("yiyang-zhi", 1);
  //              damage = (int)me->query_skill("qiantian-yiyang", 1) +damage;
                damage = (int)me->query_skill("kurong-changong", 1) +damage;
       damage = damage + random(damage);
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage*2);               
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                if(me->query_skill("yiyang-zhi", 1) > 180)
                call_out("perform2", 0, me, target);    
              } 
         else {       

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
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("yyz_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}
        if (!me || !target) return 0;
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");  

        if( (int)me->query("neili", 1) < 600 )
                return notify_fail("���Ҫ�ٳ��ڶ�ָ��ȴ�����Լ������������ˣ�\n");     
       
        msg = YEL "\n����$N̤ǰһ�������ڶ�ָ���յ���$n��ǰ������Ѩ������Ѩ�������֮�\n"NOR;
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 3){                
                msg += HIR "���һָ���У�$nֻ����ȫ������ͨ���������������ܸ��ӣ�\n"NOR;   
                target->start_busy(me->query_skill("force",1)/50+2);
//else            msg += HIG "���һָ���У���$n�Ѿ�ȫ������ͨ������������û��ʲôЧ����\n"NOR;   
                if((int)me->query_skill("yiyang-zhi", 1) > 249)
                call_out("perform3", 0, me, target);    
                } 
        else {
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
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("yyz_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}
        if (!me || !target) return 0;
        skill = (int)me->query_skill("yiyang-zhi", 1);                
        skill = skill/10;
       
        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("���Ҫ�ٳ�����ָ��ȴ�����Լ������������ˣ�\n");     

        msg = YEL "\n������$Nһ��ָ�����ε�����Դ���������ͬʱ͸��$n���������Ϲ�Ѩ��
��ά�����Ѩ����������Ѩ����������Ѩ������������Ѩ��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3){                
                msg += HIR "$nֻ�������澭��������ϢΪ֮һ����ȫ��������Ȼ�᲻�����ˣ�\n" NOR;
                target->add_temp("apply/attack", -100);
                target->add_temp("apply/dodge", -100);
                target->add_temp("apply/parry", -100);  
                target->add("neili", -500);                 
                call_out("back", 3 + skill, target);
                } 
        else {
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

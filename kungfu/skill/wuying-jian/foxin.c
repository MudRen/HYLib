// foxing ʾ����
// campsun
//2000.9.17

#include <ansi.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

inherit F_SSERVER;
int perform(object me, object target)
{
  object weapon;
string msg;
int damage,p;        
int extra;
        string dodge_skill;

        if( !target ) target = offensive_target(me);

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("wuying-jian", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("yijinjing", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("hunyuan-yiqi", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ������ѧ��ʹ�������ֵľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               
        msg = HIY "\n$N��ȻԾ�����һ��һ������ʱ֮���߳�һ�С��硹�־��Ĵ����ȣ�ֱϮ$nǰ�أ�\n" NOR;
	            damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+350;
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/8);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                   
 msg += damage_msg(damage, "����");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);               
        msg = HIY "\n������$N���ȹ��أ�������һŤ�������ȵ�һ�С�Ӱ���־���������������$n��\n" NOR;
me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+100;
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/7);

        
     msg += damage_msg(damage, "����");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  
        
         if( (int)me->query_skill("yijinjing", 1) >150  ){

        msg = HIY "\nֻ��$N�ҽž���δ���������һת������˳��ɨ��һ�С��桹�־�����Ӱ������\n" NOR;
me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+200;
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/6);

        
     msg += damage_msg(damage, "����");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  

}
if( (int)me->query_skill("yijinjing", 1) >180  ){

        msg = HIY "\n�����$N��δ�󳷣��Ѿ������Ρ��־����ھ�ֱ͸�ż⣬��$n�ظ�����������ʮ�£�\n" NOR;
me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+350;
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/5);

        
     msg += damage_msg(damage, "����");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  

}

 if( random((int)me->query_skill("yijinjing", 1)) >180  ){

        msg = RED "\n��ʱ$N˫��չ��������һ��ǿ�ҵ����磬˫����ʱ�벢������Ӱ���Ρ�һ�����ں���$n����֮�ϣ�\n" NOR;
me->add("neili",-100);
        target->start_busy(1+random(2));

damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+450;
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/4);

        
     msg += damage_msg(damage, "����");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  

 }
extra = me->query_skill("wuying-jian",1) / 10;
if ((int)me->query_skill("yijinjing",1) >250
&&(int)me->query_skill("wuying-jian",1) >250
&& me->query("neili") >500)
{

if (random(3)==0) target->start_busy(3);
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
	msg = HIR  "�ۿ���ʽҪ�꣬ͻȻ��$N��ʩչ�������ٻ�Ӱ�����ţݣ����μ�����ת��һ����Ӱ��ͻȻ��$n�ɳ�һ�ȣ�" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//	COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "��Ӱ���ַɳ�һ�ȣ�" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        extra *=2;
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        msg = HIR  "$N���ν��ȣ���������һ�ȣ�" NOR;
COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
//        COMBAT_D->do_attack(me,target, 0, TYPE_REGULAR,msg,"����");
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
me->add("neili",-350);
}
msg =YEL "\n$N��������ʹ�꣬ȫ��һת���������ڵ��ϡ�\n";
message_vision(msg, me, target);                  
me->start_busy(3+random(3));
	me->add("neili", -me->query("max_neili")/7);
        msg = RED "\n$N�ӵ����ϵ���������˵�����������������سɷ�һ��ǿ��֮���Ʒ�ֱ��$n��ȥ��\n"NOR;        
//weapon->unequip();
//        weapon->move(environment(me));

//        me->set_temp("sl_wuying", 1);
        
        if (random(me->query_skill("force")) > target->query_skill("force") /3 ){                     
//                me->start_busy(1);
                target->start_busy(2); 
                me->add("neili", -100);
                me->add("jing", -20);
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*2 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
//                me->start_busy(2);
//                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIY"�㵫��һ��΢�����������������Ȼ������Ȼ�ѱƵ��Լ�����������֪�������æԾ�����ߡ�\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;

        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = HIC "\n$N���ƾ���δ��������Ҳ�����Ƴ�����������������سɷ��Ʒ���ɽ������ӿ��$n��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("wuying-jian", 1) > 199 ){                
//                me->start_busy(1);
                target->start_busy(2);
                me->add("neili", -100);
                me->add("jing", -30);                
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*3 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/3);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
//                me->start_busy(2);
                me->add("neili", -100);
                tell_object(target, HIY"�㴭Ϣδ�����־�һ�ɾ��������������æԾ�����ߣ��Ǳ��رܿ���\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                
        }
        message_vision(msg, me, target); 
        return 1;
}

int perform3(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;
  
        if(!living(target))
              return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = HIG "\n$N΢΢һЦ��˫���ಢ��ǰ�Ƴ�����������ʲô��������$n��ͬ��ǰ��Բ����ȫ�ڡ����سɷ𡹾�������֮�£�\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("wuying-jian", 1) > 249 )
        {
//                me->start_busy(2);
                target->start_busy(random(5)+2);
                me->add("neili", -200);
                me->add("jing", -40);                
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
//                me->start_busy(2);
//                target->start_busy(1);
                me->add("neili", -200);
                target->add("jing", -100);
                tell_object(target, HIY"���þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }
        message_vision(msg, me, target); 
        return 1;
}


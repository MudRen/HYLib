// hama.c ������Ӱ��

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg, dodge_skill;
        object weapon;
        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("���سɷ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        if( (int)me->query_skill("wuying-jian", 1) < 100 )
                return notify_fail("���������Ӱ������������������ʹ�����سɷ�ԵУ�\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
        return notify_fail(RED"װ��������ʹ�á����سɷ�!\n"NOR);

//        if (me->query_skill_mapped("force") != "yijinjing")
//                return notify_fail("����ڹ������׽��\n");

	if( (int)me->query_skill("yijinjing", 1) < 150 )
		return notify_fail("����׽������졣\n");

        if( (int)me->query("max_neili") < 1500 )
                return notify_fail("�������������㣬ʹ����������Ӱ���ľ��У�\n");     

        if( (int)me->query("neili") < 400 )
                return notify_fail("�������������㣬ʹ����������Ӱ���ľ��У�\n");     

        if( (int)me->query_skill("force", 1) < 150 )
                return notify_fail("�������������죬ʹ����������Ӱ���ľ��У�\n");

        if (me->query_str() < 28 )
                return notify_fail("�������̫С��ʹ���������سɷ�\n");

        if( me->query_temp("sl_wuying") )
                return notify_fail("���ʹ�꡸������Ӱ�������У�Ŀǰ��Ѫ��ӿ���޷��ٴ����ã�\n");
        
        msg = RED "\n$N�ӵ����ϵ���������˵�����������������سɷ�һ��ǿ��֮���Ʒ�ֱ��$n��ȥ��\n"NOR;        
weapon->unequip();
//        weapon->move(environment(me));

        
        if (random(me->query_skill("force")) > target->query_skill("force") /4 ){                     
                me->start_busy(1);
                target->start_busy(2); 
                me->add("neili", -200);
                me->add("jing", -20);
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*2 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
                me->start_busy(2);
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

if (!target)
{
        me->delete_temp("sl_wuying");
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
}
        if(!living(target)) 
{
        me->delete_temp("sl_wuying");
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
}
        if( (int)me->query("neili", 1) < 500 )
{
        me->delete_temp("sl_wuying");
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     
}
        msg = HIC "\n$N���ƾ���δ��������Ҳ�����Ƴ�����������������سɷ��Ʒ���ɽ������ӿ��$n��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("wuying-jian", 1) > 199 ){                
                me->start_busy(1);
                target->start_busy(2);
                me->add("neili", -300);
                me->add("jing", -30);                
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*3 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                me->start_busy(2);
                me->add("neili", -200);
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
if (!target)
{
        me->delete_temp("sl_wuying");
          return notify_fail("�����Ѿ�������ս���ˡ�\n");
}  
        if(!living(target))
{
        me->delete_temp("sl_wuying");
              return notify_fail("�����Ѿ�������ս���ˡ�\n");
}
        if( (int)me->query("neili", 1) < 700 )
{
        me->delete_temp("sl_wuying");
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     
}
        msg = HIG "\n$N΢΢һЦ��˫���ಢ��ǰ�Ƴ�����������ʲô��������$n��ͬ��ǰ��Բ����ȫ�ڡ����سɷ𡹾�������֮�£�\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("wuying-jian", 1) > 249 )
        {
                me->start_busy(2);
                target->start_busy(random(3));
                me->add("neili", -400);
                me->add("jing", -40);                
                damage = (int)me->query_skill("wuying-jian", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
                me->start_busy(2);
//                target->start_busy(1);
                me->add("neili", -300);
                target->add("jing", -100);
                tell_object(target, HIY"���þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }

        message_vision(msg, me, target); 
        return 1;
}


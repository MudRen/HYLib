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
        int damage, p;
        string dodge_skill;
	if(me->is_busy())
		return notify_fail("������û�գ���\n");
	extra = me->query_skill("lingshe-zhangfa",1);
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("��ʹ�õ��������ԡ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("hamashengong", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("lingshe-zhangfa", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("hamagong", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "hamagong")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ������ѧ��ʹ���˰��յľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);               


	me->add_temp("apply/attack",(extra/3));
	me->add_temp("apply/damage",(extra));
	weapon = me->query_temp("weapon");
if (random(2)==0) target->start_busy(3);
        msg = HIY "$N���������⣬ͻȻһ�����ȣ���------ �� ----- �� ----- ɨ ----- �� ----- Ҷ ----- ��������" NOR;
	         message_vision(msg, me, target);                
	 msg =  YEL  "$N���μӿ죬����֮�����������" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
	msg =  YEL  "$Nͻ�������Ĵӿ��������������$n��ǰ����һ�ȣ�" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N���Ȼ�������$n��࣬����һ����" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
        msg = YEL  "$N����������һ�������Ӹ����£���ͷ����һ�ȣ�" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "���ڰ�գ�$N����Ϊ�ƣ���ʵΪ�ȣ���$n��̹�ȥ��" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
        msg = YEL "$N�������裬�ܲ�͸�磬ʹ$n�����е�͸����������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
	 msg = YEL "$N���л��ɳˣ�һ�Ƚ���һ�ȣ�����������" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
	 msg = YEL "$N�������֮���������е�"+ weapon->name() +"����ǧ����˳�$n��ȥ��" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("hamagong",1)));
        me->add_temp("apply/attack",-(extra/3));
	 me->add_temp("apply/damage",-(extra));
if (extra > 250
&&  random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
{
	 msg = RED "�߶�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("snake_poison",10);
	 msg = RED "��ܶ�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("chanchu_poison",10);
	 msg = RED "�����߶�" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("qx_snake_poison",20);
}

        msg = BLU "\n$N���Ӷ��£�����ƽ�ƶ�����ʹ������$N��ƽ�����ġ���󡹦�����У��Ʒ�ֱ��$n��ȥ��\n"NOR;        
//        me->set_temp("hmg_hama", 1);
        
        if (random(me->query_skill("force")) > target->query_skill("force") /3
         || random(me->query("combat_exp")) > target->query("combat_exp")/3){                     
                target->start_busy(1); 
                me->add("neili", -100);
                me->add("jing", -10);
                damage = (int)me->query_skill("hamashengong", 1);                
                damage = damage*2 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {
                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIY"�㵫��һ��΢�����������������Ȼ������Ȼ�ѱƵ��Լ�����������֪�������æԾ�����ߡ�\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
                call_out("remove_effect", me->query_con()/6, me);
        }
        message_vision(msg, me, target); 
        return 1;
        me->start_busy(4);

        return 1;
}


int perform2(object me, object target, int p)
{
        int damage;
        string msg, dodge_skill;

        if (!me)
{
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("hmg_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}

        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = BLU "\n$N���ƾ���δ��������Ҳ�����Ƴ����������������󡹦���Ʒ���ɽ������ӿ��$n��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("hamagong", 1) > 199 ){                
                target->start_busy(1);
                me->add("neili", -100);
                me->add("jing", -20);                
                damage = (int)me->query_skill("hamashengong", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                
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
  
        if (!me)
{
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("hmg_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}

        if(!living(target))
              return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("���Ҫ�ٷ�һ�ƣ�ȴ�����Լ������������ˣ�\n");     

        msg = BLU "\n$N˫��һ�ǣ�˫���ಢ��ǰ�����Ƴ���$n��ͬ��ǰ��Բ����ȫ�ڡ���󡹦����������֮�£�\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("hamashengong", 1) > 249 )
        {

                target->start_busy(random(3));
                me->add("jing", -30);                
                damage = (int)me->query_skill("hamashengong", 1);                
                damage = damage*6 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
                me->start_busy(4);
                target->start_busy(1);
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

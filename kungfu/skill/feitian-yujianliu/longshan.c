// longshan ������
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
inherit F_SSERVER;
int perform(object me, object target)
{
	object weapon, ob;
	string msg,dodge_skill;
        int extra,damage,p;
        extra = me->query_skill("feitian-yujianliu",1);

	 if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("ֻ����ս����ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
			return notify_fail("��ʹ�õ��������ԡ�\n");


	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("xuanhualiu-quanfa", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("feitian-yujianliu", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("shayi-xinfa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "shayi-xinfa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ������������ѧ��ʹ�����������ľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);              
	
	extra = me->query_skill("feitian-yujianliu",1) / 15;
	extra += me->query_skill("feitian-yujianliu",1) /15;
	me->add_temp("apply/attack", 100);	
	me->add_temp("apply/damage", extra*4);
if (random(3)==0) target->start_busy(3);
message_vision(RED"$N��������ɫ���۾���ͻȻ���������Ĺ��$n��\n"NOR,me,target);
	msg = HIR "$N�ٶ�ͻȻ�ӿ�!��Ÿ���ʹ���˾��ֲ�ͬ������! $n��Ȼ�е��޷������Ͷ�ܣ���\n" NOR;     
message_vision(msg, me, target);
	msg = HIG "Ҽ������" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIC "��������ն��" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIB "���������ģ�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIY "������̣�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIR "�飡�Ҵ̣�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = HIM "½�������ϣ�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shayi-xinfa",1)));
	msg = HIW "�⣡�����ϣ�" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shayi-xinfa",1)));
	msg = CYN "�ƣ���磡" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shayi-xinfa",1)));
	msg = BLU "������ͻ����" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("shayi-xinfa",1)));
	me->add_temp("apply/attack", -100);
	me->add_temp("apply/damage", -extra*4);

	me->start_busy(4);
weapon->unequip();

        msg = HIW "\n$NͻȻȫ�����������һȭ������һ���ɫ��ȫ�������ʹ���������һ����\n   һȭ�����ȭ��ֱ��$n��ȥ��\n"NOR;        
        
        if (random(me->query_skill("force")) > target->query_skill("force") /3
         || random(me->query("combat_exp")) > target->query("combat_exp")/3){                     
                target->start_busy(1); 
                me->add("neili", -200);
                me->add("jing", -10);
                damage = (int)me->query_skill("xuanhualiu-quanfa", 1);                
                damage = damage*3 + random(damage);
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/3);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 0, me, target, p);    
                } 
        else {

                target->start_busy(1);
                me->add("neili", -100);
                tell_object(target, HIG"�㵫��һ��ǿ�����������������������֪�������æԾ�����ߡ�\n" NOR);
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

        if (!me)
{
 return notify_fail("���Ѿ������ˡ�\n");
}

        if (!target)
{
        me->delete_temp("ft_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}

        if(!living(target)) 
          return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("���Ҫ�ٷ�һȭ��ȴ�����Լ������������ˣ�\n");     

        msg = RED "\n�����ؾ�!��$N��ȭ����δ������ȭҲ���Ŵ����\n   ��$nû�в����ֿ���ʱ����ڶ���,ȭ����ɽ������ӿ��$n��\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("shayi-xinfa", 1) > 199 ){                
                target->start_busy(1);
                me->add("neili", -100);
                me->add("jing", -20);                
                damage = (int)me->query_skill("xuanhualiu-quanfa", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage/2);
                target->receive_wound("qi", damage/3);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";                
                call_out("perform3", 0, me, target, p);  
        } 
        else 
        {
                me->add("neili", -100);
                tell_object(target, HIG"�㴭Ϣδ�����ֿ�����δ������ֻ��Ծ�����ߣ��Ǳ��رܿ���\n" NOR);
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
        me->delete_temp("ft_hama");
         return notify_fail("�����Ѿ������ˡ�\n");
}

        if(!living(target))
              return notify_fail("�����Ѿ�������ս���ˡ�\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("���Ҫ�ٷ�һȭ��ȴ�����Լ������������ˣ�\n");     

        msg = HIR "\n�����ؾ�!��$Nȫ�����һ����,ƴ����������ʹ����������ȭ�����ռ�������\n   $n��ͬ��ǰ��Բ����ȫ�ڡ����ؾ�!����������֮�£�\n"NOR;        
        if (random(me->query_skill("force")) > target->query_skill("force") / 3 &&
            me->query_skill("xuanhualiu-quanfa", 1) > 249 )
        {
                target->start_busy(random(3));
                me->add("neili", -300);
                me->add("jing", -30);                
                damage = (int)me->query_skill("xuanhualiu-quanfa", 1);                
                damage = damage*5 + random(damage)*2;
                if(me->query("neili") > target->query("neili")*2 ) damage += random(damage);
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                p = (int)target->query("qi")*100/(int)target->query("eff_qi");
                msg += damage_msg(damage, "����");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
        } else 
        {
                me->start_busy(4);
                me->add("neili", -100);
                target->add("jing", -100);
                tell_object(target, HIG"���þ�ȫ����������һ��һ����ҡҡ������վ��������������㿪����������һ����\n" NOR);
                dodge_skill = target->query_skill_mapped("dodge");
	        if( !dodge_skill ) dodge_skill = "dodge";
	        msg += SKILL_D(dodge_skill)->query_dodge_msg(target, 1);
        }

        message_vision(msg, me, target); 
        return 1;
}
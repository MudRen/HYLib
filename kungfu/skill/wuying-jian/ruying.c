// ruying ��Ӱ����
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
        if( !target ) target = offensive_target(me);

        if( !target || !me->is_fighting(target) )
                return notify_fail("����Ӱ���Ρ�ֻ����ս���жԶ���ʹ�á�\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("��������Ӱ��ֻ����ս����ʹ�á�\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
                return notify_fail("����Ӱ���Ρ������ý�����ʩչ��\n");

        if( (int)me->query_skill("wuying-jian", 1) < 150 )
                return notify_fail("��ġ�������Ӱ����������죬����ʹ�á���Ӱ���Ρ���\n");

        if (me->query_skill_mapped("force") != "yijinjing")
                return notify_fail("����ڹ������׽��\n");

	if( (int)me->query_skill("yijinjing", 1) < 100 )
		return notify_fail("����׽������졣\n");

        if( (int)me->query_dex() < 27 )
                return notify_fail("���������ǿ������ʹ�á���Ӱ���Ρ���\n");
      

        if( (int)me->query("neili") < 1000 )
                return notify_fail("����������̫��������ʹ�á���Ӱ���Ρ���\n");

        msg = HIY "\n$N��ȻԾ�����һ��һ������ʱ֮���߳�һ�С��硹�־��Ĵ����ȣ�ֱϮ$nǰ�أ�\n" NOR;
	            damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+50;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/6);
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                   
 msg += damage_msg(damage, "����");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);               
        msg = HIY "\n������$N���ȹ��أ�������һŤ�������ȵ�һ�С�Ӱ���־���������������$n��\n" NOR;
me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+100;
                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/6);

        
     msg += damage_msg(damage, "����");
 msg += "( $n"+eff_status_msg(p)+" )\n";
message_vision(msg, me, target);                  
        
         if( (int)me->query_skill("yijinjing", 1) >150  ){

        msg = HIY "\nֻ��$N�ҽž���δ���������һת������˳��ɨ��һ�С��桹�־�����Ӱ������\n" NOR;
me->add("neili",-100);
damage = (int)me->query_skill("wuying-jian", 1);
                damage = (int)me->query_skill("yijinjing", 1) +damage;
                damage = random(damage)+200;
                target->receive_damage("qi", damage);
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
                target->receive_damage("qi", damage);
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
                target->receive_damage("qi", damage);
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
me->add("neili",-150);
}
msg =YEL "\n$N��������ʹ�꣬ȫ��һת���������ڵ��ϡ�\n";
message_vision(msg, me, target);                  
me->start_busy(3);
        return 1;



}

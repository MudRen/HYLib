//���

#include <ansi.h>


inherit F_SSERVER;


int perform(object me, object target)
{
	
  int skill;
	string msg;
	object weapon;
	
 if( !target ) target = offensive_target(me);

	
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		
return notify_fail("���ֻ����ս����ʹ�á�\n");
msg = HIR "$N���һ����\n" NOR;
  
    	message_combatd(
        HIR "$N"HIR"��������һ�������漴һ��ŭ��һ�Ż������������
 $n"HIR"һ��֮�����һƬ��֮�У�\n" NOR, me, target);
   if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
message_combatd(HIR "$n"HIR"һ���ҽУ������˵ò��ᣡ\n" NOR, me, target);
    target->add("eff_qi", -target->query("eff_qi")/20);           
    target->add("qi", -target->query("qi")/20);           
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
    me->start_busy(1); 	
}
else 
{
	
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$nһ��ɶҲ��������,ֻ�ò�ȡ��ʽ������������\n" NOR;
            target->start_busy(6);           
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
            } else {
                msg += HIY"����$p������$N����ͼ������㣬ȫ��Ӧ�����硣\n" NOR;
                me->start_busy(random(2));
        }
        message_combatd(msg, me, target);
message_combatd(HIC "$n"HIC"���Ų�æ��һ����Ծ�����˳�ȥ��\n" NOR, me, target);
    me->start_busy(1); 	
}
        return 1;
  
 }
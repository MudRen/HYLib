//����

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
		
return notify_fail("����ֻ����ս����ʹ�á�\n");

  msg = HIR "$N���һ����\n" NOR;
    	message_combatd(
        HIW "ֻ��$N"HIW"��һ�ţ�һ�Ű�ɫ���ȵ�Ũ��ֱ����$n!\n" NOR, me, target);
	
   if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
message_combatd(HIR "$n"HIW"һ��ɶҲ��������,ֻ�ò�ȡ��ʽ������������\n" NOR, me, target);
target->apply_condition("ill_dongshang",10 );
target->apply_condition("ill_fashao",10 );
target->apply_condition("ill_kesou",10 );
target->apply_condition("ill_shanghan",10 );
target->apply_condition("ill_zhongshu",10 );
	       target->apply_condition("snake_poison",10 );
	       target->apply_condition("wugong_poison",10 );
	       target->apply_condition("chanchu_poison",10);
	       target->apply_condition("snake_poison",30 );
	       target->apply_condition("wugong_poison",30 );
	       target->apply_condition("zhizhu_poison",30 );
	       target->apply_condition("xiezi_poison",30 );
	       target->apply_condition("chanchu_poison",30);
    target->start_busy(6);           
}
else 
{
    if( (int)me->query("qi") > (int)me->query("eff_qi") ) me->set("qi", (int)me->query("eff_qi"));
      if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
                msg += HIR "$nһ��ɶҲ��������,ֻ�ò�ȡ��ʽ������������\n" NOR;
            target->start_busy(3);           
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
message_combatd(HIC "$n"HIC"����һ����Ծ����Ũ��Ĺ�����Χ��\n" NOR, me, target);
    me->start_busy(1); 	
}

        return 1;
  
 }
 // weishe.c
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{
        string who,weapon;
        int cps, skill, myexp,tarexp; 
	
//	if( !target ) target = offensive_target(me);
        if( !target ) return notify_fail("��Ҫ����˭��\n");	
	myexp = (int)me->query("combat_exp");
	tarexp = (int)target->query("combat_exp");
	cps = (int)target->query("cps");
	skill=(int)me->query_skill("kwan-yin-spells",1);
	
	if( skill < 160 )
		return notify_fail("��Ĺ����������䲻��������ʹ�����壡\n");

	if( me->is_fighting() )
                return notify_fail("ս���в���ʹ�á����塹��\n");
        if( me->query("weishe/timer")+300 > time())
        	return notify_fail("����ܺķ��������㻹����Ϣһ�°ɡ�\n");
        	
//        if( !target ) target = offensive_target(me);
	if( me==target)
                return notify_fail("���������Լ���\n"); 
        if( (int)me->query("neili") < 100 )
                return notify_fail("��ķ���������\n"); 
                
        if( !me->is_fighting() && !target->is_fighting() &&
 		environment(me) == environment(target))
 	{
 		weapon=target->query_temp("weapon");
 		if(objectp(weapon)){
 			message_vision(HIR"$N����$n���һ�����������������е����������־��ܣ�������ʱ����\n"NOR,me,target);
 			if(myexp+random(myexp/2) < tarexp/2)
 				message_vision(HIC"$N��$n��Цһ�����������ĵ��С����Ҳ�����ң�\n"NOR,target,me);
 			else {
 				message_vision(WHT"$N��$n���������壬���������ķ��������е�������\n"NOR,target,me);
 				weapon->unequip();
 			}
 		me->add("neili", -100);
 		me->set("weishe/timer",time());
 		}else return notify_fail("�Է�û��������������Ҫʹ�����壡\n");
	}
	me->start_busy(1);
        return 1;
}     


// bx_arrow.c ��Ѫ��

#include <ansi.h>
// inherit F_CLEAN_UP;

// inherit SSERVER;
inherit F_SSERVER;

int exert(object me, object target)
{
	string msg;
	int success, ap, dp;


	if( !target ) target = offensive_target(me);
       if ( target == me ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("��Ѫ��ֻ����ս����ʹ�á�\n");

     if( !target || !target->is_character() || !me->is_fighting(target) )
            return notify_fail("��Ѫ��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

//	if( !target
//	|| !target->is_character()
//	|| target->is_corpse()
//	|| target==me)
//		return notify_fail("��Ҫ��˭ʩչ��Ѫ����\n");
	if( !objectp(target) || target->query("id") == "mu ren" )
		return notify_fail("��Ҫ��˭ʩչ��Ѫ����\n");

	if((int)me->query("max_neili") < 400 )
		return notify_fail("�������������������Чʩչ��Ѫ����\n");

	if((int)me->query("max_jing") < 200 )
		return notify_fail("��ľ���������������Чʩչ��Ѫ����\n");

	if((int)me->query_skill("force",1) < 50 
         || (int)me->query_skill("wudu-shengong",1) < 50 )
		return notify_fail("����ڹ���Ϊ������������Чʩչ��Ѫ����\n");

//	if((int)me->query("qi") > (int)me->query("max_qi")*2/3 )
//		return notify_fail("���ڻ������ھͺͱ���ƴ���ɣ�\n");

	if((int)me->query("combat_exp") < (int)target->query("combat_exp")/10)
		return notify_fail("�Է��书ǿ��ʮ�����������õģ����ǿ��ܰɣ�\n");

	message_vision( HIC
"$N˫ĿѪ�죬��ͷɢ�������췢��һ����Х��\n\n$N����һ�ᣬ���Լ�������һҧ����������������һ���涾Ѫ����$n���˹�ȥ��\n" NOR,me,target);

	success = 1;
	ap = me->query_skill("force",1)+me->query_skill("wudu-shengong",1);
	ap = ap /2 ;
       ap = ap * ap * ap/10;
	ap = ap+(int)me->query("combat_exp");
//	ap = ap * ap;          
	dp = target->query("combat_exp");
//     dp = dp * dp;
	if( random(ap+dp) < random(dp) ) success = 0;

	ap = (int)me->query("max_neili");
	dp = (int)target->query("max_neili");
	if( ap < random(dp) ) success = 0;

	if(success == 1 ){
	        message_vision( HIR "���$n�ٲ�������Ѫ��������ţ���ʱ����һ���ҽУ�\n$N��״������Цһ������ǰһ�ڵ��ڵ��ϡ�\n" NOR,me,target);

		target->kill_ob(me);
		me->kill_ob(target);
		me->add("max_neili", -50);
		me->add("max_jing", -50);
		me->save();
		
		target->receive_wound("qi", (int)target->query("max_qi")+1, me);
		target->receive_wound("jing", (int)target->query("max_jing")+1, me);
		COMBAT_D->report_status(target);

		me->receive_wound("qi", (int)me->query("max_qi")+1, target);
		me->receive_wound("jing", (int)me->query("max_jing")+1, target);
		COMBAT_D->report_status(me);

	}
	    
	else {
	     message_vision( HIR "����Ѫ����$n�������𣬻���һ��Ѫ����ɢƮȥ��\n$Nһ����Ц����̾һ������ǰһ�ڵ��ڵ��ϡ�\n" NOR,me,target);

//		target->kill_ob(me);
//		me->kill_ob(target);

		me->add("max_neili", -30);
		me->add("max_jing", -30);
		me->save();
		
		me->receive_wound("qi", (int)me->query("max_qi")+1, target);
		me->receive_wound("jing", (int)me->query("max_jing")+1, target);
		COMBAT_D->report_status(me);
	} 

//	return 3+random(5);
       return 1;
}


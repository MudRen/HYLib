// cuo.c �ٻ���ȭ ���־�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>
#define PNAME "�����־�"

inherit F_SSERVER;

void remove_effect(object me, int aamount, int damount);

int perform(object me, object target)
{
  string msg;
	int flag;
	string fskill,sskill,bskill,pfname;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];


	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if( objectp(me->query_temp("weapon")) )
		return notify_fail("�������ֲ���ʹ��"PNAME"��\n");

	if( me->query_temp("kongming") )
		return notify_fail("���Ѿ���ʹ�á����־���\n");
		
	fskill = "honghua-shengong";
	bskill = "cuff";


	if( (int)me->query_skill(fskill, 1) < 150 )
		return notify_fail("���"+to_chinese(fskill)+"����Ϊ������\n");
	if( (int)me->query_skill(sskill, 1) < 150 )
		return notify_fail("���"+to_chinese(sskill)+"����Ϊ������������"+PNAME+"��\n");
	if( (int)me->query("neili") < 800 )
		return notify_fail("�������������\n");
	if( (int)me->query("max_neili") < 1000 )
		return notify_fail("���������Ϊ��������\n");

	msg = HIY"$N"HIY"ʹ���ٻ���ȭ�Ĵ��־����������Ƕ��ǣ��ö��ֲ�֪�����ʵ��ʵ��\n" NOR;
	if((int)random(me->query("combat_exp")) >	(int)target->query("combat_exp") / 3)
	{
  	target->start_busy(8);
  	me->add("neili", -400);
		        me->add_temp("apply/dodge", 50);
  tell_object(me,HIG"��Ķ����������!\n"NOR);
        me->add_temp("apply/defense", 50);
  tell_object(me,HIG"��ķ����������!\n"NOR);
        me->add_temp("apply/dexerity",50);
  tell_object(me,HIG"����ٶ������!\n"NOR);  
		
		me->set_temp("kongming", 1);
		me->start_call_out( (: call_other, __FILE__, "remove_effect", me, 1, 0:), 10);
		msg += HIY"$n"HIY"���������Ա�$N���ң����л��ڿմ���\n"NOR;
// ��Ч��combatd.c�����֣�ͬ����ȭ�ľ��С���ʱ�������2�뼴���С�
	}
	else{
	  me->add("neili", -100);
		msg += HIG"��$n"HIG"��԰ٻ���ȭ�������ģ�����$N"HIG"ȭ����ʵӰ�죡\n"NOR;
	  me->start_busy(2);
	}
	message_combatd(msg, me, target);
	return 1;
}

void remove_effect(object me, int i, int j)
{
	if ( (int)me->query_temp("kongming") ) 
	{
		me->delete_temp("kongming");
		        me->add_temp("apply/dodge", -50);
        me->add_temp("apply/defense", -50);
        me->add_temp("apply/dexerity",-50);

		tell_object(me, HIR"�������һ�٣����־��չ��ˡ�\n"NOR);
	}
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		����ƭʵ��������ƶ�������

	����Ҫ��
		�컨��150��
		�ٻ���ȭ150��
		������Ϊ1000
		����800
HELP
	);
	return 1;
}


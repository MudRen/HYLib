// ruying.c ��Ӱ����
// Last Modified by winder on May. 29 2001

#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "����Ӱ���Ρ�"
int perform(object me, object target)
{
	string msg;
	int count;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];

	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if( objectp(me->query_temp("weapon")) )
		return notify_fail("ʹ�á���Ӱ���Ρ�ʱ˫�ֱ�����ţ�\n");
	fskill = "zhanzhuang-gong";
	bskill = "leg";
	
		fskill = me->query_skill_mapped("force");

		sskill = "ruying-leg";
		fskill = "zhanzhuang-gong";


	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"�ȼ�����������ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 200 )
		return notify_fail("���"+to_chinese(sskill)+"������죬����ʹ��"+PNAME+"��\n");

	if( (int)me->query_dex() < 27 )
		return notify_fail("���������ǿ������ʹ��"PNAME"��\n");

	if( (int)me->query("neili") < 1000 )
		return notify_fail("����������̫��������ʹ��"PNAME"��\n");

	msg = HIY"$N"HIY"��Ȼ��������˫����������ʱ֮�����߰��ȣ�һ�ȼȳ����ڶ�����Ӱ���Σ�����������\n" NOR;
	message_combatd(msg, me, target);
	for (count=0;count<8;count++)
	{
		if (flag ==1 ) target = offensive_target(me);
		if (!objectp(target)) break;
		if (random(3)==0) target->start_busy(2);
		COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
	}
	me->add("neili", -400);
	me->start_busy(2);
	return 1;
}

string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
	write(@HELP

	ʹ�ù�Ч��
		���������߳����ȣ�ʹ�����޴�Ϣ֮��������ǿ��
	����Ҫ��
		վ׮��50��
		��Ӱ������200��
		������27
		����1000
HELP
	);
	return 1;
}


// liuyun.c �����߽�
// Last Modified by Sir on 5/17/2001

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
#define PNAME "�������߽���"
int perform(object me, object target)
{
	object weapon, ob;
	string msg, string1;
	int count,attack_time,i;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;

	sskill = explode(__FILE__,"/")[<2];
	pfname = explode(__FILE__,"/")[<1][0..<3];


	if( !objectp(target) ) {flag =1;target = offensive_target(me);}
	
	if( !target || !target->is_character() || target == me ||	
	  	!me->is_fighting(target) ||
  	!living(target) || target->query_temp("noliving") )
		return notify_fail(PNAME"ֻ�ܶ�ս���еĶ���ʹ�á�\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail(PNAME"��ʼʱ��������һ�ѽ���\n");

	fskill = "baiyun-xinfa";
	bskill = "sword";


	if( (int)me->query_skill(fskill, 1) < 100 )
		return notify_fail("���"+to_chinese(fskill)+"�������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(sskill, 1) < 100 )
		return notify_fail("���"+to_chinese(sskill)+"�����������޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query_skill(bskill, 1) < 100 )
		return notify_fail("���"+to_chinese(bskill)+"�������ң��޷�ʹ��"+PNAME+"��\n");

	if( (int)me->query("neili") < 400 )
		return notify_fail("�������������\n");

	msg = HIC "$N�����ɽ��������ˮ��˳����Ȼ�İ����ķ�������"+weapon->query("name")+ HIC"��ʱ��â�������������಻��ӿ����ͷ��˲Ϣ֮�䣬ȫ�������һ�Ű���֮�С�\n" NOR;
	message_combatd(msg, me);

//	attack_time = 3 + random(5);
		attack_time = 7;
    for(i = 0; i < attack_time; i++)
		{
			if (flag == 1) target = offensive_target(me);
			if (!objectp(target)) break;
if (random(3)==0) target->start_busy(2);
			COMBAT_D->do_attack(me,target,me->query_temp("weapon"),0);
			me->add("neili", -50);
		}
	me->start_busy(2+random(3));

	if(!target->is_fighting(me)) target->fight_ob(me);
	return 1;
}
string name() {return replace_string(replace_string(PNAME,"��",""),"��","");}

int help(object me)
{
	write(WHT"\n"+to_chinese(explode(__FILE__,"/")[<2])+"֮"+name()+WHT"��"NOR"\n");
        write(@HELP

        ʹ�ù�Ч��
                ������ˮ�����������

        ����Ҫ��
                �����ķ�100��
                ��ɽ����100��
                ����400
HELP
        );
        return 1;
}


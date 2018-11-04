// xiangfu-lun perform
// by iceland
// changed by emnil	2/7/2000

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h";
#include "wushuai.h";

int perform(object me, object target)
{
	string msg;
	int times,p,damage,x,h,t,lx,i;
	object weapon;

	weapon = me->query_temp("weapon");
	x = me->query_skill("riyue-lun", 1)/4;
	h = me->query_skill("hammer", 1)/4;

	if( !target ) target = offensive_target(me);

	if( !target
	  ||!target->is_character()
	  ||!me->is_fighting(target) 
	  ||!living(target))
		return notify_fail("��������˥��ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	if (!weapon)  return notify_fail("�������ʹ�÷���ʱ����ʩչ��������˥����\n");

 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "hammer")
		return notify_fail("�������ʹ�÷���ʱ����ʩչ��������˥����\n");
//	if (weapon->query("id") != "jin lun"
//	  && weapon->query("id") != "fa lun")
//		return notify_fail("�������ʹ�÷���ʱ����ʩչ��������˥����\n");

	t = weapon->query_amount();

	if (me->query_skill_mapped("hammer") != "riyue-lun")
		return notify_fail("����뼤�������ַ�����ʩչ��������˥����\n");

	if(me->query_skill("riyue-lun", 1) < 150 )
		return notify_fail("��������ַ���������죬ʹ������������˥��������\n");

	if(me->query_skill("longxiang", 1) < 160 )
		return notify_fail("��������������δ�ﵽ�ڰ˲㾳�磬�޷�ʹ����������˥��������\n");

	if((int)me->query_skill("force") < 160 )
		return notify_fail("����ڹ��ȼ�������ʹ������������˥��������\n");

	if(me->query_skill_mapped("force") != "longxiang")
		return notify_fail("û�������������Ϊ���������޷�ʹ����������˥�������ģ�\n"); 

	if((int)me->query_str() < 30)
		return notify_fail("�������������ǿ����ʹ������������˥��������\n");
       
	if(me->query_skill_mapped("parry") != "riyue-lun")
		return notify_fail("��������˥����Ҫʹ�������ַ��м�һ�ез�������\n");                       

	if((int)me->query("max_neili") < 3000 )
		return notify_fail("��������Ϊ��ǳ��ʹ������������˥����\n");      

	if( (int)me->query("neili") < 1000 )
		return notify_fail("����������̫����ʹ������������˥����\n");

	msg = HIY"\nֻ������-��-��֮��������$N�����з�����ת������ʹ����������˥��������\n"NOR;
        
//	if(weapon->query("id") == "jin lun"){
		me->set_temp("fhl", 1);
		me->add_temp("apply/damage", 350);
		t=5;
		msg+= HIR"$N���з���ַ����Ӳӷ�⣬��Ϊ����ͭ��Ǧ����⻪��Ю�������ɽ�����㹥��$n��\n\n"NOR;
//	}
	if(me->query_temp("xs/longxiang")) {
		msg += MAG"$N���������ھ����ڱ���֮�ϣ�"+weapon->query("name")+MAG"ͨ����������������ɫ��â��\n"NOR;
		lx = me->query_skill("longxiang",1)/5;
		if(lx>50) lx = 50;
		if(me->query_temp("apply/damage") >= 125) lx = lx/2;
		h = h/2;
		x = x/5;
	}
	else lx = 0;
	msg += "\n";

	message_vision(msg, me, target);

	me->add_temp("apply/strength", x);
	me->add_temp("apply/hammer", h); 
	if(wizardp(me) && me->query("env/test")) 
		tell_object(me,sprintf("lx:%d , str:%d , att:%d , damage:%d\n",lx,x,h,me->query_temp("apply/damage")));

	i = 0;
	for (times=0;times<t;times++) {
		switch(times) {
			case 0:
				msg=msga[random(sizeof(msga))];
				if (random(me->query_skill("hammer")) > target->query_skill("parry") /2 ) {
					damage = (int)me->query_skill("riyue-lun",1) + (int)me->query_skill("longxiang",1); 
					damage = damage + random(damage)*2*(100+lx)/100;
					target->receive_damage("qi", damage);
					target->receive_wound("qi", damage/2);
					me->add("neili", -damage/6);
					p = (int)target->query("qi")*100/(int)target->query("max_qi");
					msg += damage_msg(damage, "����");
					msg += "( $n"+eff_status_msg(p)+" )\n";
					if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("damage:%d   ",damage));
					i++;
				}
				else {
					me->add("neili", -100);
					msg += msgd[random(sizeof(msgd))];
				}

				message_vision(msg, me, target);
				break;
			case 1:
				COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
				message_vision("\n",me);
				me->add("neili", -100);
				break;
			case 2:
				msg=msga[random(sizeof(msga))];
				if (random(me->query("combat_exp")) > target->query("combat_exp") /2 ) {
					damage = (int)me->query_skill("riyue-lun",1) + (int)me->query_skill("longxiang",1);
					damage = damage + random(damage)*2*(100+lx)/100;
					target->receive_damage("qi", damage);
					target->receive_wound("qi", damage/2);
					me->add("neili", -damage/6);
					p = (int)target->query("qi")*100/(int)target->query("max_qi");
					msg += damage_msg(damage, "����");
					msg += "( $n"+eff_status_msg(p)+" )\n";
					if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("damage:%d   ",damage));
					i++;
				}
				else {
					me->add("neili", -150);
					msg += msgd[random(sizeof(msgd))];
				}

				message_vision(msg, me, target);
				break;
			case 3:
				if(i==0) me->add_temp("apply/hammer", me->query_skill("force")/5); 
				if(i==2) me->add_temp("apply/damage", -me->query_temp("apply/damage")/2 ); 
				COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 1);
				if(i==2) me->add_temp("apply/damage", me->query_temp("apply/damage") ); 
				if(i==0) me->add_temp("apply/hammer", -me->query_skill("force")/5); 
				message_vision("\n",me);
				me->add("neili", -100);
				break;
 			case 4:
				msg=msga[random(sizeof(msga))];
				if ( random(me->query_con()+me->query_str())*3 > target->query_dex() ) {
					damage = (int)me->query_skill("riyue-lun",1) + (int)me->query_skill("longxiang",1);
					damage = damage/2 + random(damage)*(150+lx)/150;
					target->receive_damage("qi", damage);
					target->receive_wound("qi", damage/2);
					me->add("neili", -damage/4);
					p = (int)target->query("qi")*100/(int)target->query("max_qi");
					msg += damage_msg(damage, "����");
					msg += "( $n"+eff_status_msg(p)+" )\n";
					if(wizardp(me) && me->query("env/test")) tell_object(me,sprintf("damage:%d   ",damage));
				}
				else {
					me->add("neili", -150);
					msg += msgd[random(sizeof(msgd))];
				}

				message_vision(msg, me, target);
				break;
		}
	}

	if(me->query("neili")<0) me->set("neili",0);
	if(me->query("jing")<0) me->set("jing",0);

	msg=HIY"\n$Ņ�ֽ�ס���µķ��֣�������������������һ�㣬�ж���������ࡣ\n"NOR;
	message_vision(msg, me, target);	

	if (me->query_temp("fhl")){
		me->delete_temp("fhl");
		me->add_temp("apply/damage", -50);
	}
	me->add_temp("apply/strength", -x);
	me->add_temp("apply/hammer", -h);

	me->start_busy(2);
//	me->start_perform(5,"������˥");

	return 1;
}

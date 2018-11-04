#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt,l;
	int skill, ap, dp, neili_wound, qi_wound;
	object weapon;
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("��ʹ�õ��������ԡ�\n");
	if(me->is_busy())
		return notify_fail("������û�գ���\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("biye-wu", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("zimu-zhen", 1) < 500 )
		return notify_fail("��ı����⹦������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("biyun-xinfa", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "biyun-xinfa")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");


        msg = HBWHT "$N��ͨ������ѧ��ʹ�������ŵľ�ѧ֮���裡\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);    		
	weapon = me->query_temp("weapon");
	extra = me->query_skill("zimu-zhen",1);
if (random(3)==0) target->start_busy(3);
	msg = GRN  "$Nʹ�����Ű����е����Ӹ��ڣ�����$n" NOR;
	message_vision(msg,me,target);
	me->add_temp("apply/attack",extra/3);
	me->add_temp("apply/damage",extra);
        l=extra/30;
	lmt = random(l)+5;
	if (lmt>12) lmt=12;
	for(i=1;i<=lmt;i++)
	{
	msg =  BLU "��"+chinese_number(i)+"��" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
        me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-extra);
	me->start_busy(4);
	msg = HIW "$NͻȻ���ƣ�Ȼ��Ѹ�ٷ���! ���о�Ȼ�ж�ɰ�����Ʒ羡Ȼ��������ɫ�ģ���\n";
	msg += HIG "$N˫ĿͻȻ���������̹�,��ָ�ڲ��ײ����΢΢һ��,һ������������Ϣ����$nü�ġ�\n"NOR;
        target->apply_condition("chanchu_poison", 60);
        target->apply_condition("xiezi_poison", 60);
        target->apply_condition("wugong_poison", 60);
        target->apply_condition("snake_poison", 60);
        target->apply_condition("zhizhu_poison", 60);
        target->apply_condition("tmzhuihun_poison", 60);
        target->apply_condition("tmpili_poison", 60);
        target->apply_condition("zm_poison", 60);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        target->apply_condition("tmqidu_poison", 60);
	} 
        msg += HIR"$nӲ��ͷƤ������Ӳ�ӣ���������о޶���\n" NOR;
        message_vision(msg,me,target);

	msg = HIY "$N��ָ�뵶��ָ��������ö����,Ǳ��������һʽ�������롹��ֱ��$n���ϡ��С��µ����ȥ��\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("throwing") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;

	if( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  ) {
		msg = "$N�������롹����Ŀ��, $n��ʱ���õ�����һ���ʹ��\n";
		msg += "ȫ��������й������\n" NOR;

		neili_wound = 600 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
            target->receive_damage( "qi",extra*3);
            target->receive_wound( "qi",extra*6);
       	    target->add("neili", -neili_wound);
	}
	else
	{
			me->add("neili",-80);
		msg = "����$n˲�䷴Ӧ��������Ų��Ծ�����������ش���\n"NOR;
	}
	message_vision(msg, me, target);
	return 1;
}


#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string *style_siqi = ({
HIG "СԷݺ��Ъ����$N����ᵯ����$w��ֱ��$n��$l��\n" NOR,
HIG "���ŵ���࣭��$N����$w�������ƣ�Ʈ��$n��$l��\n" NOR,
HIG "�ۿ�����ȥ����$N�����ڶ�������$w����ˮ��Ϯ��$n��$l��\n" NOR,
HIG "��������������$N����$w������ǧ�����$n��$l��\n" NOR
});
/*
       string *style_qiusheng= ({
HIR "��ɽ�续����$N����Ծ��ֱ�����죬����$w�������������϶��¹���$n��$l��\n" NOR,
HIR "������������$N�����һ������������$w��Х��������$n��$l��\n" NOR,
HIR "�������ڣ���$N����һ��������$wȦת��Х����ǿ������Х����Ȼһ�壬����$n��$l��\n" NOR
});
*/
        string *style_mix= ({
HIG "СԷݺ��Ъ����$N����ᵯ����$w��ֱ��$n��$l��\n" NOR,
HIR "��ɽ�续����$N����Ծ��ֱ�����죬����$w�������������϶��¹���$n��$l��\n" NOR,
HIG "���ŵ���࣭��$N����$w�������ƣ�Ʈ��$n��$l��\n" NOR,
HIR "������������$N�����һ������������$w��Х��������$n��$l��\n" NOR,
HIG "�ۿ�����ȥ����$N�����ڶ�������$w����ˮ��Ϯ��$n��$l��\n" NOR
HIR "�������ڣ���$N����һ��������$wȦת��Х����ǿ������Х����Ȼһ�壬����$n��$l��\n" NOR,
HIG "��������������$N����$w������ǧ�����$n��$l��\n" NOR,
});

        string msg;
	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIM "�۲ʵ����ֻ�ܶ�ս���еĶ���ʹ�á�\n"NOR);

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("��ʹ�õ��������ǵ���\n");

	if( (int)me->query_skill("zhaosheshu", 1) < 150 )
		return notify_fail("���������������졣\n");

	if( (int)me->query_skill("shenlong-bashi", 1) < 250 )
		return notify_fail("���������ʽ������졣\n");

	if( (int)me->query_skill("shenlong-xinfa", 1) < 150 )
		return notify_fail("��ı����ڹ�������졣\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("�����������ˡ�\n");


	if(pointerp(obs=me->query_team()) )
	{
	FLAG=1;
	for(i=0;i<sizeof(obs);i++)
	{
	if(obs[i] == me) continue;
	if(!obs[i]) {FLAG=0; continue;}
	if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
	if(!obs[i]->query_skill("shenlong-bashi")) {FLAG=0; continue;}
	if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
	if(ob->query("skill_type") != "parry"){FLAG=0; continue;}
	if(obs[i]->query_skill_mapped("parry") != "shenlong-bashi") {FLAG=0; continue;}
	}	
	if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("parry");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/30;
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	skl_you=(int)you->query_skill("parry");
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/30;
        me->add_temp("apply/attack",(skl_you+skl_me)/4);
        me->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->add_temp("apply/attack",(skl_you+skl_me)/4);
        you->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->kill_ob(target);
	for(i=0;i<sizeof(style_mix);i++)
	if(i%2) COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
	else    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
        me->add_temp("apply/attack",-(skl_you+skl_me)/4);
        me->add_temp("apply/damage",-(extra_you+extra_me)/2);
        you->add_temp("apply/attack",-(skl_you+skl_me)/4);
        you->add_temp("apply/damage",-(extra_you+extra_me)/2);
	}
	else
	{
        me->add_temp("apply/attack",skl_me/10);
        me->add_temp("apply/damage",extra_me/3);
        for(i=0;i<sizeof(style_siqi);i++)
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_siqi[i]);
        me->add_temp("apply/attack",-skl_me/10);
        me->add_temp("apply/damage",-extra_me/3);
	}	
         if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "��һ������"+HIR+"����$n������\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",60);
        }
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "�ڶ�������"+HIM+"ɨ��$n������\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",60);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "���һ������"+HIB+"ɨ��$n������!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",60);
        }
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);
        me->add("neili",-300);
	me->start_busy(2);
	return 1;
}
